//
//  Nameable.h
//  TUCUT
//
//  Created by Wahid Tanner on 11/1/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_Nameable_h
#define TUCUT_Protocol_Nameable_h

#include <locale>
#include <string>

namespace TUCUT {
namespace Protocol {
        
class Nameable
{
public:
    virtual ~Nameable ()
    { }

    virtual std::string name () const
    {
        return mNameCamel;
    }

    virtual std::string namePascal () const
    {
        return mNamePascal;
    }

    virtual std::string nameOriginal () const
    {
        return mNameOriginal;
    }

protected:
    Nameable (const std::string & name = "")
    : mNameOriginal(name), mNameCamel(name), mNamePascal(name)
    {
        mNameCamel[0] = std::tolower(mNameCamel[0]);
        mNamePascal[0] = std::toupper(mNamePascal[0]);
    }

    Nameable (const Nameable & src)
    : mNameOriginal(src.mNameOriginal), mNameCamel(src.mNameCamel), mNamePascal(src.mNamePascal)
    { }

    Nameable & operator = (const Nameable & rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        mNameOriginal = rhs.mNameOriginal;
        mNameCamel = rhs.mNameCamel;
        mNamePascal = rhs.mNamePascal;

        return *this;
    }

private:
    std::string mNameOriginal;
    std::string mNameCamel;
    std::string mNamePascal;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_Nameable_h
