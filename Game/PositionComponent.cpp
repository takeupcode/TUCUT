//
//  PositionComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/5/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "PositionComponent.h"
#include "../Math/Adjust.h"

namespace TUCUT {
namespace Game {

const std::string PositionComponent::defaultToken = "PositionComponent";

void PositionComponent::initialize ()
{
    GameComponent::initialize();
    
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    mPositionChangedActionId = pGameMgr->getOrCreateGameAction(positionChangedToken);
}

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

std::vector<double> PositionComponent::getFloatings (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    std::vector<double> result;
    
    if (!object)
    {
        return result;
    }
    
    switch (propertyId)
    {
    case xyz:
        result.push_back(object->properties().getValue(groupName, xName)->getFloating());

        result.push_back(object->properties().getValue(groupName, yName)->getFloating());
        
        result.push_back(object->properties().getValue(groupName, zName)->getFloating());
        break;
        
    case xyzOld:
        result.push_back(object->properties().getValue(groupName, xOldName)->getFloating());
        
        result.push_back(object->properties().getValue(groupName, yOldName)->getFloating());
        
        result.push_back(object->properties().getValue(groupName, zOldName)->getFloating());
        break;
    }
    
    return result;
}

void PositionComponent::setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const
{
    if (!object)
    {
        return;
    }

    Game::GameManager * pGameMgr = Game::GameManager::instance();

    double old;
    switch (propertyId)
    {
    case x:
        value = Math::clamp(mMinPosition.x, mMaxPosition.x, value);
        old = object->properties().getValue(groupName, xName)->getFloating();
        object->properties().getValue(groupName, xOldName)->setFloating(old);
        object->properties().getValue(groupName, xName)->setFloating(value);
            
        pGameMgr->queueGameAction(object->identity(), mPositionChangedActionId);
        break;
        
    case y:
        value = Math::clamp(mMinPosition.y, mMaxPosition.y, value);
        old = object->properties().getValue(groupName, yName)->getFloating();
        object->properties().getValue(groupName, yOldName)->setFloating(old);
        object->properties().getValue(groupName, yName)->setFloating(value);
            
        pGameMgr->queueGameAction(object->identity(), mPositionChangedActionId);
        break;
        
    case z:
        value = Math::clamp(mMinPosition.z, mMaxPosition.z, value);
        old = object->properties().getValue(groupName, zName)->getFloating();
        object->properties().getValue(groupName, zOldName)->setFloating(old);
        object->properties().getValue(groupName, zName)->setFloating(value);
            
        pGameMgr->queueGameAction(object->identity(), mPositionChangedActionId);
        break;
        
    case xOld:
        value = Math::clamp(mMinPosition.x, mMaxPosition.x, value);
        object->properties().getValue(groupName, xOldName)->setFloating(value);
        break;
        
    case yOld:
        value = Math::clamp(mMinPosition.y, mMaxPosition.y, value);
        object->properties().getValue(groupName, yOldName)->setFloating(value);
        break;
        
    case zOld:
        value = Math::clamp(mMinPosition.z, mMaxPosition.z, value);
        object->properties().getValue(groupName, zOldName)->setFloating(value);
        break;
    }
}

void PositionComponent::setFloatings (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<double> & value) const
{
    if (!object)
    {
        return;
    }

    Game::GameManager * pGameMgr = Game::GameManager::instance();

    double old;
    double singleValue;
    switch (propertyId)
    {
    case xyz:
        singleValue = Math::clamp(mMinPosition.x, mMaxPosition.x, value[0]);
        old = object->properties().getValue(groupName, xName)->getFloating();
        object->properties().getValue(groupName, xOldName)->setFloating(old);
        object->properties().getValue(groupName, xName)->setFloating(singleValue);

        singleValue = Math::clamp(mMinPosition.y, mMaxPosition.y, value[1]);
        old = object->properties().getValue(groupName, yName)->getFloating();
        object->properties().getValue(groupName, yOldName)->setFloating(old);
        object->properties().getValue(groupName, yName)->setFloating(singleValue);

        singleValue = Math::clamp(mMinPosition.z, mMaxPosition.z, value[2]);
        old = object->properties().getValue(groupName, zName)->getFloating();
        object->properties().getValue(groupName, zOldName)->setFloating(old);
        object->properties().getValue(groupName, zName)->setFloating(singleValue);
            
        pGameMgr->queueGameAction(object->identity(), mPositionChangedActionId);
        break;
        
    case xyzOld:
        singleValue = Math::clamp(mMinPosition.x, mMaxPosition.x, value[0]);
        object->properties().getValue(groupName, xOldName)->setFloating(singleValue);

        singleValue = Math::clamp(mMinPosition.y, mMaxPosition.y, value[1]);
        object->properties().getValue(groupName, yOldName)->setFloating(singleValue);

        singleValue = Math::clamp(mMinPosition.z, mMaxPosition.z, value[2]);
        object->properties().getValue(groupName, zOldName)->setFloating(singleValue);
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
