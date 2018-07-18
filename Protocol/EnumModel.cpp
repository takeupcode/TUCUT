//
//  EnumModel.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/30/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "EnumModel.h"

using namespace std;
using namespace TUCUT;

Protocol::EnumModel::EnumModel (const string & name)
: Nestable(name)
{
}

Protocol::EnumModel::EnumModel (const EnumModel & src)
: Nestable(src), OptionModelContainer(src), EnumValueModelContainer(src)
{
}

Protocol::EnumModel & Protocol::EnumModel::operator = (const EnumModel & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    Nestable::operator=(rhs);
    OptionModelContainer::operator=(rhs);
    EnumValueModelContainer::operator=(rhs);

    return *this;
}
