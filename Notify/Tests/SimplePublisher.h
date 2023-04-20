//  SimplePublisher.h
//  TUCUT/Notify (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2013-06-26.
//  Copyright © Take Up Code, Inc.
//
#ifndef TestTUCUT_Notify_SimplePublisher_h
#define TestTUCUT_Notify_SimplePublisher_h

#include <memory>
#include <string>

#include "../EventPublisher.h"

class SimplePublisher
{
public:
    using PropertyChangedEvent = TUCUT::Notify::EventPublisher<const std::string &>;

    SimplePublisher ()
    : mPropertyChanged(new PropertyChangedEvent(1))
    { }

    virtual ~SimplePublisher ()
    { }

    PropertyChangedEvent * propertyChanged ()
    {
        return mPropertyChanged.get();
    }

private:
    std::unique_ptr<PropertyChangedEvent> mPropertyChanged;
};

#endif // TestTUCUT_Notify_SimplePublisher_h
