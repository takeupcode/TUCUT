//
//  AdvancedPublisher.h
//  TestTUCUT
//
//  Created by Wahid Tanner on 7/19/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#ifndef TestTUCUT_Event_AdvancedPublisher_h
#define TestTUCUT_Event_AdvancedPublisher_h

#include <memory>
#include <string>

#include "../EventPublisher.h"

class AdvancedPublisher
{
private:
    const int minimumAdultAge = 20;

public:
    using PropertyChangedEvent = TUCUT::Event::EventPublisher<const std::string &>;
    using AgeAndAdultEvent = TUCUT::Event::EventPublisher<int, bool>;

    static const std::string nameProperty;
    static const std::string ageProperty;
    static const std::string adultProperty;

    AdvancedPublisher (const std::string & name, int age)
    : mName(name), mAge(age), mPropertyChanged(new PropertyChangedEvent(1)),
    mAgeAndAdult(new AgeAndAdultEvent(2))
    {
        if (mAge < minimumAdultAge)
        {
            mAdult = false;
        }
        else
        {
            mAdult = true;
        }
    }

    virtual ~AdvancedPublisher ()
    { }

    PropertyChangedEvent * propertyChanged ()
    {
        return mPropertyChanged.get();
    }

    AgeAndAdultEvent * ageAndAdult ()
    {
        return mAgeAndAdult.get();
    }

    std::string name ()
    {
        return mName;
    }

    int age ()
    {
        return mAge;
    }

    bool adult ()
    {
        return mAdult;
    }

    void setName (const std::string & name)
    {
        if (mName != name)
        {
            mName = name;
            propertyChanged()->signal(nameProperty);
        }
    }

    void setAge (int age)
    {
        if (mAge != age)
        {
            mAge = age;
            propertyChanged()->signal(ageProperty);

            if (mAge < minimumAdultAge)
            {
                if (mAdult)
                {
                    mAdult = false;
                    propertyChanged()->signal(adultProperty);
                }
            }
            else
            {
                if (!mAdult)
                {
                    mAdult = true;
                    propertyChanged()->signal(adultProperty);
                }
            }
        }
        ageAndAdult()->signal(mAge, mAdult);
    }

private:
    std::string mName;
    int mAge;
    bool mAdult;
    std::unique_ptr<PropertyChangedEvent> mPropertyChanged;
    std::unique_ptr<AgeAndAdultEvent> mAgeAndAdult;
};

#endif // TestTUCUT_Event_AdvancedPublisher_h
