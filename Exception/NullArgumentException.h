//
//  NullArgumentException.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 3/25/13.
//  Copyright © 2013 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Exception_NullArgumentException_h
#define TUCUT_Exception_NullArgumentException_h

#include "InvalidArgumentException.h"

namespace TUCUT {
namespace Exception {
        
class NullArgumentException : public InvalidArgumentException
{
public:
    NullArgumentException (const std::string & argumentName)
    {
        mMessage = "Argument cannot be null";
        
        if (argumentName.size() != 0)
        {
            mMessage += ": " + argumentName;
        }
    }
    
    virtual ~NullArgumentException ()
    { }

protected:
    NullArgumentException ()
    { }
};
        
} // namespace Exception
} // namespace TUCUT

#endif // TUCUT_Exception_NullArgumentException_h




