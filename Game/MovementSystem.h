//
//  MovementSystem.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/10/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_MovementSystem_h
#define TUCUT_Game_MovementSystem_h

#include "GameManager.h"
#include "GameSystem.h"

namespace TUCUT {
namespace Game {

class MovementSystem : public Game::GameSystem
{
public:
    static const std::string defaultToken;
    static constexpr int moveCmd = 1;
    
    std::shared_ptr<MovementSystem> getSharedMovementSystem ()
    {
        return std::static_pointer_cast<MovementSystem>(shared_from_this());
    }
    
    bool isInstantMode () const;
    
    void setInstantMode (bool instant);
    
protected:
    friend class Game::GameManager;
    
    static const std::string targetIdName;
    static const std::string xVelocityName;
    static const std::string yVelocityName;
    static const std::string zVelocityName;

    MovementSystem (const std::string & token, int identity)
    : GameSystem(token, identity), mInstantMode(false)
    {
        mRequiredAbilityTokens.push_back("GameMoveable");
        mRequiredAbilityTokens.push_back("GamePosition");
        
        mRequiredCommandTokens.push_back("GameMove");
    }

    void update (TimeResolution elapsedTime) override;

    void notify (int id, int commandId, const PropertyGroup & commandProperties) override;
    
private:
    bool mInstantMode;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_MovementSystem_h
