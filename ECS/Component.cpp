//  Component.cpp
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-11-15.
//  Copyright © Take Up Code, Inc.
//
#include "Component.h"

#include "Application.h"

std::string const
TUCUT::ECS::Component::defaultToken = "Component";

void TUCUT::ECS::Component::initialize ()
{
  Application * app = Application::instance();
  for (auto const & token: mAbilityTokens)
  {
    app->getOrCreateAbility(token);
  }
  for (auto const & token: mActionTokens)
  {
    app->getOrCreateAction(token);
  }
}

std::shared_ptr<TUCUT::ECS::Component>
TUCUT::ECS::Component::getSharedComponent ()
{
  return shared_from_this();
}

void TUCUT::ECS::Component::addDefaultProperties (
  int entityId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return addDefaultProperties(entity);
}

void TUCUT::ECS::Component::addDefaultProperties (
  std::shared_ptr<Entity> const &) const
{ }

void TUCUT::ECS::Component::removeProperties (
  int entityId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return removeProperties(entity);
}

void TUCUT::ECS::Component::removeProperties (
  std::shared_ptr<Entity> const &) const
{ }

std::string TUCUT::ECS::Component::getString (
  int entityId, int propertyId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return getString(entity, propertyId);
}

std::string TUCUT::ECS::Component::getString (
  std::shared_ptr<Entity> const &, int) const
{
  return "";
}

int TUCUT::ECS::Component::getInteger (
  int entityId, int propertyId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return getInteger(entity, propertyId);
}

int TUCUT::ECS::Component::getInteger (
  std::shared_ptr<Entity> const &, int) const
{
    return 0;
}

double TUCUT::ECS::Component::getFloating (
  int entityId, int propertyId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return getFloating(entity, propertyId);
}

double TUCUT::ECS::Component::getFloating (
  std::shared_ptr<Entity> const &, int) const
{
  return 0;
}

bool TUCUT::ECS::Component::getBoolean (
  int entityId, int propertyId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return getBoolean(entity, propertyId);
}

bool TUCUT::ECS::Component::getBoolean (
  std::shared_ptr<Entity> const &, int) const
{
  return false;
}

std::vector<std::string> TUCUT::ECS::Component::getStrings (
  int entityId, int propertyId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return getStrings(entity, propertyId);
}

std::vector<std::string> TUCUT::ECS::Component::getStrings (
  std::shared_ptr<Entity> const &, int) const
{
  return std::vector<std::string>();
}

std::vector<int> TUCUT::ECS::Component::getIntegers (
  int entityId, int propertyId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return getIntegers(entity, propertyId);
}

std::vector<int> TUCUT::ECS::Component::getIntegers (
  std::shared_ptr<Entity> const &, int) const
{
  return std::vector<int>();
}

std::vector<double> TUCUT::ECS::Component::getFloatings (
  int entityId, int propertyId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return getFloatings(entity, propertyId);
}

std::vector<double> TUCUT::ECS::Component::getFloatings (
  std::shared_ptr<Entity> const &, int) const
{
  return std::vector<double>();
}

std::vector<bool> TUCUT::ECS::Component::getBooleans (
  int entityId, int propertyId) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  return getBooleans(entity, propertyId);
}

std::vector<bool> TUCUT::ECS::Component::getBooleans (
  std::shared_ptr<Entity> const &, int) const
{
  return std::vector<bool>();
}

void TUCUT::ECS::Component::setString (
  int entityId,
  int propertyId,
  std::string const & value) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  setString(entity, propertyId, value);
}

void TUCUT::ECS::Component::setString (
  std::shared_ptr<Entity> const &,
  int,
  std::string const &) const
{ }

void TUCUT::ECS::Component::setInteger (
  int entityId,
  int propertyId,
  int value) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  setInteger(entity, propertyId, value);
}

void TUCUT::ECS::Component::setInteger (
  std::shared_ptr<Entity> const &,
  int,
  int) const
{ }

void TUCUT::ECS::Component::setFloating (
  int entityId,
  int propertyId,
  double value) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  setFloating(entity, propertyId, value);
}

void TUCUT::ECS::Component::setFloating (
  std::shared_ptr<Entity> const &,
  int,
  double) const
{ }

void TUCUT::ECS::Component::setBoolean (
  int entityId,
  int propertyId,
  bool value) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  setBoolean(entity, propertyId, value);
}

void TUCUT::ECS::Component::setBoolean (
  std::shared_ptr<Entity> const &,
  int,
  bool) const
{ }

void TUCUT::ECS::Component::setStrings (
  int entityId,
  int propertyId,
  std::vector<std::string> const & value) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  setStrings(entity, propertyId, value);
}

void TUCUT::ECS::Component::setStrings (
  std::shared_ptr<Entity> const &,
  int,
  std::vector<std::string> const &) const
{ }

void TUCUT::ECS::Component::setIntegers (
  int entityId,
  int propertyId,
  std::vector<int> const & value) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  setIntegers(entity, propertyId, value);
}

void TUCUT::ECS::Component::setIntegers (
  std::shared_ptr<Entity> const &,
  int,
  std::vector<int> const &) const
{ }

void TUCUT::ECS::Component::setFloatings (
  int entityId,
  int propertyId,
  std::vector<double> const & value) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  setFloatings(entity, propertyId, value);
}

void TUCUT::ECS::Component::setFloatings (
  std::shared_ptr<Entity> const &,
  int,
  std::vector<double> const &) const
{ }

void TUCUT::ECS::Component::setBooleans (
  int entityId,
  int propertyId,
  std::vector<bool> const & value) const
{
  Application * app = Application::instance();
  auto entity = app->getBaseEntity(entityId);

  setBooleans(entity, propertyId, value);
}

void TUCUT::ECS::Component::setBooleans (
  std::shared_ptr<Entity> const &,
  int,
  std::vector<bool> const &) const
{ }
