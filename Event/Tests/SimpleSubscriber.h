//
//  SimpleSubscriber.h
//  TestTUCUT
//
//  Created by Wahid Tanner on 6/25/13.
//  Copyright © 2013 Take Up Code. All rights reserved.
//

#ifndef TestTUCUT_Event_SimpleSubscriber_h
#define TestTUCUT_Event_SimpleSubscriber_h

#include <string>

#include "../EventSubscriber.h"
#include "SimplePublisher.h"

class SimpleSubscriber : public TUCUT::Event::EventSubscriber<const std::string &>
{
public:
    explicit SimpleSubscriber ()
    { }
    
    virtual ~SimpleSubscriber ()
    { }
    
    virtual void notify (const std::string & stringArg)
    {
        mNotified = true;
        mProperty = stringArg;
    }
    
    bool notified ()
    {
        return mNotified;
    }
    
    std::string property ()
    {
        return mProperty;
    }
    
private:
    bool mNotified;
    std::string mProperty;
};

#endif // TestTUCUT_Event_SimpleSubscriber_h
