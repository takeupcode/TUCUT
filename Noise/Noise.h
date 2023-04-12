//
//  Noise.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 9/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Noise_Noise_h
#define TUCUT_Noise_Noise_h

#include <vector>

#include "../Math/Point.h"

namespace TUCUT {
namespace Noise {

class NoiseGenerator
{
public:
    explicit NoiseGenerator (int seed = 0,
                             double frequency = 1.0,
                             double amplitude = 1.0,
                             double lacunarity = 2.0,
                             double persistence = 0.5);

    virtual ~NoiseGenerator () = default;

    int seed () const;

    virtual double generate (double x, Math::Point1d * offset = nullptr, size_t layers = 1, Math::Point1d * derivative = nullptr) const;

    virtual double generate (double x, double y, Math::Point2d * offset = nullptr, size_t layers = 1, Math::Point2d * derivative = nullptr) const;

protected:
    int mSeed;
    double mFrequency;
    double mAmplitude;
    double mLacunarity;
    double mPersistence;
};

} // namespace Noise
} // namespace TUCUT

#endif // TUCUT_Noise_Noise_h
