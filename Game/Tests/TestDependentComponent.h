//
//  TestDependentComponent.h
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/29/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_TestDependentComponent_h
#define TUCUT_Game_TestDependentComponent_h

#include "../GameComponent.h"

namespace TUCUT {
namespace Test {
        
class TestDependentComponent : public Game::GameComponent
{
public:
    std::shared_ptr<TestDependentComponent> getSharedTestDependentComponent ()
    {
        return std::static_pointer_cast<TestDependentComponent>(shared_from_this());
    }
    
protected:
    friend class Game::GameManager;
    
    static std::shared_ptr<GameComponent> createSharedGameComponent (std::string token, int identity)
    {
        auto result = std::shared_ptr<GameComponent>(new TestDependentComponent(token, identity));
        
        std::static_pointer_cast<TestDependentComponent>(result)->initialize();
        
        return result;
    }
    
    TestDependentComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    {
        mDependentComponentTokens.push_back("SimpleComponent");
    }
};
        
} // namespace Test
} // namespace TUCUT

#endif // TUCUT_Game_TestDependentComponent_h
