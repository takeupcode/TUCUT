//  PositionComponent.h
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-05.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Game_PositionComponent_hpp
#define TUCUT_Game_PositionComponent_hpp

#include "../ECS/Application.h"
#include "../Math/Vector.h"
#include "IPositionComponent.h"

#include <memory>
#include <string>
#include <vector>

namespace TUCUT::Game
{
  class PositionComponent : public IPositionComponent
  {
  public:
    static std::string const defaultToken;

    std::shared_ptr<PositionComponent>
    getSharedPositionComponent ();

    void addDefaultProperties (
      std::shared_ptr<GameObject> const & object
      ) const override;

    void removeProperties (
      std::shared_ptr<GameObject> const & object
      ) const override;

    double getFloating (
      std::shared_ptr<GameObject> const & object,
      int propertyId
      ) const override;

    std::vector<double> getFloatings (
      std::shared_ptr<GameObject> const & object,
      int propertyId
      ) const override;

    void setFloating (
      std::shared_ptr<GameObject> const & object,
      int propertyId,
      double value
      ) const override;

    void setFloatings (
      std::shared_ptr<GameObject> const & object,
      int propertyId,
      std::vector<double> const & value
      ) const override;

    void setMinPosition (Math::Vector3d const & position);

    void setMaxPosition (Math::Vector3d const & position);

  protected:
    friend class ECS::Application;

    PositionComponent (std::string const & token, int identity)
    : IPositionComponent(token, identity)
    {
      mAbilityTokens.push_back("Position");

      mActionTokens.push_back(positionChangedToken);
    }

    void initialize () override;

  private:
    Math::Vector3d mMinPosition;
    Math::Vector3d mMaxPosition;
    int mPositionChangedActionId = 0;
  };
} // namespace TUCUT::Game

#endif // TUCUT_Game_PositionComponent_h
