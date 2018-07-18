//
//  MessageFieldModel.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/3/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "EnumModel.h"
#include "MessageModel.h"
#include "MessageFieldModel.h"
#include "ProtoModel.h"

using namespace std;
using namespace TUCUT;

Protocol::MessageFieldModel::MessageFieldModel (Requiredness requiredness, const std::string & fieldType,
                                                const std::string & name, unsigned int index)
: Nameable(name), mRequiredness(requiredness), mFieldType(fieldType), mIndex(index)
{
    setFieldCategory();
}

Protocol::MessageFieldModel::MessageFieldModel (const MessageFieldModel & src)
: Nameable(src), Packageable(src), OptionModelContainer(src), mRequiredness(src.mRequiredness), mFieldType(src.mFieldType),
  mFieldTypePackage(src.mFieldTypePackage), mFieldCategory(src.mFieldCategory), mIndex(src.mIndex), mDefaultValue(src.mDefaultValue)
{
}

Protocol::MessageFieldModel::Requiredness Protocol::MessageFieldModel::requiredness () const
{
    return mRequiredness;
}

string Protocol::MessageFieldModel::fieldType () const
{
    return mFieldType;
}

string Protocol::MessageFieldModel::fieldTypePackage () const
{
    return mFieldTypePackage;
}

Protocol::MessageFieldModel::FieldCategory Protocol::MessageFieldModel::fieldCategory () const
{
    return mFieldCategory;
}

std::string Protocol::MessageFieldModel::defaultValue () const
{
    return mDefaultValue;
}

void Protocol::MessageFieldModel::setDefaultValue (const std::string & defaultValue)
{
    mDefaultValue = defaultValue;
}

void Protocol::MessageFieldModel::updateFieldCategoryToEnum (const EnumModel * pReferencedType)
{
    if (mFieldCategory == FieldCategory::unknown)
    {
        mFieldCategory = FieldCategory::enumType;
        mFieldType = pReferencedType->nameFullWithoutPackage();
        mFieldTypePackage = pReferencedType->package();
    }
}

void Protocol::MessageFieldModel::updateFieldCategoryToMessage (const MessageModel * pReferencedType)
{
    if (mFieldCategory == FieldCategory::unknown)
    {
        mFieldCategory = FieldCategory::messageType;
        mFieldType = pReferencedType->nameFullWithoutPackage();
        mFieldTypePackage = pReferencedType->package();
    }
}

unsigned int Protocol::MessageFieldModel::index () const
{
    return mIndex;
}

Protocol::MessageFieldModel & Protocol::MessageFieldModel::operator = (const MessageFieldModel & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    Nameable::operator=(rhs);
    Packageable::operator=(rhs);
    OptionModelContainer::operator=(rhs);

    mRequiredness = rhs.mRequiredness;
    mFieldCategory = rhs.mFieldCategory;
    mDefaultValue = rhs.mDefaultValue;
    mFieldType = rhs.mFieldType;
    mFieldTypePackage = rhs.mFieldTypePackage;
    mIndex = rhs.mIndex;

    return *this;
}

void Protocol::MessageFieldModel::setFieldCategory ()
{
    if (mFieldType == "bool")
    {
        mFieldCategory = FieldCategory::boolType;
    }
    else if (mFieldType == "string")
    {
        mFieldCategory = FieldCategory::stringType;
    }
    else if (mFieldType == "double")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "float")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "int32")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "int64")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "uint32")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "uint64")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "sint32")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "sint64")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "fixed32")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "fixed64")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "sfixed32")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "sfixed64")
    {
        mFieldCategory = FieldCategory::numericType;
    }
    else if (mFieldType == "bytes")
    {
        mFieldCategory = FieldCategory::bytesType;
    }
    else
    {
        mFieldCategory = FieldCategory::unknown;
    }
}
