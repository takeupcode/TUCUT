//
//  InvalidOperationException.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 3/26/13.
//  Copyright © 2013 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Exception_InvalidOperationException_h
#define TUCUT_Exception_InvalidOperationException_h

#include <stdexcept>
#include <string>

namespace TUCUT {
namespace Exception {
        
class InvalidOperationException : public std::logic_error
{
public:
    InvalidOperationException (const std::string & operation, const std::string & message = std::string(""))
    : std::logic_error("")
    {
        mMessage = "Operation is not allowed";
        
        if (operation.size() != 0)
        {
            mMessage += ": " + operation;
        }
        
        if (message.size() != 0)
        {
            mMessage += ": " + message;
        }
    }
    
    virtual ~InvalidOperationException ()
    { }
    
    virtual const char * what () const noexcept
    {
        return mMessage.c_str();
    }
    
protected:
    InvalidOperationException ()
    : std::logic_error("")
    { }

    std::string mMessage;
};
        
} // namespace Exception
} // namespace TUCUT

#endif // TUCUT_Exception_InvalidOperationException_h




