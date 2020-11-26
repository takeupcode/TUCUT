//
//  CodeGeneratorCPP.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/17/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>
#include <vector>

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/filesystem/fstream.hpp>

#include "CodeGeneratorCPP.h"
#include "CodeGeneratorUtilityCPP.h"

#include "../Text/TextUtil.h"

using namespace std;
using namespace boost;
using namespace TUCUT;

const string Protocol::CodeGeneratorCPP::mHeaderFileExtension = ".protocol.h";
const string Protocol::CodeGeneratorCPP::mSourceFileExtension = ".protocol.cpp";
const string Protocol::CodeGeneratorCPP::mBaseClassesNamespace = "TUCUT::Protocol";
const string Protocol::CodeGeneratorCPP::mBaseClassesFileName = "ProtoBase";
#include "CodeGeneratorPrologCPP.cpp"
#include "ProtoBaseTemplateCPP.h"

Protocol::CodeGeneratorCPP::CodeGeneratorCPP ()
{ }

void Protocol::CodeGeneratorCPP::generateCode (const string & outputFolder, const ProtoModel * protoModel,
                                               const std::string & projectName, bool generateCommonCode) const
{
    if (protoModel != nullptr)
    {
        generateHeaderFile(outputFolder, *protoModel, projectName);
        generateSourceFile(outputFolder, *protoModel, projectName);
    }
    if (generateCommonCode)
    {
        generateHeaderFileCommon(outputFolder, projectName);
    }
}

void Protocol::CodeGeneratorCPP::generateHeaderFile (const std::string & outputFolder, const ProtoModel & protoModel,
                                                     const std::string & projectName) const
{
    boost::filesystem::path outputPath(outputFolder);
    boost::filesystem::path modelPath(protoModel.namePascal());
    boost::filesystem::path headerPath(outputPath / boost::filesystem::change_extension(modelPath.filename(), mHeaderFileExtension));

    boost::filesystem::create_directory(outputFolder);
    boost::filesystem::ofstream headerFile(headerPath, ios::out | ios::trunc);
    CodeWriter headerFileWriter(headerFile);

    headerFileWriter.writeLine(mGeneratedFileProlog);
    headerFileWriter.writeHeaderIncludeBlockOpening(headerIncludeBlockText(protoModel, projectName));

    writeStandardIncludeFileNamesToHeader(headerFileWriter, true);
    writeIncludedProtoFileNamesToHeader(headerFileWriter, protoModel);

    writeProtoEnumsToHeader(headerFileWriter, protoModel);

    writeProtoMessagesToHeader(headerFileWriter, protoModel);

    headerFileWriter.writeHeaderIncludeBlockClosing();
}

void Protocol::CodeGeneratorCPP::generateHeaderFileCommon (const std::string & outputFolder, const std::string & projectName) const
{
    boost::filesystem::path outputPath(outputFolder);
    boost::filesystem::path protoBasePath(mBaseClassesFileName);
    boost::filesystem::path headerPath(outputPath / boost::filesystem::change_extension(protoBasePath, mHeaderFileExtension));

    boost::filesystem::create_directory(outputFolder);
    boost::filesystem::ofstream headerFile(headerPath, ios::out | ios::trunc);
    CodeWriter headerFileWriter(headerFile);

    headerFileWriter.writeLine(mGeneratedFileProlog);
    headerFileWriter.writeHeaderIncludeBlockOpening(headerIncludeBlockText(mBaseClassesFileName, projectName));

    writeStandardIncludeFileNamesToHeader(headerFileWriter, false);

    headerFileWriter.writeLine(mProtoBaseHeaderFileTemplate);

    headerFileWriter.writeHeaderIncludeBlockClosing();
}

void Protocol::CodeGeneratorCPP::generateSourceFile (const std::string & outputFolder, const ProtoModel & protoModel,
                                                     const std::string &) const
{
    boost::filesystem::path outputPath(outputFolder);
    boost::filesystem::path modelPath(protoModel.namePascal());
    boost::filesystem::path sourcePath(outputPath / boost::filesystem::change_extension(modelPath.filename(), mSourceFileExtension));

    boost::filesystem::create_directory(outputFolder);
    boost::filesystem::ofstream sourceFile(sourcePath, ios::out | ios::trunc);
    CodeWriter sourceFileWriter(sourceFile);

    sourceFileWriter.writeLine(mGeneratedFileProlog);

    sourceFileWriter.writeIncludeProject(boost::filesystem::change_extension(modelPath, mHeaderFileExtension).string());
    sourceFileWriter.writeBlankLine();
    sourceFileWriter.writeUsingNamespace("std");
    sourceFileWriter.writeBlankLine();

    writeProtoMessagesToSource(sourceFileWriter, protoModel);
}

string Protocol::CodeGeneratorCPP::headerIncludeBlockText (const ProtoModel & protoModel, const std::string & projectName) const
{
    string text = projectName;
    if (!text.empty())
    {
        text += "_";
    }

    boost::filesystem::path modelPath(protoModel.namePascal());
    text += boost::filesystem::basename(modelPath.filename());
    text += "_protocol_h";

    return text;
}

string Protocol::CodeGeneratorCPP::headerIncludeBlockText (const std::string & headerBaseName, const std::string & projectName) const
{
    string text = projectName;
    if (!text.empty())
    {
        text += "_";
    }

    text += headerBaseName;
    text += "_h";

    return text;
}

void Protocol::CodeGeneratorCPP::writeStandardIncludeFileNamesToHeader (CodeWriter & headerFileWriter, bool includeBase) const
{
    headerFileWriter.writeIncludeLibrary("cstdint");
    headerFileWriter.writeIncludeLibrary("memory");
    headerFileWriter.writeIncludeLibrary("stdexcept");
    headerFileWriter.writeIncludeLibrary("string");
    headerFileWriter.writeIncludeLibrary("type_traits");
    headerFileWriter.writeIncludeLibrary("vector");
    headerFileWriter.writeBlankLine();

    if (includeBase)
    {
        boost::filesystem::path protoBasePath(mBaseClassesFileName);
        boost::filesystem::path headerPath(boost::filesystem::change_extension(protoBasePath, mHeaderFileExtension));
        headerFileWriter.writeIncludeProject(headerPath.string());
        headerFileWriter.writeBlankLine();
    }
}

void Protocol::CodeGeneratorCPP::writeIncludedProtoFileNamesToHeader (CodeWriter & headerFileWriter, const ProtoModel & protoModel) const
{
    auto importedProtoBegin = protoModel.importedProtoNames()->cbegin();
    auto importedProtoEnd = protoModel.importedProtoNames()->cend();
    bool importsFound = false;
    while (importedProtoBegin != importedProtoEnd)
    {
        importsFound = true;
        boost::filesystem::path protoPath(*importedProtoBegin);
        boost::filesystem::path headerPath(boost::filesystem::change_extension(protoPath, mHeaderFileExtension));
        headerFileWriter.writeIncludeProject(headerPath.string());
        ++importedProtoBegin;
    }
    if (importsFound)
    {
        headerFileWriter.writeBlankLine();
    }
}

void Protocol::CodeGeneratorCPP::writeProtoEnumsToHeader (CodeWriter & headerFileWriter, const ProtoModel & protoModel) const
{
    string currentPackage;
    vector<string> enumNamespaces;
    auto protoEnumBegin = protoModel.enums()->cbegin();
    auto protoEnumEnd = protoModel.enums()->cend();
    while (protoEnumBegin != protoEnumEnd)
    {
        auto enumModel = *protoEnumBegin;

        string enumPackage = enumModel->package();
        if (enumPackage != currentPackage)
        {
            for (size_t i = 0; i < enumNamespaces.size(); i++)
            {
                headerFileWriter.writeNamespaceClosing();
            }
            currentPackage = enumPackage;
            enumNamespaces = Text::TextUtil::splitString(enumPackage, '.');
            for (auto & str: enumNamespaces)
            {
                headerFileWriter.writeNamespaceOpening(str);
            }
        }

        writeEnumToHeader(headerFileWriter, protoModel, *enumModel, enumModel->namePascal());

        ++protoEnumBegin;
    }
    for (size_t i = 0; i < enumNamespaces.size(); i++)
    {
        headerFileWriter.writeNamespaceClosing();
    }
}

void Protocol::CodeGeneratorCPP::writeEnumToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                    const EnumModel & enumModel, const std::string & enumName) const
{
    headerFileWriter.writeEnumOpening(enumName);

    auto enumValueBegin = enumModel.enumValues()->cbegin();
    auto enumValueEnd = enumModel.enumValues()->cend();
    bool firstEnumValue = true;
    while (enumValueBegin != enumValueEnd)
    {
        auto enumValueModel = *enumValueBegin;
        if (firstEnumValue)
        {
            headerFileWriter.writeEnumValueFirst(enumValueModel->name(), enumValueModel->value());
            firstEnumValue = false;
        }
        else
        {
            headerFileWriter.writeEnumValueSubsequent(enumValueModel->name(), enumValueModel->value());
        }
        ++enumValueBegin;
    }

    headerFileWriter.writeEnumClosing();
}

void Protocol::CodeGeneratorCPP::writeProtoMessagesToHeader (CodeWriter & headerFileWriter, const ProtoModel & protoModel) const
{
    string currentPackage;
    vector<string> messageNamespaces;
    auto protoMessageBegin = protoModel.messages()->cbegin();
    auto protoMessageEnd = protoModel.messages()->cend();
    while (protoMessageBegin != protoMessageEnd)
    {
        auto messageModel = *protoMessageBegin;

        string messagePackage = messageModel->package();
        if (messagePackage != currentPackage)
        {
            for (size_t i = 0; i < messageNamespaces.size(); i++)
            {
                headerFileWriter.writeNamespaceClosing();
            }
            currentPackage = messagePackage;
            messageNamespaces = Text::TextUtil::splitString(messagePackage, '.');
            for (auto & str: messageNamespaces)
            {
                headerFileWriter.writeNamespaceOpening(str);
            }
        }
        writeMessageDeclarationToHeader(headerFileWriter, protoModel, *messageModel, messageModel->namePascal());

        ++protoMessageBegin;
    }
    headerFileWriter.writeBlankLine();

    protoMessageBegin = protoModel.messages()->cbegin();
    protoMessageEnd = protoModel.messages()->cend();
    while (protoMessageBegin != protoMessageEnd)
    {
        auto messageModel = *protoMessageBegin;

        string messagePackage = messageModel->package();
        if (messagePackage != currentPackage)
        {
            for (size_t i = 0; i < messageNamespaces.size(); i++)
            {
                headerFileWriter.writeNamespaceClosing();
            }
            currentPackage = messagePackage;
            messageNamespaces = Text::TextUtil::splitString(messagePackage, '.');
            for (auto & str: messageNamespaces)
            {
                headerFileWriter.writeNamespaceOpening(str);
            }
        }
        writeMessageEnumToHeader(headerFileWriter, protoModel, *messageModel, messageModel->namePascal());

        ++protoMessageBegin;
    }
    
    protoMessageBegin = protoModel.messages()->cbegin();
    protoMessageEnd = protoModel.messages()->cend();
    while (protoMessageBegin != protoMessageEnd)
    {
        auto messageModel = *protoMessageBegin;

        string messagePackage = messageModel->package();
        if (messagePackage != currentPackage)
        {
            for (size_t i = 0; i < messageNamespaces.size(); i++)
            {
                headerFileWriter.writeNamespaceClosing();
            }
            currentPackage = messagePackage;
            messageNamespaces = Text::TextUtil::splitString(messagePackage, '.');
            for (auto & str: messageNamespaces)
            {
                headerFileWriter.writeNamespaceOpening(str);
            }
        }
        writeMessageToHeader(headerFileWriter, protoModel, *messageModel, messageModel->namePascal());

        ++protoMessageBegin;
    }
    for (size_t i = 0; i < messageNamespaces.size(); i++)
    {
        headerFileWriter.writeNamespaceClosing();
    }
}

void Protocol::CodeGeneratorCPP::writeMessageDeclarationToHeader (CodeWriter & headerFileWriter,
                                                                  const ProtoModel & protoModel,
                                                                  const MessageModel & messageModel,
                                                                  const std::string & className) const
{
    // Generate forward declarations for all the nested classes first.
    auto messageMessageBegin = messageModel.messages()->cbegin();
    auto messageMessageEnd = messageModel.messages()->cend();
    while (messageMessageBegin != messageMessageEnd)
    {
        auto messageSubModel = *messageMessageBegin;

        string subClassName = className + "_" + messageSubModel->namePascal();
        writeMessageDeclarationToHeader(headerFileWriter, protoModel, *messageSubModel, subClassName);

        ++messageMessageBegin;
    }
    headerFileWriter.writeClassForwardDeclaration(className);
}

void Protocol::CodeGeneratorCPP::writeMessageEnumToHeader (CodeWriter & headerFileWriter,
                                                           const ProtoModel & protoModel,
                                                           const MessageModel & messageModel,
                                                           const std::string & className) const
{
    // Generate nested enums for all the nested messages first.
    auto messageMessageBegin = messageModel.messages()->cbegin();
    auto messageMessageEnd = messageModel.messages()->cend();
    while (messageMessageBegin != messageMessageEnd)
    {
        auto messageSubModel = *messageMessageBegin;

        string subClassName = className + "_" + messageSubModel->namePascal();
        writeMessageEnumToHeader(headerFileWriter, protoModel, *messageSubModel, subClassName);

        ++messageMessageBegin;
    }

    // Then generate the nested enums with modified names for this message.
    auto messageEnumBegin = messageModel.enums()->cbegin();
    auto messageEnumEnd = messageModel.enums()->cend();
    while (messageEnumBegin != messageEnumEnd)
    {
        auto enumSubModel = *messageEnumBegin;

        string subEnumName = className + "_" + enumSubModel->namePascal();
        writeEnumToHeader(headerFileWriter, protoModel, *enumSubModel, subEnumName);

        ++messageEnumBegin;
    }
}

void Protocol::CodeGeneratorCPP::writeMessageToHeader (CodeWriter & headerFileWriter,
                                                       const ProtoModel & protoModel,
                                                       const MessageModel & messageModel,
                                                       const std::string & className) const
{
    bool subMessageFound = false;
    auto messageMessageBegin = messageModel.messages()->cbegin();
    auto messageMessageEnd = messageModel.messages()->cend();
    while (messageMessageBegin != messageMessageEnd)
    {
        subMessageFound = true;
        auto messageSubModel = *messageMessageBegin;

        string subClassName = className + "_" + messageSubModel->namePascal();
        writeMessageToHeader(headerFileWriter, protoModel, *messageSubModel, subClassName);

        ++messageMessageBegin;
    }
    if (subMessageFound)
    {
        headerFileWriter.writeBlankLine();
    }

    string baseClass = "public " + mBaseClassesNamespace + "::ProtoMessage";
    headerFileWriter.writeClassOpening(className, baseClass);

    headerFileWriter.writeClassPublic();

    bool subEnumFound = false;
    auto messageEnumBegin = messageModel.enums()->cbegin();
    auto messageEnumEnd = messageModel.enums()->cend();
    while (messageEnumBegin != messageEnumEnd)
    {
        subEnumFound = true;
        auto enumSubModel = *messageEnumBegin;

        string subEnumName = className + "_" + enumSubModel->namePascal();
        headerFileWriter.writeTypedef(subEnumName, enumSubModel->namePascal());

        ++messageEnumBegin;
    }

    messageMessageBegin = messageModel.messages()->cbegin();
    messageMessageEnd = messageModel.messages()->cend();
    while (messageMessageBegin != messageMessageEnd)
    {
        auto messageSubModel = *messageMessageBegin;

        string subClassName = className + "_" + messageSubModel->namePascal();
        headerFileWriter.writeTypedef(subClassName, messageSubModel->namePascal());

        ++messageMessageBegin;
    }
    
    if (subEnumFound || subMessageFound)
    {
        headerFileWriter.writeBlankLine();
        headerFileWriter.writeClassPublic();
    }

    writeMessageConstructorToHeader(headerFileWriter, protoModel, messageModel, className);

    writeMessageCopyConstructorToHeader(headerFileWriter, protoModel, messageModel, className);

    writeMessageDestructorToHeader(headerFileWriter, protoModel, messageModel, className);

    writeMessageAssignmentOperatorToHeader(headerFileWriter, protoModel, messageModel, className);

    writeMessageSwapToHeader(headerFileWriter, protoModel, messageModel, className);

    writeMessageClearToHeader(headerFileWriter, protoModel, messageModel, className);

    string methodName = "parse";
    string methodReturn = "size_t";
    string methodParameters = "const char * pData";
    headerFileWriter.writeClassMethodDeclaration(methodName, methodReturn, methodParameters, false, true);

    methodName = "serialize";
    methodReturn = "std::string";
    headerFileWriter.writeClassMethodDeclaration(methodName, methodReturn, true, true);

    methodName = "byteSize";
    methodReturn = "size_t";
    headerFileWriter.writeClassMethodDeclaration(methodName, methodReturn, true, true);

    methodName = "valid";
    methodReturn = "bool";
    headerFileWriter.writeClassMethodDeclaration(methodName, methodReturn, true, true);

    auto messageFieldBegin = messageModel.fields()->cbegin();
    auto messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        writeMessageFieldToHeader(headerFileWriter, protoModel, *messageFieldModel);

        ++messageFieldBegin;
    }

    auto oneofBegin = messageModel.oneofs()->cbegin();
    auto oneofEnd = messageModel.oneofs()->cend();
    while (oneofBegin != oneofEnd)
    {
        auto oneofModel = *oneofBegin;

        writeOneofToHeader(headerFileWriter, protoModel, *oneofModel);

        ++oneofBegin;
    }

    headerFileWriter.writeClassPrivate();

    string classDataName = className + "Data";
    headerFileWriter.writeStructOpening(classDataName);

    messageFieldBegin = messageModel.fields()->cbegin();
    messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        writeMessageFieldIndexToHeader(headerFileWriter, *messageFieldModel);

        ++messageFieldBegin;
    }

    oneofBegin = messageModel.oneofs()->cbegin();
    oneofEnd = messageModel.oneofs()->cend();
    while (oneofBegin != oneofEnd)
    {
        auto oneofModel = *oneofBegin;

        writeMessageFieldIndexesToHeader(headerFileWriter, *oneofModel);

        ++oneofBegin;
    }

    headerFileWriter.writeBlankLine();

    methodName = classDataName;
    headerFileWriter.writeClassMethodDeclaration(methodName);

    methodName = "~";
    methodName += classDataName;
    headerFileWriter.writeClassMethodInlineOpening(methodName);
    headerFileWriter.writeClassMethodInlineClosing();

    messageFieldBegin = messageModel.fields()->cbegin();
    messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        writeMessageFieldBackingFieldsToHeader(headerFileWriter, protoModel, *messageFieldModel);

        ++messageFieldBegin;
    }

    oneofBegin = messageModel.oneofs()->cbegin();
    oneofEnd = messageModel.oneofs()->cend();
    while (oneofBegin != oneofEnd)
    {
        auto oneofModel = *oneofBegin;

        writeOneofBackingFieldsToHeader(headerFileWriter, protoModel, *oneofModel);
        
        ++oneofBegin;
    }

    headerFileWriter.writeBlankLine();

    headerFileWriter.writeClassPrivate();

    methodName = classDataName;
    methodReturn = "";
    methodParameters = "const ";
    methodParameters += classDataName + " & src";
    headerFileWriter.writeClassMethodDeclaration(methodName, methodReturn, methodParameters, false, false, false, false, true);

    methodName = "operator =";
    methodReturn = classDataName + " &";
    methodParameters = "const ";
    methodParameters += classDataName + " & rhs";
    headerFileWriter.writeClassMethodDeclaration(methodName, methodReturn, methodParameters, false, false, false, false, true);

    headerFileWriter.writeStructClosing();

    string backingFieldName = "mData";
    string backingFieldType = "std::shared_ptr<";
    backingFieldType += className + "Data>";
    headerFileWriter.writeClassFieldDeclaration(backingFieldName, backingFieldType);

    headerFileWriter.writeClassClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageConstructorToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                  const MessageModel &, const std::string & className) const
{
    string methodName = className;
    string methodParameters = "";
    string initializationParameters = "mData(new ";
    initializationParameters += className + "Data())";
    headerFileWriter.writeConstructorImplementationOpening(methodName, methodParameters, initializationParameters);
    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageCopyConstructorToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                      const MessageModel &, const std::string & className) const
{
    string methodName = className;
    string methodParameters = "const ";
    methodParameters += className + " & src";
    string initializationParameters = "ProtoMessage(src), mData(src.mData)";
    headerFileWriter.writeConstructorImplementationOpening(methodName, methodParameters, initializationParameters);
    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageDestructorToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                 const MessageModel &, const std::string & className) const
{
    string methodName = "~";
    methodName += className;
    string methodReturn = "";
    headerFileWriter.writeClassMethodInlineOpening(methodName, false, true);
    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageAssignmentOperatorToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                         const MessageModel &,
                                                                         const std::string & className) const
{
    string methodName = "operator =";
    string methodReturn = className + " &";
    string methodParameters = "const ";
    methodParameters += className + " & rhs";
    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

    string statement = "this == &rhs";
    headerFileWriter.writeIfOpening(statement);
    statement = "return *this;";
    headerFileWriter.writeLineIndented(statement);
    headerFileWriter.writeIfClosing();

    headerFileWriter.writeBlankLine();

    statement = "ProtoMessage::operator=(rhs);";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeBlankLine();

    statement = "mData = rhs.mData;";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeBlankLine();

    statement = "return *this;";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageSwapToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                           const MessageModel &, const std::string & className) const
{
    string methodName = "swap";
    string methodReturn = "void";
    string methodParameters = className + " * other";
    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

    string dataType = "std::shared_ptr<";
    dataType += className + "Data>";
    string statement = dataType + " thisData(mData);";
    headerFileWriter.writeLineIndented(statement);
    statement = dataType + " otherData(other->mData);";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeBlankLine();

    statement = "mData = otherData;";
    headerFileWriter.writeLineIndented(statement);
    statement = "other->mData = thisData;";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageClearToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                            const MessageModel &, const std::string & className) const
{
    string methodName = "clear";
    string methodReturn = "void";
    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn);

    string statement = "mData.reset(new ";
    statement += className + "Data());";
    headerFileWriter.writeLineIndented(statement);
    
    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldToHeader (CodeWriter & headerFileWriter, const ProtoModel & protoModel,
                                                            const MessageFieldModel & messageFieldModel) const
{
    if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
    {
        writeMessageFieldSizeRepeatedToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldGetRepeatedToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldSetRepeatedToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldAddRepeatedToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldAddNewRepeatedToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldClearRepeatedToHeader(headerFileWriter, protoModel, messageFieldModel);
    }
    else
    {
        writeMessageFieldHasToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldGetToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldSetToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldCreateNewToHeader(headerFileWriter, protoModel, messageFieldModel);

        writeMessageFieldClearToHeader(headerFileWriter, protoModel, messageFieldModel);
    }
}

void Protocol::CodeGeneratorCPP::writeMessageOneofFieldToHeader (CodeWriter & headerFileWriter, const ProtoModel & protoModel,
                                                                 const MessageFieldModel & messageFieldModel,
                                                                 const OneofModel & oneofModel) const
{
    writeMessageFieldHasToHeader(headerFileWriter, protoModel, messageFieldModel, &oneofModel);

    writeMessageFieldGetToHeader(headerFileWriter, protoModel, messageFieldModel, &oneofModel);

    writeMessageFieldSetToHeader(headerFileWriter, protoModel, messageFieldModel, &oneofModel);

    writeMessageFieldCreateNewToHeader(headerFileWriter, protoModel, messageFieldModel, &oneofModel);

    writeMessageFieldClearToHeader(headerFileWriter, protoModel, messageFieldModel, &oneofModel);
}

void Protocol::CodeGeneratorCPP::writeMessageFieldSizeRepeatedToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                        const MessageFieldModel & messageFieldModel) const
{
    string methodName = "size";
    methodName += messageFieldModel.namePascal();
    string methodReturn = "size_t";
    string methodParameters = "";
    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters, true);

    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Collection";
    string statement = "return ";
    statement += fieldValueName + ".size();";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldGetRepeatedToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                       const MessageFieldModel & messageFieldModel) const
{
    string fieldType = fullTypeName(messageFieldModel);
    string methodName = messageFieldModel.name();
    string methodReturn;
    string methodParameters = "size_t index";

    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Collection";
    string statement = "return ";
    statement += fieldValueName + ".value(index);";

    switch (messageFieldModel.fieldCategory())
    {
        case MessageFieldModel::FieldCategory::boolType:
        case MessageFieldModel::FieldCategory::numericType:
        case MessageFieldModel::FieldCategory::enumType:
        {
            methodReturn += fieldType;
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters, true);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        case MessageFieldModel::FieldCategory::stringType:
        case MessageFieldModel::FieldCategory::bytesType:
        case MessageFieldModel::FieldCategory::messageType:
        {
            methodReturn += "const ";
            methodReturn += fieldType + " &";
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters, true);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        default:
            break;
    }

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldSetRepeatedToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                       const MessageFieldModel & messageFieldModel) const
{
    string fieldType = fullTypeName(messageFieldModel);
    string methodName = "set";
    methodName += messageFieldModel.namePascal();
    string methodReturn = "void";
    string methodParameters = "size_t index, ";

    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Collection";
    string statement = fieldValueName + ".setValue(index, value);";

    switch (messageFieldModel.fieldCategory())
    {
        case MessageFieldModel::FieldCategory::boolType:
        case MessageFieldModel::FieldCategory::numericType:
        case MessageFieldModel::FieldCategory::enumType:
        {
            methodParameters += fieldType + " value";
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        case MessageFieldModel::FieldCategory::stringType:
        case MessageFieldModel::FieldCategory::bytesType:
        case MessageFieldModel::FieldCategory::messageType:
        {
            methodParameters += "const ";
            methodParameters += fieldType + " & value";
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        default:
            break;
    }

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldAddRepeatedToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                       const MessageFieldModel & messageFieldModel) const
{
    string fieldType = fullTypeName(messageFieldModel);
    string methodName = "add";
    methodName += messageFieldModel.namePascal();
    string methodReturn = "void";
    string methodParameters = "";

    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Collection";
    string statement = fieldValueName + ".addValue(value);";

    switch (messageFieldModel.fieldCategory())
    {
        case MessageFieldModel::FieldCategory::boolType:
        case MessageFieldModel::FieldCategory::numericType:
        case MessageFieldModel::FieldCategory::enumType:
        {
            methodParameters += fieldType + " value";
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        case MessageFieldModel::FieldCategory::stringType:
        case MessageFieldModel::FieldCategory::bytesType:
        case MessageFieldModel::FieldCategory::messageType:
        {
            methodParameters += "const ";
            methodParameters += fieldType + " & value";
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        default:
            break;
    }

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldAddNewRepeatedToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                          const MessageFieldModel & messageFieldModel) const
{
    string fieldType = fullTypeName(messageFieldModel);
    string methodName = "addNew";
    methodName += messageFieldModel.namePascal();
    string methodReturn = fieldType + " &";
    string methodParameters = "";

    switch (messageFieldModel.fieldCategory())
    {
        case MessageFieldModel::FieldCategory::messageType:
        {
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

            string fieldValueName = "mData->m";
            fieldValueName += messageFieldModel.namePascal() + "Collection";
            string statement = "return ";
            statement += fieldValueName + ".addNewValue();";
            headerFileWriter.writeLineIndented(statement);

            headerFileWriter.writeClassMethodInlineClosing();
            break;
        }

        default:
            break;
    }
}

void Protocol::CodeGeneratorCPP::writeMessageFieldClearRepeatedToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                         const MessageFieldModel & messageFieldModel) const
{
    string methodName = "clear";
    methodName += messageFieldModel.namePascal();
    string methodReturn = "void";
    string methodParameters = "";

    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Collection";
    string statement = fieldValueName + ".clearValue();";

    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldHasToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                               const MessageFieldModel & messageFieldModel,
                                                               const OneofModel * oneofModel) const
{
    string methodName = "has";
    methodName += messageFieldModel.namePascal();
    string methodReturn = "bool";
    string methodParameters = "";

    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters, true);

    string statement;
    if (oneofModel != nullptr)
    {
        string oneofEnumClassName = oneofModel->namePascal() + "Choices";
        string oneofEnumInstanceName = "mData->mCurrent";
        oneofEnumInstanceName += oneofModel->namePascal() + "Choice";

        statement = oneofEnumInstanceName + " != " + oneofEnumClassName + "::" + messageFieldModel.name();
        headerFileWriter.writeIfOpening(statement);

        statement = "return false;";
        headerFileWriter.writeLineIndented(statement);

        headerFileWriter.writeIfClosing();
        headerFileWriter.writeBlankLine();
    }

    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Value";
    statement = "return ";
    statement += fieldValueName + ".hasValue();";

    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldGetToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                               const MessageFieldModel & messageFieldModel,
                                                               const OneofModel *) const
{
    string fieldType = fullTypeName(messageFieldModel);
    string methodName = messageFieldModel.name();
    string methodReturn = "";
    string methodParameters = "";

    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Value";
    string statement = "return ";
    statement += fieldValueName + ".value();";

    switch (messageFieldModel.fieldCategory())
    {
        case MessageFieldModel::FieldCategory::boolType:
        case MessageFieldModel::FieldCategory::numericType:
        case MessageFieldModel::FieldCategory::enumType:
        {
            methodReturn += fieldType;
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters, true);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        case MessageFieldModel::FieldCategory::stringType:
        case MessageFieldModel::FieldCategory::bytesType:
        case MessageFieldModel::FieldCategory::messageType:
        {
            methodReturn += "const ";
            methodReturn += fieldType + " &";
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters, true);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        default:
            break;
    }

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldSetToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                               const MessageFieldModel & messageFieldModel,
                                                               const OneofModel * oneofModel) const
{
    string fieldType = fullTypeName(messageFieldModel);
    string methodName = "set";
    methodName += messageFieldModel.namePascal();
    string methodReturn = "void";
    string methodParameters = "";

    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Value";
    string statement = fieldValueName + ".setValue(value);";

    switch (messageFieldModel.fieldCategory())
    {
        case MessageFieldModel::FieldCategory::boolType:
        case MessageFieldModel::FieldCategory::numericType:
        case MessageFieldModel::FieldCategory::enumType:
        {
            methodParameters += fieldType + " value";
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        case MessageFieldModel::FieldCategory::stringType:
        case MessageFieldModel::FieldCategory::bytesType:
        case MessageFieldModel::FieldCategory::messageType:
        {
            methodParameters += "const ";
            methodParameters += fieldType + " & value";
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

            headerFileWriter.writeLineIndented(statement);
            break;
        }

        default:
            break;
    }

    if (oneofModel != nullptr)
    {
        headerFileWriter.writeBlankLine();

        string oneofEnumClassName = oneofModel->namePascal() + "Choices";
        string oneofEnumInstanceName = "mData->mCurrent";
        oneofEnumInstanceName += oneofModel->namePascal() + "Choice";

        statement = oneofEnumInstanceName + " = " + oneofEnumClassName + "::" + messageFieldModel.name() + ";";
        headerFileWriter.writeLineIndented(statement);
    }

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldCreateNewToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                     const MessageFieldModel & messageFieldModel,
                                                                     const OneofModel * oneofModel) const
{
    string fieldType = fullTypeName(messageFieldModel);
    string methodName = "createNew";
    methodName += messageFieldModel.namePascal();
    string methodReturn = fieldType + " &";
    string methodParameters = "";

    switch (messageFieldModel.fieldCategory())
    {
        case MessageFieldModel::FieldCategory::messageType:
        {
            headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

            string fieldValueName = "mData->m";
            fieldValueName += messageFieldModel.namePascal() + "Value";
            string statement = "return ";
            statement += fieldValueName + ".createNewValue();";
            headerFileWriter.writeLineIndented(statement);

            if (oneofModel != nullptr)
            {
                headerFileWriter.writeBlankLine();

                string oneofEnumClassName = oneofModel->namePascal() + "Choices";
                string oneofEnumInstanceName = "mData->mCurrent";
                oneofEnumInstanceName += oneofModel->namePascal() + "Choice";

                statement = oneofEnumInstanceName + " = " + oneofEnumClassName + "::" + messageFieldModel.name() + ";";
                headerFileWriter.writeLineIndented(statement);
            }

            headerFileWriter.writeClassMethodInlineClosing();
            break;
        }

        default:
            break;
    }
}

void Protocol::CodeGeneratorCPP::writeMessageFieldClearToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                 const MessageFieldModel & messageFieldModel,
                                                                 const OneofModel * oneofModel) const
{
    string methodName = "clear";
    methodName += messageFieldModel.namePascal();
    string methodReturn = "void";
    string methodParameters = "";

    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

    string statement;
    string oneofEnumClassName;
    string oneofEnumInstanceName;
    if (oneofModel != nullptr)
    {
        oneofEnumClassName = oneofModel->namePascal() + "Choices";
        oneofEnumInstanceName = "mData->mCurrent";
        oneofEnumInstanceName += oneofModel->namePascal() + "Choice";

        statement = oneofEnumInstanceName + " != " + oneofEnumClassName + "::" + messageFieldModel.name();
        headerFileWriter.writeIfOpening(statement);

        statement = "return;";
        headerFileWriter.writeLineIndented(statement);
        
        headerFileWriter.writeIfClosing();
        headerFileWriter.writeBlankLine();
    }
    
    string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Value";
    statement = fieldValueName + ".clearValue();";
    
    headerFileWriter.writeLineIndented(statement);
    
    if (oneofModel != nullptr)
    {
        headerFileWriter.writeBlankLine();
        
        statement = oneofEnumInstanceName + " = " + oneofEnumClassName + "::none;";
        headerFileWriter.writeLineIndented(statement);
    }
    
    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldBackingFieldsToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                         const MessageFieldModel & messageFieldModel) const
{
    string backingFieldName;
    string fieldType = fullTypeNameInternal(messageFieldModel);

    if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
    {
        backingFieldName = "m";
        backingFieldName += messageFieldModel.namePascal() + "Collection";
        headerFileWriter.writeClassFieldDeclaration(backingFieldName, fieldType);
    }
    else
    {
        backingFieldName = "m";
        backingFieldName += messageFieldModel.namePascal() + "Value";
        headerFileWriter.writeClassFieldDeclaration(backingFieldName, fieldType);
    }
}

void Protocol::CodeGeneratorCPP::writeMessageFieldIndexToHeader (CodeWriter & headerFileWriter,
                                                                 const MessageFieldModel & messageFieldModel) const
{
    string constantName = "m";
    constantName += messageFieldModel.namePascal() + "Index";
    string fieldType = "const unsigned int";
    headerFileWriter.writeClassFieldDeclaration(constantName, fieldType, to_string(messageFieldModel.index()), true);
}

void Protocol::CodeGeneratorCPP::writeOneofToHeader (CodeWriter & headerFileWriter, const ProtoModel & protoModel,
                                                     const OneofModel & oneofModel) const
{
    string enumName = oneofModel.namePascal() + "Choices";
    headerFileWriter.writeEnumOpening(enumName);
    headerFileWriter.writeEnumValueFirst("none", 0);

    auto messageFieldBegin = oneofModel.fields()->cbegin();
    auto messageFieldEnd = oneofModel.fields()->cend();
    string enumValueName;
    int enumValueValue = 1;
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        enumValueName = messageFieldModel->name();
        headerFileWriter.writeEnumValueSubsequent(enumValueName, enumValueValue);
        enumValueValue++;

        ++messageFieldBegin;
    }

    headerFileWriter.writeEnumClosing();

    writeMessageOneofCurrentToHeader(headerFileWriter, protoModel, oneofModel);

    writeMessageOneofClearToHeader(headerFileWriter, protoModel, oneofModel);

    messageFieldBegin = oneofModel.fields()->cbegin();
    messageFieldEnd = oneofModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        writeMessageOneofFieldToHeader(headerFileWriter, protoModel, *messageFieldModel, oneofModel);

        ++messageFieldBegin;
    }
}

void Protocol::CodeGeneratorCPP::writeOneofBackingFieldsToHeader (CodeWriter & headerFileWriter, const ProtoModel & protoModel,
                                                                  const OneofModel & oneofModel) const
{
    string backingFieldName;
    string backingFieldType;

    backingFieldName = "mCurrent";
    backingFieldName += oneofModel.namePascal() + "Choice";
    backingFieldType = oneofModel.namePascal() + "Choices";
    headerFileWriter.writeClassFieldDeclaration(backingFieldName, backingFieldType);

    auto messageFieldBegin = oneofModel.fields()->cbegin();
    auto messageFieldEnd = oneofModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        writeMessageFieldBackingFieldsToHeader(headerFileWriter, protoModel, *messageFieldModel);

        ++messageFieldBegin;
    }
}

void Protocol::CodeGeneratorCPP::writeMessageFieldIndexesToHeader (CodeWriter & headerFileWriter,
                                                                   const OneofModel & oneofModel) const
{
    auto messageFieldBegin = oneofModel.fields()->cbegin();
    auto messageFieldEnd = oneofModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        writeMessageFieldIndexToHeader(headerFileWriter, *messageFieldModel);

        ++messageFieldBegin;
    }
}

void Protocol::CodeGeneratorCPP::writeMessageOneofCurrentToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                   const OneofModel & oneofModel) const
{
    string oneofEnumClassName = oneofModel.namePascal() + "Choices";
    string oneofEnumInstanceName = "mData->mCurrent";
    oneofEnumInstanceName += oneofModel.namePascal() + "Choice";

    string methodName = "current";
    methodName += oneofModel.namePascal() + "Choice";
    string methodReturn = oneofEnumClassName;
    string methodParameters = "";
    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters, true);

    string statement = "return ";
    statement += oneofEnumInstanceName + ";";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageOneofClearToHeader (CodeWriter & headerFileWriter, const ProtoModel &,
                                                                 const OneofModel & oneofModel) const
{
    string methodName = "clear";
    methodName += oneofModel.namePascal();
    string methodReturn = "void";
    string methodParameters = "";
    headerFileWriter.writeClassMethodInlineOpening(methodName, methodReturn, methodParameters);

    string oneofEnumClassName = oneofModel.namePascal() + "Choices";
    string oneofEnumInstanceName = "mData->mCurrent";
    oneofEnumInstanceName += oneofModel.namePascal() + "Choice";

    string statement = oneofEnumInstanceName + " = " + oneofEnumClassName + "::none;";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeProtoMessagesToSource (CodeWriter & sourceFileWriter, const ProtoModel & protoModel) const
{
    auto protoMessageBegin = protoModel.messages()->cbegin();
    auto protoMessageEnd = protoModel.messages()->cend();
    while (protoMessageBegin != protoMessageEnd)
    {
        auto messageModel = *protoMessageBegin;

        writeMessageToSource(sourceFileWriter, protoModel, *messageModel, messageModel->namePascal());

        ++protoMessageBegin;
    }
}

void Protocol::CodeGeneratorCPP::writeMessageToSource (CodeWriter & sourceFileWriter, const ProtoModel & protoModel,
                                                       const MessageModel & messageModel, const std::string & className) const
{
    auto messageMessageBegin = messageModel.messages()->cbegin();
    auto messageMessageEnd = messageModel.messages()->cend();
    while (messageMessageBegin != messageMessageEnd)
    {
        auto messageSubModel = *messageMessageBegin;

        string subClassName = className + "_" + messageSubModel->namePascal();
        writeMessageToSource(sourceFileWriter, protoModel, *messageSubModel, subClassName);

        ++messageMessageBegin;
    }

    string fullScope = Text::TextUtil::replaceString(messageModel.package(), ".", "::");
    if (!fullScope.empty())
    {
        fullScope += "::";
    }
    fullScope += className;

    writeMessageDataConstructorToSource(sourceFileWriter, protoModel, messageModel, className, fullScope);

    writeMessageParseToSource(sourceFileWriter, protoModel, messageModel, className, fullScope);

    writeMessageSerializeToSource(sourceFileWriter, protoModel, messageModel, className, fullScope);

    writeMessageByteSizeToSource(sourceFileWriter, protoModel, messageModel, className, fullScope);

    writeMessageValidToSource(sourceFileWriter, protoModel, messageModel, className, fullScope);
}

void Protocol::CodeGeneratorCPP::writeMessageDataConstructorToSource (CodeWriter & sourceFileWriter, const ProtoModel & protoModel,
                                                                  const MessageModel & messageModel, const std::string & className,
                                                                  const std::string & fullScope) const
{
    string classDataName = className + "Data";
    string fullDataScope = fullScope + "::";
    fullDataScope += classDataName;

    string initializationParameters = "";
    bool firstParameter = true;
    auto messageFieldBegin = messageModel.fields()->cbegin();
    auto messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        string fieldInitialization = messageFieldInitialization(*messageFieldModel);
        if (!fieldInitialization.empty())
        {
            if (!firstParameter)
            {
                initializationParameters += ", ";
            }
            firstParameter = false;

            initializationParameters += fieldInitialization;
        }

        ++messageFieldBegin;
    }

    auto oneofBegin = messageModel.oneofs()->cbegin();
    auto oneofEnd = messageModel.oneofs()->cend();
    while (oneofBegin != oneofEnd)
    {
        auto oneofModel = *oneofBegin;

        if (!firstParameter)
        {
            initializationParameters += ", ";
        }
        firstParameter = false;

        string oneofEnumClassName = fullScope + "::" + oneofModel->namePascal() + "Choices";
        string oneofEnumInstanceName = "mCurrent";
        oneofEnumInstanceName += oneofModel->namePascal() + "Choice";

        initializationParameters += oneofEnumInstanceName + "(" + oneofEnumClassName + "::none)";

        messageFieldBegin = oneofModel->fields()->cbegin();
        messageFieldEnd = oneofModel->fields()->cend();
        while (messageFieldBegin != messageFieldEnd)
        {
            auto messageFieldModel = *messageFieldBegin;

            string fieldInitialization = messageFieldInitialization(*messageFieldModel);
            if (!fieldInitialization.empty())
            {
                initializationParameters += ", ";

                initializationParameters += fieldInitialization;
            }
            
            ++messageFieldBegin;
        }

        ++oneofBegin;
    }

    string methodName = fullDataScope + "::" + classDataName;
    string methodParameters = "";
    sourceFileWriter.writeConstructorImplementationOpening(methodName, methodParameters, initializationParameters);

    messageFieldBegin = messageModel.fields()->cbegin();
    messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        writeMessageDataFieldInitializationToSource(sourceFileWriter, protoModel, *messageFieldModel, classDataName, fullDataScope);

        ++messageFieldBegin;
    }

    oneofBegin = messageModel.oneofs()->cbegin();
    oneofEnd = messageModel.oneofs()->cend();
    while (oneofBegin != oneofEnd)
    {
        auto oneofModel = *oneofBegin;

        messageFieldBegin = oneofModel->fields()->cbegin();
        messageFieldEnd = oneofModel->fields()->cend();
        while (messageFieldBegin != messageFieldEnd)
        {
            auto messageFieldModel = *messageFieldBegin;

            writeMessageDataFieldInitializationToSource(sourceFileWriter, protoModel, *messageFieldModel, classDataName, fullDataScope);

            ++messageFieldBegin;
        }
        
        ++oneofBegin;
    }

    sourceFileWriter.writeMethodImplementationClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageDataFieldInitializationToSource (CodeWriter & sourceFileWriter, const ProtoModel &,
                                                                              const MessageFieldModel & messageFieldModel, const std::string &,
                                                                              const std::string &) const
{
    string fieldValueName = "m";
    fieldValueName += messageFieldModel.namePascal();
    if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
    {
        fieldValueName += "Collection";
    }
    else
    {
        fieldValueName += "Value";
    }

    string fieldIndexName = "m";
    fieldIndexName += messageFieldModel.namePascal() + "Index";

    string statement = fieldValueName + ".setIndex(" + fieldIndexName + ");";
    sourceFileWriter.writeLineIndented(statement);
}

std::string Protocol::CodeGeneratorCPP::messageFieldInitialization (const MessageFieldModel & messageFieldModel) const
{
    string fieldInitialization;

    if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
    {
        fieldInitialization = "m" + messageFieldModel.namePascal() + "Collection";
    }
    else
    {
        fieldInitialization = "m" + messageFieldModel.namePascal() + "Value";
    }

    switch (messageFieldModel.fieldCategory())
    {
        case MessageFieldModel::FieldCategory::boolType:
        case MessageFieldModel::FieldCategory::numericType:
        {
            if (messageFieldModel.defaultValue().empty())
            {
                return "";
            }
            fieldInitialization += "(" + messageFieldModel.defaultValue() + ")";
            break;
        }

        case MessageFieldModel::FieldCategory::enumType:
        {
            if (messageFieldModel.defaultValue().empty())
            {
                return "";
            }
            string defaultValue = fullTypeName(messageFieldModel) + "::" + messageFieldModel.defaultValue();
            fieldInitialization += "(" + defaultValue + ")";
            break;
        }

        case MessageFieldModel::FieldCategory::stringType:
        {
            if (messageFieldModel.defaultValue().empty())
            {
                return "";
            }
            fieldInitialization += "(\"" + messageFieldModel.defaultValue() + "\")";
            break;
        }

        case MessageFieldModel::FieldCategory::bytesType:
        case MessageFieldModel::FieldCategory::messageType:
        {
            return "";
        }

        default:
            break;
    }

    return fieldInitialization;
}

void Protocol::CodeGeneratorCPP::writeMessageParseToSource (CodeWriter & sourceFileWriter, const ProtoModel &,
                                                            const MessageModel & messageModel, const std::string & className,
                                                            const std::string & fullScope) const
{
    string methodName = fullScope + "::parse";
    string methodReturn = "size_t";
    string methodParameters = "const char * pData";
    sourceFileWriter.writeMethodImplementationOpening(methodName, methodReturn, methodParameters);

    string statement = "pData == nullptr";
    sourceFileWriter.writeIfOpening(statement);
    statement = "throw std::invalid_argument(\"pData cannot be null.\");";
    sourceFileWriter.writeLineIndented(statement);
    sourceFileWriter.writeIfClosing();

    sourceFileWriter.writeBlankLine();

    statement = "size_t lengthBytesParsed = 0;";
    sourceFileWriter.writeLineIndented(statement);
    statement = "std::uint32_t length = TUCUT::Protocol::PrimitiveEncoding::parseVariableUnsignedInt32(pData, &lengthBytesParsed);";
    sourceFileWriter.writeLineIndented(statement);
    statement = "pData += lengthBytesParsed;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeBlankLine();

    statement = "std::uint32_t remainingBytes = length;";
    sourceFileWriter.writeLineIndented(statement);
    statement = "remainingBytes";
    sourceFileWriter.writeWhileLoopOpening(statement);

    statement = "size_t fieldKeyBytesParsed = 0;";
    sourceFileWriter.writeLineIndented(statement);
    statement = "std::uint32_t fieldKey = TUCUT::Protocol::PrimitiveEncoding::parseVariableUnsignedInt32(pData, &fieldKeyBytesParsed);";
    sourceFileWriter.writeLineIndented(statement);
    statement = "pData += fieldKeyBytesParsed;";
    sourceFileWriter.writeLineIndented(statement);
    statement = "remainingBytes -= fieldKeyBytesParsed;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeBlankLine();

    statement = "std::uint32_t fieldIndex = fieldKey >> 3;";
    sourceFileWriter.writeLineIndented(statement);
    statement = "std::uint32_t fieldWireType = fieldKey & 0x07;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeBlankLine();

    statement = "size_t fieldBytesParsed = 0;";
    sourceFileWriter.writeLineIndented(statement);
    statement = "fieldIndex";
    sourceFileWriter.writeSwitchOpening(statement);

    auto messageFieldBegin = messageModel.fields()->cbegin();
    auto messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        string fieldIndexName = className + "Data::m";
        fieldIndexName += messageFieldModel->namePascal() + "Index";

        sourceFileWriter.writeSwitchCaseOpening(fieldIndexName);

        string fieldValueName = "mData->m";
        fieldValueName += messageFieldModel->namePascal();
        if (messageFieldModel->requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldValueName += "Collection";
        }
        else
        {
            fieldValueName += "Value";
        }

        statement = "fieldBytesParsed = ";
        statement += fieldValueName + ".parse(pData);";
        sourceFileWriter.writeLineIndented(statement);

        sourceFileWriter.writeSwitchCaseClosing();

        sourceFileWriter.writeBlankLine();

        ++messageFieldBegin;
    }

    auto oneofBegin = messageModel.oneofs()->cbegin();
    auto oneofEnd = messageModel.oneofs()->cend();
    while (oneofBegin != oneofEnd)
    {
        auto oneofModel = *oneofBegin;

        string oneofEnumClassName = oneofModel->namePascal() + "Choices";
        string oneofEnumInstanceName = "mData->mCurrent";
        oneofEnumInstanceName += oneofModel->namePascal() + "Choice";

        messageFieldBegin = oneofModel->fields()->cbegin();
        messageFieldEnd = oneofModel->fields()->cend();
        while (messageFieldBegin != messageFieldEnd)
        {
            auto messageFieldModel = *messageFieldBegin;

            string fieldIndexName = className + "Data::m";
            fieldIndexName += messageFieldModel->namePascal() + "Index";

            sourceFileWriter.writeSwitchCaseOpening(fieldIndexName);

            string fieldValueName = "mData->m";
            fieldValueName += messageFieldModel->namePascal();
            if (messageFieldModel->requiredness() == MessageFieldModel::Requiredness::repeated)
            {
                fieldValueName += "Collection";
            }
            else
            {
                fieldValueName += "Value";
            }

            statement = "fieldBytesParsed = ";
            statement += fieldValueName + ".parse(pData);";
            sourceFileWriter.writeLineIndented(statement);

            statement = oneofEnumInstanceName + " = ";
            statement += oneofEnumClassName + "::" + messageFieldModel->name() + ";";
            sourceFileWriter.writeLineIndented(statement);

            sourceFileWriter.writeSwitchCaseClosing();
            
            sourceFileWriter.writeBlankLine();

            ++messageFieldBegin;
        }
        
        ++oneofBegin;
    }

    sourceFileWriter.writeSwitchDefaultCaseOpening();
    statement = "fieldWireType";
    sourceFileWriter.writeSwitchOpening(statement);

    statement = "0";
    sourceFileWriter.writeSwitchCaseOpening(statement);
    statement = "TUCUT::Protocol::PrimitiveEncoding::parseVariableUnsignedInt64(pData, &fieldBytesParsed);";
    sourceFileWriter.writeLineIndented(statement);
    sourceFileWriter.writeSwitchCaseClosing();

    statement = "1";
    sourceFileWriter.writeSwitchCaseOpening(statement);
    statement = "fieldBytesParsed = 8;";
    sourceFileWriter.writeLineIndented(statement);
    sourceFileWriter.writeSwitchCaseClosing();

    statement = "2";
    sourceFileWriter.writeSwitchCaseOpening(statement);
    statement = "size_t fieldLengthBytesParsed = 0;";
    sourceFileWriter.writeLineIndented(statement);
    statement = "std::uint32_t fieldLength = TUCUT::Protocol::PrimitiveEncoding::parseVariableUnsignedInt32(pData, &fieldLengthBytesParsed);";
    sourceFileWriter.writeLineIndented(statement);
    statement = "fieldBytesParsed = fieldLengthBytesParsed + fieldLength;";
    sourceFileWriter.writeLineIndented(statement);
    sourceFileWriter.writeSwitchCaseClosing();

    statement = "5";
    sourceFileWriter.writeSwitchCaseOpening(statement);
    statement = "fieldBytesParsed = 4;";
    sourceFileWriter.writeLineIndented(statement);
    sourceFileWriter.writeSwitchCaseClosing();

    sourceFileWriter.writeSwitchClosing();
    sourceFileWriter.writeSwitchCaseClosing();

    sourceFileWriter.writeSwitchClosing();
    statement = "pData += fieldBytesParsed;";
    sourceFileWriter.writeLineIndented(statement);
    statement = "remainingBytes -= fieldBytesParsed;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeWhileLoopClosing();

    statement = "return lengthBytesParsed + length;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeMethodImplementationClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageSerializeToSource (CodeWriter & sourceFileWriter, const ProtoModel &,
                                                                const MessageModel & messageModel, const std::string &,
                                                                const std::string & fullScope) const
{
    string methodName = fullScope + "::serialize";
    string methodReturn = "std::string";
    sourceFileWriter.writeMethodImplementationOpening(methodName, methodReturn, true);

    string statement = "std::string result;";
    sourceFileWriter.writeLineIndented(statement);
    sourceFileWriter.writeBlankLine();

    auto messageFieldBegin = messageModel.fields()->cbegin();
    auto messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        string fieldValueName = "mData->m";
        fieldValueName += messageFieldModel->namePascal();
        if (messageFieldModel->requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldValueName += "Collection";
        }
        else
        {
            fieldValueName += "Value";
        }

        statement = "result += ";
        statement += fieldValueName + ".serialize();";
        sourceFileWriter.writeLineIndented(statement);

        sourceFileWriter.writeBlankLine();

        ++messageFieldBegin;
    }

    auto oneofBegin = messageModel.oneofs()->cbegin();
    auto oneofEnd = messageModel.oneofs()->cend();
    while (oneofBegin != oneofEnd)
    {
        auto oneofModel = *oneofBegin;

        string oneofEnumClassName = oneofModel->namePascal() + "Choices";
        string oneofEnumInstanceName = "mData->mCurrent";
        oneofEnumInstanceName += oneofModel->namePascal() + "Choice";

        statement = oneofEnumInstanceName;
        sourceFileWriter.writeSwitchOpening(statement);
        string oneofEnumCase = oneofEnumClassName + "::none";
        sourceFileWriter.writeSwitchCaseOpening(oneofEnumCase);
        sourceFileWriter.writeSwitchCaseClosing();

        messageFieldBegin = oneofModel->fields()->cbegin();
        messageFieldEnd = oneofModel->fields()->cend();
        while (messageFieldBegin != messageFieldEnd)
        {
            auto messageFieldModel = *messageFieldBegin;

            sourceFileWriter.writeBlankLine();
            
            oneofEnumCase = oneofEnumClassName + "::" + messageFieldModel->name();
            sourceFileWriter.writeSwitchCaseOpening(oneofEnumCase);

            string fieldValueName = "mData->m";
            fieldValueName += messageFieldModel->namePascal();
            if (messageFieldModel->requiredness() == MessageFieldModel::Requiredness::repeated)
            {
                fieldValueName += "Collection";
            }
            else
            {
                fieldValueName += "Value";
            }

            statement = "result += ";
            statement += fieldValueName + ".serialize();";
            sourceFileWriter.writeLineIndented(statement);

            sourceFileWriter.writeSwitchCaseClosing();

            ++messageFieldBegin;
        }

        sourceFileWriter.writeSwitchClosing();
        sourceFileWriter.writeBlankLine();

        ++oneofBegin;
    }

    statement = "result.empty()";
    sourceFileWriter.writeIfOpening(statement);

    statement = "return result;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeIfClosing();

    statement = "this->index() == 0";
    sourceFileWriter.writeElseIfOpening(statement);

    statement = "result = TUCUT::Protocol::PrimitiveEncoding::serializeVariableUnsignedInt32(static_cast<std::uint32_t>(result.length())) +";
    sourceFileWriter.writeLineIndented(statement);
    statement = "    result;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeIfClosing();
    sourceFileWriter.writeElseOpening();

    statement = "result = TUCUT::Protocol::PrimitiveEncoding::serializeVariableUnsignedInt32(key()) +";
    sourceFileWriter.writeLineIndented(statement);
    statement = "    TUCUT::Protocol::PrimitiveEncoding::serializeVariableUnsignedInt32(static_cast<std::uint32_t>(result.length())) +";
    sourceFileWriter.writeLineIndented(statement);
    statement = "    result;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeIfClosing();

    sourceFileWriter.writeBlankLine();

    statement = "return result;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeMethodImplementationClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageByteSizeToSource (CodeWriter & sourceFileWriter, const ProtoModel &,
                                                               const MessageModel & messageModel, const std::string &,
                                                               const std::string & fullScope) const
{
    string methodName = fullScope + "::byteSize";
    string methodReturn = "size_t";
    sourceFileWriter.writeMethodImplementationOpening(methodName, methodReturn, true);

    string statement = "size_t result = 0;";
    sourceFileWriter.writeLineIndented(statement);
    sourceFileWriter.writeBlankLine();

    auto messageFieldBegin = messageModel.fields()->cbegin();
    auto messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        string fieldValueName = "mData->m";
        fieldValueName += messageFieldModel->namePascal();
        if (messageFieldModel->requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldValueName += "Collection";
        }
        else
        {
            fieldValueName += "Value";
        }

        statement = "result += ";
        statement += fieldValueName + ".byteSize();";
        sourceFileWriter.writeLineIndented(statement);

        sourceFileWriter.writeBlankLine();
        
        ++messageFieldBegin;
    }

    statement = "result += TUCUT::Protocol::PrimitiveEncoding::sizeVariableUnsignedInt32(static_cast<std::uint32_t>(result));";
    sourceFileWriter.writeLineIndented(statement);

    statement = "result += TUCUT::Protocol::PrimitiveEncoding::sizeVariableUnsignedInt32(key());";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeBlankLine();

    statement = "return result;";
    sourceFileWriter.writeLineIndented(statement);
    
    sourceFileWriter.writeMethodImplementationClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageValidToSource (CodeWriter & sourceFileWriter, const ProtoModel &,
                                                              const MessageModel & messageModel, const std::string &,
                                                              const std::string & fullScope) const
{
    string methodName = fullScope + "::valid";
    string methodReturn = "bool";
    sourceFileWriter.writeMethodImplementationOpening(methodName, methodReturn, true);

    string statement;
    auto messageFieldBegin = messageModel.fields()->cbegin();
    auto messageFieldEnd = messageModel.fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
        auto messageFieldModel = *messageFieldBegin;

        string fieldValueName = "mData->m";
        fieldValueName += messageFieldModel->namePascal();
        if (messageFieldModel->requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldValueName += "Collection";
        }
        else
        {
            fieldValueName += "Value";
        }

        statement = "!" + fieldValueName + ".valid()";
        sourceFileWriter.writeIfOpening(statement);
        statement = "return false;";
        sourceFileWriter.writeLineIndented(statement);
        sourceFileWriter.writeIfClosing();

        ++messageFieldBegin;
    }
    statement = "return true;";
    sourceFileWriter.writeLineIndented(statement);

    sourceFileWriter.writeMethodImplementationClosing();
}

string Protocol::CodeGeneratorCPP::fullTypeName (const MessageFieldModel & messageFieldModel) const
{
    string fieldType = messageFieldModel.fieldType();
    if (fieldType == "bool")
    {
        return "bool";
    }
    if (fieldType == "string")
    {
        return "std::string";
    }
    if (fieldType == "double")
    {
        return "double";
    }
    if (fieldType == "float")
    {
        return "float";
    }
    if (fieldType == "int32")
    {
        return "int32_t";
    }
    if (fieldType == "int64")
    {
        return "int64_t";
    }
    if (fieldType == "uint32")
    {
        return "uint32_t";
    }
    if (fieldType == "uint64")
    {
        return "uint64_t";
    }
    if (fieldType == "sint32")
    {
        return "int32_t";
    }
    if (fieldType == "sint64")
    {
        return "int64_t";
    }
    if (fieldType == "fixed32")
    {
        return "int32_t";
    }
    if (fieldType == "fixed64")
    {
        return "int64_t";
    }
    if (fieldType == "sfixed32")
    {
        return "int32_t";
    }
    if (fieldType == "sfixed64")
    {
        return "int64_t";
    }
    if (fieldType == "bytes")
    {
        return "std::string";
    }

    fieldType = Text::TextUtil::replaceString(fieldType, ".", "_");
    string fieldTypePackage = Text::TextUtil::replaceString(messageFieldModel.fieldTypePackage(), ".", "::");
    if (!fieldTypePackage.empty())
    {
        fieldTypePackage += "::";
    }
    fieldType = fieldTypePackage + fieldType;
    return fieldType;
}

string Protocol::CodeGeneratorCPP::fullTypeNameInternal (const MessageFieldModel & messageFieldModel) const
{
    string fieldType = messageFieldModel.fieldType();
    if (fieldType == "bool")
    {
        fieldType = mBaseClassesNamespace + "::ProtoBool";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "string")
    {
        fieldType = mBaseClassesNamespace + "::ProtoString";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "double")
    {
        fieldType = mBaseClassesNamespace + "::ProtoDouble";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "float")
    {
        fieldType = mBaseClassesNamespace + "::ProtoFloat";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "int32")
    {
        fieldType = mBaseClassesNamespace + "::ProtoInt32";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "int64")
    {
        fieldType = mBaseClassesNamespace + "::ProtoInt64";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "uint32")
    {
        fieldType = mBaseClassesNamespace + "::ProtoUnsignedInt32";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "uint64")
    {
        fieldType = mBaseClassesNamespace + "::ProtoUnsignedInt64";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "sint32")
    {
        fieldType = mBaseClassesNamespace + "::ProtoSignedInt32";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "sint64")
    {
        fieldType = mBaseClassesNamespace + "::ProtoSignedInt64";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "fixed32")
    {
        fieldType = mBaseClassesNamespace + "::ProtoFixedInt32";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "fixed64")
    {
        fieldType = mBaseClassesNamespace + "::ProtoFixedInt64";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "sfixed32")
    {
        fieldType = mBaseClassesNamespace + "::ProtoFixedSignedInt32";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "sfixed64")
    {
        fieldType = mBaseClassesNamespace + "::ProtoFixedSignedInt64";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }
    if (fieldType == "bytes")
    {
        fieldType = mBaseClassesNamespace + "::ProtoBytes";
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType += "Collection";
        }
        return fieldType;
    }

    fieldType = Text::TextUtil::replaceString(fieldType, ".", "_");
    string fieldTypePackage = Text::TextUtil::replaceString(messageFieldModel.fieldTypePackage(), ".", "::");
    if (!fieldTypePackage.empty())
    {
        fieldTypePackage += "::";
    }
    fieldType = fieldTypePackage + fieldType;

    if (messageFieldModel.fieldCategory() == MessageFieldModel::FieldCategory::enumType)
    {
        if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
        {
            fieldType = mBaseClassesNamespace + "::ProtoEnumCollection<" + fieldType + ">";
        }
        else
        {
            fieldType = mBaseClassesNamespace + "::ProtoEnum<" + fieldType + ">";
        }
        return fieldType;
    }

    if (messageFieldModel.requiredness() == MessageFieldModel::Requiredness::repeated)
    {
        fieldType = mBaseClassesNamespace + "::ProtoMessageCollection<" + fieldType + ">";
    }
    else
    {
        fieldType = mBaseClassesNamespace + "::ProtoMessageField<" + fieldType + ">";
    }

    return fieldType;
}
