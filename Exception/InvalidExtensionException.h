//
//  InvalidExtensionException.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 8/16/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Exception_InvalidExtensionException_h
#define TUCUT_Exception_InvalidExtensionException_h

#include <stdexcept>
#include <string>

namespace TUCUT {
namespace Exception {
        
class InvalidExtensionException : public std::logic_error
{
public:
    InvalidExtensionException (const std::string & path, const std::string & message = std::string(""))
    : std::logic_error("")
    {
        mMessage = "Extension is invalid";
        
        if (path.size() != 0)
        {
            mMessage += ": " + path;
        }

        if (message.size() != 0)
        {
            mMessage += ": " + message;
        }
    }
    
    virtual ~InvalidExtensionException ()
    { }
    
    virtual const char * what () const noexcept
    {
        return mMessage.c_str();
    }            
    
protected:
    InvalidExtensionException ()
    : std::logic_error("")
    { }

    std::string mMessage;
};
        
} // namespace Exception
} // namespace TUCUT

#endif // TUCUT_Exception_InvalidExtensionException_h




