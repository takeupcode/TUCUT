//
//  GameRegion.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 1/25/19.
//  Copyright © 2019 Take Up Code. All rights reserved.
//

#include "GameRegion.h"

namespace TUCUT {
namespace Game {

void GameRegion::initialize ()
{ }

std::shared_ptr<GameRegion> GameRegion::getSharedGameRegion ()
{
    return shared_from_this();
}

} // namespace Game
} // namespace TUCUT
