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

std::shared_ptr<GameObject> GameObject::createSharedGameObject ()
{
    auto result = std::shared_ptr<GameObject>(new GameObject());
    
    result->initialize();
    
    return result;
}

std::shared_ptr<GameObject> GameObject::getSharedGameObject ()
{
    return shared_from_this();
}

PropertyContainer & GameObject::properties ()
{
    return mProperties;
}

} // namespace Game
} // namespace TUCUT
