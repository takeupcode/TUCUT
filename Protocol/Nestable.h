//
//  Nestable.h
//  TUCUT
//
//  Created by Wahid Tanner on 11/8/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_Nestable_h
#define TUCUT_Protocol_Nestable_h

#include <string>

#include "Nameable.h"
#include "Packageable.h"

namespace TUCUT {
namespace Protocol {
        
class Nestable : public Nameable, public Packageable
{
public:
    virtual ~Nestable ()
    { }

    virtual Nestable * parent () const
    {
        return mParent;
    }

    virtual void setParent (Nestable * parent)
    {
        mParent = parent;
    }

    virtual std::string nameFullWithPackage () const
    {
        std::string messagePath = nameFullWithoutPackage();
        std::string fullName = package();
        if (!fullName.empty())
        {
            fullName += ".";
        }
        fullName += messagePath;
        
        return fullName;
    }

    virtual std::string nameFullWithoutPackage () const
    {
        std::string fullName;
        Nestable * pParentMessage = parent();
        while (pParentMessage != nullptr)
        {
            if (fullName.empty())
            {
                fullName = pParentMessage->namePascal();
            }
            else
            {
                fullName = pParentMessage->namePascal() + "." + fullName;
            }
            pParentMessage = pParentMessage->parent();
        }

        if (!fullName.empty())
        {
            fullName += ".";
        }
        fullName += namePascal();

        return fullName;
    }

protected:
    Nestable (const std::string & name = "", const std::string & package = "")
    : Nameable(name), Packageable(package), mParent(nullptr)
    { }

    Nestable (const Nestable & src)
    : Nameable(src), Packageable(src), mParent(src.mParent)
    { }

    Nestable & operator = (const Nestable & rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        Nameable::operator=(rhs);
        Packageable::operator=(rhs);

        mParent = rhs.mParent;

        return *this;
    }

private:
    Nestable * mParent;
};
        
} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_Nestable_h
