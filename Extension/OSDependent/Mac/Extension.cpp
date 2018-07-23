//
//  Extension.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 6/15/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#include <dlfcn.h>

#include "../../../Exception/InvalidArgumentException.h"
#include "../../../Exception/InvalidExtensionException.h"
#include "../../../Exception/NullArgumentException.h"
#include "Extension.h"

using namespace std;
using namespace TUCUT;

Extension::Extension::Extension (void * handle, const std::string & path)
: mHandle(handle), mPath(path)
{
    if (handle == nullptr)
    {
        throw Exception::NullArgumentException("handle");
    }
    if (path == "")
    {
        throw Exception::InvalidArgumentException("path", "path cannot be empty.");
    }

    tucutGetExtensionProtocolVersion = reinterpret_cast<decltype(tucutGetExtensionProtocolVersion)>(dlsym(mHandle, "tucutGetExtensionProtocolVersion"));
    if (tucutGetExtensionProtocolVersion == nullptr)
    {
        throw Exception::InvalidExtensionException(mPath, "Cannot find tucutGetExtensionProtocolVersion.");
    }

    tucutGetExtensionAddress = reinterpret_cast<decltype(tucutGetExtensionAddress)>(dlsym(mHandle, "tucutGetExtensionAddress"));
    if (tucutGetExtensionAddress == nullptr)
    {
        throw Exception::InvalidExtensionException(mPath, "Cannot find tucutGetExtensionAddress.");
    }

    tucutSendMessage = reinterpret_cast<decltype(tucutSendMessage)>(dlsym(mHandle, "tucutSendMessage"));
    if (tucutSendMessage == nullptr)
    {
        throw Exception::InvalidExtensionException(mPath, "Cannot find tucutSendMessage.");
    }

    tucutSetExtensionManager = reinterpret_cast<decltype(tucutSetExtensionManager)>(dlsym(mHandle, "tucutSetExtensionManager"));
    if (tucutSetExtensionManager == nullptr)
    {
        throw Exception::InvalidExtensionException(mPath, "Cannot find tucutSetExtensionManager.");
    }
}

Extension::Extension::~Extension ()
{
    dlclose(mHandle);
}

int Extension::Extension::protocolVersion () const
{
    return tucutGetExtensionProtocolVersion();
}

string Extension::Extension::address () const
{
    char * marshalledResult = tucutGetExtensionAddress();
    string result = marshalledResult;
    delete [] marshalledResult;

    return result;
}

string Extension::Extension::sendMessage (const string & message) const
{
    char * marshalledResult = tucutSendMessage(message.c_str());
    string result = marshalledResult;
    delete [] marshalledResult;

    return result;
}

void Extension::Extension::setExtensionManager (ExtensionManager * pExtensionManager) const
{
    tucutSetExtensionManager(pExtensionManager);
}

