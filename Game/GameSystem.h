//
//  GameSystem.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/27/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameSystem_h
#define TUCUT_Game_GameSystem_h

#include <memory>
#include <string>

#include "../Identity/Identifiable.h"

namespace TUCUT {
namespace Game {
    
class GameSystem : public std::enable_shared_from_this<GameSystem>, public Identity::Identifiable<int>
{
public:
    std::shared_ptr<GameSystem> getSharedGameSystem ();
    
    virtual ~GameSystem () = default;
    
    virtual void update ()
    { }
    
    virtual void onAction (int objectId, int actionId)
    { }

protected:
    friend class GameManager;
    
    static std::shared_ptr<GameSystem> createSharedGameSystem (std::string token, int identity);
    
    GameSystem (const std::string & token, int identity)
    : Identifiable(token, identity)
    { }
    
    virtual void initialize ();
};
    
} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameSystem_h
