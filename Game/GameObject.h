//
//  GameObject.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameObject_h
#define TUCUT_Game_GameObject_h

#include <memory>
#include <string>

#include "GameComponent.h"
#include "PropertyContainer.h"

#include "../Identity/Identifiable.h"

namespace TUCUT {
namespace Game {

class GameObject : public std::enable_shared_from_this<GameObject>, public Identity::Identifiable<int>
{
public:
    std::shared_ptr<GameObject> getSharedGameObject ();
    
    virtual ~GameObject () = default;
    
    PropertyContainer & properties ()
    {
        return mProperties;
    }
    
    const PropertyContainer & properties () const
    {
        return mProperties;
    }
    
    bool hasGameComponent (int componentId) const;
    bool hasGameComponent (const std::shared_ptr<GameComponent> & component) const;

    bool addGameComponent (int componentId);
    bool addGameComponent (const std::shared_ptr<GameComponent> & component);
    
    void removeGameComponent (int componentId);
    void removeGameComponent (const std::shared_ptr<GameComponent> & component);

protected:
    friend class GameManager;
    
    static std::shared_ptr<GameObject> createSharedGameObject (std::string token, int identity);
    
    GameObject (std::string token, int identity)
    : Identifiable(token, identity)
    { }
    
    virtual void initialize ();
    
private:
    using ComponentVector = std::vector<bool>;
    
    PropertyContainer mProperties;
    ComponentVector mComponents;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameObject_h
