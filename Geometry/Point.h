//
//  Point.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/14/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Geometry_Point_h
#define TUCUT_Geometry_Point_h

namespace TUCUT {
namespace Geometry {

template <typename T>
class Point1
{
public:
    Point1 ()
    : x()
    { }
    
    explicit Point1 (T x)
    : x(x)
    { }

    T x;
};

template <typename T>
class Point2
{
public:
    Point2 ()
    : x(), y()
    { }
    
    Point2 (T x, T y)
    : x(x), y(y)
    { }

    T x;
    T y;
};

template <typename T>
class Point3
{
public:
    Point3 ()
    : x(), y(), z()
    { }
    
    Point3 (T x, T y, T z)
    : x(x), y(y), z(z)
    { }

    T x;
    T y;
    T z;
};

template <typename T>
class Point4
{
public:
    Point4 ()
    : x(), y(), z(), w()
    { }
    
    Point4 (T x, T y, T z, T w)
    : x(x), y(y), z(z), w(w)
    { }

    T x;
    T y;
    T z;
    T w;
};
    
using Point1i = Point1<int>;
using Point2i = Point2<int>;
using Point3i = Point3<int>;
using Point4i = Point4<int>;

using Point1d = Point1<double>;
using Point2d = Point2<double>;
using Point3d = Point3<double>;
using Point4d = Point4<double>;

} // namespace Geometry
} // namespace TUCUT

#endif // TUCUT_Geometry_Point_h
