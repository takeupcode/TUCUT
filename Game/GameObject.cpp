//
//  GameObject.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameObject.h"

namespace TUCUT {
namespace Game {

void GameObject::initialize ()
{ }

std::shared_ptr<GameObject> GameObject::createSharedGameObject (std::string token, int identity)
{
    auto result = std::shared_ptr<GameObject>(new GameObject(token, identity));
    
    result->initialize();
    
    return result;
}

std::shared_ptr<GameObject> GameObject::getSharedGameObject ()
{
    return shared_from_this();
}
    
bool GameObject::hasGameComponent (int componentId) const
{
    return mComponents[componentId];
}

bool GameObject::hasGameComponent (const std::shared_ptr<GameComponent> & component) const
{
    return hasGameComponent(component->identity());
}

bool GameObject::addGameComponent (int componentId)
{
    while (mComponents.size() <= static_cast<std::size_t>(componentId))
    {
        mComponents.push_back(false);
    }
    
    if (mComponents[componentId])
    {
        return false;
    }
    
    mComponents[componentId] = true;
    
    return true;
}

bool GameObject::addGameComponent (const std::shared_ptr<GameComponent> & component)
{
    return addGameComponent(component->identity());
}

void GameObject::removeGameComponent (int componentId)
{
    if (mComponents.size() > static_cast<std::size_t>(componentId))
    {
        mComponents[componentId] = false;
    }
}

void GameObject::removeGameComponent (const std::shared_ptr<GameComponent> & component)
{
    removeGameComponent(component->identity());
}

} // namespace Game
} // namespace TUCUT
