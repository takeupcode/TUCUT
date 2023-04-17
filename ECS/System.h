//  System.h
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-11-27.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_ECS_System_h
#define TUCUT_ECS_System_h

#include "../Event/EventSubscriber.h"
#include "../Identity/Identifiable.h"
#include "ApplicationTime.h"
#include "Entity.h"

#include <memory>
#include <string>
#include <vector>

namespace TUCUT::ECS
{
  class System : public std::enable_shared_from_this<System>,
    public Identity::Identifiable<int>,
    public Event::EventSubscriber<
      std::shared_ptr<Entity> const &>,
    public Event::EventSubscriber<int, PropertyGroup const &>
  {
  public:
    static std::string const defaultToken;

    std::shared_ptr<System> getSharedSystem ();

    virtual ~System () = default;

    bool hasEntity (int identity) const;

  protected:
    friend class Application;

    using EntityMap =
      std::unordered_map<int, std::shared_ptr<Entity>>;

    System (std::string const & token, int identity)
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

    void notify (int id,
      std::shared_ptr<Entity> const & entity) override;

    void notify (int id,
      int commandId,
      PropertyGroup const & commandProperties) override;

    EntityMap mEntities;
    std::vector<std::string> mRequiredAbilityTokens;
    std::vector<std::string> mRequiredCommandTokens;
    std::vector<std::string> mActionTokens;
  };
} // namespace TUCUT::ECS

#endif // TUCUT_ECS_System_h
