//
//  ExtensionLoader.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 6/15/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#include <dirent.h>
#include <dlfcn.h>

#include "../../../Exception/InvalidArgumentException.h"
#include "../../../Exception/InvalidExtensionException.h"
#include "../../ExtensionManager.h"
#include "Extension.h"

using namespace std;
using namespace TUCUT;

shared_ptr<Extension::ExtensionInterface> Extension::ExtensionManager::ExtensionLoader::load (const string & path)
{
    void * handle = dlopen(path.c_str(), RTLD_LOCAL);
    if (handle == nullptr)
    {
        throw Exception::InvalidExtensionException(path);
    }
    return shared_ptr<ExtensionInterface>(new Extension(handle, path));
}

list<shared_ptr<Extension::ExtensionInterface>> Extension::ExtensionManager::ExtensionLoader::loadAll (const string & path)
{
    DIR * pDir = opendir(path.c_str());
    if (pDir == nullptr)
    {
        throw Exception::InvalidArgumentException("path", "Cannot open extension folder.");
    }

    struct dirent * entry;
    list<shared_ptr<ExtensionInterface>> extensions;
    while ((entry = readdir(pDir)) != nullptr)
    {
        string name = entry->d_name;
        if ((name != ".") && (name != ".."))
        {
            shared_ptr<ExtensionInterface> singleExtension;
            try
            {
                singleExtension = load(name);
            }
            catch (const Exception::InvalidExtensionException & ex)
            {
                continue;
            }
            extensions.push_back(singleExtension);
        }
    }
    closedir(pDir);

    return extensions;
}
