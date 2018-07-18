//
//  OneofModel.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/5/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_OneofModel_h
#define TUCUT_Protocol_OneofModel_h

#include <string>

#include "MessageFieldModel.h"
#include "Nameable.h"
#include "OptionModel.h"

// Every model header includes its container header.
#include "OneofModelContainer.h"

namespace TUCUT {
namespace Protocol {
        
class OneofModel : public Nameable, public OptionModelContainer, public MessageFieldModelContainer
{
public:
    explicit OneofModel (const std::string & name);

    OneofModel (const OneofModel & src);

    OneofModel & operator = (const OneofModel & rhs);
};
        
} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_OneofModel_h
