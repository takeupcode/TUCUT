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
    
public:
    EventPublisher ()
    : mSubscribers(new MappedSubscriberType())
    { }
    
    EventPublisher (const PublisherType & src) = delete;
    
    EventPublisher (PublisherType && src)
    : mSubscribers(src.mSubscribers.release())
    { }
    
    virtual ~EventPublisher ()
    { }
    
    PublisherType & operator = (const PublisherType & rhs) = delete;
    
    PublisherType & operator = (PublisherType && rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        
        mSubscribers.reset(rhs.mSubscribers.release());
        
        return *this;
    }
    
    void signal (Args... args) const
    {
        // Iterate through a copy of the subscribers because the notify handlers
        // could decide to unsubscribe which would invalidate the iterator if
        // we were iterating through the original collection.
        MappedSubscriberType mSubscribersCopy = *mSubscribers;
        for (auto & subscriberPair : mSubscribersCopy)
        {
            subscriberPair.second->notify(args...);
        }
    }
    
    void connect (const std::string & identity, SubscriberType * subscriber)
    {
        auto identifiedPosition = mSubscribers->find(identity);
        if (identifiedPosition != mSubscribers->end())
        {
            identifiedPosition->second = subscriber;
        }
        else
        {
            mSubscribers->insert({identity, subscriber});
        }
    }
    
    void disconnect (const std::string & identity)
    {
        mSubscribers->erase(identity);
    }
    
private:
    using MappedSubscriberType = std::unordered_map<std::string, SubscriberType *>;
    
    std::unique_ptr<MappedSubscriberType> mSubscribers;
};
    
} // namespace Event
} // namespace TUCUT

#endif // TUCUT_Event_EventPublisher_h
