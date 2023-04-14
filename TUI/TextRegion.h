//
//  TextRegion.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_TextRegion_h
#define TUCUT_Curses_TextRegion_h

#include <string>
#include <unordered_map>
#include <vector>

#include "../Game/GameRegion.h"

namespace TUCUT {
namespace Curses {
    
class TextRegion : public Game::GameRegion
{
public:
    std::shared_ptr<TextRegion> getSharedTextRegion ();
    
    unsigned int columns () const
    {
        return mColumns;
    }
    
    unsigned int rows () const
    {
        return mRows;
    }
    
    bool addTileType (const std::string & typeName, char symbol);
    
    char tile (unsigned int x, unsigned int y);

    void setTile (unsigned int x, unsigned int y, const std::string & typeName);
    
    void removeTile (unsigned int x, unsigned int y);
    
    double getFriction (const Math::Point3d & position) const override;
    
    Math::Point3d resolveCollisions (const Math::Point3d & currentPosition, const Math::Point3d & newPosition) const override;

private:
    friend class Game::GameRegion;
    
    TextRegion (unsigned int columns, unsigned int rows)
    : mColumns(columns), mRows(rows), mNextTileTypeId(1)
    {
        mTiles.resize(columns * rows);
    }
    
    TextRegion (const TextRegion &) = delete;
    TextRegion (TextRegion &&) = delete;
    
    TextRegion & operator = (const TextRegion &) = delete;
    TextRegion & operator = (TextRegion &&) = delete;
    
    int getTileTypeId (const std::string & typeName) const;
    
    int createTileType (const std::string & typeName, char symbol);

    unsigned int mColumns;
    unsigned int mRows;
    int mNextTileTypeId;
    std::unordered_map<std::string, int> mTileTypes;
    std::vector<char> mTileSymbols;
    std::vector<int> mTiles;
};

} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_TextRegion_h
