//
//  MovementComponent.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/9/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_MovementComponent_h
#define TUCUT_Game_MovementComponent_h

#include "GameManager.h"
#include "GameComponent.h"

namespace TUCUT {
namespace Game {

class MovementComponent : public Game::GameComponent
{
public:
    static const std::string defaultToken;
    static constexpr int xVelocity = 1;
    static constexpr int yVelocity = 2;
    static constexpr int zVelocity = 3;
    
    std::shared_ptr<MovementComponent> getSharedMovementComponent ();
    
    void addDefaultProperties (const std::shared_ptr<GameObject> & object) const override;
    
    void removeProperties (const std::shared_ptr<GameObject> & object) const override;
    
    double getFloating (const std::shared_ptr<GameObject> & object, int propertyId) const override;
    
    void setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const override;
    
protected:
    friend class GameManager;
    
    static const std::string groupName;
    static const std::string xVelocityName;
    static const std::string yVelocityName;
    static const std::string zVelocityName;
    
    MovementComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    {
        mAbilityTokens.push_back("GameMoveable");
    }
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_MovementComponent_h
