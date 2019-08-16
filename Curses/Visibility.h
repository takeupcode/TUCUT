//
//  Visibility.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 07/19/19.
//  Copyright © 2019 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_Visibility_h
#define TUCUT_Curses_Visibility_h

#include <stdexcept>

#include "TextRegion.h"

#include "../Math/Adjust.h"
#include "../Math/Point.h"

namespace TUCUT {
namespace Curses {

class Visibility
{
public:
    static bool isVisible (const Math::Point2i & centerPoint,
        const Math::Point2i & relativePoint,
        unsigned int range,
        TextRegion * region)
    {
        int absX = Math::makePositive(relativePoint.x);
        int absY = Math::makePositive(relativePoint.y);
        
        unsigned int pointRange = static_cast<unsigned int>(std::max(absX, absY));
        
        if (pointRange > range || pointRange > mMaxRange)
        {
            return false;
        }
        
        if (pointRange < 2)
        {
            return true;
        }
        
        // This will give a number that can be multiplied by 4
        // to give the total number of squares in a given range.
        unsigned int sideLength = pointRange * 2;
        
        const std::vector<Math::Point2i> * visibilityLinks = nullptr;
        if (absX > absY) // Left or right excluding corners
        {
            if (relativePoint.x < 0) // Left
            {
                visibilityLinks = &mVisibilityLinks[pointRange][
                    sideLength * 3 + sideLength / 2 - relativePoint.y
                    ];
            }
            else // Right
            {
                visibilityLinks = &mVisibilityLinks[pointRange][
                    sideLength + sideLength / 2 + relativePoint.y
                    ];
            }
        }
        else // Top or bottom icluding corners
        {
            if (relativePoint.y < 0) // Top
            {
                visibilityLinks = &mVisibilityLinks[pointRange][
                    sideLength / 2 + relativePoint.x
                    ];
            }
            else // Bottom
            {
                visibilityLinks = &mVisibilityLinks[pointRange][
                    sideLength * 2 + sideLength / 2 - relativePoint.x
                    ];
            }
        }
        
        bool visible = true;
        for (const auto & link : *visibilityLinks)
        {
            if (region->tile(centerPoint.x + link.x, centerPoint.y + link.y) != ' ' ||
                !isVisible(centerPoint, link, range, region))
            {
                visible = false;
                break;
            }
        }
        
        return visible;
    }

private:
    static unsigned int rangeOfRelativePoint (const Math::Point2i & point)
    {
        int absX = Math::makePositive(point.x);
        int absY = Math::makePositive(point.y);
        
        return std::max(absX, absY);
    }

    // (range)->(positions in range)->(relative coordinates needed)
    static const std::vector<std::vector<std::vector<Math::Point2i>>> mVisibilityLinks;
    static const unsigned int mMaxRange = 4;
};
    
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_Visibility_h
