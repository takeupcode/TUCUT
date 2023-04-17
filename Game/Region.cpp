//  Region.cpp
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2019-01-25.
//  Copyright © Take Up Code, Inc.
//
#include "Region.h"

void TUCUT::Game::Region::initialize ()
{ }

std::shared_ptr<TUCUT::Game::Region>
TUCUT::Game::Region::getSharedRegion ()
{
  return shared_from_this();
}
