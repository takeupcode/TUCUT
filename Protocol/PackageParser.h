//
//  PackageParser.h
//  TUCUT
//
//  Created by Wahid Tanner on 9/26/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_PackageParser_h
#define TUCUT_Protocol_PackageParser_h

#include "ParserInterface.h"

namespace TUCUT {
namespace Protocol {
        
class PackageParser : public ParserInterface
{
public:
    PackageParser ();

    virtual bool parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, std::shared_ptr<ProtoModel> model);
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_PackageParser_h
