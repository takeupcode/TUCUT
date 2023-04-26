//  TextRegion.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-16.
//  Copyright © Take Up Code, Inc.
//
#include "TextRegion.h"

#include "../Math/Adjust.h"

namespace TUCUT {
namespace Curses {

std::shared_ptr<TextRegion> TextRegion::getSharedTextRegion ()
{
    return std::static_pointer_cast<TextRegion>(shared_from_this());
}

bool TextRegion::addTileType (std::string const & typeName, char symbol)
{
    if (getTileTypeId(typeName))
    {
        return false;
    }

    createTileType(typeName, symbol);

    return true;
}

char TextRegion::tile (unsigned int x, unsigned int y)
{
    int tileIndex = Math::rowMajorIndex(x, y, mColumns);

    if (mTiles.size() > static_cast<std::size_t>(tileIndex) && mTiles[tileIndex] != 0)
    {
        return mTileSymbols[mTiles[tileIndex]];
    }

    return ' ';
}

void TextRegion::setTile (unsigned int x, unsigned int y, std::string const & typeName)
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

double TextRegion::getFriction (Math::Point3d const & position) const
{
    return 10.0;
}

Math::Point3d TextRegion::resolveCollisions (Math::Point3d const & currentPosition, Math::Point3d const & newPosition) const
{
    int x = static_cast<int>(newPosition.x);
    int y = static_cast<int>(newPosition.y);
    int tileIndex = Math::rowMajorIndex(x, y, mColumns);

    if (mTiles.size() > static_cast<std::size_t>(tileIndex) && mTiles[tileIndex] != 0)
    {
        return currentPosition;
    }

    return newPosition;
}

int TextRegion::getTileTypeId (std::string const & typeName) const
{
    auto tileTypeMapResult = mTileTypes.find(typeName);
    if (tileTypeMapResult == mTileTypes.end())
    {
        return 0;
    }

    return tileTypeMapResult->second;
}

int TextRegion::createTileType (std::string const & typeName, char symbol)
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
