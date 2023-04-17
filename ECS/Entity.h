//  Entity.h
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-08-19.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_ECS_Entity_h
#define TUCUT_ECS_Entity_h

#include "../Identity/Identifiable.h"
#include "PropertyContainer.h"

#include <memory>
#include <string>

namespace TUCUT::ECS
{
  class Component;

  class Entity : public std::enable_shared_from_this<Entity>,
    public Identity::Identifiable<int>
  {
  public:
    static std::string const defaultToken;

    std::shared_ptr<Entity> getSharedEntity ();

    virtual ~Entity () = default;

    PropertyContainer & properties ()
    {
      return mProperties;
    }

    PropertyContainer const & properties () const
    {
      return mProperties;
    }

    bool hasComponent (int componentId) const;
    bool hasComponent (
      std::shared_ptr<Component> const & component) const;

    bool addComponent (int componentId);
    bool addComponent (
      std::shared_ptr<Component> const & component);

    void removeComponent (int componentId);
    void removeComponent (
      std::shared_ptr<Component> const & component);

    bool hasAbility (int abilityId) const;
    bool hasAbility (std::string const & token) const;

    std::shared_ptr<Component> getComponentFromAbility (
      int abilityId) const;
    std::shared_ptr<Component> getComponentFromAbility (
      std::string const & token) const;

  protected:
    friend class Application;

    Entity (std::string const & token, int identity)
    : Identifiable(token, identity)
    { }

    virtual void initialize ();

  private:
    using ComponentBoolVector = std::vector<bool>;
    using ComponentPtrVector =
      std::vector<std::shared_ptr<Component>>;
    using AbilityVector = std::vector<ComponentPtrVector>;

    PropertyContainer mProperties;
    ComponentBoolVector mComponents;
    AbilityVector mAbilities;
  };
} // namespace TUCUT::ECS

#endif // TUCUT_ECS_Entity_h
