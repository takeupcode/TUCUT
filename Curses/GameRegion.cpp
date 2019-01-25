//
//  GameRegion.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameRegion.h"

#include "../Math/Adjust.h"

namespace TUCUT {
namespace Curses {
    
bool GameRegion::addTileType (const std::string & typeName, char symbol)
{
    if (getTileTypeId(typeName))
    {
        return false;
    }
    
    createTileType(typeName, symbol);
    
    return true;
}

void GameRegion::setTile (unsigned int x, unsigned int y, const std::string & typeName)
{
    int tileTypeId = getTileTypeId(typeName);
    if (tileTypeId == 0)
    {
        return;
    }
    
    int tileIndex = Math::rowMajorIndex(x, y, mColumns);
    mTiles[tileIndex] = tileTypeId;
}

void GameRegion::removeTile (unsigned int x, unsigned int y)
{
    int tileIndex = Math::rowMajorIndex(x, y, mColumns);
    mTiles[tileIndex] = 0;
}

void GameRegion::resolveCollisions (std::shared_ptr<Game::GameObject> & object)
{
    
}

int GameRegion::getTileTypeId (const std::string & typeName) const
{
    auto tileTypeMapResult = mTileTypes.find(typeName);
    if (tileTypeMapResult == mTileTypes.end())
    {
        return 0;
    }
    
    return tileTypeMapResult->second;
}

int GameRegion::createTileType (const std::string & typeName, char symbol)
{
    if (typeName.empty())
    {
        throw std::runtime_error("Unable to create tile type");
    }
    
    mTileTypes[typeName] = mNextTileTypeId;
    
    while (mTileSymbols.size() <= static_cast<std::size_t>(mNextTileTypeId))
    {
        mTileSymbols.push_back('\0');
    }
    mTileSymbols[mNextTileTypeId] = symbol;
    
    return mNextTileTypeId++;
}

} // namespace Curses
} // namespace TUCUT
