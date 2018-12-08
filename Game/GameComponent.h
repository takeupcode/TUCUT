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

#include "PropertyValue.h"
#include "../Identity/Identifiable.h"

namespace TUCUT {
namespace Game {

class GameObject;
    
class GameComponent : public std::enable_shared_from_this<GameComponent>, public Identity::Identifiable<int>
{
public:
    static const std::string defaultToken;
    
    std::shared_ptr<GameComponent> getSharedGameComponent ();
    
    virtual ~GameComponent () = default;
    
    virtual std::vector<std::string> getAbilities () const
    {
        return mAbilityTokens;
    }
    
    virtual void addDefaultProperties (int objectId) const;
    virtual void addDefaultProperties (const std::shared_ptr<GameObject> & object) const;
    
    virtual void removeProperties (int objectId) const;
    virtual void removeProperties (const std::shared_ptr<GameObject> & object) const;

    virtual PropertyValue * getPropertyValue (int objectId, int propertyId) const;
    virtual PropertyValue * getPropertyValue (const std::shared_ptr<GameObject> & object, int propertyId) const;
    
protected:
    friend class GameManager;
    
    GameComponent (const std::string & token, int identity)
    : Identifiable(token, identity)
    { }
    
    virtual void initialize ();
    
    std::vector<std::string> mAbilityTokens;
};
    
} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameComponent_h
