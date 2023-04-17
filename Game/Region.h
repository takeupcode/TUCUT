//  Region.h
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2019-01-25.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Game_Region_h
#define TUCUT_Game_Region_h

#include "../Math/Point.h"

#include <memory>

namespace TUCUT::Game
{
  class Region : public std::enable_shared_from_this<Region>
  {
  public:
    template <typename T, typename... Args>
    static std::shared_ptr<T> createRegion (Args... args)
    {
      // This will be an instance of T but a pointer to
      // the base Region class.
      auto region = std::shared_ptr<Region>(new T(args...));

      region->initialize();

      // We can be sure this cast will work.
      return std::static_pointer_cast<T>(region);
    }

    std::shared_ptr<Region> getSharedRegion ();

    virtual ~Region () = default;

    virtual double getFriction (
      Math::Point3d const & position) const = 0;

    virtual Math::Point3d resolveCollisions (
      Math::Point3d const & currentPosition,
      Math::Point3d const & newPosition) const = 0;

  protected:
    Region ()
    { }

    Region (Region const &) = delete;
    Region (Region &&) = delete;

    Region & operator = (Region const &) = delete;
    Region & operator = (Region &&) = delete;

    virtual void initialize ();
  };
} // namespace TUCUT::Game

#endif // TUCUT_Game_Region_h
