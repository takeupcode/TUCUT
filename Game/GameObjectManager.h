//
//  GameObjectManager.hpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameObjectManager_h
#define TUCUT_Game_GameObjectManager_h

#include <memory>
#include <unordered_map>

#include "GameObject.h"

namespace TUCUT {
namespace Game {

class GameObjectManager
{
public:
    static GameObjectManager * instance ();
    
    void initialize ();
    
    void deinitialize ();
    
    bool addGameObject (const std::string & gameObjectName, const std::shared_ptr<GameObject> & gameObject);
    
    void removeGameObject (const std::string & gameObjectName);
    
    std::shared_ptr<GameObject> getGameObject (const std::string & gameObjectName) const;
    
private:
    using GameObjectMap = std::unordered_map<std::string, std::shared_ptr<GameObject>>;
    
    GameObjectManager () = default;
    
    GameObjectMap mGameObjects;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameObjectManager_h
