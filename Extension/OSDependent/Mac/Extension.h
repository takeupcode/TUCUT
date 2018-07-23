//
//  Extension.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 6/15/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Extension_Extension_h
#define TUCUT_Extension_Extension_h

#include "../../ExtensionInterface.h"

namespace TUCUT {
namespace Extension {
        
class Extension : public ExtensionInterface
{
public:
    Extension (void * handle, const std::string & path);
    virtual ~Extension ();

    virtual int protocolVersion () const;
    virtual std::string address () const;
    virtual std::string sendMessage (const std::string & message) const;
    virtual void setExtensionManager (ExtensionManager * pExtensionManager) const;

private:
    Extension (const Extension & src) = delete;
    Extension & operator = (const Extension & rhs) = delete;

    void * mHandle;
    std::string mPath;

    int (*tucutGetExtensionProtocolVersion)();
    char * (*tucutGetExtensionAddress)();
    char * (*tucutSendMessage)(const char *);
    void (*tucutSetExtensionManager)(ExtensionManager *);
};

} // namespace Extension
} // namespace TUCUT

#endif // TUCUT_Extension_Extension_h
