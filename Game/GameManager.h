//
//  GameManager.hpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameManager_h
#define TUCUT_Game_GameManager_h

#include <memory>
#include <unordered_map>

#include "GameObject.h"

namespace TUCUT {
namespace Game {

class GameManager
{
public:
    static GameManager * instance ();
    
    void initialize ();
    
    void deinitialize ();
    
    bool registerGameObjectToken (const std::string & token);
    
    std::shared_ptr<GameObject> createGameObject (const std::string & token);
    
    void removeGameObject (const std::string & token, int identity);
    
    std::shared_ptr<GameObject> getGameObject (const std::string & token, int identity) const;
    
private:
    using GameObjectMap = std::unordered_map<int, std::shared_ptr<GameObject>>;
    using GameObjectTokenMap = std::unordered_map<std::string, std::unique_ptr<GameObjectMap>>;

    GameManager ()
    : mNextId(1)
    { }

    GameObjectMap * getGameObjectMap (const std::string & token);
    const GameObjectMap * getGameObjectMap (const std::string & token) const;

    int mNextId;
    GameObjectTokenMap mGameObjects;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameManager_h
