//
//  ExtensionInterface.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 6/15/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Extension_ExtensionInterface_h
#define TUCUT_Extension_ExtensionInterface_h

#include <string>

namespace TUCUT {
namespace Extension {
        
class ExtensionManager;

class ExtensionInterface
{
public:
    virtual ~ExtensionInterface ()
    { }
    
    virtual int protocolVersion () const = 0;
    virtual std::string address () const = 0;
    virtual std::string sendMessage (const std::string & message) const = 0;
    virtual void setExtensionManager (ExtensionManager * pExtensionManager) const = 0;

protected:
    ExtensionInterface ()
    { }
    
private:
    ExtensionInterface (const ExtensionInterface & src) = delete;
    ExtensionInterface & operator = (const ExtensionInterface & rhs) = delete;
};

} // namespace Extension
} // namespace TUCUT

#endif // TUCUT_Extension_ExtensionInterface_h
