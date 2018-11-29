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
    
    void onAction (int objectId, int actionId) override
    {
        mNotified = true;
        mObjectId = objectId;
        mActionId = actionId;
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
    
    static std::shared_ptr<GameSystem> createSharedGameSystem (std::string token, int identity)
    {
        auto result = std::shared_ptr<GameSystem>(new TestActionSystem(token, identity));
        
        std::static_pointer_cast<TestActionSystem>(result)->initialize();
        
        return result;
    }
    
    TestActionSystem (const std::string & token, int identity)
    : GameSystem(token, identity), mNotified(false), mObjectId(0), mActionId(0)
    { }
    
private:
    bool mNotified;
    int mObjectId;
    int mActionId;
};
        
} // namespace Test
} // namespace TUCUT

#endif // TUCUT_Game_TestActionSystem_h
