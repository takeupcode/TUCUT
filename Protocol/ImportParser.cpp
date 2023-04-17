//
//  ImportParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/12/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//
#include "ImportParser.h"

#include "InvalidProtoException.h"
#include "ProtoParser.h"

#include <filesystem>
#include <memory>

using namespace TUCUT;

bool Protocol::ImportParser::parse (
  TokenReader::iterator current,
  TokenReader::iterator end,
  bool,
  std::shared_ptr<ProtoModel> model)
{
  if (current == end || *current != "import")
  {
    return false;
  }

  // Move to the public flag or proto name.
  bool publicFlag = false;
  ++current;
  if (current != end && *current == "public")
  {
    publicFlag = true;
    ++current;
  }
  if (current == end || *current != "\"")
  {
    throw InvalidProtoException(
      current.line(), current.column(),
      "Expected beginning quote character.");
  }

  // Move to the proto name.
  ++current;
  if (current == end || current->empty())
  {
    throw InvalidProtoException(
      current.line(), current.column(),
      "Expected beginning quote character.");
  }
  std::string protoName = *current;

  // Move to the ending quote.
  ++current;
  if (current == end || *current != "\"")
  {
    throw InvalidProtoException(
      current.line(), current.column(),
      "Expected ending quote character.");
  }

  // Move to the semicolon.
  ++current;
  if (current == end || *current != ";")
  {
    throw InvalidProtoException(
      current.line(), current.column(),
      "Expected ; character.");
  }

  model->addImportedProtoName(current, protoName);

  std::filesystem::path currentPath(model->nameOriginal());
  std::filesystem::path importedPath(protoName);
  std::filesystem::path fullPath(
    currentPath.parent_path() / importedPath);

  std::shared_ptr<Protocol::ProtoModel> importedModel;
  ProtoParser parser(fullPath.string());
  importedModel = parser.parse();

  if (publicFlag)
  {
    for (auto & publicEnumType:
      *importedModel->publicEnumTypes())
    {
      model->addPublicEnumType(current, publicEnumType.second);
    }
    for (auto & publicMessageType:
      *importedModel->publicMessageTypes())
    {
      model->addPublicMessageType(current,
        publicMessageType.second);
    }
  }
  else
  {
    for (auto & publicEnumType:
      *importedModel->publicEnumTypes())
    {
      model->addPrivateEnumType(current, publicEnumType.second);
    }
    for (auto & publicMessageType:
      *importedModel->publicMessageTypes())
    {
      model->addPrivateMessageType(current,
        publicMessageType.second);
    }
  }

  return true;
}
