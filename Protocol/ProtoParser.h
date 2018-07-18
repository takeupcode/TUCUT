//
//  ProtoParser.h
//  TUCUT
//
//  Created by Wahid Tanner on 9/16/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_ProtoParser_h
#define TUCUT_Protocol_ProtoParser_h

#include <list>
#include <memory>
#include <string>

#include "ParserInterface.h"
#include "ProtoModel.h"
#include "TokenReader.h"

namespace TUCUT {
namespace Protocol {
        
class ProtoParser
{
public:
    ProtoParser (const std::string & protoFileName);

    std::shared_ptr<ProtoModel> parse ();

private:
    std::string mFileName;
    std::shared_ptr<ProtoModel> mModel;
    std::unique_ptr<TokenReader> mReader;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_ProtoParser_h
