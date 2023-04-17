//  MovementComponent.h
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-09.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Game_MovementComponent_h
#define TUCUT_Game_MovementComponent_h

#include "../ECS/Application.h"
#include "IMovementComponent.h"

namespace TUCUT::Game
{
  class MovementComponent : public IMovementComponent
  {
  public:
    static std::string const defaultToken;

    std::shared_ptr<MovementComponent>
    getSharedMovementComponent ();

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

  protected:
    friend class ECS::Application;

    MovementComponent (std::string const & token, int identity)
    : IMovementComponent(token, identity)
    {
      mAbilityTokens.push_back("Moveable");
    }
  };
} // namespace TUCUT::Game

#endif // TUCUT_Game_MovementComponent_h
