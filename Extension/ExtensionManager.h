//
//  ExtensionManager.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 6/15/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Extension_ExtensionManager_h
#define TUCUT_Extension_ExtensionManager_h

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

#include "ExtensionInterface.h"
#include "Messages/Generated/ExtensionManager.protocol.h"

namespace TUCUT {
namespace Extension {
        
class ExtensionManager
{
private:
    using ExtensionMap = std::unordered_map<std::string, std::shared_ptr<ExtensionInterface>>;
    
    class ExtensionLoader
    {
    public:
        static std::shared_ptr<ExtensionInterface> load (const std::string & path);
        static std::list<std::shared_ptr<ExtensionInterface>> loadAll (const std::string & path);
    };

public:
    ~ExtensionManager ();

    static ExtensionManager * instance ();
    
    char * marshal (const std::string & extensionData) const;

    virtual void load (const std::string & path);
    virtual void loadAll (const std::string & path);
    virtual std::string sendMessage (const std::string & message);
    virtual std::string sendMessage (const std::string & address, const std::string & message) const;

private:
    ExtensionManager ();
    ExtensionManager (const ExtensionManager & src) = delete;
    ExtensionManager & operator = (const ExtensionManager & rhs) = delete;

    static ExtensionManager * mpInstance;
    ExtensionMap mLoadedExtensions;
};

} // namespace Extension
} // namespace TUCUT

#endif // TUCUT_Extension_ExtensionManager_h
