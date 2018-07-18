//
//  OneofModel.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/5/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "OneofModel.h"

using namespace std;
using namespace TUCUT;

Protocol::OneofModel::OneofModel (const string & name)
: Nameable(name)
{
}

Protocol::OneofModel::OneofModel (const OneofModel & src)
: Nameable(src), OptionModelContainer(src), MessageFieldModelContainer(src)
{
}

Protocol::OneofModel & Protocol::OneofModel::operator = (const OneofModel & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    Nameable::operator=(rhs);
    OptionModelContainer::operator=(rhs);
    MessageFieldModelContainer::operator=(rhs);

    return *this;
}
