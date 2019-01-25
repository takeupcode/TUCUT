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
#include "../Math/Adjust.h"

namespace TUCUT {
namespace Game {

const std::string MovementSystem::defaultToken = "MovementSystem";
    
bool MovementSystem::isInstantMode () const
{
    return mInstantMode;
}

void MovementSystem::setInstantMode (bool instant)
{
    mInstantMode = instant;
}

void MovementSystem::update (TimeResolution elapsedTime)
{
    TimeInSeconds seconds = elapsedTime;
    double friction = 10.0 * seconds.count();
    
    for (const auto & gameObj: mGameObjects)
    {
        auto movementComp = gameObj.second->getGameComponentFromAbility("GameMoveable");
        if (!movementComp)
        {
            continue;
        }

        auto xAcceleration = movementComp->getFloating(gameObj.second, MovementComponent::xAcceleration);
        auto xVelocity = movementComp->getFloating(gameObj.second, MovementComponent::xVelocity);
        if (xAcceleration || xVelocity)
        {
            auto xVelocityMax = movementComp->getFloating(gameObj.second, MovementComponent::xVelocityMax);
            
            if (isInstantMode())
            {
                xVelocity += xAcceleration;
                xVelocity = Math::clamp(-xVelocityMax, xVelocityMax, xVelocity);
                
                movementComp->setFloating(gameObj.second, MovementComponent::xAcceleration, 0);
                movementComp->setFloating(gameObj.second, MovementComponent::xVelocity, 0);
            }
            else
            {
                xVelocity += xAcceleration * seconds.count();
                xVelocity = Math::toZero(friction, xVelocity);
                xVelocity = Math::clamp(-xVelocityMax, xVelocityMax, xVelocity);
                
                movementComp->setFloating(gameObj.second, MovementComponent::xVelocity, xVelocity);
            }
        }
        
        auto yAcceleration = movementComp->getFloating(gameObj.second, MovementComponent::yAcceleration);
        auto yVelocity = movementComp->getFloating(gameObj.second, MovementComponent::yVelocity);
        if (yAcceleration || yVelocity)
        {
            auto yVelocityMax = movementComp->getFloating(gameObj.second, MovementComponent::yVelocityMax);
            
            if (isInstantMode())
            {
                yVelocity += yAcceleration;
                yVelocity = Math::clamp(-yVelocityMax, yVelocityMax, yVelocity);
                
                movementComp->setFloating(gameObj.second, MovementComponent::yAcceleration, 0);
                movementComp->setFloating(gameObj.second, MovementComponent::yVelocity, 0);
            }
            else
            {
                yVelocity += yAcceleration * seconds.count();
                yVelocity = Math::toZero(friction, yVelocity);
                yVelocity = Math::clamp(-yVelocityMax, yVelocityMax, yVelocity);
                
                movementComp->setFloating(gameObj.second, MovementComponent::yVelocity, yVelocity);
            }
        }

        auto zAcceleration = movementComp->getFloating(gameObj.second, MovementComponent::zAcceleration);
        auto zVelocity = movementComp->getFloating(gameObj.second, MovementComponent::zVelocity);
        if (zAcceleration || zVelocity)
        {
            auto zVelocityMax = movementComp->getFloating(gameObj.second, MovementComponent::zVelocityMax);
            
            zVelocity += zAcceleration * seconds.count();
            zVelocity = Math::clamp(-zVelocityMax, zVelocityMax, zVelocity);

            movementComp->setFloating(gameObj.second, MovementComponent::zVelocity, zVelocity);
        }

        if (xVelocity || yVelocity || zVelocity)
        {
            auto positionComp = gameObj.second->getGameComponentFromAbility("GamePosition");
            if (!positionComp)
            {
                continue;
            }
            
            std::vector<double> positions;
            
            auto x = positionComp->getFloating(gameObj.second, PositionComponent::x);
            x += isInstantMode() ? xVelocity : xVelocity * seconds.count();
            positions.push_back(x);

            auto y = positionComp->getFloating(gameObj.second, PositionComponent::y);
            y += isInstantMode() ? yVelocity : yVelocity * seconds.count();
            positions.push_back(y);

            auto z = positionComp->getFloating(gameObj.second, PositionComponent::z);
            z += zVelocity * seconds.count();
            positions.push_back(z);

            // Set all three position coordinates at once so the position component can
            // queue a single moved action.
            positionComp->setFloatings(gameObj.second, PositionComponent::xyz, positions);
        }
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
    auto propValue = commandProperties.getValue(xAccelerationName);
    auto xAcceleration = propValue ? propValue->getFloating() : 0;
    propValue = commandProperties.getValue(yAccelerationName);
    auto yAcceleration = propValue ? propValue->getFloating() : 0;
    propValue = commandProperties.getValue(zAccelerationName);
    auto zAcceleration = propValue ? propValue->getFloating() : 0;
    
    auto gameObjectMapResult = mGameObjects.find(targetId);
    if (gameObjectMapResult != mGameObjects.end())
    {
        auto movementComp = gameObjectMapResult->second->getGameComponentFromAbility("GameMoveable");
        if (!movementComp)
        {
            return;
        }
        
        if (xAcceleration)
        {
            movementComp->setFloating(gameObjectMapResult->second, MovementComponent::xAcceleration, xAcceleration);
        }
        
        if (yAcceleration)
        {
            movementComp->setFloating(gameObjectMapResult->second, MovementComponent::yAcceleration, yAcceleration);
        }
        
        if (zAcceleration)
        {
            movementComp->setFloating(gameObjectMapResult->second, MovementComponent::zAcceleration, zAcceleration);
        }
    }
}

} // namespace Game
} // namespace TUCUT
