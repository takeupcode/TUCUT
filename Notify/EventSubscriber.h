//  EventSubscriber.h
//  TUCUT/Notify (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2016-07-24.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Notify_EventSubscriber_h
#define TUCUT_Notify_EventSubscriber_h

namespace TUCUT::Notify
{
  template <typename... Args>
  class EventPublisher;

  template <typename... Args>
  class EventSubscriber
  {
  public:
    virtual ~EventSubscriber () = default;

  protected:
    friend class EventPublisher<Args...>;

    virtual void notify (int id, Args... args) = 0;
  };
} // namespace TUCUT::Notify

#endif // TUCUT_Notify_EventSubscriber_h
