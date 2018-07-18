//
//  ParserManager.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/29/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "ParserManager.h"
#include "EnumParser.h"
#include "EnumValueParser.h"
#include "ImportParser.h"
#include "MessageParser.h"
#include "MessageFieldParser.h"
#include "OneofParser.h"
#include "OneofFieldParser.h"
#include "OptionGroupParser.h"
#include "OptionSingleParser.h"
#include "OptionValueParser.h"
#include "PackageParser.h"

using namespace std;
using namespace TUCUT;

Protocol::ParserManager::ParserManager ()
{
    mParserMap.emplace("none", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("all", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("proto", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("enum", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("enumValue", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("message", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("messageField", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("oneof", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("oneofField", shared_ptr<ParserCollection>(new ParserCollection()));
    mParserMap.emplace("option", shared_ptr<ParserCollection>(new ParserCollection()));

    shared_ptr<ParserInterface> packageParser(new PackageParser());
    shared_ptr<ParserInterface> messageParser(new MessageParser());
    shared_ptr<ParserInterface> enumParser(new EnumParser());
    shared_ptr<ParserInterface> enumValueParser(new EnumValueParser());
    shared_ptr<ParserInterface> importParser(new ImportParser());
    shared_ptr<ParserInterface> messageFieldParser(new MessageFieldParser());
    shared_ptr<ParserInterface> oneofParser(new OneofParser());
    shared_ptr<ParserInterface> oneofFieldParser(new OneofFieldParser());
    shared_ptr<ParserInterface> optionGroupParser(new OptionGroupParser());
    shared_ptr<ParserInterface> optionSingleParser(new OptionSingleParser());
    shared_ptr<ParserInterface> optionValueParser(new OptionValueParser());

    auto parserIter = mParserMap.find("all");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(packageParser);
        parserIter->second->push_back(messageParser);
        parserIter->second->push_back(enumParser);
        parserIter->second->push_back(enumValueParser);
        parserIter->second->push_back(importParser);
        parserIter->second->push_back(messageFieldParser);
        parserIter->second->push_back(oneofParser);
        parserIter->second->push_back(oneofFieldParser);
        parserIter->second->push_back(optionGroupParser);
        parserIter->second->push_back(optionSingleParser);
        parserIter->second->push_back(optionValueParser);
    }

    parserIter = mParserMap.find("proto");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(importParser);
        parserIter->second->push_back(packageParser);
        parserIter->second->push_back(messageParser);
        parserIter->second->push_back(enumParser);
        parserIter->second->push_back(optionSingleParser);
    }

    parserIter = mParserMap.find("enum");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(enumValueParser);
        parserIter->second->push_back(optionSingleParser);
    }

    parserIter = mParserMap.find("enumValue");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(optionGroupParser);
    }

    parserIter = mParserMap.find("message");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(messageParser);
        parserIter->second->push_back(enumParser);
        parserIter->second->push_back(messageFieldParser);
        parserIter->second->push_back(oneofParser);
        parserIter->second->push_back(optionSingleParser);
    }

    parserIter = mParserMap.find("messageField");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(optionGroupParser);
    }

    parserIter = mParserMap.find("oneof");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(oneofFieldParser);
        parserIter->second->push_back(optionSingleParser);
    }

    parserIter = mParserMap.find("oneofField");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(optionGroupParser);
    }

    parserIter = mParserMap.find("option");
    if (parserIter != mParserMap.end())
    {
        parserIter->second->push_back(optionValueParser);
    }
}

Protocol::ParserManager::~ParserManager ()
{
}

Protocol::ParserManager * Protocol::ParserManager::instance ()
{
    static ParserManager * singleton = nullptr;
    if (singleton == nullptr)
    {
        singleton = new ParserManager();
    }

    return singleton;
}

const Protocol::ParserManager::ParserCollection * Protocol::ParserManager::parsers (const std::string & category) const
{
    ParserCollection *pCollection = nullptr;
    auto parserIter = mParserMap.find(category);
    if (parserIter != mParserMap.end())
    {
        pCollection = parserIter->second.get();
    }
    else
    {
        parserIter = mParserMap.find("none");
        if (parserIter != mParserMap.end())
        {
            pCollection = parserIter->second.get();
        }
    }

    return pCollection;
}
