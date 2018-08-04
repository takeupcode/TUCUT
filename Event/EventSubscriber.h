//
//  EventSubscriber.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/24/16.
//  Copyright © 2016 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Event_EventSubscriber_h
#define TUCUT_Event_EventSubscriber_h

namespace TUCUT {
namespace Event {

template <typename... Args>
class EventPublisher;

template <typename... Args>
class EventSubscriber
{
public:
    virtual ~EventSubscriber ()
    { }

protected:
    friend class EventPublisher<Args...>;
    
    virtual void notify (int id, Args... args) = 0;
};
    
} // namespace Event
} // namespace TUCUT

#endif /* TUCUT_Event_EventSubscriber_h */
