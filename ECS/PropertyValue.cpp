//  PropertyValue.cpp
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-07-31.
//  Copyright © Take Up Code, Inc.
//
#include "PropertyValue.h"

#include <stdexcept>

std::unique_ptr<TUCUT::ECS::PropertyValue>
TUCUT::ECS::PropertyValue::createStringPropertyValue (
  std::string const & value, bool readOnly)
{
  return std::unique_ptr<PropertyValue>(
    new StringPropertyValue(value, readOnly));
}

std::unique_ptr<TUCUT::ECS::PropertyValue>
TUCUT::ECS::PropertyValue::createIntegerPropertyValue (
  int value, bool readOnly)
{
  return std::unique_ptr<PropertyValue>(
    new IntegerPropertyValue(value, readOnly));
}

std::unique_ptr<TUCUT::ECS::PropertyValue>
TUCUT::ECS::PropertyValue::createFloatingPropertyValue (
  double value, bool readOnly)
{
  return std::unique_ptr<PropertyValue>(
    new FloatingPropertyValue(value, readOnly));
}

std::unique_ptr<TUCUT::ECS::PropertyValue>
TUCUT::ECS::PropertyValue::createBooleanPropertyValue (
  bool value, bool readOnly)
{
  return std::unique_ptr<PropertyValue>(
    new BooleanPropertyValue(value, readOnly));
}

bool TUCUT::ECS::PropertyValue::isString () const
{
  return false;
}

bool TUCUT::ECS::PropertyValue::isInteger () const
{
  return false;
}

bool TUCUT::ECS::PropertyValue::isFloating () const
{
  return false;
}

bool TUCUT::ECS::PropertyValue::isBoolean () const
{
  return false;
}

std::string TUCUT::ECS::PropertyValue::getString () const
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

int TUCUT::ECS::PropertyValue::getInteger () const
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

double TUCUT::ECS::PropertyValue::getFloating () const
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

bool TUCUT::ECS::PropertyValue::getBoolean () const
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

void TUCUT::ECS::PropertyValue::setString (std::string const &)
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

void TUCUT::ECS::PropertyValue::setInteger (int)
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

void TUCUT::ECS::PropertyValue::setFloating (double)
{
  throw std::runtime_error("Wrong type of PropertyValue");
}

void TUCUT::ECS::PropertyValue::setBoolean (bool)
{
  throw std::runtime_error("Wrong type of PropertyValue");
}
