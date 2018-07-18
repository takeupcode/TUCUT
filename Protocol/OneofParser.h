//
//  OneofParser.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/5/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_OneofParser_h
#define TUCUT_Protocol_OneofParser_h

#include "ParserInterface.h"

namespace TUCUT {
namespace Protocol {
        
class OneofParser : public ParserInterface
{
public:
    OneofParser ();

    virtual bool parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, std::shared_ptr<ProtoModel> model);
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_OneofParser_h
