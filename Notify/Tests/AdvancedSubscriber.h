//  AdvancedSubscriber.h
//  TUCUT/Notify (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2014-07-20.
//  Copyright © Take Up Code, Inc.
//
#ifndef TestTUCUT_Notify_AdvancedSubscriber_h
#define TestTUCUT_Notify_AdvancedSubscriber_h

#include <memory>
#include <string>

#include "../EventSubscriber.h"
#include "AdvancedPublisher.h"

class AdvancedSubscriber : public TUCUT::Notify::EventSubscriber<const std::string &>,
    public TUCUT::Notify::EventSubscriber<int, bool>
{
private:
    struct AdvancedSubscriberData
    {
        int mId;
        bool mNameNotified;
        bool mAgeNotified;
        bool mAdultNotified;
        bool mCombinedAgeAndAdultNotified;

        void resetData ()
        {
            mId = 0;
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
        resetData();
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

    virtual void notify (int id, const std::string & property)
    {
        mData->mId = id;

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

    virtual void notify (int id, int, bool)
    {
        mData->mId = id;
        mData->mCombinedAgeAndAdultNotified = true;
    }

    void resetData ()
    {
        mData->resetData();
    }

    int id ()
    {
        return mData->mId;
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

#endif // TestTUCUT_Notify_AdvancedSubscriber_h
