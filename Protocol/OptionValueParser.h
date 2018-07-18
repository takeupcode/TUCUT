//
//  OptionValueParser.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/9/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_OptionValueParser_h
#define TUCUT_Protocol_OptionValueParser_h

#include "ParserInterface.h"

namespace TUCUT {
namespace Protocol {
        
class OptionValueParser : public ParserInterface
{
public:
    OptionValueParser ();

    virtual bool parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, std::shared_ptr<ProtoModel> model);
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_OptionValueParser_h
