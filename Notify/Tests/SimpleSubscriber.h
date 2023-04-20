//  SimpleSubscriber.h
//  TUCUT/Notify (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2013-06-25.
//  Copyright © Take Up Code, Inc.
//
#ifndef TestTUCUT_Notify_SimpleSubscriber_h
#define TestTUCUT_Notify_SimpleSubscriber_h

#include <string>

#include "../EventSubscriber.h"
#include "SimplePublisher.h"

class SimpleSubscriber : public TUCUT::Notify::EventSubscriber<const std::string &>
{
public:
    explicit SimpleSubscriber ()
    : mNotified(false), mId(0)
    { }

    virtual ~SimpleSubscriber ()
    { }

    virtual void notify (int id, const std::string & stringArg)
    {
        mNotified = true;
        mId = id;
        mProperty = stringArg;
    }

    bool notified ()
    {
        return mNotified;
    }

    int id ()
    {
        return mId;
    }

    std::string property ()
    {
        return mProperty;
    }

private:
    bool mNotified;
    int mId;
    std::string mProperty;
};

#endif // TestTUCUT_Notify_SimpleSubscriber_h
