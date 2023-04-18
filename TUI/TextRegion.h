//  TextRegion.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-16.
//  Copyright © Take Up Code, Inc.
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

    bool addTileType (std::string const & typeName, char symbol);

    char tile (unsigned int x, unsigned int y);

    void setTile (unsigned int x, unsigned int y, std::string const & typeName);

    void removeTile (unsigned int x, unsigned int y);

    double getFriction (Math::Point3d const & position) const override;

    Math::Point3d resolveCollisions (Math::Point3d const & currentPosition, Math::Point3d const & newPosition) const override;

private:
    friend class Game::GameRegion;

    TextRegion (unsigned int columns, unsigned int rows)
    : mColumns(columns), mRows(rows), mNextTileTypeId(1)
    {
        mTiles.resize(columns * rows);
    }

    TextRegion (TextRegion const &) = delete;
    TextRegion (TextRegion &&) = delete;

    TextRegion & operator = (TextRegion const &) = delete;
    TextRegion & operator = (TextRegion &&) = delete;

    int getTileTypeId (std::string const & typeName) const;

    int createTileType (std::string const & typeName, char symbol);

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
