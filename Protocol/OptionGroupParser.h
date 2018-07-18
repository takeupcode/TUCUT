//
//  OptionGroupParser.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/10/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_OptionGroupParser_h
#define TUCUT_Protocol_OptionGroupParser_h

#include "ParserInterface.h"

namespace TUCUT {
namespace Protocol {
        
class OptionGroupParser : public ParserInterface
{
public:
    OptionGroupParser ();

    virtual bool parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, std::shared_ptr<ProtoModel> model);
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_OptionGroupParser_h
