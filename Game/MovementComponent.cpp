//
//  MovementComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/9/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "MovementComponent.h"

namespace TUCUT {
namespace Game {

const std::string MovementComponent::defaultToken = "MovementComponent";
const std::string MovementComponent::groupName = "GameMoveable";
const std::string MovementComponent::xVelocityName = "xVelocity";
const std::string MovementComponent::yVelocityName = "yVelocity";
const std::string MovementComponent::zVelocityName = "zVelocity";

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
    group->addValue(xVelocityName, defaultFloatValue);
    group->addValue(yVelocityName, defaultFloatValue);
    group->addValue(zVelocityName, defaultFloatValue);
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
    case xVelocity:
        return object->properties().getValue(groupName, xVelocityName)->getFloating();
        
    case yVelocity:
        return object->properties().getValue(groupName, yVelocityName)->getFloating();
        
    case zVelocity:
        return object->properties().getValue(groupName, zVelocityName)->getFloating();
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
    case xVelocity:
        object->properties().getValue(groupName, xVelocityName)->setFloating(value);
        break;
        
    case yVelocity:
        object->properties().getValue(groupName, yVelocityName)->setFloating(value);
        break;
        
    case zVelocity:
        object->properties().getValue(groupName, zVelocityName)->setFloating(value);
        break;
    }
}

} // namespace Game
} // namespace TUCUT
