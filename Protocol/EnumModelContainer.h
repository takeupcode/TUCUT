//
//  EnumModelContainer.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/20/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_EnumModelContainer_h
#define TUCUT_Protocol_EnumModelContainer_h

#include <memory>
#include <vector>

namespace TUCUT {
namespace Protocol {
        
// The container classes really only need to know that the contained class exists.
class EnumModel;

class EnumModelContainer
{
public:
    typedef std::vector<std::shared_ptr<EnumModel>> EnumModelCollection;
    typedef std::shared_ptr<EnumModelCollection> SPEnumModelCollection;

    virtual ~EnumModelContainer ()
    { }

    virtual void addEnum (const EnumModelCollection::value_type & enumeration)
    {
        mEnums->push_back(enumeration);
    }

    virtual const SPEnumModelCollection enums () const
    {
        return mEnums;
    }

protected:
    EnumModelContainer ()
    : mEnums(new EnumModelCollection())
    { }

    EnumModelContainer (const EnumModelContainer & src)
    : mEnums(src.mEnums)
    { }

    EnumModelContainer & operator = (const EnumModelContainer & rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        mEnums = rhs.mEnums;

        return *this;
    }

private:
    SPEnumModelCollection mEnums;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_EnumModelContainer_h
