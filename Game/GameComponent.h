//
//  GameComponent.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameComponent_h
#define TUCUT_Game_GameComponent_h

#include <memory>
#include <string>
#include <vector>

#include "../Identity/Identifiable.h"

namespace TUCUT {
namespace Game {

class GameObject;
    
class GameComponent : public std::enable_shared_from_this<GameComponent>, public Identity::Identifiable<int>
{
public:
    std::shared_ptr<GameComponent> getSharedGameComponent ();
    
    virtual ~GameComponent () = default;
    
    bool hasRequiredComponents (int objectId) const;
    bool hasRequiredComponents (const std::shared_ptr<GameObject> & object) const;

protected:
    friend class GameManager;
    
    GameComponent (const std::string & token, int identity)
    : Identifiable(token, identity)
    { }
    
    virtual void initialize ();
    
    virtual bool hasRequiredComponentsCallback (const std::shared_ptr<GameObject> & object) const;
    
    std::vector<std::string> mRequiredComponentTokens;

private:
    bool hasRequiredComponentsImpl (const std::shared_ptr<GameObject> & object, bool checkObject) const;
};
    
} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameComponent_h
