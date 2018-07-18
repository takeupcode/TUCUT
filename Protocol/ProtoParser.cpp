//
//  ProtoParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/16/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <memory>

#include "ProtoParser.h"
#include "TokenReader.h"
#include "ParserManager.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::ProtoParser::ProtoParser (const string & protoFileName)
: mFileName(protoFileName), mReader(new TokenReader(protoFileName))
{
}

shared_ptr<Protocol::ProtoModel> Protocol::ProtoParser::parse ()
{
    mModel.reset(new Protocol::ProtoModel(mFileName));
    auto current = mReader->begin();
    auto end = mReader->end();
    ParserManager * parserMgr = ParserManager::instance();

    while (current != end)
    {
        bool parserFound = false;
        for (auto & parser: *parserMgr->parsers("proto"))
        {
            if (parser->parse(current, end, true, mModel))
            {
                parserFound = true;
                break;
            }
        }
        if (!parserFound)
        {
            // Try again for the second chance parsers.
            for (auto & parser: *parserMgr->parsers("proto"))
            {
                if (parser->parse(current, end, false, mModel))
                {
                    parserFound = true;
                    break;
                }
            }
            if (!parserFound)
            {
                throw InvalidProtoException(current.line(), current.column(), "Unexpected proto content found.");
            }
        }
        ++current;
    }
    mModel->completeModel();

    return mModel;
}
