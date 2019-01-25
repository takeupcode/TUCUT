//
//  GameRegion.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_GameRegion_h
#define TUCUT_Curses_GameRegion_h

#include <string>
#include <unordered_map>
#include <vector>

#include "../Game/GameObject.h"

namespace TUCUT {
namespace Curses {
    
class GameRegion
{
public:
    GameRegion (unsigned int columns, unsigned int rows)
    : mColumns(columns), mRows(rows), mNextTileTypeId(1)
    {
        mTiles.resize(columns * rows);
    }
    
    GameRegion (const GameRegion &) = default;
    GameRegion (GameRegion &&) = default;
    
    GameRegion & operator = (const GameRegion &) = default;
    GameRegion & operator = (GameRegion &&) = default;
    
    unsigned int columns () const
    {
        return mColumns;
    }
    
    unsigned int rows () const
    {
        return mRows;
    }
    
    bool addTileType (const std::string & typeName, char symbol);
    
    void setTile (unsigned int x, unsigned int y, const std::string & typeName);
    
    void removeTile (unsigned int x, unsigned int y);
    
    void resolveCollisions (std::shared_ptr<Game::GameObject> & object);
    
private:
    int getTileTypeId (const std::string & typeName) const;
    
    int createTileType (const std::string & typeName, char symbol);

    unsigned int mColumns;
    unsigned int mRows;
    int mNextTileTypeId;
    std::unordered_map<std::string, int> mTileTypes;
    std::vector<char> mTileSymbols;
    std::vector<int> mTiles;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Curses_GameRegion_h
