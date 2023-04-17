//  Region.cpp
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2019-01-25.
//  Copyright © Take Up Code, Inc.
//
#include "Region.h"

using namespace TUCUT;

void Game::Region::initialize ()
{ }

std::shared_ptr<Game::Region> Game::Region::getSharedRegion ()
{
  return shared_from_this();
}
