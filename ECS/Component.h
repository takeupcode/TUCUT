//  Component.h
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-11-15.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_ECS_Component_h
#define TUCUT_ECS_Component_h

#include "../Identity/Identifiable.h"
#include "PropertyValue.h"

#include <memory>
#include <string>
#include <vector>

namespace TUCUT::ECS
{
  class Entity;

  class Component :
    public std::enable_shared_from_this<Component>,
    public Identity::Identifiable<int>
  {
  public:
    static std::string const defaultToken;

    std::shared_ptr<Component> getSharedComponent ();

    virtual ~Component () = default;

    virtual std::vector<std::string> getAbilities () const
    {
        return mAbilityTokens;
    }

    virtual void addDefaultProperties (int entityId) const;
    virtual void addDefaultProperties (
      std::shared_ptr<Entity> const & entity) const;

    virtual void removeProperties (int entityId) const;
    virtual void removeProperties (
      std::shared_ptr<Entity> const & entity) const;

    virtual std::string getString (
      int entityId, int propertyId) const;
    virtual std::string getString (
      std::shared_ptr<Entity> const & entity,
      int propertyId) const;

    virtual int getInteger (
      int entityId, int propertyId) const;
    virtual int getInteger (
      std::shared_ptr<Entity> const & entity,
      int propertyId) const;

    virtual double getFloating (
      int entityId, int propertyId) const;
    virtual double getFloating (
      std::shared_ptr<Entity> const & entity,
      int propertyId) const;

    virtual bool getBoolean (
      int entityId, int propertyId) const;
    virtual bool getBoolean (
      std::shared_ptr<Entity> const & entity,
      int propertyId) const;

    virtual std::vector<std::string> getStrings (
      int entityId, int propertyId) const;
    virtual std::vector<std::string> getStrings (
      std::shared_ptr<Entity> const & entity,
      int propertyId) const;

    virtual std::vector<int> getIntegers (
      int entityId, int propertyId) const;
    virtual std::vector<int> getIntegers (
      std::shared_ptr<Entity> const & entity,
      int propertyId) const;

    virtual std::vector<double> getFloatings (
      int entityId, int propertyId) const;
    virtual std::vector<double> getFloatings (
      std::shared_ptr<Entity> const & entity,
      int propertyId) const;

    virtual std::vector<bool> getBooleans (
      int entityId, int propertyId) const;
    virtual std::vector<bool> getBooleans (
      std::shared_ptr<Entity> const & entity,
      int propertyId) const;

    virtual void setString (
      int entityId,
      int propertyId,
      std::string const & value) const;
    virtual void setString (
      std::shared_ptr<Entity> const & entity,
      int propertyId,
      std::string const & value) const;

    virtual void setInteger (
      int entityId,
      int propertyId,
      int value) const;
    virtual void setInteger (
      std::shared_ptr<Entity> const & entity,
      int propertyId,
      int value) const;

    virtual void setFloating (
      int entityId,
      int propertyId,
      double value) const;
    virtual void setFloating (
      std::shared_ptr<Entity> const & entity,
      int propertyId,
      double value) const;

    virtual void setBoolean (
      int entityId,
      int propertyId,
      bool value) const;
    virtual void setBoolean (
      std::shared_ptr<Entity> const & entity,
      int propertyId,
      bool value) const;

    virtual void setStrings (
      int entityId,
      int propertyId,
      std::vector<std::string> const & value) const;
    virtual void setStrings (
      std::shared_ptr<Entity> const & entity,
      int propertyId,
      std::vector<std::string> const & value) const;

    virtual void setIntegers (
      int entityId,
      int propertyId,
      std::vector<int> const & value) const;
    virtual void setIntegers (
      std::shared_ptr<Entity> const & entity,
      int propertyId,
      std::vector<int> const & value) const;

    virtual void setFloatings (
      int entityId,
      int propertyId,
      std::vector<double> const & value) const;
    virtual void setFloatings (
      std::shared_ptr<Entity> const & entity,
      int propertyId,
      std::vector<double> const & value) const;

    virtual void setBooleans (
      int entityId,
      int propertyId,
      std::vector<bool> const & value) const;
    virtual void setBooleans (
      std::shared_ptr<Entity> const & entity,
      int propertyId,
      std::vector<bool> const & value) const;

  protected:
    friend class Application;

    Component (std::string const & token, int identity)
    : Identifiable(token, identity)
    { }

    virtual void initialize ();

    std::vector<std::string> mAbilityTokens;
    std::vector<std::string> mActionTokens;
  };
} // namespace TUCUT::ECS

#endif // TUCUT_ECS_Component_h
