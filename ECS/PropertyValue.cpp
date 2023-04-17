//  PropertyValue.cpp
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-07-31.
//  Copyright © Take Up Code, Inc.
//
#include "PropertyValue.h"

#include <stdexcept>

using namespace TUCUT;

std::unique_ptr<ECS::PropertyValue>
ECS::PropertyValue::createStringPropertyValue (
  std::string const & value, bool readOnly)
{
  return std::unique_ptr<PropertyValue>(
    new StringPropertyValue(value, readOnly));
}

std::unique_ptr<ECS::PropertyValue>
ECS::PropertyValue::createIntegerPropertyValue (
  int value, bool readOnly)
{
  return std::unique_ptr<PropertyValue>(
    new IntegerPropertyValue(value, readOnly));
}

std::unique_ptr<ECS::PropertyValue>
ECS::PropertyValue::createFloatingPropertyValue (
  double value, bool readOnly)
{
  return std::unique_ptr<PropertyValue>(
    new FloatingPropertyValue(value, readOnly));
}

std::unique_ptr<ECS::PropertyValue>
ECS::PropertyValue::createBooleanPropertyValue (
  bool value, bool readOnly)
{
  return std::unique_ptr<PropertyValue>(
    new BooleanPropertyValue(value, readOnly));
}

bool ECS::PropertyValue::isString () const
{
  return false;
}

bool ECS::PropertyValue::isInteger () const
{
  return false;
}

bool ECS::PropertyValue::isFloating () const
{
  return false;
}

bool ECS::PropertyValue::isBoolean () const
{
  return false;
}

std::string ECS::PropertyValue::getString () const
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

int ECS::PropertyValue::getInteger () const
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

double ECS::PropertyValue::getFloating () const
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

bool ECS::PropertyValue::getBoolean () const
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

void ECS::PropertyValue::setString (std::string const &)
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

void ECS::PropertyValue::setInteger (int)
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

void ECS::PropertyValue::setFloating (double)
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

void ECS::PropertyValue::setBoolean (bool)
{
  throw std::runtime_error("Wrong type of PropertyValue");
}
