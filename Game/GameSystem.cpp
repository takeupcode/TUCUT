//
//  GameSystem.cpp
//  TUCUT
//
//  Created by Abdul Wahid Tanner on 11/27/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameSystem.h"

namespace TUCUT {
namespace Game {
    
void GameSystem::initialize ()
{ }

std::shared_ptr<GameSystem> GameSystem::createSharedGameSystem (std::string token, int identity)
{
    auto result = std::shared_ptr<GameSystem>(new GameSystem(token, identity));
    
    result->initialize();
    
    return result;
}

std::shared_ptr<GameSystem> GameSystem::getSharedGameSystem ()
{
    return shared_from_this();
}
    
} // namespace Game
} // namespace TUCUT
