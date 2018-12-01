//
//  TestActionSystem.h
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/29/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_TestActionSystem_h
#define TUCUT_Game_TestActionSystem_h

#include "../GameSystem.h"

namespace TUCUT {
namespace Test {
        
class TestActionSystem : public Game::GameSystem
{
public:
    std::shared_ptr<TestActionSystem> getSharedTestActionSystem ()
    {
        return std::static_pointer_cast<TestActionSystem>(shared_from_this());
    }
    
    bool notified () const
    {
        return mNotified;
    }
    
    int objectId () const
    {
        return mObjectId;
    }
    
    int actionId () const
    {
        return mActionId;
    }
    
    void reset ()
    {
        mNotified = false;
        mObjectId = 0;
        mActionId = 0;
    }

protected:
    friend class Game::GameManager;
    
    TestActionSystem (const std::string & token, int identity)
    : GameSystem(token, identity), mNotified(false), mObjectId(0), mActionId(0)
    { }
    
    void onAction (int objectId, int actionId) override
    {
        mNotified = true;
        mObjectId = objectId;
        mActionId = actionId;
    }

private:
    bool mNotified;
    int mObjectId;
    int mActionId;
};
        
} // namespace Test
} // namespace TUCUT

#endif // TUCUT_Game_TestActionSystem_h
