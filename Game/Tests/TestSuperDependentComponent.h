//
//  TestSuperDependentComponent.h
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/29/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_TestSuperDependentComponent_h
#define TUCUT_Game_TestSuperDependentComponent_h

#include "../GameComponent.h"

namespace TUCUT {
namespace Test {
        
class TestSuperDependentComponent : public Game::GameComponent
{
public:
    std::shared_ptr<TestSuperDependentComponent> getSharedTestSuperDependentComponent ()
    {
        return std::static_pointer_cast<TestSuperDependentComponent>(shared_from_this());
    }
    
protected:
    friend class Game::GameManager;
    
    TestSuperDependentComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    {
        mAbilityTokens.push_back("Ability3");
    }
};
        
} // namespace Test
} // namespace TUCUT

#endif // TUCUT_Game_TestSuperDependentComponent_h
