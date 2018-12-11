//
//  MovementSystem.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/10/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "MovementSystem.h"
#include "MovementComponent.h"
#include "PositionComponent.h"

namespace TUCUT {
namespace Game {

const std::string MovementSystem::defaultToken = "MovementSystem";
const std::string MovementSystem::targetIdName = "targetId";
const std::string MovementSystem::xVelocityName = "xVelocity";
const std::string MovementSystem::yVelocityName = "yVelocity";
const std::string MovementSystem::zVelocityName = "zVelocity";

void MovementSystem::update (TimeResolution elapsedTime)
{
    TimeInSeconds seconds = elapsedTime;
    double adjustment = 10.0 * seconds.count();
    
    for (const auto & gameObj: mGameObjects)
    {
        auto movementComp = gameObj.second->getGameComponentFromAbility("GameMoveable");
        if (!movementComp)
        {
            continue;
        }

        auto xVelocity = movementComp->getFloating(gameObj.second, MovementComponent::xVelocity);
        if (xVelocity)
        {
            if (xVelocity > 0)
            {
                xVelocity -= adjustment;
                if (xVelocity < 0)
                {
                    xVelocity = 0;
                }
            }
            else
            {
                xVelocity += adjustment;
                if (xVelocity > 0)
                {
                    xVelocity = 0;
                }
            }
            movementComp->setFloating(gameObj.second, MovementComponent::xVelocity, xVelocity);
        }
        
        auto yVelocity = movementComp->getFloating(gameObj.second, MovementComponent::yVelocity);
        if (yVelocity)
        {
            if (yVelocity > 0)
            {
                yVelocity -= adjustment;
                if (yVelocity < 0)
                {
                    yVelocity = 0;
                }
            }
            else
            {
                yVelocity += adjustment;
                if (yVelocity > 0)
                {
                    yVelocity = 0;
                }
            }
            movementComp->setFloating(gameObj.second, MovementComponent::yVelocity, yVelocity);
        }

        auto zVelocity = movementComp->getFloating(gameObj.second, MovementComponent::zVelocity) - adjustment;
        if (zVelocity > -100.0)
        {
            movementComp->setFloating(gameObj.second, MovementComponent::zVelocity, zVelocity);
        }

        auto positionComp = gameObj.second->getGameComponentFromAbility("GamePosition");
        if (!positionComp)
        {
            continue;
        }
        
        if (xVelocity)
        {
            auto x = positionComp->getFloating(gameObj.second, PositionComponent::x) + xVelocity;
            positionComp->setFloating(gameObj.second, PositionComponent::x, x);
        }
        
        if (yVelocity)
        {
            auto y = positionComp->getFloating(gameObj.second, PositionComponent::y) + yVelocity;
            positionComp->setFloating(gameObj.second, PositionComponent::y, y);
        }
        
        auto z = positionComp->getFloating(gameObj.second, PositionComponent::z) + zVelocity;
        positionComp->setFloating(gameObj.second, PositionComponent::z, z);
    }
}

void MovementSystem::notify (int id, int commandId, const PropertyGroup & commandProperties)
{
    if (id != GameManager::GameCommandSentEventId)
    {
        return;
    }
    
    if (commandId != moveCmd)
    {
        return;
    }
    
    auto targetId = commandProperties.getValue(targetIdName)->getInteger();
    auto propValue = commandProperties.getValue(xVelocityName);
    auto x = propValue ? propValue->getFloating() : 0;
    propValue = commandProperties.getValue(yVelocityName);
    auto y = propValue ? propValue->getFloating() : 0;
    propValue = commandProperties.getValue(zVelocityName);
    auto z = propValue ? propValue->getFloating() : 0;
    
    auto gameObjectMapResult = mGameObjects.find(targetId);
    if (gameObjectMapResult != mGameObjects.end())
    {
        auto movementComp = gameObjectMapResult->second->getGameComponentFromAbility("GameMoveable");
        if (!movementComp)
        {
            return;
        }
        
        if (x)
        {
            auto xVelocityNew = movementComp->getFloating(gameObjectMapResult->second, MovementComponent::xVelocity) + x;
            movementComp->setFloating(gameObjectMapResult->second, MovementComponent::xVelocity, xVelocityNew);
        }
        
        if (y)
        {
            auto yVelocityNew = movementComp->getFloating(gameObjectMapResult->second, MovementComponent::yVelocity) + y;
            movementComp->setFloating(gameObjectMapResult->second, MovementComponent::yVelocity, yVelocityNew);
        }
        
        if (z)
        {
            auto zVelocityNew = movementComp->getFloating(gameObjectMapResult->second, MovementComponent::zVelocity) + z;
            movementComp->setFloating(gameObjectMapResult->second, MovementComponent::zVelocity, zVelocityNew);
        }
    }
}

} // namespace Game
} // namespace TUCUT
