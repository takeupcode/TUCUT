//
//  EnumModel.h
//  TUCUT
//
//  Created by Wahid Tanner on 9/30/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_EnumModel_h
#define TUCUT_Protocol_EnumModel_h

#include <string>

#include "EnumValueModel.h"
#include "Nestable.h"
#include "OptionModel.h"

// Every model header includes its container header.
#include "EnumModelContainer.h"

namespace TUCUT {
namespace Protocol {
        
class EnumModel : public Nestable, public OptionModelContainer, public EnumValueModelContainer
{
public:
    explicit EnumModel (const std::string & name);

    EnumModel (const EnumModel & src);

    EnumModel & operator = (const EnumModel & rhs);
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_EnumModel_h
