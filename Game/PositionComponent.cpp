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
    
    double defaultPosition = 0.0;
    group->addValue(xName, defaultPosition);
    group->addValue(yName, defaultPosition);
    group->addValue(zName, defaultPosition);
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
    }
    
    return 0;
}

void PositionComponent::setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const
{
    if (!object)
    {
        return;
    }
    
    switch (propertyId)
    {
        case x:
            object->properties().getValue(groupName, xName)->setFloating(value);
            break;
            
        case y:
            object->properties().getValue(groupName, yName)->setFloating(value);
            break;
            
        case z:
            object->properties().getValue(groupName, zName)->setFloating(value);
            break;
    }
}

} // namespace Game
} // namespace TUCUT
