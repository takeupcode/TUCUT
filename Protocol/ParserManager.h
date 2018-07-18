//
//  ParserManager.h
//  TUCUT
//
//  Created by Wahid Tanner on 9/29/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_ParserManager_h
#define TUCUT_Protocol_ParserManager_h

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "ParserInterface.h"

namespace TUCUT {
namespace Protocol {
        
class ParserManager
{
public:
    typedef std::vector<std::shared_ptr<ParserInterface>> ParserCollection;
    typedef std::unordered_map<std::string, std::shared_ptr<ParserCollection>> ParserCollectionMap;

    ~ParserManager ();

    static ParserManager * instance ();

    const ParserCollection * parsers (const std::string & category = "all") const;

private:
    ParserManager ();
    ParserManager (const ParserManager & src) = delete;
    ParserManager & operator = (const ParserManager & rhs) = delete;

    ParserCollectionMap mParserMap;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_ParserManager_h
