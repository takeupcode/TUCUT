//
//  GameObject.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameObject.h"
#include "GameComponent.h"
#include "GameManager.h"

#include <algorithm>
#include <stdexcept>

namespace TUCUT {
namespace Game {

void GameObject::initialize ()
{ }

std::shared_ptr<GameObject> GameObject::getSharedGameObject ()
{
    return shared_from_this();
}
    
bool GameObject::hasGameComponent (int componentId) const
{
    if (componentId < 1)
    {
        return false;
    }
    
    if (mComponents.size() > static_cast<std::size_t>(componentId))
    {
        return mComponents[componentId];
    }
    
    return false;
}

bool GameObject::hasGameComponent (const std::shared_ptr<GameComponent> & component) const
{
    return hasGameComponent(component->identity());
}

bool GameObject::addGameComponent (int componentId)
{
    if (componentId < 1)
    {
        return false;
    }
    
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    auto component = pGameMgr->getGameComponent<GameComponent>(componentId);
    
    return addGameComponent(component);
    
    return false;
}

bool GameObject::addGameComponent (const std::shared_ptr<GameComponent> & component)
{
    if (!component)
    {
        return false;
    }
    
    auto componentId = component->identity();
    while (mComponents.size() <= static_cast<std::size_t>(componentId))
    {
        mComponents.push_back(false);
    }
    
    if (mComponents[componentId])
    {
        return false;
    }
    else
    {
        Game::GameManager * pGameMgr = Game::GameManager::instance();
        
        for (const auto & ability: component->getAbilities())
        {
            auto abilityId = pGameMgr->getGameAbilityId(ability);
            if (abilityId < 1)
            {
                throw std::runtime_error("Unable to find registered game ability");
            }
            
            while (mAbilities.size() <= static_cast<std::size_t>(abilityId))
            {
                mAbilities.push_back({});
            }
            mAbilities[abilityId].push_back(component);
        }
        
        mComponents[componentId] = true;
        
        pGameMgr->onGameObjectComponentChanged(getSharedGameObject());
    }
    
    return true;
}

void GameObject::removeGameComponent (int componentId)
{
    if (componentId < 1)
    {
        return;
    }
    
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    auto component = pGameMgr->getGameComponent<GameComponent>(componentId);

    removeGameComponent(component);
}

void GameObject::removeGameComponent (const std::shared_ptr<GameComponent> & component)
{
    if (!component)
    {
        return;
    }
    
    auto componentId = component->identity();
    if (mComponents.size() > static_cast<std::size_t>(componentId))
    {
        if (mComponents[componentId])
        {
            Game::GameManager * pGameMgr = Game::GameManager::instance();
            
            mComponents[componentId] = false;
            
            for (const auto & ability: component->getAbilities())
            {
                auto abilityId = pGameMgr->getGameAbilityId(ability);
                if (abilityId > 0 && mAbilities.size() > static_cast<std::size_t>(abilityId))
                {
                    mAbilities[abilityId].erase(std::find(mAbilities[abilityId].begin(), mAbilities[abilityId].end(),
                                                          component));
                }
            }

            pGameMgr->onGameObjectComponentChanged(getSharedGameObject());
        }
    }
}
    
bool GameObject::hasGameAbility (int abilityId) const
{
    if (abilityId < 1)
    {
        return false;
    }
    
    if (mAbilities.size() > static_cast<std::size_t>(abilityId))
    {
        return !mAbilities[abilityId].empty();
    }
    
    return false;
}

bool GameObject::hasGameAbility (const std::string & token) const
{
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto abilityId = pGameMgr->getGameAbilityId(token);
    
    return hasGameAbility(abilityId);
}
    
std::shared_ptr<GameComponent> GameObject::getGameComponentFromAbility (int abilityId) const
{
    if (abilityId < 1)
    {
        return nullptr;
    }
    
    if (mAbilities.size() > static_cast<std::size_t>(abilityId))
    {
        if (!mAbilities[abilityId].empty())
        {
            return mAbilities[abilityId].back();
        }
    }
    
    return nullptr;
}

std::shared_ptr<GameComponent> GameObject::getGameComponentFromAbility (const std::string & token) const
{
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto abilityId = pGameMgr->getGameAbilityId(token);
    
    return getGameComponentFromAbility(abilityId);
}

} // namespace Game
} // namespace TUCUT
