//
//  EnumValueParser.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/6/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_EnumValueParser_h
#define TUCUT_Protocol_EnumValueParser_h

#include "ParserInterface.h"

namespace TUCUT {
namespace Protocol {
        
class EnumValueParser : public ParserInterface
{
public:
    EnumValueParser ();

    virtual bool parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, std::shared_ptr<ProtoModel> model);
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_EnumValueParser_h
