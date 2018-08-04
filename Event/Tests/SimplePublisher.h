//
//  SimplePublisher.h
//  TestTUCUT
//
//  Created by Wahid Tanner on 6/26/13.
//  Copyright © 2013 Take Up Code. All rights reserved.
//

#ifndef TestTUCUT_Event_SimplePublisher_h
#define TestTUCUT_Event_SimplePublisher_h

#include <memory>
#include <string>

#include "../EventPublisher.h"

class SimplePublisher
{
public:
    using PropertyChangedEvent = TUCUT::Event::EventPublisher<const std::string &>;

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

#endif // TestTUCUT_Event_SimplePublisher_h
