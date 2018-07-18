//
//  EnumValueModelContainer.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/19/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_EnumValueModelContainer_h
#define TUCUT_Protocol_EnumValueModelContainer_h

#include <memory>
#include <vector>

namespace TUCUT {
namespace Protocol {
        
// The container classes really only need to know that the contained class exists.
class EnumValueModel;

class EnumValueModelContainer
{
public:
    typedef std::vector<std::shared_ptr<EnumValueModel>> EnumValueModelCollection;
    typedef std::shared_ptr<EnumValueModelCollection> SPEnumValueModelCollection;

    virtual ~EnumValueModelContainer ()
    { }

    virtual void addEnumValue (const EnumValueModelCollection::value_type & enumValue)
    {
        mValues->push_back(enumValue);
    }

    virtual const SPEnumValueModelCollection enumValues () const
    {
        return mValues;
    }

protected:
    EnumValueModelContainer ()
    : mValues(new EnumValueModelCollection())
    { }

    EnumValueModelContainer (const EnumValueModelContainer & src)
    : mValues(src.mValues)
    { }

    EnumValueModelContainer & operator = (const EnumValueModelContainer & rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        mValues = rhs.mValues;

        return *this;
    }

private:
    SPEnumValueModelCollection mValues;
};
        
} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_EnumValueModelContainer_h
