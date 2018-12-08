//
//  PositionComponent.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/5/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_PositionComponent_hpp
#define TUCUT_Game_PositionComponent_hpp

#include <memory>
#include <string>
#include <vector>
    
#include "GameComponent.h"

namespace TUCUT {
namespace Game {

class PositionComponent : public Game::GameComponent
{
public:
    static const std::string defaultToken;
    static constexpr int x = 1;
    static constexpr int y = 2;
    static constexpr int z = 3;
    
    std::shared_ptr<PositionComponent> getSharedPositionComponent ();
    
    void addDefaultProperties (const std::shared_ptr<GameObject> & object) const override;
    
    void removeProperties (const std::shared_ptr<GameObject> & object) const override;

    PropertyValue * getPropertyValue (const std::shared_ptr<GameObject> & object, int propertyId) const override;

protected:
    friend class GameManager;

    static const std::string groupName;
    static const std::string xName;
    static const std::string yName;
    static const std::string zName;

    PositionComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    {
        mAbilityTokens.push_back("GamePosition");
    }
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_PositionComponent_h
