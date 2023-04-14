//
//  GameManagerSubscriber.h
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/22/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameManagerSubscriber_h
#define TUCUT_Game_GameManagerSubscriber_h

#include "../GameObject.h"
#include "../../Event/EventSubscriber.h"

namespace TUCUT {
namespace Test {
        
    class GameManagerSubscriber : public Event::EventSubscriber<const std::shared_ptr<Game::GameObject> &>
{
public:
    GameManagerSubscriber ()
    : mNotified(false), mId(0)
    { }
    
    void notify (int id, const std::shared_ptr<Game::GameObject> &) override
    {
        mNotified = true;
        mId = id;
    }
    
    bool notified () const
    {
        return mNotified;
    }
    
    int id () const
    {
        return mId;
    }
    
    void reset ()
    {
        mNotified = false;
        mId = 0;
    }
    
private:
    bool mNotified;
    int mId;
};

} // namespace Test
} // namespace TUCUT

#endif // TUCUT_Game_GameManagerSubscriber_h
