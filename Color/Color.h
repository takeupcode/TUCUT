//
//  Color.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Color_Color_h
#define TUCUT_Color_Color_h

#include "../Math/Lerp.h"

namespace TUCUT {
namespace Color {

class ColorRGB
{
public:
    ColorRGB (int red, int green, int blue, int alpha = 255)
    : mRed(red), mGreen(green), mBlue(blue), mAlpha(alpha)
    {
        if (red < 0)
        {
            mRed = 0;
        }
        else if (red > 255)
        {
            mRed = 255;
        }
        
        if (green < 0)
        {
            mGreen = 0;
        }
        else if (green > 255)
        {
            mGreen = 255;
        }
        
        if (blue < 0)
        {
            mBlue = 0;
        }
        else if (blue > 255)
        {
            mBlue = 255;
        }
        
        if (alpha < 0)
        {
            mAlpha = 0;
        }
        else if (alpha > 255)
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

    static ColorRGB createBlack ()
    { return ColorRGB(0, 0, 0); }
    static ColorRGB createWhite ()
    { return ColorRGB(255, 255, 255); }
    static ColorRGB createLightGrey ()
    { return ColorRGB(211, 211, 211); }
    static ColorRGB createSilver ()
    { return ColorRGB(192, 192, 192); }
    static ColorRGB createDarkGrey ()
    { return ColorRGB(169, 169, 169); }
    static ColorRGB createGrey ()
    { return ColorRGB(128, 128, 128); }

    static ColorRGB createRed ()
    { return ColorRGB(255, 0, 0); }
    static ColorRGB createLime ()
    { return ColorRGB(0, 255, 0); }
    static ColorRGB createBlue ()
    { return ColorRGB(0, 0, 255); }
    static ColorRGB createYellow ()
    { return ColorRGB(255, 255, 0); }
    static ColorRGB createAqua ()
    { return ColorRGB(0, 255, 255); }
    static ColorRGB createMagenta ()
    { return ColorRGB(255, 0, 255); }

    static ColorRGB createMaroon ()
    { return ColorRGB(128, 0, 0); }
    static ColorRGB createGreen ()
    { return ColorRGB(0, 128, 0); }
    static ColorRGB createNavy ()
    { return ColorRGB(0, 0, 128); }
    static ColorRGB createOlive ()
    { return ColorRGB(128, 128, 0); }
    static ColorRGB createTeal ()
    { return ColorRGB(0, 128, 128); }
    static ColorRGB createPurple ()
    { return ColorRGB(128, 0, 128); }

    static ColorRGB createPink ()
    { return ColorRGB(255, 192, 203); }
    static ColorRGB createBrown ()
    { return ColorRGB(139, 69, 19); }
    static ColorRGB createTan ()
    { return ColorRGB(210, 180, 140); }
    static ColorRGB createLavender ()
    { return ColorRGB(230, 230, 250); }
    static ColorRGB createGold ()
    { return ColorRGB(255, 215, 0); }
    static ColorRGB createOrange ()
    { return ColorRGB(255, 165, 0); }
    static ColorRGB createKhaki ()
    { return ColorRGB(240, 230, 140); }
    static ColorRGB createTurquoise ()
    { return ColorRGB(64, 224, 208); }
    static ColorRGB createIndigo ()
    { return ColorRGB(75, 0, 130); }
    static ColorRGB createPlum ()
    { return ColorRGB(221, 160, 221); }
    static ColorRGB createViolet ()
    { return ColorRGB(238, 130, 238); }
    static ColorRGB createBeige ()
    { return ColorRGB(245, 245, 220); }
    static ColorRGB createWheat ()
    { return ColorRGB(245, 222, 179); }
    static ColorRGB createWood ()
    { return ColorRGB(222, 184, 135); }
    static ColorRGB createPeach ()
    { return ColorRGB(255, 218, 185); }
    static ColorRGB createIvory ()
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
    int r = static_cast<int>(Math::lerp(n1.red(), n2.red(), t));
    int g = static_cast<int>(Math::lerp(n1.green(), n2.green(), t));
    int b = static_cast<int>(Math::lerp(n1.blue(), n2.blue(), t));
    int a = static_cast<int>(Math::lerp(n1.alpha(), n2.alpha(), t));
    
    return ColorRGB(r, g, b, a);
}

} // namespace Color
} // namespace TUCUT

#endif // TUCUT_Color_Color_h
