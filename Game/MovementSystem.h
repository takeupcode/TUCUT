//  MovementSystem.h
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-10.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Game_MovementSystem_h
#define TUCUT_Game_MovementSystem_h

#include "../ECS/Application.h"
#include "../ECS/ApplicationTime.h"
#include "IMovementSystem.h"

namespace TUCUT::Game
{
  class Region;

  class MovementSystem : public IMovementSystem
  {
  public:
    static std::string const defaultToken;

    std::shared_ptr<MovementSystem> getSharedMovementSystem ()
    {
      return std::static_pointer_cast<MovementSystem>(
        shared_from_this());
    }

    bool isInstantMode () const;

    void setInstantMode (bool instant);

    std::shared_ptr<Region> region ();

    void setRegion (std::shared_ptr<Region> region);

  protected:
    friend class ECS::Application;

    MovementSystem (std::string const & token, int identity)
    : IMovementSystem(token, identity), mInstantMode(false)
    {
      mRequiredAbilityTokens.push_back("Moveable");
      mRequiredAbilityTokens.push_back("Position");

      mRequiredCommandTokens.push_back("Move");
    }

    void update (ECS::TimeResolution elapsedTime) override;

    void notify (int id,
      int commandId,
      PropertyGroup const & commandProperties) override;

  private:
    bool mInstantMode;
    std::shared_ptr<Region> mRegion;
  };
} // namespace TUCUT::Game

#endif // TUCUT_Game_MovementSystem_h
