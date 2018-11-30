//
//  TestSimpleComponent.h
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/29/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_TestSimpleComponent_h
#define TUCUT_Game_TestSimpleComponent_h

#include "../GameComponent.h"

namespace TUCUT {
namespace Test {
        
class TestSimpleComponent : public Game::GameComponent
{
public:
    std::shared_ptr<TestSimpleComponent> getSharedTestSimpleComponent ()
    {
        return std::static_pointer_cast<TestSimpleComponent>(shared_from_this());
    }

protected:
    friend class Game::GameManager;
    
    static std::shared_ptr<GameComponent> createSharedGameComponent (std::string token, int identity)
    {
        auto result = std::shared_ptr<GameComponent>(new TestSimpleComponent(token, identity));
        
        std::static_pointer_cast<TestSimpleComponent>(result)->initialize();
        
        return result;
    }
    
    TestSimpleComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    { }
};
        
} // namespace Test
} // namespace TUCUT

#endif // TUCUT_Game_TestSimpleComponent_h
