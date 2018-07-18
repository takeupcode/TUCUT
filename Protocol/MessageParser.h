//
//  MessageParser.h
//  TUCUT
//
//  Created by Wahid Tanner on 9/26/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_MessageParser_h
#define TUCUT_Protocol_MessageParser_h

#include "ParserInterface.h"

namespace TUCUT {
namespace Protocol {
        
class MessageParser : public ParserInterface
{
public:
    MessageParser ();

    virtual bool parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, std::shared_ptr<ProtoModel> model);
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_MessageParser_h
