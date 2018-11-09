//
//  OptionModelContainer.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/19/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_OptionModelContainer_h
#define TUCUT_Protocol_OptionModelContainer_h

#include <memory>
#include <vector>

namespace TUCUT {
namespace Protocol {
        
// The container classes really only need to know that the contained class exists.
class OptionModel;

class OptionModelContainer
{
public:
    typedef std::vector<std::shared_ptr<OptionModel>> OptionModelCollection;
    typedef std::shared_ptr<OptionModelCollection> SPOptionModelCollection;

    virtual ~OptionModelContainer ()
    { }

    void addOption (const OptionModelCollection::value_type & option)
    {
        mOptions->push_back(option);
    }

    virtual const SPOptionModelCollection options () const
    {
        return mOptions;
    }

protected:
    OptionModelContainer ()
    : mOptions(new OptionModelCollection())
    { }

    OptionModelContainer (const OptionModelContainer & src)
    : mOptions(src.mOptions)
    { }

    OptionModelContainer & operator = (const OptionModelContainer & rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        mOptions = rhs.mOptions;

        return *this;
    }

private:
    SPOptionModelCollection mOptions;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_OptionModelContainer_h
