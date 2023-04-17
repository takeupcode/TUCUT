//  IPositionComponent.cpp
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-15.
//  Copyright © Take Up Code, Inc.
//
#include "IPositionComponent.h"

namespace TUCUT::Game
{
  std::string const
    IPositionComponent::groupName = "Position";
  std::string const
    IPositionComponent::xyzName = "xyz";
  std::string const
    IPositionComponent::xName = "x";
  std::string const
    IPositionComponent::yName = "y";
  std::string const
    IPositionComponent::zName = "z";
  std::string const
    IPositionComponent::xyzOldName = "xyzOld";
  std::string const
    IPositionComponent::xOldName = "xOld";
  std::string const
    IPositionComponent::yOldName = "yOld";
  std::string const
    IPositionComponent::zOldName = "zOld";
  std::string const
    IPositionComponent::positionChangedToken =
      "PositionChanged";
} // namespace TUCUT::Game
