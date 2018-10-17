//
//  Color.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Color_Color_h
#define TUCUT_Color_Color_h

#include "../Geometry/Lerp.h"

namespace TUCUT {
namespace Color {

class ColorRGB
{
public:
    ColorRGB (int red, int green, int blue, int alpha = 255)
    : mRed(red), mGreen(green), mBlue(blue), mAlpha(alpha)
    {
        if (mRed < 0)
        {
            mRed = 0;
        }
        else if (mRed > 255)
        {
            mRed = 255;
        }
        
        if (mGreen < 0)
        {
            mGreen = 0;
        }
        else if (mGreen > 255)
        {
            mGreen = 255;
        }
        
        if (mBlue < 0)
        {
            mBlue = 0;
        }
        else if (mBlue > 255)
        {
            mBlue = 255;
        }
        
        if (mAlpha < 0)
        {
            mAlpha = 0;
        }
        else if (mAlpha > 255)
        {
            mAlpha = 255;
        }
    }
    
    int red () const
    {
        return mRed;
    }
    
    int green () const
    {
        return mGreen;
    }
    
    int blue () const
    {
        return mBlue;
    }
    
    int alpha () const
    {
        return mAlpha;
    }

    static ColorRGB Black ()
    { return ColorRGB(0, 0, 0); }
    static ColorRGB White ()
    { return ColorRGB(255, 255, 255); }
    static ColorRGB LightGrey ()
    { return ColorRGB(211, 211, 211); }
    static ColorRGB Silver ()
    { return ColorRGB(192, 192, 192); }
    static ColorRGB DarkGrey ()
    { return ColorRGB(169, 169, 169); }
    static ColorRGB Grey ()
    { return ColorRGB(128, 128, 128); }

    static ColorRGB Red ()
    { return ColorRGB(255, 0, 0); }
    static ColorRGB Lime ()
    { return ColorRGB(0, 255, 0); }
    static ColorRGB Blue ()
    { return ColorRGB(0, 0, 255); }
    static ColorRGB Yellow ()
    { return ColorRGB(255, 255, 0); }
    static ColorRGB Aqua ()
    { return ColorRGB(0, 255, 255); }
    static ColorRGB Magenta ()
    { return ColorRGB(255, 0, 255); }

    static ColorRGB Maroon ()
    { return ColorRGB(128, 0, 0); }
    static ColorRGB Green ()
    { return ColorRGB(0, 128, 0); }
    static ColorRGB Navy ()
    { return ColorRGB(0, 0, 128); }
    static ColorRGB Olive ()
    { return ColorRGB(128, 128, 0); }
    static ColorRGB Teal ()
    { return ColorRGB(0, 128, 128); }
    static ColorRGB Purple ()
    { return ColorRGB(128, 0, 128); }

    static ColorRGB Pink ()
    { return ColorRGB(255, 192, 203); }
    static ColorRGB Brown ()
    { return ColorRGB(139, 69, 19); }
    static ColorRGB Tan ()
    { return ColorRGB(210, 180, 140); }
    static ColorRGB Lavender ()
    { return ColorRGB(230, 230, 250); }
    static ColorRGB Gold ()
    { return ColorRGB(255, 215, 0); }
    static ColorRGB Orange ()
    { return ColorRGB(255, 165, 0); }
    static ColorRGB Khaki ()
    { return ColorRGB(240, 230, 140); }
    static ColorRGB Turquoise ()
    { return ColorRGB(64, 224, 208); }
    static ColorRGB Indigo ()
    { return ColorRGB(75, 0, 130); }
    static ColorRGB Plum ()
    { return ColorRGB(221, 160, 221); }
    static ColorRGB Violet ()
    { return ColorRGB(238, 130, 238); }
    static ColorRGB Beige ()
    { return ColorRGB(245, 245, 220); }
    static ColorRGB Wheat ()
    { return ColorRGB(245, 222, 179); }
    static ColorRGB Wood ()
    { return ColorRGB(222, 184, 135); }
    static ColorRGB Peach ()
    { return ColorRGB(255, 218, 185); }
    static ColorRGB Ivory ()
    { return ColorRGB(255, 255, 240); }

private:
    unsigned char mRed;
    unsigned char mGreen;
    unsigned char mBlue;
    unsigned char mAlpha;
};
    
template <typename T>
ColorRGB lerpColor (const ColorRGB & n1, const ColorRGB & n2, T t)
{
    int r = static_cast<int>(Geometry::lerp(n1.red(), n2.red(), t));
    int g = static_cast<int>(Geometry::lerp(n1.green(), n2.green(), t));
    int b = static_cast<int>(Geometry::lerp(n1.blue(), n2.blue(), t));
    int a = static_cast<int>(Geometry::lerp(n1.alpha(), n2.alpha(), t));
    
    return ColorRGB(r, g, b, a);
}

} // namespace Color
} // namespace TUCUT

#endif // TUCUT_Color_Color_h
