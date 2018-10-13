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

namespace TUCUT {
namespace Noise {

class NoiseGenerator
{
public:
    explicit NoiseGenerator (int seed = 0,
                             double frequency = 1.0,
                             double amplitude = 1.0,
                             double lacunarity = 2.0,
                             double persistence = 0.5)
    : mSeed(seed), mFrequency(frequency), mAmplitude(amplitude), mLacunarity(lacunarity), mPersistence(persistence)
    { }
    
    virtual ~NoiseGenerator () = default;
    
    virtual std::vector<double> generate (double x, size_t layers = 1, bool calcDerivatives = false) const;
    
    virtual std::vector<double> generate (double x, double y, size_t layers = 1, bool calcDerivatives = false) const;
    
    virtual std::vector<double> generate (double x, double y, double z, size_t layers = 1, bool calcDerivatives = false) const;
    
    virtual std::vector<double> generate (double x, double y, double z, double w, size_t layers = 1, bool calcDerivatives = false) const;

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
