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
        
        mComponents[componentId] = true;
        pGameMgr->onGameObjectComponentChanged(getSharedGameObject());
    }
    
    return true;
}

bool GameObject::addGameComponent (const std::shared_ptr<GameComponent> & component)
{
    return addGameComponent(component->identity());
}

void GameObject::removeGameComponent (int componentId)
{
    if (componentId < 1)
    {
        return;
    }
    
    if (mComponents.size() > static_cast<std::size_t>(componentId))
    {
        if (mComponents[componentId])
        {
            Game::GameManager * pGameMgr = Game::GameManager::instance();
            
            mComponents[componentId] = false;
            pGameMgr->onGameObjectComponentChanged(getSharedGameObject());
        }
    }
}

void GameObject::removeGameComponent (const std::shared_ptr<GameComponent> & component)
{
    removeGameComponent(component->identity());
}

} // namespace Game
} // namespace TUCUT
