//
//  GameComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameComponent.h"

namespace TUCUT {
namespace Game {
    
void GameComponent::initialize ()
{ }

std::shared_ptr<GameComponent> GameComponent::createSharedGameComponent (std::string token, int identity)
{
    auto result = std::shared_ptr<GameComponent>(new GameComponent(token, identity));
    
    result->initialize();
    
    return result;
}

std::shared_ptr<GameComponent> GameComponent::getSharedGameComponent ()
{
    return shared_from_this();
}
    
} // namespace Game
} // namespace TUCUT
