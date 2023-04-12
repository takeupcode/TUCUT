//
//  CodeGeneratorCPP.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/17/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//
#ifndef TUCUT_Protocol_CodeGeneratorCPP_h
#define TUCUT_Protocol_CodeGeneratorCPP_h

#include "CodeGeneratorInterface.h"
#include "CodeWriterCPP.h"
#include "MessageFieldModel.h"
#include "MessageModel.h"
#include "OneofModel.h"

namespace TUCUT::Protocol
{
  class CodeGeneratorCPP : public CodeGeneratorInterface
  {
  public:
    virtual void generateCode (
      std::string const & outputFolder,
      ProtoModel const * protoModel,
      std::string const & projectName,
      bool generateCommonCode) const;

  private:
    friend class CodeGeneratorManager;

    void generateHeaderFile (
      std::string const & outputFolder,
      ProtoModel const & protoModel,
      std::string const & projectName) const;

    void generateHeaderFileCommon (
      std::string const & outputFolder,
      std::string const & projectName) const;

    void generateSourceFile (
      std::string const & outputFolder,
      ProtoModel const & protoModel,
      std::string const & projectName) const;

    std::string headerIncludeBlockText (
      ProtoModel const & protoModel,
      std::string const & projectName) const;

    std::string headerIncludeBlockText (
      std::string const & headerBaseName,
      std::string const & projectName) const;

    std::string fullTypeName (
      MessageFieldModel const & messageFieldModel) const;

    std::string fullTypeNameInternal (
      MessageFieldModel const & messageFieldModel) const;

    void writeStandardIncludeFileNamesToHeader (
      CodeWriter & headerFileWriter,
      bool includeBase) const;

    void writeIncludedProtoFileNamesToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel) const;

    void writeProtoEnumsToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel) const;

    void writeEnumToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      EnumModel const & enumModel,
      std::string const & enumName) const;

    void writeProtoMessagesToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel) const;

    void writeMessageDeclarationToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageEnumToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageConstructorToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageCopyConstructorToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageDestructorToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageAssignmentOperatorToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageSwapToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageClearToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageFieldToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageOneofFieldToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel,
      OneofModel const & oneofModel) const;

    void writeMessageFieldSizeRepeatedToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageFieldGetRepeatedToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageFieldSetRepeatedToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageFieldAddRepeatedToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageFieldAddNewRepeatedToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageFieldClearRepeatedToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageFieldHasToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel,
      OneofModel const * oneofModel = nullptr) const;

    void writeMessageFieldGetToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel,
      OneofModel const * oneofModel = nullptr) const;

    void writeMessageFieldSetToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel,
      OneofModel const * oneofModel = nullptr) const;

    void writeMessageFieldCreateNewToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel,
      OneofModel const * oneofModel = nullptr) const;

    void writeMessageFieldClearToHeader (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel,
      OneofModel const * oneofModel = nullptr) const;

    void writeMessageFieldBackingFieldsToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageFieldIndexToHeader (
      CodeWriter & headerFileWriter,
      MessageFieldModel const & messageFieldModel) const;

    void writeOneofToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      OneofModel const & oneofModel) const;

    void writeOneofBackingFieldsToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      OneofModel const & oneofModel) const;

    void writeMessageFieldIndexesToHeader (
      CodeWriter & headerFileWriter,
      OneofModel const & oneofModel) const;

    void writeMessageOneofCurrentToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      OneofModel const & oneofModel) const;

    void writeMessageOneofClearToHeader (
      CodeWriter & headerFileWriter,
      ProtoModel const & protoModel,
      OneofModel const & oneofModel) const;

    void writeProtoMessagesToSource (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel) const;

    void writeMessageToSource (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className) const;

    void writeMessageDataConstructorToSource (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className,
      std::string const & fullScope) const;

    void writeMessageDataFieldInitializationToSource (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageFieldModel const & messageFieldModel,
      std::string const & className,
      std::string const & fullScope) const;

    std::string messageFieldInitialization (
      MessageFieldModel const & messageFieldModel) const;

    void writeMessageParseToSource (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className,
      std::string const & fullScope) const;

    void writeMessageSerializeToSource (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className,
      std::string const & fullScope) const;

    void writeMessageByteSizeToSource (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className,
      std::string const & fullScope) const;

    void writeMessageValidToSource (
      CodeWriter & sourceFileWriter,
      ProtoModel const & protoModel,
      MessageModel const & messageModel,
      std::string const & className,
      std::string const & fullScope) const;

    static std::string const mHeaderFileExtension;
    static std::string const mSourceFileExtension;
    static std::string const mGeneratedFileProlog;
    static std::string const mProtoBaseHeaderFileTemplate;
    static std::string const mBaseClassesNamespace;
    static std::string const mBaseClassesFileName;
  };

} // namespace TUCUT::Protocol

#endif // TUCUT_Protocol_CodeGeneratorCPP_h
