//
//  GameObject.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameObject_hpp
#define TUCUT_Game_GameObject_hpp

#include <memory>

#include "PropertyContainer.h"

#include "../Identity/Identifiable.h"

namespace TUCUT {
namespace Game {

class GameObject : public std::enable_shared_from_this<GameObject>, public Identity::Identifiable<int>
{
public:
    static std::shared_ptr<GameObject> createSharedGameObject (std::string token, int identity);
    
    std::shared_ptr<GameObject> getSharedGameObject ();
    
    virtual ~GameObject () = default;
    
    PropertyContainer & properties ();
    
protected:
    GameObject (std::string token, int identity)
    : Identifiable(token, identity)
    { }
    
    virtual void initialize ();
    
private:
    PropertyContainer mProperties;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameObject_h
