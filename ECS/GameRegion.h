//
//  GameRegion.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 1/25/19.
//  Copyright © 2019 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameRegion_h
#define TUCUT_Game_GameRegion_h

#include <memory>

#include "../Math/Point.h"

namespace TUCUT {
namespace Game {

class GameRegion : public std::enable_shared_from_this<GameRegion>
{
public:
    template <typename T, typename... Args>
    static std::shared_ptr<T> createGameRegion (Args... args)
    {
        // This will be an instance of T but a pointer to the base GameRegion class.
        auto gameRegion = std::shared_ptr<GameRegion>(new T(args...));
        
        gameRegion->initialize();
    
        // We can be sure this cast will work.
        return std::static_pointer_cast<T>(gameRegion);
    }
    
    std::shared_ptr<GameRegion> getSharedGameRegion ();
    
    virtual ~GameRegion () = default;
    
    virtual double getFriction (const Math::Point3d & position) const = 0;
    
    virtual Math::Point3d resolveCollisions (const Math::Point3d & currentPosition, const Math::Point3d & newPosition) const = 0;

protected:
    GameRegion ()
    { }
    
    GameRegion (const GameRegion &) = delete;
    GameRegion (GameRegion &&) = delete;
    
    GameRegion & operator = (const GameRegion &) = delete;
    GameRegion & operator = (GameRegion &&) = delete;

    virtual void initialize ();
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameRegion_h
