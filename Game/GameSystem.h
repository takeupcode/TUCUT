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
#include "GameTime.h"
#include "../Identity/Identifiable.h"
#include "../Event/EventSubscriber.h"

namespace TUCUT {
namespace Game {

class GameSystem : public std::enable_shared_from_this<GameSystem>, public Identity::Identifiable<int>,
    public Event::EventSubscriber<const std::shared_ptr<GameObject> &>,
    public Event::EventSubscriber<int, const PropertyGroup &>
{
public:
    static const std::string defaultToken;

    std::shared_ptr<GameSystem> getSharedGameSystem ();

    virtual ~GameSystem () = default;

    bool hasGameObject (int identity) const;

protected:
    friend class GameManager;

    using GameObjectMap = std::unordered_map<int, std::shared_ptr<GameObject>>;

    GameSystem (const std::string & token, int identity)
    : Identifiable(token, identity)
    { }

    virtual void initialize ();

    virtual void handleInput ()
    { }

    virtual void update (TimeResolution)
    { }

    virtual void render ()
    { }

    virtual void onAction (int, int)
    { }

    void notify (int id, const std::shared_ptr<GameObject> & gameObject) override;

    void notify (int id, int commandId, const PropertyGroup & commandProperties) override;

    GameObjectMap mGameObjects;
    std::vector<std::string> mRequiredAbilityTokens;
    std::vector<std::string> mRequiredCommandTokens;
    std::vector<std::string> mActionTokens;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameSystem_h
