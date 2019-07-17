//
//  CodeIndenter.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/25/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_CodeIndenter_h
#define TUCUT_Protocol_CodeIndenter_h

#include <string>

namespace TUCUT {
namespace Protocol {
        
class CodeIndenter
{
public:
    explicit CodeIndenter (const std::string & indentBy = "    ", unsigned int minimumLevel = 0)
    : mCurrentLevel(minimumLevel), mMinimumLevel(minimumLevel), mIndentBy(indentBy), mPrefix("")
    {
        for (unsigned int level = 0; level < mCurrentLevel; level++)
        {
            mPrefix += mIndentBy;
        }
    }

    void indent ()
    {
        mCurrentLevel++;
        mPrefix += mIndentBy;
    }

    void unindent ()
    {
        if (mCurrentLevel > mMinimumLevel)
        {
            mCurrentLevel--;
            mPrefix.resize(mCurrentLevel * mIndentBy.length());
        }
    }

    std::string prefix () const
    {
        return mPrefix;
    }

    CodeIndenter & operator ++ ()
    {
        indent();

        return *this;
    }

    CodeIndenter operator ++ (int)
    {
        CodeIndenter previousValue(*this);

        indent();

        return previousValue;
    }

    CodeIndenter & operator -- ()
    {
        unindent();

        return *this;
    }

    CodeIndenter operator -- (int)
    {
        CodeIndenter previousValue(*this);

        unindent();

        return previousValue;
    }

private:
    unsigned int mCurrentLevel;
    const unsigned int mMinimumLevel;
    const std::string mIndentBy;
    std::string mPrefix;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_CodeIndenter_h
