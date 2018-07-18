//
//  OptionModel.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/9/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_OptionModel_h
#define TUCUT_Protocol_OptionModel_h

#include <string>

#include "Nameable.h"

// Every model header includes its container header.
#include "OptionModelContainer.h"

namespace TUCUT {
namespace Protocol {
        
class OptionModel : public Nameable
{
public:
    OptionModel (const std::string & name, const std::string & value);

    OptionModel (const OptionModel & src);

    std::string value () const;

    OptionModel & operator = (const OptionModel & rhs);

private:
    std::string mValue;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_OptionModel_h
