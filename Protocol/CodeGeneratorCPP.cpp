//  CodeGeneratorCPP.cpp
//  TUCUT/Protocol (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2014-10-17.
//  Copyright © Take Up Code, Inc.
//
#include "CodeGeneratorCPP.h"

#include "../Text/TextUtil.h"

#include "CodeGeneratorPrologCPP.cpp"
#include "CodeGeneratorUtilityCPP.h"
#include "ProtoBaseTemplateCPP.h"

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

using namespace TUCUT;

std::string const
  Protocol::CodeGeneratorCPP::mHeaderFileExtension =
  ".protocol.h";
std::string const
  Protocol::CodeGeneratorCPP::mSourceFileExtension =
  ".protocol.cpp";
std::string const
  Protocol::CodeGeneratorCPP::mBaseClassesNamespace =
  "TUCUT::Protocol";
std::string const
  Protocol::CodeGeneratorCPP::mBaseClassesFileName =
  "ProtoBase";

void Protocol::CodeGeneratorCPP::generateCode (
  std::string const & outputFolder,
  ProtoModel const * protoModel,
  std::string const & projectName,
  bool generateCommonCode) const
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

void Protocol::CodeGeneratorCPP::generateHeaderFile (
  std::string const & outputFolder,
  ProtoModel const & protoModel,
  std::string const & projectName) const
{
  std::filesystem::path outputPath(outputFolder);
  std::filesystem::path modelPath(protoModel.namePascal());
  std::filesystem::path headerPath(outputPath /
    modelPath.filename().replace_extension(
      mHeaderFileExtension));

  std::filesystem::create_directory(outputFolder);
  std::ofstream headerFile(headerPath,
    std::ios::out | std::ios::trunc);
  CodeWriter headerFileWriter(headerFile);

  headerFileWriter.writeLine(mGeneratedFileProlog);
  headerFileWriter.writeHeaderIncludeBlockOpening(
    headerIncludeBlockText(protoModel, projectName));

  writeStandardIncludeFileNamesToHeader(
    headerFileWriter, true);
  writeIncludedProtoFileNamesToHeader(
    headerFileWriter, protoModel);

  writeProtoEnumsToHeader(headerFileWriter, protoModel);

  writeProtoMessagesToHeader(headerFileWriter, protoModel);

  headerFileWriter.writeHeaderIncludeBlockClosing();
}

void Protocol::CodeGeneratorCPP::generateHeaderFileCommon (
  std::string const & outputFolder,
  std::string const & projectName) const
{
  std::filesystem::path outputPath(outputFolder);
  std::filesystem::path protoBasePath(mBaseClassesFileName);
  std::filesystem::path headerPath(outputPath /
    protoBasePath.replace_extension(mHeaderFileExtension));

  std::filesystem::create_directory(outputFolder);
  std::ofstream headerFile(headerPath,
    std::ios::out | std::ios::trunc);
  CodeWriter headerFileWriter(headerFile);

  headerFileWriter.writeLine(mGeneratedFileProlog);
  headerFileWriter.writeHeaderIncludeBlockOpening(
    headerIncludeBlockText(mBaseClassesFileName, projectName));

  writeStandardIncludeFileNamesToHeader(
    headerFileWriter, false);

  headerFileWriter.writeLine(mProtoBaseHeaderFileTemplate);

  headerFileWriter.writeHeaderIncludeBlockClosing();
}

void Protocol::CodeGeneratorCPP::generateSourceFile (
  std::string const & outputFolder,
  ProtoModel const & protoModel,
  std::string const &) const
{
  std::filesystem::path outputPath(outputFolder);
  std::filesystem::path modelPath(protoModel.namePascal());
  std::filesystem::path sourcePath(outputPath /
    modelPath.filename().replace_extension(
      mSourceFileExtension));

  std::filesystem::create_directory(outputFolder);
  std::ofstream sourceFile(sourcePath,
    std::ios::out | std::ios::trunc);
  CodeWriter sourceFileWriter(sourceFile);

  sourceFileWriter.writeLine(mGeneratedFileProlog);

  sourceFileWriter.writeIncludeProject(
    modelPath.replace_extension(mHeaderFileExtension).string());
  sourceFileWriter.writeBlankLine();
  sourceFileWriter.writeUsingNamespace("std");
  sourceFileWriter.writeBlankLine();

  writeProtoMessagesToSource(sourceFileWriter, protoModel);
}

std::string Protocol::CodeGeneratorCPP::headerIncludeBlockText (
  ProtoModel const & protoModel,
  std::string const & projectName) const
{
  std::string text = projectName;
  if (!text.empty())
  {
    text += "_";
  }

  std::filesystem::path modelPath(protoModel.namePascal());
  text += modelPath.filename().stem().string();
  text += "_protocol_h";

  return text;
}

std::string Protocol::CodeGeneratorCPP::headerIncludeBlockText (
  std::string const & headerBaseName,
  std::string const & projectName) const
{
  std::string text = projectName;
  if (!text.empty())
  {
    text += "_";
  }

  text += headerBaseName;
  text += "_h";

  return text;
}

void Protocol::CodeGeneratorCPP::
writeStandardIncludeFileNamesToHeader (
  CodeWriter & headerFileWriter,
  bool includeBase) const
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
    std::filesystem::path protoBasePath(mBaseClassesFileName);
    std::filesystem::path headerPath(
      protoBasePath.replace_extension(mHeaderFileExtension));
    headerFileWriter.writeIncludeProject(headerPath.string());
    headerFileWriter.writeBlankLine();
  }
}

void Protocol::CodeGeneratorCPP::
writeIncludedProtoFileNamesToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel) const
{
  auto importedProtoBegin =
    protoModel.importedProtoNames()->cbegin();
  auto importedProtoEnd =
    protoModel.importedProtoNames()->cend();
  bool importsFound = false;
  while (importedProtoBegin != importedProtoEnd)
  {
    importsFound = true;
    std::filesystem::path protoPath(*importedProtoBegin);
    std::filesystem::path headerPath(
      protoPath.replace_extension(mHeaderFileExtension));
    headerFileWriter.writeIncludeProject(headerPath.string());
    ++importedProtoBegin;
  }
  if (importsFound)
  {
    headerFileWriter.writeBlankLine();
  }
}

void Protocol::CodeGeneratorCPP::writeProtoEnumsToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel) const
{
  std::string currentPackage;
  std::vector<std::string> enumNamespaces;
  auto protoEnumBegin = protoModel.enums()->cbegin();
  auto protoEnumEnd = protoModel.enums()->cend();
  while (protoEnumBegin != protoEnumEnd)
  {
    auto enumModel = *protoEnumBegin;

    std::string enumPackage = enumModel->package();
    if (enumPackage != currentPackage)
    {
      for (size_t i = 0; i < enumNamespaces.size(); i++)
      {
        headerFileWriter.writeNamespaceClosing();
      }
      currentPackage = enumPackage;
      enumNamespaces = Text::splitString(
        enumPackage, '.');
      for (auto & str: enumNamespaces)
      {
        headerFileWriter.writeNamespaceOpening(str);
      }
    }

    writeEnumToHeader(headerFileWriter, protoModel,
      *enumModel, enumModel->namePascal());

    ++protoEnumBegin;
  }
  for (size_t i = 0; i < enumNamespaces.size(); i++)
  {
    headerFileWriter.writeNamespaceClosing();
  }
}

void Protocol::CodeGeneratorCPP::writeEnumToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  const EnumModel & enumModel,
  std::string const & enumName) const
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
      headerFileWriter.writeEnumValueFirst(
        enumValueModel->name(), enumValueModel->value());
      firstEnumValue = false;
    }
    else
    {
      headerFileWriter.writeEnumValueSubsequent(
        enumValueModel->name(), enumValueModel->value());
    }
    ++enumValueBegin;
  }

  headerFileWriter.writeEnumClosing();
}

void Protocol::CodeGeneratorCPP::writeProtoMessagesToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel) const
{
  std::string currentPackage;
  std::vector<std::string> messageNamespaces;
  auto protoMessageBegin = protoModel.messages()->cbegin();
  auto protoMessageEnd = protoModel.messages()->cend();
  while (protoMessageBegin != protoMessageEnd)
  {
    auto messageModel = *protoMessageBegin;

    std::string messagePackage = messageModel->package();
    if (messagePackage != currentPackage)
    {
      for (size_t i = 0; i < messageNamespaces.size(); i++)
      {
        headerFileWriter.writeNamespaceClosing();
      }
      currentPackage = messagePackage;
      messageNamespaces = Text::splitString(
        messagePackage, '.');
      for (auto & str: messageNamespaces)
      {
        headerFileWriter.writeNamespaceOpening(str);
      }
    }
    writeMessageDeclarationToHeader(
      headerFileWriter, protoModel, *messageModel,
      messageModel->namePascal());

    ++protoMessageBegin;
  }
  headerFileWriter.writeBlankLine();

  protoMessageBegin = protoModel.messages()->cbegin();
  protoMessageEnd = protoModel.messages()->cend();
  while (protoMessageBegin != protoMessageEnd)
  {
    auto messageModel = *protoMessageBegin;

    std::string messagePackage = messageModel->package();
    if (messagePackage != currentPackage)
    {
      for (size_t i = 0; i < messageNamespaces.size(); i++)
      {
        headerFileWriter.writeNamespaceClosing();
      }
      currentPackage = messagePackage;
      messageNamespaces = Text::splitString(
        messagePackage, '.');
      for (auto & str: messageNamespaces)
      {
        headerFileWriter.writeNamespaceOpening(str);
      }
    }
    writeMessageEnumToHeader(headerFileWriter, protoModel,
      *messageModel, messageModel->namePascal());

    ++protoMessageBegin;
  }

  protoMessageBegin = protoModel.messages()->cbegin();
  protoMessageEnd = protoModel.messages()->cend();
  while (protoMessageBegin != protoMessageEnd)
  {
    auto messageModel = *protoMessageBegin;

    std::string messagePackage = messageModel->package();
    if (messagePackage != currentPackage)
    {
      for (size_t i = 0; i < messageNamespaces.size(); i++)
      {
        headerFileWriter.writeNamespaceClosing();
      }
      currentPackage = messagePackage;
      messageNamespaces = Text::splitString(
        messagePackage, '.');
      for (auto & str: messageNamespaces)
      {
        headerFileWriter.writeNamespaceOpening(str);
      }
    }
    writeMessageToHeader(headerFileWriter, protoModel,
      *messageModel, messageModel->namePascal());

    ++protoMessageBegin;
  }
  for (size_t i = 0; i < messageNamespaces.size(); i++)
  {
    headerFileWriter.writeNamespaceClosing();
  }
}

void Protocol::CodeGeneratorCPP::
writeMessageDeclarationToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel,
  MessageModel const & messageModel,
  std::string const & className) const
{
  // Generate forward declarations for all the nested
  // classes first.
  auto messageMessageBegin = messageModel.messages()->cbegin();
  auto messageMessageEnd = messageModel.messages()->cend();
  while (messageMessageBegin != messageMessageEnd)
  {
    auto messageSubModel = *messageMessageBegin;

    std::string subClassName = className + "_" +
      messageSubModel->namePascal();
    writeMessageDeclarationToHeader(headerFileWriter,
      protoModel, *messageSubModel, subClassName);

    ++messageMessageBegin;
  }
  headerFileWriter.writeClassForwardDeclaration(className);
}

void Protocol::CodeGeneratorCPP::writeMessageEnumToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel,
  MessageModel const & messageModel,
  std::string const & className) const
{
  // Generate nested enums for all the nested messages first.
  auto messageMessageBegin = messageModel.messages()->cbegin();
  auto messageMessageEnd = messageModel.messages()->cend();
  while (messageMessageBegin != messageMessageEnd)
  {
    auto messageSubModel = *messageMessageBegin;

    std::string subClassName = className + "_" +
      messageSubModel->namePascal();
    writeMessageEnumToHeader(headerFileWriter, protoModel,
      *messageSubModel, subClassName);

    ++messageMessageBegin;
  }

  // Then generate the nested enums with modified names
  // for this message.
  auto messageEnumBegin = messageModel.enums()->cbegin();
  auto messageEnumEnd = messageModel.enums()->cend();
  while (messageEnumBegin != messageEnumEnd)
  {
    auto enumSubModel = *messageEnumBegin;

    std::string subEnumName = className + "_" +
      enumSubModel->namePascal();
    writeEnumToHeader(headerFileWriter, protoModel,
      *enumSubModel, subEnumName);

    ++messageEnumBegin;
  }
}

void Protocol::CodeGeneratorCPP::writeMessageToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel,
  MessageModel const & messageModel,
  std::string const & className) const
{
  bool subMessageFound = false;
  auto messageMessageBegin = messageModel.messages()->cbegin();
  auto messageMessageEnd = messageModel.messages()->cend();
  while (messageMessageBegin != messageMessageEnd)
  {
    subMessageFound = true;
    auto messageSubModel = *messageMessageBegin;

    std::string subClassName = className + "_" +
      messageSubModel->namePascal();
    writeMessageToHeader(headerFileWriter, protoModel,
      *messageSubModel, subClassName);

    ++messageMessageBegin;
  }
  if (subMessageFound)
  {
    headerFileWriter.writeBlankLine();
  }

  std::string baseClass = "public " + mBaseClassesNamespace +
    "::ProtoMessage";
  headerFileWriter.writeClassOpening(className, baseClass);

  headerFileWriter.writeClassPublic();

  bool subEnumFound = false;
  auto messageEnumBegin = messageModel.enums()->cbegin();
  auto messageEnumEnd = messageModel.enums()->cend();
  while (messageEnumBegin != messageEnumEnd)
  {
    subEnumFound = true;
    auto enumSubModel = *messageEnumBegin;

    std::string subEnumName = className + "_" +
      enumSubModel->namePascal();
    headerFileWriter.writeTypedef(subEnumName,
      enumSubModel->namePascal());

    ++messageEnumBegin;
  }

  messageMessageBegin = messageModel.messages()->cbegin();
  messageMessageEnd = messageModel.messages()->cend();
  while (messageMessageBegin != messageMessageEnd)
  {
    auto messageSubModel = *messageMessageBegin;

    std::string subClassName = className + "_" +
      messageSubModel->namePascal();
    headerFileWriter.writeTypedef(subClassName,
      messageSubModel->namePascal());

    ++messageMessageBegin;
  }

  if (subEnumFound || subMessageFound)
  {
    headerFileWriter.writeBlankLine();
    headerFileWriter.writeClassPublic();
  }

  writeMessageConstructorToHeader(headerFileWriter,
    protoModel, messageModel, className);

  writeMessageCopyConstructorToHeader(headerFileWriter,
    protoModel, messageModel, className);

  writeMessageDestructorToHeader(headerFileWriter,
    protoModel, messageModel, className);

  writeMessageAssignmentOperatorToHeader(headerFileWriter,
    protoModel, messageModel, className);

  writeMessageSwapToHeader(headerFileWriter,
    protoModel, messageModel, className);

  writeMessageClearToHeader(headerFileWriter,
    protoModel, messageModel, className);

  std::string methodName = "parse";
  std::string methodReturn = "size_t";
  std::string methodParameters = "const char * pData";
  headerFileWriter.writeClassMethodDeclaration(methodName,
    methodReturn, methodParameters, false, true);

  methodName = "serialize";
  methodReturn = "std::string";
  headerFileWriter.writeClassMethodDeclaration(methodName,
    methodReturn, true, true);

  methodName = "byteSize";
  methodReturn = "size_t";
  headerFileWriter.writeClassMethodDeclaration(methodName,
    methodReturn, true, true);

  methodName = "valid";
  methodReturn = "bool";
  headerFileWriter.writeClassMethodDeclaration(methodName,
    methodReturn, true, true);

  auto messageFieldBegin = messageModel.fields()->cbegin();
  auto messageFieldEnd = messageModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    writeMessageFieldToHeader(headerFileWriter,
      protoModel, *messageFieldModel);

    ++messageFieldBegin;
  }

  auto oneofBegin = messageModel.oneofs()->cbegin();
  auto oneofEnd = messageModel.oneofs()->cend();
  while (oneofBegin != oneofEnd)
  {
    auto oneofModel = *oneofBegin;

    writeOneofToHeader(headerFileWriter,
      protoModel, *oneofModel);

    ++oneofBegin;
  }

  headerFileWriter.writeClassPrivate();

  std::string classDataName = className + "Data";
  headerFileWriter.writeStructOpening(classDataName);

  messageFieldBegin = messageModel.fields()->cbegin();
  messageFieldEnd = messageModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    writeMessageFieldIndexToHeader(headerFileWriter,
      *messageFieldModel);

    ++messageFieldBegin;
  }

  oneofBegin = messageModel.oneofs()->cbegin();
  oneofEnd = messageModel.oneofs()->cend();
  while (oneofBegin != oneofEnd)
  {
    auto oneofModel = *oneofBegin;

    writeMessageFieldIndexesToHeader(headerFileWriter,
      *oneofModel);

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

    writeMessageFieldBackingFieldsToHeader(headerFileWriter,
      protoModel, *messageFieldModel);

    ++messageFieldBegin;
  }

  oneofBegin = messageModel.oneofs()->cbegin();
  oneofEnd = messageModel.oneofs()->cend();
  while (oneofBegin != oneofEnd)
  {
    auto oneofModel = *oneofBegin;

    writeOneofBackingFieldsToHeader(headerFileWriter,
      protoModel, *oneofModel);

    ++oneofBegin;
  }

  headerFileWriter.writeBlankLine();

  headerFileWriter.writeClassPrivate();

  methodName = classDataName;
  methodReturn = "";
  methodParameters = "const ";
  methodParameters += classDataName + " & src";
  headerFileWriter.writeClassMethodDeclaration(
    methodName, methodReturn, methodParameters,
    false, false, false, false, true);

  methodName = "operator =";
  methodReturn = classDataName + " &";
  methodParameters = "const ";
  methodParameters += classDataName + " & rhs";
  headerFileWriter.writeClassMethodDeclaration(
    methodName, methodReturn, methodParameters,
    false, false, false, false, true);

  headerFileWriter.writeStructClosing();

  std::string backingFieldName = "mData";
  std::string backingFieldType = "std::shared_ptr<";
  backingFieldType += className + "Data>";
  headerFileWriter.writeClassFieldDeclaration(
    backingFieldName, backingFieldType);

  headerFileWriter.writeClassClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageConstructorToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageModel const &,
  std::string const & className) const
{
  std::string methodName = className;
  std::string methodParameters = "";
  std::string initializationParameters = "mData(new ";
  initializationParameters += className + "Data())";
  headerFileWriter.writeConstructorImplementationOpening(
    methodName, methodParameters, initializationParameters);
  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageCopyConstructorToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageModel const &,
  std::string const & className) const
{
  std::string methodName = className;
  std::string methodParameters = "const ";
  methodParameters += className + " & src";
  std::string initializationParameters =
    "ProtoMessage(src), mData(src.mData)";
  headerFileWriter.writeConstructorImplementationOpening(
    methodName, methodParameters, initializationParameters);
  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageDestructorToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageModel const &,
  std::string const & className) const
{
  std::string methodName = "~";
  methodName += className;
  std::string methodReturn = "";
  headerFileWriter.writeClassMethodInlineOpening(
    methodName, false, true);
  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageAssignmentOperatorToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageModel const &,
  std::string const & className) const
{
  std::string methodName = "operator =";
  std::string methodReturn = className + " &";
  std::string methodParameters = "const ";
  methodParameters += className + " & rhs";
  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn, methodParameters);

  std::string statement = "this == &rhs";
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

void Protocol::CodeGeneratorCPP::writeMessageSwapToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageModel const &,
  std::string const & className) const
{
  std::string methodName = "swap";
  std::string methodReturn = "void";
  std::string methodParameters = className + " * other";
  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn, methodParameters);

  std::string dataType = "std::shared_ptr<";
  dataType += className + "Data>";
  std::string statement = dataType + " thisData(mData);";
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

void Protocol::CodeGeneratorCPP::writeMessageClearToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageModel const &,
  std::string const & className) const
{
  std::string methodName = "clear";
  std::string methodReturn = "void";
  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn);

  std::string statement = "mData.reset(new ";
  statement += className + "Data());";
  headerFileWriter.writeLineIndented(statement);

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel,
  MessageFieldModel const & messageFieldModel) const
{
  if (messageFieldModel.requiredness() ==
    MessageFieldModel::Requiredness::repeated)
  {
    writeMessageFieldSizeRepeatedToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldGetRepeatedToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldSetRepeatedToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldAddRepeatedToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldAddNewRepeatedToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldClearRepeatedToHeader(
      headerFileWriter, protoModel, messageFieldModel);
  }
  else
  {
    writeMessageFieldHasToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldGetToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldSetToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldCreateNewToHeader(
      headerFileWriter, protoModel, messageFieldModel);

    writeMessageFieldClearToHeader(
      headerFileWriter, protoModel, messageFieldModel);
  }
}

void Protocol::CodeGeneratorCPP::
writeMessageOneofFieldToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel,
  MessageFieldModel const & messageFieldModel,
  OneofModel const & oneofModel) const
{
  writeMessageFieldHasToHeader(
    headerFileWriter, protoModel,
    messageFieldModel, &oneofModel);

  writeMessageFieldGetToHeader(
    headerFileWriter, protoModel,
    messageFieldModel, &oneofModel);

  writeMessageFieldSetToHeader(
    headerFileWriter, protoModel,
    messageFieldModel, &oneofModel);

  writeMessageFieldCreateNewToHeader(
    headerFileWriter, protoModel,
    messageFieldModel, &oneofModel);

  writeMessageFieldClearToHeader(
    headerFileWriter, protoModel,
    messageFieldModel, &oneofModel);
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldSizeRepeatedToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel) const
{
  std::string methodName = "size";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = "size_t";
  std::string methodParameters = "";
  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn, methodParameters, true);

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() +
    "Collection";
  std::string statement = "return ";
  statement += fieldValueName + ".size();";
  headerFileWriter.writeLineIndented(statement);

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldGetRepeatedToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel) const
{
  std::string fieldType = fullTypeName(messageFieldModel);
  std::string methodName = messageFieldModel.name();
  std::string methodReturn;
  std::string methodParameters = "size_t index";

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() +
    "Collection";
  std::string statement = "return ";
  statement += fieldValueName + ".value(index);";

  switch (messageFieldModel.fieldCategory())
  {
  case MessageFieldModel::FieldCategory::boolType:
  case MessageFieldModel::FieldCategory::numericType:
  case MessageFieldModel::FieldCategory::enumType:
  {
    methodReturn += fieldType;
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters, true);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  case MessageFieldModel::FieldCategory::stringType:
  case MessageFieldModel::FieldCategory::bytesType:
  case MessageFieldModel::FieldCategory::messageType:
  {
    methodReturn += "const ";
    methodReturn += fieldType + " &";
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters, true);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  default:
    break;
  }

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldSetRepeatedToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel) const
{
  std::string fieldType = fullTypeName(messageFieldModel);
  std::string methodName = "set";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = "void";
  std::string methodParameters = "size_t index, ";

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() +
    "Collection";
  std::string statement = fieldValueName +
    ".setValue(index, value);";

  switch (messageFieldModel.fieldCategory())
  {
  case MessageFieldModel::FieldCategory::boolType:
  case MessageFieldModel::FieldCategory::numericType:
  case MessageFieldModel::FieldCategory::enumType:
  {
    methodParameters += fieldType + " value";
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  case MessageFieldModel::FieldCategory::stringType:
  case MessageFieldModel::FieldCategory::bytesType:
  case MessageFieldModel::FieldCategory::messageType:
  {
    methodParameters += "const ";
    methodParameters += fieldType + " & value";
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  default:
    break;
  }

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldAddRepeatedToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel) const
{
  std::string fieldType = fullTypeName(messageFieldModel);
  std::string methodName = "add";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = "void";
  std::string methodParameters = "";

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() +
    "Collection";
  std::string statement = fieldValueName + ".addValue(value);";

  switch (messageFieldModel.fieldCategory())
  {
  case MessageFieldModel::FieldCategory::boolType:
  case MessageFieldModel::FieldCategory::numericType:
  case MessageFieldModel::FieldCategory::enumType:
  {
    methodParameters += fieldType + " value";
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  case MessageFieldModel::FieldCategory::stringType:
  case MessageFieldModel::FieldCategory::bytesType:
  case MessageFieldModel::FieldCategory::messageType:
  {
    methodParameters += "const ";
    methodParameters += fieldType + " & value";
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  default:
    break;
  }

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldAddNewRepeatedToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel) const
{
  std::string fieldType = fullTypeName(messageFieldModel);
  std::string methodName = "addNew";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = fieldType + " &";
  std::string methodParameters = "";

  switch (messageFieldModel.fieldCategory())
  {
  case MessageFieldModel::FieldCategory::messageType:
  {
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters);

    std::string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() +
      "Collection";
    std::string statement = "return ";
    statement += fieldValueName + ".addNewValue();";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeClassMethodInlineClosing();
    break;
  }

  default:
    break;
  }
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldClearRepeatedToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel) const
{
  std::string methodName = "clear";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = "void";
  std::string methodParameters = "";

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() +
    "Collection";
  std::string statement = fieldValueName + ".clearValue();";

  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn, methodParameters);

  headerFileWriter.writeLineIndented(statement);

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldHasToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel,
  OneofModel const * oneofModel) const
{
  std::string methodName = "has";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = "bool";
  std::string methodParameters = "";

  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn, methodParameters, true);

  std::string statement;
  if (oneofModel != nullptr)
  {
    std::string oneofEnumClassName = oneofModel->namePascal() +
      "Choices";
    std::string oneofEnumInstanceName = "mData->mCurrent";
    oneofEnumInstanceName += oneofModel->namePascal() +
      "Choice";

    statement = oneofEnumInstanceName + " != " +
      oneofEnumClassName + "::" + messageFieldModel.name();
    headerFileWriter.writeIfOpening(statement);

    statement = "return false;";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeIfClosing();
    headerFileWriter.writeBlankLine();
  }

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() + "Value";
  statement = "return ";
  statement += fieldValueName + ".hasValue();";

  headerFileWriter.writeLineIndented(statement);

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldGetToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel,
  OneofModel const *) const
{
  std::string fieldType = fullTypeName(messageFieldModel);
  std::string methodName = messageFieldModel.name();
  std::string methodReturn = "";
  std::string methodParameters = "";

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() + "Value";
  std::string statement = "return ";
  statement += fieldValueName + ".value();";

  switch (messageFieldModel.fieldCategory())
  {
  case MessageFieldModel::FieldCategory::boolType:
  case MessageFieldModel::FieldCategory::numericType:
  case MessageFieldModel::FieldCategory::enumType:
  {
    methodReturn += fieldType;
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters, true);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  case MessageFieldModel::FieldCategory::stringType:
  case MessageFieldModel::FieldCategory::bytesType:
  case MessageFieldModel::FieldCategory::messageType:
  {
    methodReturn += "const ";
    methodReturn += fieldType + " &";
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters, true);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  default:
    break;
  }

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageFieldSetToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel,
  OneofModel const * oneofModel) const
{
  std::string fieldType = fullTypeName(messageFieldModel);
  std::string methodName = "set";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = "void";
  std::string methodParameters = "";

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() + "Value";
  std::string statement = fieldValueName + ".setValue(value);";

  switch (messageFieldModel.fieldCategory())
  {
  case MessageFieldModel::FieldCategory::boolType:
  case MessageFieldModel::FieldCategory::numericType:
  case MessageFieldModel::FieldCategory::enumType:
  {
    methodParameters += fieldType + " value";
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  case MessageFieldModel::FieldCategory::stringType:
  case MessageFieldModel::FieldCategory::bytesType:
  case MessageFieldModel::FieldCategory::messageType:
  {
    methodParameters += "const ";
    methodParameters += fieldType + " & value";
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters);

    headerFileWriter.writeLineIndented(statement);
    break;
  }

  default:
    break;
  }

  if (oneofModel != nullptr)
  {
    headerFileWriter.writeBlankLine();

    std::string oneofEnumClassName = oneofModel->namePascal() +
      "Choices";
    std::string oneofEnumInstanceName = "mData->mCurrent";
    oneofEnumInstanceName += oneofModel->namePascal() +
      "Choice";

    statement = oneofEnumInstanceName + " = " +
      oneofEnumClassName + "::" +
      messageFieldModel.name() + ";";
    headerFileWriter.writeLineIndented(statement);
  }

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldCreateNewToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel,
  OneofModel const * oneofModel) const
{
  std::string fieldType = fullTypeName(messageFieldModel);
  std::string methodName = "createNew";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = fieldType + " &";
  std::string methodParameters = "";

  switch (messageFieldModel.fieldCategory())
  {
  case MessageFieldModel::FieldCategory::messageType:
  {
    headerFileWriter.writeClassMethodInlineOpening(
      methodName, methodReturn, methodParameters);

    std::string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel.namePascal() + "Value";
    std::string statement = "return ";
    statement += fieldValueName + ".createNewValue();";
    headerFileWriter.writeLineIndented(statement);

    if (oneofModel != nullptr)
    {
      headerFileWriter.writeBlankLine();

      std::string oneofEnumClassName =
        oneofModel->namePascal() + "Choices";
      std::string oneofEnumInstanceName = "mData->mCurrent";
      oneofEnumInstanceName += oneofModel->namePascal() +
        "Choice";

      statement = oneofEnumInstanceName + " = " +
        oneofEnumClassName + "::" +
        messageFieldModel.name() + ";";
      headerFileWriter.writeLineIndented(statement);
    }

    headerFileWriter.writeClassMethodInlineClosing();
    break;
  }

  default:
    break;
  }
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldClearToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel,
  OneofModel const * oneofModel) const
{
  std::string methodName = "clear";
  methodName += messageFieldModel.namePascal();
  std::string methodReturn = "void";
  std::string methodParameters = "";

  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn, methodParameters);

  std::string statement;
  std::string oneofEnumClassName;
  std::string oneofEnumInstanceName;
  if (oneofModel != nullptr)
  {
    oneofEnumClassName = oneofModel->namePascal() + "Choices";
    oneofEnumInstanceName = "mData->mCurrent";
    oneofEnumInstanceName += oneofModel->namePascal() +
      "Choice";

    statement = oneofEnumInstanceName + " != " +
      oneofEnumClassName + "::" + messageFieldModel.name();
    headerFileWriter.writeIfOpening(statement);

    statement = "return;";
    headerFileWriter.writeLineIndented(statement);

    headerFileWriter.writeIfClosing();
    headerFileWriter.writeBlankLine();
  }

  std::string fieldValueName = "mData->m";
  fieldValueName += messageFieldModel.namePascal() + "Value";
  statement = fieldValueName + ".clearValue();";

  headerFileWriter.writeLineIndented(statement);

  if (oneofModel != nullptr)
  {
    headerFileWriter.writeBlankLine();

    statement = oneofEnumInstanceName + " = " +
      oneofEnumClassName + "::none;";
    headerFileWriter.writeLineIndented(statement);
  }

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldBackingFieldsToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel) const
{
  std::string backingFieldName;
  std::string fieldType =
    fullTypeNameInternal(messageFieldModel);

  if (messageFieldModel.requiredness() ==
    MessageFieldModel::Requiredness::repeated)
  {
    backingFieldName = "m";
    backingFieldName += messageFieldModel.namePascal() +
      "Collection";
    headerFileWriter.writeClassFieldDeclaration(
      backingFieldName, fieldType);
  }
  else
  {
    backingFieldName = "m";
    backingFieldName += messageFieldModel.namePascal() +
      "Value";
    headerFileWriter.writeClassFieldDeclaration(
      backingFieldName, fieldType);
  }
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldIndexToHeader (
  CodeWriter & headerFileWriter,
  MessageFieldModel const & messageFieldModel) const
{
  std::string constantName = "m";
  constantName += messageFieldModel.namePascal() + "Index";
  std::string fieldType = "const unsigned int";
  headerFileWriter.writeClassFieldDeclaration(
    constantName, fieldType,
    std::to_string(messageFieldModel.index()), true);
}

void Protocol::CodeGeneratorCPP::writeOneofToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel,
  OneofModel const & oneofModel) const
{
  std::string enumName = oneofModel.namePascal() + "Choices";
  headerFileWriter.writeEnumOpening(enumName);
  headerFileWriter.writeEnumValueFirst("none", 0);

  auto messageFieldBegin = oneofModel.fields()->cbegin();
  auto messageFieldEnd = oneofModel.fields()->cend();
  std::string enumValueName;
  int enumValueValue = 1;
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    enumValueName = messageFieldModel->name();
    headerFileWriter.writeEnumValueSubsequent(
      enumValueName, enumValueValue);
    enumValueValue++;

    ++messageFieldBegin;
  }

  headerFileWriter.writeEnumClosing();

  writeMessageOneofCurrentToHeader(headerFileWriter,
    protoModel, oneofModel);

  writeMessageOneofClearToHeader(headerFileWriter,
    protoModel, oneofModel);

  messageFieldBegin = oneofModel.fields()->cbegin();
  messageFieldEnd = oneofModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    writeMessageOneofFieldToHeader(headerFileWriter,
      protoModel, *messageFieldModel, oneofModel);

    ++messageFieldBegin;
  }
}

void Protocol::CodeGeneratorCPP::
writeOneofBackingFieldsToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const & protoModel,
  OneofModel const & oneofModel) const
{
  std::string backingFieldName;
  std::string backingFieldType;

  backingFieldName = "mCurrent";
  backingFieldName += oneofModel.namePascal() + "Choice";
  backingFieldType = oneofModel.namePascal() + "Choices";
  headerFileWriter.writeClassFieldDeclaration(
    backingFieldName, backingFieldType);

  auto messageFieldBegin = oneofModel.fields()->cbegin();
  auto messageFieldEnd = oneofModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    writeMessageFieldBackingFieldsToHeader(
      headerFileWriter, protoModel, *messageFieldModel);

    ++messageFieldBegin;
  }
}

void Protocol::CodeGeneratorCPP::
writeMessageFieldIndexesToHeader (
  CodeWriter & headerFileWriter,
  OneofModel const & oneofModel) const
{
  auto messageFieldBegin = oneofModel.fields()->cbegin();
  auto messageFieldEnd = oneofModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    writeMessageFieldIndexToHeader(headerFileWriter,
      *messageFieldModel);

    ++messageFieldBegin;
  }
}

void Protocol::CodeGeneratorCPP::
writeMessageOneofCurrentToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  OneofModel const & oneofModel) const
{
  std::string oneofEnumClassName = oneofModel.namePascal() +
    "Choices";
  std::string oneofEnumInstanceName = "mData->mCurrent";
  oneofEnumInstanceName += oneofModel.namePascal() + "Choice";

  std::string methodName = "current";
  methodName += oneofModel.namePascal() + "Choice";
  std::string methodReturn = oneofEnumClassName;
  std::string methodParameters = "";
  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn, methodParameters, true);

  std::string statement = "return ";
  statement += oneofEnumInstanceName + ";";
  headerFileWriter.writeLineIndented(statement);

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageOneofClearToHeader (
  CodeWriter & headerFileWriter,
  ProtoModel const &,
  OneofModel const & oneofModel) const
{
  std::string methodName = "clear";
  methodName += oneofModel.namePascal();
  std::string methodReturn = "void";
  std::string methodParameters = "";
  headerFileWriter.writeClassMethodInlineOpening(
    methodName, methodReturn, methodParameters);

  std::string oneofEnumClassName = oneofModel.namePascal() +
    "Choices";
  std::string oneofEnumInstanceName = "mData->mCurrent";
  oneofEnumInstanceName += oneofModel.namePascal() + "Choice";

  std::string statement = oneofEnumInstanceName + " = " +
    oneofEnumClassName + "::none;";
  headerFileWriter.writeLineIndented(statement);

  headerFileWriter.writeClassMethodInlineClosing();
}

void Protocol::CodeGeneratorCPP::writeProtoMessagesToSource (
  CodeWriter & sourceFileWriter,
  ProtoModel const & protoModel) const
{
  auto protoMessageBegin = protoModel.messages()->cbegin();
  auto protoMessageEnd = protoModel.messages()->cend();
  while (protoMessageBegin != protoMessageEnd)
  {
    auto messageModel = *protoMessageBegin;

    writeMessageToSource(sourceFileWriter, protoModel,
      *messageModel, messageModel->namePascal());

    ++protoMessageBegin;
  }
}

void Protocol::CodeGeneratorCPP::writeMessageToSource (
  CodeWriter & sourceFileWriter,
  ProtoModel const & protoModel,
  MessageModel const & messageModel,
  std::string const & className) const
{
  auto messageMessageBegin = messageModel.messages()->cbegin();
  auto messageMessageEnd = messageModel.messages()->cend();
  while (messageMessageBegin != messageMessageEnd)
  {
    auto messageSubModel = *messageMessageBegin;

    std::string subClassName = className + "_" +
      messageSubModel->namePascal();
    writeMessageToSource(sourceFileWriter, protoModel,
      *messageSubModel, subClassName);

    ++messageMessageBegin;
  }

  std::string fullScope = messageModel.package();
  Text::replaceAll(fullScope, ".", "::");
  if (!fullScope.empty())
  {
    fullScope += "::";
  }
  fullScope += className;

  writeMessageDataConstructorToSource(sourceFileWriter,
    protoModel, messageModel, className, fullScope);

  writeMessageParseToSource(sourceFileWriter,
    protoModel, messageModel, className, fullScope);

  writeMessageSerializeToSource(sourceFileWriter,
    protoModel, messageModel, className, fullScope);

  writeMessageByteSizeToSource(sourceFileWriter,
    protoModel, messageModel, className, fullScope);

  writeMessageValidToSource(sourceFileWriter,
    protoModel, messageModel, className, fullScope);
}

void Protocol::CodeGeneratorCPP::
writeMessageDataConstructorToSource (
  CodeWriter & sourceFileWriter,
  ProtoModel const & protoModel,
  MessageModel const & messageModel,
  std::string const & className,
  std::string const & fullScope) const
{
  std::string classDataName = className + "Data";
  std::string fullDataScope = fullScope + "::";
  fullDataScope += classDataName;

  std::string initializationParameters = "";
  bool firstParameter = true;
  auto messageFieldBegin = messageModel.fields()->cbegin();
  auto messageFieldEnd = messageModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    std::string fieldInitialization =
      messageFieldInitialization(*messageFieldModel);
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

    std::string oneofEnumClassName = fullScope + "::" +
      oneofModel->namePascal() + "Choices";
    std::string oneofEnumInstanceName = "mCurrent";
    oneofEnumInstanceName += oneofModel->namePascal() +
      "Choice";

    initializationParameters += oneofEnumInstanceName +
      "(" + oneofEnumClassName + "::none)";

    messageFieldBegin = oneofModel->fields()->cbegin();
    messageFieldEnd = oneofModel->fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
      auto messageFieldModel = *messageFieldBegin;

      std::string fieldInitialization =
        messageFieldInitialization(*messageFieldModel);
      if (!fieldInitialization.empty())
      {
        initializationParameters += ", ";

        initializationParameters += fieldInitialization;
      }

      ++messageFieldBegin;
    }

    ++oneofBegin;
  }

  std::string methodName = fullDataScope + "::" + classDataName;
  std::string methodParameters = "";
  sourceFileWriter.writeConstructorImplementationOpening(
    methodName, methodParameters, initializationParameters);

  messageFieldBegin = messageModel.fields()->cbegin();
  messageFieldEnd = messageModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    writeMessageDataFieldInitializationToSource(
      sourceFileWriter, protoModel, *messageFieldModel,
      classDataName, fullDataScope);

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

      writeMessageDataFieldInitializationToSource(
        sourceFileWriter, protoModel, *messageFieldModel,
        classDataName, fullDataScope);

      ++messageFieldBegin;
    }

    ++oneofBegin;
  }

  sourceFileWriter.writeMethodImplementationClosing();
}

void Protocol::CodeGeneratorCPP::
writeMessageDataFieldInitializationToSource (
  CodeWriter & sourceFileWriter,
  ProtoModel const &,
  MessageFieldModel const & messageFieldModel,
  std::string const &,
  std::string const &) const
{
  std::string fieldValueName = "m";
  fieldValueName += messageFieldModel.namePascal();
  if (messageFieldModel.requiredness() ==
    MessageFieldModel::Requiredness::repeated)
  {
    fieldValueName += "Collection";
  }
  else
  {
    fieldValueName += "Value";
  }

  std::string fieldIndexName = "m";
  fieldIndexName += messageFieldModel.namePascal() + "Index";

  std::string statement = fieldValueName + ".setIndex(" +
    fieldIndexName + ");";
  sourceFileWriter.writeLineIndented(statement);
}

std::string Protocol::CodeGeneratorCPP::
messageFieldInitialization (
  MessageFieldModel const & messageFieldModel) const
{
  std::string fieldInitialization;

  if (messageFieldModel.requiredness() ==
    MessageFieldModel::Requiredness::repeated)
  {
    fieldInitialization = "m" +
      messageFieldModel.namePascal() + "Collection";
  }
  else
  {
    fieldInitialization = "m" +
      messageFieldModel.namePascal() + "Value";
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
      fieldInitialization +=
        "(" + messageFieldModel.defaultValue() + ")";
      break;
    }

  case MessageFieldModel::FieldCategory::enumType:
    {
      if (messageFieldModel.defaultValue().empty())
      {
          return "";
      }
      std::string defaultValue =
        fullTypeName(messageFieldModel) +
        "::" + messageFieldModel.defaultValue();
      fieldInitialization += "(" + defaultValue + ")";
      break;
    }

  case MessageFieldModel::FieldCategory::stringType:
    {
      if (messageFieldModel.defaultValue().empty())
      {
        return "";
      }
      fieldInitialization +=
        "(\"" + messageFieldModel.defaultValue() + "\")";
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

void Protocol::CodeGeneratorCPP::writeMessageParseToSource (
  CodeWriter & sourceFileWriter,
  ProtoModel const &,
  MessageModel const & messageModel,
  std::string const & className,
  std::string const & fullScope) const
{
  std::string methodName = fullScope + "::parse";
  std::string methodReturn = "size_t";
  std::string methodParameters = "const char * pData";
  sourceFileWriter.writeMethodImplementationOpening(
    methodName, methodReturn, methodParameters);

  std::string statement = "pData == nullptr";
  sourceFileWriter.writeIfOpening(statement);
  statement =
    "throw std::invalid_argument(\"pData cannot be null.\");";
  sourceFileWriter.writeLineIndented(statement);
  sourceFileWriter.writeIfClosing();

  sourceFileWriter.writeBlankLine();

  statement = "size_t lengthBytesParsed = 0;";
  sourceFileWriter.writeLineIndented(statement);
  statement = "std::uint32_t length = TUCUT::Protocol::"
    "PrimitiveEncoding::parseVariableUnsignedInt32("
    "pData, &lengthBytesParsed);";
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
  statement = "std::uint32_t fieldKey = TUCUT::Protocol::"
    "PrimitiveEncoding::parseVariableUnsignedInt32("
    "pData, &fieldKeyBytesParsed);";
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

    std::string fieldIndexName = className + "Data::m";
    fieldIndexName += messageFieldModel->namePascal() + "Index";

    sourceFileWriter.writeSwitchCaseOpening(fieldIndexName);

    std::string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel->namePascal();
    if (messageFieldModel->requiredness() ==
      MessageFieldModel::Requiredness::repeated)
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

    std::string oneofEnumClassName = oneofModel->namePascal() +
      "Choices";
    std::string oneofEnumInstanceName = "mData->mCurrent";
    oneofEnumInstanceName += oneofModel->namePascal() +
      "Choice";

    messageFieldBegin = oneofModel->fields()->cbegin();
    messageFieldEnd = oneofModel->fields()->cend();
    while (messageFieldBegin != messageFieldEnd)
    {
      auto messageFieldModel = *messageFieldBegin;

      std::string fieldIndexName = className + "Data::m";
      fieldIndexName += messageFieldModel->namePascal() +
        "Index";

      sourceFileWriter.writeSwitchCaseOpening(fieldIndexName);

      std::string fieldValueName = "mData->m";
      fieldValueName += messageFieldModel->namePascal();
      if (messageFieldModel->requiredness() ==
        MessageFieldModel::Requiredness::repeated)
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
      statement += oneofEnumClassName + "::" +
        messageFieldModel->name() + ";";
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
  statement = "TUCUT::Protocol::PrimitiveEncoding::"
    "parseVariableUnsignedInt64(pData, &fieldBytesParsed);";
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
  statement = "std::uint32_t fieldLength = TUCUT::Protocol::"
    "PrimitiveEncoding::parseVariableUnsignedInt32("
    "pData, &fieldLengthBytesParsed);";
  sourceFileWriter.writeLineIndented(statement);
  statement = "fieldBytesParsed = fieldLengthBytesParsed + "
    "fieldLength;";
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

void Protocol::CodeGeneratorCPP::writeMessageSerializeToSource (
  CodeWriter & sourceFileWriter,
  ProtoModel const &,
  MessageModel const & messageModel,
  std::string const &,
  std::string const & fullScope) const
{
  std::string methodName = fullScope + "::serialize";
  std::string methodReturn = "std::string";
  sourceFileWriter.writeMethodImplementationOpening(
    methodName, methodReturn, true);

  std::string statement = "std::string result;";
  sourceFileWriter.writeLineIndented(statement);
  sourceFileWriter.writeBlankLine();

  auto messageFieldBegin = messageModel.fields()->cbegin();
  auto messageFieldEnd = messageModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
      auto messageFieldModel = *messageFieldBegin;

      std::string fieldValueName = "mData->m";
      fieldValueName += messageFieldModel->namePascal();
      if (messageFieldModel->requiredness() ==
        MessageFieldModel::Requiredness::repeated)
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

      std::string oneofEnumClassName =
        oneofModel->namePascal() + "Choices";
      std::string oneofEnumInstanceName = "mData->mCurrent";
      oneofEnumInstanceName += oneofModel->namePascal() +
        "Choice";

      statement = oneofEnumInstanceName;
      sourceFileWriter.writeSwitchOpening(statement);
      std::string oneofEnumCase = oneofEnumClassName + "::none";
      sourceFileWriter.writeSwitchCaseOpening(oneofEnumCase);
      sourceFileWriter.writeSwitchCaseClosing();

      messageFieldBegin = oneofModel->fields()->cbegin();
      messageFieldEnd = oneofModel->fields()->cend();
      while (messageFieldBegin != messageFieldEnd)
      {
          auto messageFieldModel = *messageFieldBegin;

          sourceFileWriter.writeBlankLine();

          oneofEnumCase = oneofEnumClassName + "::" +
            messageFieldModel->name();
          sourceFileWriter.writeSwitchCaseOpening(
            oneofEnumCase);

          std::string fieldValueName = "mData->m";
          fieldValueName += messageFieldModel->namePascal();
          if (messageFieldModel->requiredness() ==
            MessageFieldModel::Requiredness::repeated)
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

  statement = "result = TUCUT::Protocol::PrimitiveEncoding::"
    "serializeVariableUnsignedInt32("
    "static_cast<std::uint32_t>(result.length())) +";
  sourceFileWriter.writeLineIndented(statement);
  statement = "    result;";
  sourceFileWriter.writeLineIndented(statement);

  sourceFileWriter.writeIfClosing();
  sourceFileWriter.writeElseOpening();

  statement = "result = TUCUT::Protocol::PrimitiveEncoding::"
    "serializeVariableUnsignedInt32(key()) +";
  sourceFileWriter.writeLineIndented(statement);
  statement = "    TUCUT::Protocol::PrimitiveEncoding::"
    "serializeVariableUnsignedInt32("
    "static_cast<std::uint32_t>(result.length())) +";
  sourceFileWriter.writeLineIndented(statement);
  statement = "    result;";
  sourceFileWriter.writeLineIndented(statement);

  sourceFileWriter.writeIfClosing();

  sourceFileWriter.writeBlankLine();

  statement = "return result;";
  sourceFileWriter.writeLineIndented(statement);

  sourceFileWriter.writeMethodImplementationClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageByteSizeToSource (
  CodeWriter & sourceFileWriter,
  ProtoModel const &,
  MessageModel const & messageModel,
  std::string const &,
  std::string const & fullScope) const
{
  std::string methodName = fullScope + "::byteSize";
  std::string methodReturn = "size_t";
  sourceFileWriter.writeMethodImplementationOpening(
    methodName, methodReturn, true);

  std::string statement = "size_t result = 0;";
  sourceFileWriter.writeLineIndented(statement);
  sourceFileWriter.writeBlankLine();

  auto messageFieldBegin = messageModel.fields()->cbegin();
  auto messageFieldEnd = messageModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    std::string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel->namePascal();
    if (messageFieldModel->requiredness() ==
      MessageFieldModel::Requiredness::repeated)
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

  statement = "result += TUCUT::Protocol::PrimitiveEncoding::"
    "sizeVariableUnsignedInt32("
    "static_cast<std::uint32_t>(result));";
  sourceFileWriter.writeLineIndented(statement);

  statement = "result += TUCUT::Protocol::PrimitiveEncoding::"
    "sizeVariableUnsignedInt32(key());";
  sourceFileWriter.writeLineIndented(statement);

  sourceFileWriter.writeBlankLine();

  statement = "return result;";
  sourceFileWriter.writeLineIndented(statement);

  sourceFileWriter.writeMethodImplementationClosing();
}

void Protocol::CodeGeneratorCPP::writeMessageValidToSource (
  CodeWriter & sourceFileWriter,
  ProtoModel const &,
  MessageModel const & messageModel,
  std::string const &,
  std::string const & fullScope) const
{
  std::string methodName = fullScope + "::valid";
  std::string methodReturn = "bool";
  sourceFileWriter.writeMethodImplementationOpening(
    methodName, methodReturn, true);

  std::string statement;
  auto messageFieldBegin = messageModel.fields()->cbegin();
  auto messageFieldEnd = messageModel.fields()->cend();
  while (messageFieldBegin != messageFieldEnd)
  {
    auto messageFieldModel = *messageFieldBegin;

    std::string fieldValueName = "mData->m";
    fieldValueName += messageFieldModel->namePascal();
    if (messageFieldModel->requiredness() ==
      MessageFieldModel::Requiredness::repeated)
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

std::string Protocol::CodeGeneratorCPP::fullTypeName (
  MessageFieldModel const & messageFieldModel) const
{
  std::string fieldType = messageFieldModel.fieldType();
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

  Text::replaceAll(fieldType, ".", "_");
  std::string fieldTypePackage =
    messageFieldModel.fieldTypePackage();
  Text::replaceAll(fieldTypePackage, ".", "::");
  if (!fieldTypePackage.empty())
  {
    fieldTypePackage += "::";
  }
  fieldType = fieldTypePackage + fieldType;
  return fieldType;
}

std::string Protocol::CodeGeneratorCPP::fullTypeNameInternal (
  MessageFieldModel const & messageFieldModel) const
{
  std::string fieldType = messageFieldModel.fieldType();
  if (fieldType == "bool")
  {
    fieldType = mBaseClassesNamespace + "::ProtoBool";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "string")
  {
    fieldType = mBaseClassesNamespace + "::ProtoString";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "double")
  {
    fieldType = mBaseClassesNamespace + "::ProtoDouble";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "float")
  {
    fieldType = mBaseClassesNamespace + "::ProtoFloat";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "int32")
  {
    fieldType = mBaseClassesNamespace + "::ProtoInt32";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "int64")
  {
    fieldType = mBaseClassesNamespace + "::ProtoInt64";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "uint32")
  {
    fieldType = mBaseClassesNamespace + "::ProtoUnsignedInt32";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "uint64")
  {
    fieldType = mBaseClassesNamespace + "::ProtoUnsignedInt64";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "sint32")
  {
    fieldType = mBaseClassesNamespace + "::ProtoSignedInt32";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "sint64")
  {
    fieldType = mBaseClassesNamespace + "::ProtoSignedInt64";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "fixed32")
  {
    fieldType = mBaseClassesNamespace + "::ProtoFixedInt32";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "fixed64")
  {
    fieldType = mBaseClassesNamespace + "::ProtoFixedInt64";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "sfixed32")
  {
    fieldType = mBaseClassesNamespace +
      "::ProtoFixedSignedInt32";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "sfixed64")
  {
    fieldType = mBaseClassesNamespace +
      "::ProtoFixedSignedInt64";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }
  if (fieldType == "bytes")
  {
    fieldType = mBaseClassesNamespace + "::ProtoBytes";
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType += "Collection";
    }
    return fieldType;
  }

  Text::replaceAll(fieldType, ".", "_");
  std::string fieldTypePackage =
    messageFieldModel.fieldTypePackage();
  Text::replaceAll(fieldTypePackage, ".", "::");
  if (!fieldTypePackage.empty())
  {
    fieldTypePackage += "::";
  }
  fieldType = fieldTypePackage + fieldType;

  if (messageFieldModel.fieldCategory() ==
    MessageFieldModel::FieldCategory::enumType)
  {
    if (messageFieldModel.requiredness() ==
      MessageFieldModel::Requiredness::repeated)
    {
      fieldType = mBaseClassesNamespace +
        "::ProtoEnumCollection<" + fieldType + ">";
    }
    else
    {
      fieldType = mBaseClassesNamespace +
        "::ProtoEnum<" + fieldType + ">";
    }
    return fieldType;
  }

  if (messageFieldModel.requiredness() ==
    MessageFieldModel::Requiredness::repeated)
  {
    fieldType = mBaseClassesNamespace +
      "::ProtoMessageCollection<" + fieldType + ">";
  }
  else
  {
    fieldType = mBaseClassesNamespace +
      "::ProtoMessageField<" + fieldType + ">";
  }

  return fieldType;
}
