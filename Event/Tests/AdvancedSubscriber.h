//
//  AdvancedSubscriber.h
//  TestTUCUT
//
//  Created by Wahid Tanner on 7/20/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#ifndef TestTUCUT_Event_AdvancedSubscriber_h
#define TestTUCUT_Event_AdvancedSubscriber_h

#include <memory>
#include <string>

#include "../EventSubscriber.h"
#include "AdvancedPublisher.h"

class AdvancedSubscriber : public TUCUT::Event::EventSubscriber<const std::string &>,
    public TUCUT::Event::EventSubscriber<int, bool>
{
private:
    struct AdvancedSubscriberData
    {
        bool mNameNotified;
        bool mAgeNotified;
        bool mAdultNotified;
        bool mCombinedAgeAndAdultNotified;

        void reset ()
        {
            mNameNotified = false;
            mAgeNotified = false;
            mAdultNotified = false;
            mCombinedAgeAndAdultNotified = false;
        }
    };

public:
    explicit AdvancedSubscriber ()
    : mData(new AdvancedSubscriberData())
    {
        reset();
    }

    virtual ~AdvancedSubscriber ()
    { }

    void swap (AdvancedSubscriber & other)
    {
        std::unique_ptr<AdvancedSubscriberData> thisData(mData.release());
        std::unique_ptr<AdvancedSubscriberData> otherData(other.mData.release());

        mData.reset(otherData.release());
        other.mData.reset(thisData.release());
    }

    virtual void notify (const std::string & property)
    {
        if (property == AdvancedPublisher::nameProperty)
        {
            mData->mNameNotified = true;
        }
        else if (property == AdvancedPublisher::ageProperty)
        {
            mData->mAgeNotified = true;
        }
        else if (property == AdvancedPublisher::adultProperty)
        {
            mData->mAdultNotified = true;
        }
    }

    virtual void notify (int age, bool adult)
    {
        mData->mCombinedAgeAndAdultNotified = true;
    }

    void reset ()
    {
        mData->reset();
    }

    bool nameNotified ()
    {
        return mData->mNameNotified;
    }

    bool ageNotified ()
    {
        return mData->mAgeNotified;
    }

    bool adultNotified ()
    {
        return mData->mAdultNotified;
    }

    bool combinedAgeAndAdultNotified ()
    {
        return mData->mCombinedAgeAndAdultNotified;
    }

private:
    std::unique_ptr<AdvancedSubscriberData> mData;
};

#endif // TestTUCUT_Event_AdvancedSubscriber_h
