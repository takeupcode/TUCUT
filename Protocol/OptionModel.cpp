//
//  OptionModel.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/9/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "OptionModel.h"

using namespace std;
using namespace TUCUT;

Protocol::OptionModel::OptionModel (const std::string & name, const std::string & value)
: Nameable(name), mValue(value)
{
}

Protocol::OptionModel::OptionModel (const OptionModel & src)
: Nameable(src), mValue(src.mValue)
{
}

string Protocol::OptionModel::value () const
{
    return mValue;
}

Protocol::OptionModel & Protocol::OptionModel::operator = (const OptionModel & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    Nameable::operator=(rhs);

    mValue = rhs.mValue;
    
    return *this;
}
