//
//  PositionComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/5/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "PositionComponent.h"
#include "GameManager.h"

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
            old = object->properties().getValue(groupName, xName)->getFloating();
            object->properties().getValue(groupName, xOldName)->setFloating(old);
            object->properties().getValue(groupName, xName)->setFloating(value);
            break;
            
        case y:
            old = object->properties().getValue(groupName, yName)->getFloating();
            object->properties().getValue(groupName, yOldName)->setFloating(old);
            object->properties().getValue(groupName, yName)->setFloating(value);
            break;
            
        case z:
            old = object->properties().getValue(groupName, zName)->getFloating();
            object->properties().getValue(groupName, zOldName)->setFloating(old);
            object->properties().getValue(groupName, zName)->setFloating(value);
            break;
            
        case xOld:
            object->properties().getValue(groupName, xOldName)->setFloating(value);
            break;
            
        case yOld:
            object->properties().getValue(groupName, yOldName)->setFloating(value);
            break;
            
        case zOld:
            object->properties().getValue(groupName, zOldName)->setFloating(value);
            break;
    }
}

} // namespace Game
} // namespace TUCUT
