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
#include "IMovementSystem.h"

namespace TUCUT {
namespace Game {

class GameRegion;
    
class MovementSystem : public IMovementSystem
{
public:
    static const std::string defaultToken;
    
    std::shared_ptr<MovementSystem> getSharedMovementSystem ()
    {
        return std::static_pointer_cast<MovementSystem>(shared_from_this());
    }
    
    bool isInstantMode () const;
    
    void setInstantMode (bool instant);
    
    std::shared_ptr<GameRegion> region ();
    
    void setRegion (std::shared_ptr<GameRegion> region);
    
protected:
    friend class Game::GameManager;

    MovementSystem (const std::string & token, int identity)
    : IMovementSystem(token, identity), mInstantMode(false)
    {
        mRequiredAbilityTokens.push_back("GameMoveable");
        mRequiredAbilityTokens.push_back("GamePosition");
        
        mRequiredCommandTokens.push_back("GameMove");
    }

    void update (TimeResolution elapsedTime) override;

    void notify (int id, int commandId, const PropertyGroup & commandProperties) override;
    
private:
    bool mInstantMode;
    std::shared_ptr<GameRegion> mRegion;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_MovementSystem_h
