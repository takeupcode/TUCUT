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
    
#include "GameManager.h"
#include "IPositionComponent.h"
#include "../Math/Vector.h"

namespace TUCUT {
namespace Game {

class PositionComponent : public IPositionComponent
{
public:
    static const std::string defaultToken;

    std::shared_ptr<PositionComponent> getSharedPositionComponent ();
    
    void addDefaultProperties (const std::shared_ptr<GameObject> & object) const override;
    
    void removeProperties (const std::shared_ptr<GameObject> & object) const override;

    double getFloating (const std::shared_ptr<GameObject> & object, int propertyId) const override;

    std::vector<double> getFloatings (const std::shared_ptr<GameObject> & object, int propertyId) const override;

    void setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const override;

    void setFloatings (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<double> & value) const override;

    void setMinPosition (const Math::Vector3d & position);
    
    void setMaxPosition (const Math::Vector3d & position);

protected:
    friend class GameManager;

    PositionComponent (const std::string & token, int identity)
    : IPositionComponent(token, identity)
    {
        mAbilityTokens.push_back("GamePosition");
        
        mActionTokens.push_back(positionChangedToken);
    }
    
    void initialize () override;

private:
    Math::Vector3d mMinPosition;
    Math::Vector3d mMaxPosition;
    int mPositionChangedActionId = 0;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_PositionComponent_h
