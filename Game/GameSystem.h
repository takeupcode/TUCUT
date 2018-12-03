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
#include <vector>

#include "GameObject.h"
#include "../Identity/Identifiable.h"
#include "../Event/EventSubscriber.h"

namespace TUCUT {
namespace Game {
    
class GameSystem : public std::enable_shared_from_this<GameSystem>, public Identity::Identifiable<int>,
    public Event::EventSubscriber<const std::shared_ptr<GameObject> &>
{
public:
    std::shared_ptr<GameSystem> getSharedGameSystem ();
    
    virtual ~GameSystem () = default;

    bool hasGameObject (int identity) const;

protected:
    friend class GameManager;
    
    GameSystem (const std::string & token, int identity)
    : Identifiable(token, identity)
    { }
    
    virtual void initialize ();

    virtual void update ()
    { }
    
    virtual void onAction (int objectId, int actionId)
    { }

    void notify (int id, const std::shared_ptr<GameObject> & gameObject) override;
    
    std::vector<std::string> mRequiredAbilityTokens;

private:
    using GameObjectMap = std::unordered_map<int, std::shared_ptr<GameObject>>;
    
    GameObjectMap mGameObjects;
};
    
} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameSystem_h
