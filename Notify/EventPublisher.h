//  EventPublisher.h
//  TUCUT/Notify (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2016-07-24.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Notify_EventPublisher_h
#define TUCUT_Notify_EventPublisher_h

#include "EventSubscriber.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace TUCUT::Notify
{
  template <typename... Args>
  class EventPublisher
  {
  public:
    using PublisherType = EventPublisher<Args...>;
    using SubscriberType = EventSubscriber<Args...>;
    using WeakSubscriberType = std::weak_ptr<SubscriberType> ;
    using SharedSubscriberType =
      std::shared_ptr<SubscriberType>;

  private:
    using MappedWeakSubscriberType =
      std::unordered_map<std::string, WeakSubscriberType>;

    struct EventPublisherData
    {
      int mId;
      MappedWeakSubscriberType mSubscribers;

      explicit EventPublisherData (int id)
      : mId(id)
      { }

      EventPublisherData (EventPublisherData const & src)
      : mId(src.mId), mSubscribers(src.mSubscribers)
      { }

      EventPublisherData & operator = (
        EventPublisherData const & rhs)
      {
        if (this == &rhs)
        {
          return *this;
        }

        mId = rhs.mId;
        mSubscribers = rhs.mSubscribers;

        return *this;
      }
    };

    std::unique_ptr<EventPublisherData> mData;

  public:
    explicit EventPublisher (int id)
    : mData(new EventPublisherData(id))
    { }

    EventPublisher (PublisherType const & src)
    : mData(new EventPublisherData(*src.mData))
    { }

    EventPublisher (PublisherType && src)
    : mData(src.mData.release())
    { }

    virtual ~EventPublisher () = default;

    void swap (PublisherType & other)
    {
      std::unique_ptr<EventPublisherData>
        thisData(mData.release());
      std::unique_ptr<EventPublisherData>
        otherData(other.mData.release());

      mData.reset(otherData.release());
      other.mData.reset(thisData.release());
    }

    PublisherType & operator = (PublisherType const & rhs)
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

      // Iterate through a copy of the subscribers because
      // the notify handlers could decide to unsubscribe
      // which would invalidate the iterator if we were
      // iterating through the original collection.
      MappedWeakSubscriberType mSubscribersCopy =
        mData->mSubscribers;
      for (auto & identifiedSubscriberPair : mSubscribersCopy)
      {
        try
        {
          SharedSubscriberType sharedSubscriber(
            identifiedSubscriberPair.second);

          sharedSubscriber->notify(mData->mId, args...);
        }
        catch (std::bad_weak_ptr const &)
        {
          badConnectionIdentities.push_back(
            identifiedSubscriberPair.first);
        }
      }
      for (auto & identity : badConnectionIdentities)
      {
        mData->mSubscribers.erase(identity);
      }
    }

    void connect (std::string const & identity,
      SharedSubscriberType const & subscriber)
    {
      WeakSubscriberType weakSubscriber = subscriber;

      auto identifiedPosition =
        mData->mSubscribers.find(identity);
      if (identifiedPosition != mData->mSubscribers.end())
      {
        identifiedPosition->second = weakSubscriber;
      }
      else
      {
        mData->mSubscribers.insert({identity, weakSubscriber});
      }
    }

    void disconnect (std::string const & identity)
    {
      mData->mSubscribers.erase(identity);
    }
  };
} // namespace TUCUT::Notify

#endif // TUCUT_Notify_EventPublisher_h
