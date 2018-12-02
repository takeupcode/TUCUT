//
//  TestDependentSystem.h
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 12/1/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_TestDependentSystem_h
#define TUCUT_Game_TestDependentSystem_h

#include "../GameSystem.h"

namespace TUCUT {
namespace Test {

class TestDependentSystem : public Game::GameSystem
{
public:
    std::shared_ptr<TestDependentSystem> getSharedTestDependentSystem ()
    {
        return std::static_pointer_cast<TestDependentSystem>(shared_from_this());
    }
    
protected:
    friend class Game::GameManager;
    
    TestDependentSystem (const std::string & token, int identity)
    : GameSystem(token, identity)
    {
        mRequiredComponentTokens.push_back("DependentComponent");
    }

private:
};

} // namespace Test
} // namespace TUCUT

#endif // TUCUT_Game_TestDependentSystem_h
