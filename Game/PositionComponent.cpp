//
//  PositionComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/5/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "PositionComponent.h"

namespace TUCUT {
namespace Game {

const std::string PositionComponent::defaultToken = "PositionComponent";
const std::string PositionComponent::groupName = "GamePosition";
const std::string PositionComponent::xName = "x";
const std::string PositionComponent::yName = "y";
const std::string PositionComponent::zName = "z";
const std::string PositionComponent::xOldName = "xOld";
const std::string PositionComponent::yOldName = "yOld";
const std::string PositionComponent::zOldName = "zOld";

std::shared_ptr<PositionComponent> PositionComponent::getSharedPositionComponent ()
{
    return std::static_pointer_cast<PositionComponent>(shared_from_this());
}

void PositionComponent::addDefaultProperties (const std::shared_ptr<GameObject> & object) const
{
    if (!object)
    {
        return;
    }
    
    auto group = object->properties().addGroup(groupName);
    
    double defaultFloatValue = 0.0;
    group->addValue(xName, defaultFloatValue);
    group->addValue(yName, defaultFloatValue);
    group->addValue(zName, defaultFloatValue);
    group->addValue(xOldName, defaultFloatValue);
    group->addValue(yOldName, defaultFloatValue);
    group->addValue(zOldName, defaultFloatValue);
}

void PositionComponent::removeProperties (const std::shared_ptr<GameObject> & object) const
{
    if (!object)
    {
        return;
    }
    
    object->properties().removeGroup(groupName);
}

double PositionComponent::getFloating (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    if (!object)
    {
        return 0;
    }
    
    switch (propertyId)
    {
        case x:
            return object->properties().getValue(groupName, xName)->getFloating();
            
        case y:
            return object->properties().getValue(groupName, yName)->getFloating();
            
        case z:
            return object->properties().getValue(groupName, zName)->getFloating();
            
        case xOld:
            return object->properties().getValue(groupName, xOldName)->getFloating();
            
        case yOld:
            return object->properties().getValue(groupName, yOldName)->getFloating();
            
        case zOld:
            return object->properties().getValue(groupName, zOldName)->getFloating();
    }
    
    return 0;
}

void PositionComponent::setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const
{
    if (!object)
    {
        return;
    }
    
    double old;
    switch (propertyId)
    {
        case x:
            if (value < mMinPosition.x)
            {
                value = mMinPosition.x;
            }
            else if (value > mMaxPosition.x)
            {
                value = mMaxPosition.x;
            }
            old = object->properties().getValue(groupName, xName)->getFloating();
            object->properties().getValue(groupName, xOldName)->setFloating(old);
            object->properties().getValue(groupName, xName)->setFloating(value);
            break;
            
        case y:
            if (value < mMinPosition.y)
            {
                value = mMinPosition.y;
            }
            else if (value > mMaxPosition.y)
            {
                value = mMaxPosition.y;
            }
            old = object->properties().getValue(groupName, yName)->getFloating();
            object->properties().getValue(groupName, yOldName)->setFloating(old);
            object->properties().getValue(groupName, yName)->setFloating(value);
            break;
            
        case z:
            if (value < mMinPosition.z)
            {
                value = mMinPosition.z;
            }
            else if (value > mMaxPosition.z)
            {
                value = mMaxPosition.z;
            }
            old = object->properties().getValue(groupName, zName)->getFloating();
            object->properties().getValue(groupName, zOldName)->setFloating(old);
            object->properties().getValue(groupName, zName)->setFloating(value);
            break;
            
        case xOld:
            if (value < mMinPosition.x)
            {
                value = mMinPosition.x;
            }
            else if (value > mMaxPosition.x)
            {
                value = mMaxPosition.x;
            }
            object->properties().getValue(groupName, xOldName)->setFloating(value);
            break;
            
        case yOld:
            if (value < mMinPosition.y)
            {
                value = mMinPosition.y;
            }
            else if (value > mMaxPosition.y)
            {
                value = mMaxPosition.y;
            }
            object->properties().getValue(groupName, yOldName)->setFloating(value);
            break;
            
        case zOld:
            if (value < mMinPosition.z)
            {
                value = mMinPosition.z;
            }
            else if (value > mMaxPosition.z)
            {
                value = mMaxPosition.z;
            }
            object->properties().getValue(groupName, zOldName)->setFloating(value);
            break;
    }
}

void PositionComponent::setMinPosition (const Math::Vector3d & position)
{
    mMinPosition = position;
}

void PositionComponent::setMaxPosition (const Math::Vector3d & position)
{
    mMaxPosition = position;
}

} // namespace Game
} // namespace TUCUT
