//
//  GameComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameComponent.h"
#include "GameManager.h"

namespace TUCUT {
namespace Game {
    
void GameComponent::initialize ()
{
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    for (const auto & token: mAbilityTokens)
    {
        pGameMgr->getOrCreateGameAbility(token);
    }
}

std::shared_ptr<GameComponent> GameComponent::getSharedGameComponent ()
{
    return shared_from_this();
}

} // namespace Game
} // namespace TUCUT
