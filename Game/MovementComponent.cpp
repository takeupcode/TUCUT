//
//  MovementComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/9/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "MovementComponent.h"
#include "../Math/Adjust.h"

namespace TUCUT {
namespace Game {

const std::string MovementComponent::defaultToken = "MovementComponent";

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
    group->addValue(xVelocityMaxName, defaultFloatValue);
    group->addValue(yVelocityMaxName, defaultFloatValue);
    group->addValue(zVelocityMaxName, defaultFloatValue);
    group->addValue(xAccelerationName, defaultFloatValue);
    group->addValue(yAccelerationName, defaultFloatValue);
    group->addValue(zAccelerationName, defaultFloatValue);
    group->addValue(xAccelerationDefaultName, defaultFloatValue);
    group->addValue(yAccelerationDefaultName, defaultFloatValue);
    group->addValue(zAccelerationDefaultName, defaultFloatValue);
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
            
    case xVelocityMax:
        return object->properties().getValue(groupName, xVelocityMaxName)->getFloating();
        
    case yVelocityMax:
        return object->properties().getValue(groupName, yVelocityMaxName)->getFloating();
        
    case zVelocityMax:
        return object->properties().getValue(groupName, zVelocityMaxName)->getFloating();
        
    case xAcceleration:
        return object->properties().getValue(groupName, xAccelerationName)->getFloating();
        
    case yAcceleration:
        return object->properties().getValue(groupName, yAccelerationName)->getFloating();
        
    case zAcceleration:
        return object->properties().getValue(groupName, zAccelerationName)->getFloating();
        
    case xAccelerationDefault:
        return object->properties().getValue(groupName, xAccelerationDefaultName)->getFloating();
        
    case yAccelerationDefault:
        return object->properties().getValue(groupName, yAccelerationDefaultName)->getFloating();
        
    case zAccelerationDefault:
        return object->properties().getValue(groupName, zAccelerationDefaultName)->getFloating();
    }
    
    return 0;
}

void MovementComponent::setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const
{
    if (!object)
    {
        return;
    }
    
    double max;
    switch (propertyId)
    {
    case xVelocity:
        max = object->properties().getValue(groupName, xVelocityMaxName)->getFloating();
        value = Math::clamp(-max, max, value);
        object->properties().getValue(groupName, xVelocityName)->setFloating(value);
        break;
        
    case yVelocity:
        max = object->properties().getValue(groupName, yVelocityMaxName)->getFloating();
        value = Math::clamp(-max, max, value);
        object->properties().getValue(groupName, yVelocityName)->setFloating(value);
        break;
        
    case zVelocity:
        max = object->properties().getValue(groupName, zVelocityMaxName)->getFloating();
        value = Math::clamp(-max, max, value);
        object->properties().getValue(groupName, zVelocityName)->setFloating(value);
        break;
        
    case xVelocityMax:
        value = Math::makePositive(value);
        object->properties().getValue(groupName, xVelocityMaxName)->setFloating(value);
        break;
        
    case yVelocityMax:
        value = Math::makePositive(value);
        object->properties().getValue(groupName, yVelocityMaxName)->setFloating(value);
        break;
        
    case zVelocityMax:
        value = Math::makePositive(value);
        object->properties().getValue(groupName, zVelocityMaxName)->setFloating(value);
        break;
        
    case xAcceleration:
        object->properties().getValue(groupName, xAccelerationName)->setFloating(value);
        break;
        
    case yAcceleration:
        object->properties().getValue(groupName, yAccelerationName)->setFloating(value);
        break;
        
    case zAcceleration:
        object->properties().getValue(groupName, zAccelerationName)->setFloating(value);
        break;
        
    case xAccelerationDefault:
        value = Math::makePositive(value);
        object->properties().getValue(groupName, xAccelerationDefaultName)->setFloating(value);
        break;
        
    case yAccelerationDefault:
        value = Math::makePositive(value);
        object->properties().getValue(groupName, yAccelerationDefaultName)->setFloating(value);
        break;
        
    case zAccelerationDefault:
        value = Math::makePositive(value);
        object->properties().getValue(groupName, zAccelerationDefaultName)->setFloating(value);
        break;
    }
}

} // namespace Game
} // namespace TUCUT
