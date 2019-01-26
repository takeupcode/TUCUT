//
//  TextRegion.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "TextRegion.h"

#include "../Math/Adjust.h"

namespace TUCUT {
namespace Curses {

std::shared_ptr<TextRegion> TextRegion::getSharedTextRegion ()
{
    return std::static_pointer_cast<TextRegion>(shared_from_this());
}

bool TextRegion::addTileType (const std::string & typeName, char symbol)
{
    if (getTileTypeId(typeName))
    {
        return false;
    }
    
    createTileType(typeName, symbol);
    
    return true;
}

void TextRegion::setTile (unsigned int x, unsigned int y, const std::string & typeName)
{
    int tileTypeId = getTileTypeId(typeName);
    if (tileTypeId == 0)
    {
        return;
    }
    
    int tileIndex = Math::rowMajorIndex(x, y, mColumns);
    mTiles[tileIndex] = tileTypeId;
}

void TextRegion::removeTile (unsigned int x, unsigned int y)
{
    int tileIndex = Math::rowMajorIndex(x, y, mColumns);
    mTiles[tileIndex] = 0;
}

double TextRegion::getFriction (const Math::Point3d & location) const
{
    return 10.0;
}

Math::Point3d TextRegion::resolveCollisions (const Math::Point3d & oldLocation, const Math::Point3d & newLocation) const
{
    return newLocation;
}

int TextRegion::getTileTypeId (const std::string & typeName) const
{
    auto tileTypeMapResult = mTileTypes.find(typeName);
    if (tileTypeMapResult == mTileTypes.end())
    {
        return 0;
    }
    
    return tileTypeMapResult->second;
}

int TextRegion::createTileType (const std::string & typeName, char symbol)
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
