//
//  ExtensionManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 6/15/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#include "ExtensionManager.h"

using namespace std;
using namespace TUCUT;

Extension::ExtensionManager * Extension::ExtensionManager::mpInstance = nullptr;

Extension::ExtensionManager::ExtensionManager ()
{ }

Extension::ExtensionManager::~ExtensionManager ()
{ }

Extension::ExtensionManager * Extension::ExtensionManager::instance ()
{
    if (mpInstance == nullptr)
    {
        mpInstance = new ExtensionManager();
    }
    return mpInstance;
}

char * Extension::ExtensionManager::marshal (const std::string & extensionData) const
{
    size_t length = extensionData.length();
    char * pHostData = new char[length + 1];
    extensionData.copy(pHostData, length);
    pHostData[length] = '\0';

    return pHostData;
}

void Extension::ExtensionManager::load (const string & path)
{
    shared_ptr<ExtensionInterface> extension = ExtensionLoader::load(path);
    extension->setExtensionManager(this);
    string address = extension->address();

    mLoadedExtensions.emplace(address, extension);
}

void Extension::ExtensionManager::loadAll (const string & path)
{
    list<shared_ptr<ExtensionInterface>> extensions = ExtensionLoader::loadAll(path);

    for (auto & singleExtension : extensions)
    {
        singleExtension->setExtensionManager(this);
        string address = singleExtension->address();

        mLoadedExtensions.emplace(address, singleExtension);
    }
}
string Extension::ExtensionManager::sendMessage (const string & message)
{
    ExtensionManagerRequest request;
    ExtensionManagerResponse response;
    if (request.parse(message.data()) == 0)
    {
        response.createNewResponse().setErrorEncountered(true);
    }
    else
    {
        response.createNewResponse().setErrorEncountered(false);
    }

    string responseString = response.serialize();
    return responseString;
}

string Extension::ExtensionManager::sendMessage (const string & address, const string & message) const
{
    shared_ptr<ExtensionInterface> extension = mLoadedExtensions.at(address);

    return extension->sendMessage(message);
}
