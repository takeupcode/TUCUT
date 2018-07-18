//
//  ProtoModel.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/16/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "ProtoModel.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::ProtoModel::ProtoModel (const std::string & fileName)
: Nameable(fileName), mCurrentField(nullptr), mCurrentOneof(nullptr), mCurrentEnum(nullptr),
  mCurrentEnumValue(nullptr)
{
}

Protocol::ProtoModel::ProtoModel (const ProtoModel & src)
: Nameable(src), Packageable(src), OptionModelContainer(src), EnumModelContainer(src), MessageModelContainer(src),
  mMessageQueue(src.mMessageQueue), mCurrentField(src.mCurrentField), mCurrentOneof(src.mCurrentOneof),
  mCurrentEnum(src.mCurrentEnum), mCurrentEnumValue(src.mCurrentEnumValue), mPrivateEnumTypes(src.mPrivateEnumTypes),
  mPublicEnumTypes(src.mPublicEnumTypes), mPrivateMessageTypes(src.mPrivateMessageTypes), mPublicMessageTypes(src.mPublicMessageTypes)
{
}

void Protocol::ProtoModel::completeModel ()
{
    auto messageCurrent = messages()->begin();
    auto messageEnd = messages()->end();
    while (messageCurrent != messageEnd)
    {
        auto messageModel = *messageCurrent;

        updateMessageFields(messageModel.get());

        ++messageCurrent;
    }
}

void Protocol::ProtoModel::updateMessageFields (MessageModel * pMessageModel, const std::string & parentMessages)
{
    auto subMessageCurrent = pMessageModel->messages()->begin();
    auto subMessageEnd = pMessageModel->messages()->end();
    while (subMessageCurrent != subMessageEnd)
    {
        auto messageModel = *subMessageCurrent;

        string parentScope = parentMessages;
        if (!parentScope.empty())
        {
            parentScope += ".";
        }
        parentScope += pMessageModel->namePascal();
        updateMessageFields(messageModel.get(), parentScope);

        ++subMessageCurrent;
    }

    auto messageFieldCurrent = pMessageModel->fields()->begin();
    auto messageFieldEnd = pMessageModel->fields()->end();
    while (messageFieldCurrent != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldCurrent;

        if (messageFieldModel->fieldCategory() == MessageFieldModel::FieldCategory::unknown)
        {
            string messageScope = parentMessages;
            if (!messageScope.empty())
            {
                messageScope += ".";
            }
            messageScope += pMessageModel->namePascal();
            string currentScope = messageFieldModel->package();
            if (!currentScope.empty())
            {
                currentScope += ".";
            }
            currentScope += messageScope;
            bool typeFound = false;
            while (true)
            {
                string currentPath = currentScope;
                if (!currentPath.empty())
                {
                    currentPath += ".";
                }
                currentPath += messageFieldModel->fieldType();
                EnumModel * pReferencedEnumModel = typeAsEnum(currentPath);
                if (pReferencedEnumModel != nullptr)
                {
                    messageFieldModel->updateFieldCategoryToEnum(pReferencedEnumModel);
                    typeFound = true;
                    break;
                }
                MessageModel * pReferencedMessageModel = typeAsMessage(currentPath);
                if (pReferencedMessageModel != nullptr)
                {
                    messageFieldModel->updateFieldCategoryToMessage(pReferencedMessageModel);
                    typeFound = true;
                    break;
                }

                // The current referenced type was not found. Keep backing up until a match is found.
                if (currentScope.empty())
                {
                    break;
                }

                auto index = currentScope.find_last_of('.');
                if (index == string::npos)
                {
                    currentScope = "";
                }
                else
                {
                    currentScope = currentScope.substr(0, index);
                }
            }
        }

        ++messageFieldCurrent;
    }
}

void Protocol::ProtoModel::addField (TokenReader::iterator current, MessageFieldModelCollection::value_type & field)
{
    field->setPackage(package());

    if (mMessageQueue.empty())
    {
        throw InvalidProtoException(current.line(), current.column(), "Required message not found.");
    }
    else
    {
        if (mCurrentOneof != nullptr)
        {
            mCurrentOneof->addField(field);
        }
        else
        {
            mMessageQueue.back()->addField(field);
        }
    }
    mCurrentField = field;
}

void Protocol::ProtoModel::completeField ()
{
    mCurrentField = nullptr;
}

void Protocol::ProtoModel::addEnum (TokenReader::iterator current, EnumModelCollection::value_type & enumeration)
{
    enumeration->setPackage(package());

    if (mMessageQueue.empty())
    {
        EnumModelContainer::addEnum(enumeration);
    }
    else
    {
        mMessageQueue.back()->addEnum(enumeration);
        enumeration->setParent(mMessageQueue.back().get());
    }
    mCurrentEnum = enumeration;

    addPublicEnumType(current, enumeration);
}

void Protocol::ProtoModel::completeEnum ()
{
    mCurrentEnum = nullptr;
}

void Protocol::ProtoModel::addEnumValue (TokenReader::iterator current, EnumValueModelCollection::value_type & value)
{
    if (mCurrentEnum != nullptr)
    {
        mCurrentEnum->addEnumValue(value);
    }
    else
    {
        throw InvalidProtoException(current.line(), current.column(), "Required enum not found.");
    }
    mCurrentEnumValue = value;
}

void Protocol::ProtoModel::completeEnumValue ()
{
    mCurrentEnumValue = nullptr;
}

void Protocol::ProtoModel::addMessage (TokenReader::iterator current, MessageModelCollection::value_type & message)
{
    message->setPackage(package());

    if (mMessageQueue.empty())
    {
        MessageModelContainer::addMessage(message);
    }
    else
    {
        mMessageQueue.back()->addMessage(message);
        message->setParent(mMessageQueue.back().get());
    }
    mMessageQueue.push_back(message);
    
    addPublicMessageType(current, message);
}

void Protocol::ProtoModel::completeMessage ()
{
    mMessageQueue.pop_back();
}

void Protocol::ProtoModel::addOneof (TokenReader::iterator current, OneofModelCollection::value_type & oneof)
{
    if (mMessageQueue.empty())
    {
        throw InvalidProtoException(current.line(), current.column(), "Required message not found.");
    }
    else
    {
        mMessageQueue.back()->addOneof(oneof);
        mCurrentOneof = oneof;
    }
}

void Protocol::ProtoModel::completeOneof ()
{
    mCurrentOneof = nullptr;
}

void Protocol::ProtoModel::addOption (TokenReader::iterator current, const OptionModelCollection::value_type & option)
{
    if (mCurrentField != nullptr)
    {
        mCurrentField->addOption(option);
        if (option->name() == "default")
        {
            mCurrentField->setDefaultValue(option->value());
        }
    }
    else if (mCurrentEnumValue != nullptr)
    {
        mCurrentEnumValue->addOption(option);
    }
    else if (mCurrentEnum != nullptr)
    {
        mCurrentEnum->addOption(option);
    }
    else if (mCurrentOneof != nullptr)
    {
        mCurrentOneof->addOption(option);
    }
    else if (mMessageQueue.empty())
    {
        OptionModelContainer::addOption(option);
    }
    else
    {
        mMessageQueue.back()->addOption(option);
    }
}

bool Protocol::ProtoModel::typeExists (const string & fullName) const
{
    if (typeAsEnum(fullName) != nullptr || typeAsMessage(fullName) != nullptr)
    {
        return true;
    }
    return false;
}

Protocol::EnumModel * Protocol::ProtoModel::typeAsEnum (const string & fullName) const
{
    auto typeIter = mPrivateEnumTypes.find(fullName);
    if (typeIter != mPrivateEnumTypes.end())
    {
        return typeIter->second.get();
    }
    typeIter = mPublicEnumTypes.find(fullName);
    if (typeIter != mPublicEnumTypes.end())
    {
        return typeIter->second.get();
    }
    return nullptr;
}

Protocol::MessageModel * Protocol::ProtoModel::typeAsMessage (const string & fullName) const
{
    auto typeIter = mPrivateMessageTypes.find(fullName);
    if (typeIter != mPrivateMessageTypes.end())
    {
        return typeIter->second.get();
    }
    typeIter = mPublicMessageTypes.find(fullName);
    if (typeIter != mPublicMessageTypes.end())
    {
        return typeIter->second.get();
    }
    return nullptr;
}

void Protocol::ProtoModel::addImportedProtoName (TokenReader::iterator current, const string & protoName)
{
    mImportedProtoNames.push_back(protoName);
}

void Protocol::ProtoModel::addPrivateEnumType (TokenReader::iterator current, const SPEnumModel & enumerationModel)
{
    string fullName = enumerationModel->nameFullWithPackage();
    if (typeExists(fullName))
    {
        throw InvalidProtoException(current.line(), current.column(), "Duplicate type names are not allowed.");
    }
    mPrivateEnumTypes.emplace(fullName, enumerationModel);
}

void Protocol::ProtoModel::addPublicEnumType (TokenReader::iterator current, const SPEnumModel & enumerationModel)
{
    string fullName = enumerationModel->nameFullWithPackage();
    if (typeExists(fullName))
    {
        throw InvalidProtoException(current.line(), current.column(), "Duplicate type names are not allowed.");
    }
    mPublicEnumTypes.emplace(fullName, enumerationModel);
}

void Protocol::ProtoModel::addPrivateMessageType (TokenReader::iterator current, const SPMessageModel & messageModel)
{
    string fullName = messageModel->nameFullWithPackage();
    if (typeExists(fullName))
    {
        throw InvalidProtoException(current.line(), current.column(), "Duplicate type names are not allowed.");
    }
    mPrivateMessageTypes.emplace(fullName, messageModel);
}

void Protocol::ProtoModel::addPublicMessageType (TokenReader::iterator current, const SPMessageModel & messageModel)
{
    string fullName = messageModel->nameFullWithPackage();
    if (typeExists(fullName))
    {
        throw InvalidProtoException(current.line(), current.column(), "Duplicate type names are not allowed.");
    }
    mPublicMessageTypes.emplace(fullName, messageModel);
}

const Protocol::ProtoModel::ImportedProtoNameCollection * Protocol::ProtoModel::importedProtoNames () const
{
    return &mImportedProtoNames;
}

const Protocol::ProtoModel::NamedEnumCollection * Protocol::ProtoModel::privateEnumTypes () const
{
    return &mPrivateEnumTypes;
}

const Protocol::ProtoModel::NamedEnumCollection * Protocol::ProtoModel::publicEnumTypes () const
{
    return &mPublicEnumTypes;
}

const Protocol::ProtoModel::NamedMessageCollection * Protocol::ProtoModel::privateMessageTypes () const
{
    return &mPrivateMessageTypes;
}

const Protocol::ProtoModel::NamedMessageCollection * Protocol::ProtoModel::publicMessageTypes () const
{
    return &mPublicMessageTypes;
}

Protocol::ProtoModel & Protocol::ProtoModel::operator = (const ProtoModel & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    Nameable::operator=(rhs);
    Packageable::operator=(rhs);
    OptionModelContainer::operator=(rhs);
    EnumModelContainer::operator=(rhs);
    MessageModelContainer::operator=(rhs);

    mMessageQueue = rhs.mMessageQueue;
    mCurrentField = rhs.mCurrentField;
    mCurrentOneof = rhs.mCurrentOneof;
    mCurrentEnum = rhs.mCurrentEnum;
    mCurrentEnumValue = rhs.mCurrentEnumValue;
    mPrivateEnumTypes = rhs.mPrivateEnumTypes;
    mPublicEnumTypes = rhs.mPublicEnumTypes;
    mPrivateMessageTypes = rhs.mPrivateMessageTypes;
    mPublicMessageTypes = rhs.mPublicMessageTypes;

    return *this;
}
