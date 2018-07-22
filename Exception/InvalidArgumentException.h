//
//  InvalidArgumentException.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 3/25/13.
//  Copyright © 2013 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Exception_InvalidArgumentException_h
#define TUCUT_Exception_InvalidArgumentException_h

#include <stdexcept>
#include <string>

namespace TUCUT {
namespace Exception {
        
class InvalidArgumentException : public std::invalid_argument
{
public:
    InvalidArgumentException (const std::string & argumentName, const std::string & message = std::string(""))
    : std::invalid_argument("")
    {
        mMessage = "Argument is invalid";
        
        if (argumentName.size() != 0)
        {
            mMessage += ": " + argumentName;
        }
        
        if (message.size() != 0)
        {
            mMessage += ": " + message;
        }
    }
    
    virtual ~InvalidArgumentException ()
    { }
    
    virtual const char * what () const noexcept
    {
        return mMessage.c_str();
    }
    
protected:
    InvalidArgumentException ()
    : std::invalid_argument("")
    { }

    std::string mMessage;
};
    
} // namespace Exception
} // namespace TUCUT

#endif // TUCUT_Exception_InvalidArgumentException_h




