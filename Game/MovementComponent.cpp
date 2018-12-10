//
//  MovementComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/9/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "MovementComponent.h"
#include "GameManager.h"

namespace TUCUT {
namespace Game {

const std::string MovementComponent::defaultToken = "MovementComponent";
const std::string MovementComponent::groupName = "GameMoveable";
const std::string MovementComponent::velocityName = "velocity";
const std::string MovementComponent::xDirName = "xDir";
const std::string MovementComponent::yDirName = "yDir";
const std::string MovementComponent::zDirName = "zDir";

std::shared_ptr<MovementComponent> MovementComponent::getSharedMovementComponent ()
{
    return std::static_pointer_cast<MovementComponent>(shared_from_this());
}

void MovementComponent::addDefaultProperties (const std::shared_ptr<GameObject> & object) const
{
    if (!object)
    {
        return;
    }
    
    auto group = object->properties().addGroup(groupName);
    
    double defaultFloatValue = 0.0;
    group->addValue(velocityName, defaultFloatValue);
    group->addValue(xDirName, defaultFloatValue);
    group->addValue(yDirName, defaultFloatValue);
    group->addValue(zDirName, defaultFloatValue);
}

void MovementComponent::removeProperties (const std::shared_ptr<GameObject> & object) const
{
    if (!object)
    {
        return;
    }
    
    object->properties().removeGroup(groupName);
}

double MovementComponent::getFloating (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    if (!object)
    {
        return 0;
    }
    
    switch (propertyId)
    {
    case velocity:
        return object->properties().getValue(groupName, velocityName)->getFloating();
        
    case xDir:
        return object->properties().getValue(groupName, xDirName)->getFloating();
        
    case yDir:
        return object->properties().getValue(groupName, yDirName)->getFloating();
        
    case zDir:
        return object->properties().getValue(groupName, zDirName)->getFloating();
    }
    
    return 0;
}

void MovementComponent::setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const
{
    if (!object)
    {
        return;
    }
    
    switch (propertyId)
    {
    case velocity:
        object->properties().getValue(groupName, velocityName)->setFloating(value);
        break;
        
    case xDir:
        object->properties().getValue(groupName, xDirName)->setFloating(value);
        break;
        
    case yDir:
        object->properties().getValue(groupName, yDirName)->setFloating(value);
        break;
        
    case zDir:
        object->properties().getValue(groupName, zDirName)->setFloating(value);
        break;
    }
}

} // namespace Game
} // namespace TUCUT
