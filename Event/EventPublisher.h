//
//  EventPublisher.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/24/16.
//  Copyright © 2016 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Event_EventPublisher_h
#define TUCUT_Event_EventPublisher_h

#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

#include "EventSubscriber.h"

namespace TUCUT {
namespace Event {
    
template <typename... Args>
class EventPublisher
{
public:
    using PublisherType = EventPublisher<Args...>;
    using SubscriberType = EventSubscriber<Args...>;
    using WeakSubscriberType = std::weak_ptr<SubscriberType> ;
    using SharedSubscriberType = std::shared_ptr<SubscriberType>;
    
private:
    using MappedWeakSubscriberType = std::unordered_map<std::string, WeakSubscriberType>;
    
    struct EventPublisherData
    {
        MappedWeakSubscriberType mSubscribers;
        
        EventPublisherData ()
        { }
        
        EventPublisherData (const EventPublisherData & src)
        : mSubscribers(src.mSubscribers)
        { }
        
        ~EventPublisherData ()
        { }
        
        EventPublisherData & operator = (const EventPublisherData & rhs)
        {
            if (this == &rhs)
            {
                return *this;
            }
            
            mSubscribers = rhs.mSubscribers;
            
            return *this;
        }
    };
    
    std::unique_ptr<EventPublisherData> mData;

public:
    EventPublisher ()
    : mData(new EventPublisherData())
    { }
    
    EventPublisher (const PublisherType & src)
    : mData(new EventPublisherData(*src.mData))
    { }
    
    EventPublisher (PublisherType && src)
    : mData(src.mData.release())
    { }

    virtual ~EventPublisher ()
    { }
    
    void swap (PublisherType & other)
    {
        std::unique_ptr<EventPublisherData> thisData(mData.release());
        std::unique_ptr<EventPublisherData> otherData(other.mData.release());
        
        mData.reset(otherData.release());
        other.mData.reset(thisData.release());
    }
    
    PublisherType & operator = (const PublisherType & rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        
        *mData = *rhs.mData;
        
        return *this;
    }
    
    PublisherType & operator = (PublisherType && rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        
        mData.reset(rhs.mData.release());
        
        return *this;
    }

    void signal (Args... args) const
    {
        std::vector<std::string> badConnectionIdentities;
        
        // Iterate through a copy of the subscribers because the notify handlers
        // could decide to unsubscribe which would invalidate the iterator if
        // we were iterating through the original collection.
        MappedWeakSubscriberType mSubscribersCopy = mData->mSubscribers;
        for (auto & identifiedSubscriberPair : mSubscribersCopy)
        {
            try
            {
                SharedSubscriberType sharedSubscriber(identifiedSubscriberPair.second);
                
                sharedSubscriber->notify(args...);
            }
            catch (const std::bad_weak_ptr &)
            {
                badConnectionIdentities.push_back(identifiedSubscriberPair.first);
            }
        }
        for (auto & identity : badConnectionIdentities)
        {
            mData->mSubscribers.erase(identity);
        }
    }
    
    void connect (const std::string & identity, const SharedSubscriberType & subscriber)
    {
        WeakSubscriberType weakSubscriber = subscriber;
        
        auto identifiedPosition = mData->mSubscribers.find(identity);
        if (identifiedPosition != mData->mSubscribers.end())
        {
            identifiedPosition->second = weakSubscriber;
        }
        else
        {
            mData->mSubscribers.insert({identity, weakSubscriber});
        }
    }
    
    void disconnect (const std::string & identity)
    {
        mData->mSubscribers.erase(identity);
    }
};
    
} // namespace Event
} // namespace TUCUT

#endif // TUCUT_Event_EventPublisher_h
