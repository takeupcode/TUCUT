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
    virtual ~NoiseGenerator () = default;
    
    virtual std::vector<double> generate (double x, size_t layers = 1, bool calcDerivatives = false) const = 0;

    virtual std::vector<double> generate (double x, double y, size_t layers = 1, bool calcDerivatives = false) const = 0;
    
    virtual std::vector<double> generate (double x, double y, double z, size_t layers = 1, bool calcDerivatives = false) const = 0;
    
    virtual std::vector<double> generate (double x, double y, double z, double w, size_t layers = 1, bool calcDerivatives = false) const = 0;

protected:
    NoiseGenerator (int seed,
                    double frequency,
                    double amplitude,
                    double lacunarity,
                    double persistence)
    : mSeed(seed), mFrequency(frequency), mAmplitude(amplitude), mLacunarity(lacunarity), mPersistence(persistence)
    { }
    
    int mSeed;
    double mFrequency;
    double mAmplitude;
    double mLacunarity;
    double mPersistence;
};

class ClassicNoiseGenerator : public NoiseGenerator
{
public:
    explicit ClassicNoiseGenerator (int seed = 0,
                                    double frequency = 1.0,
                                    double amplitude = 1.0,
                                    double lacunarity = 2.0,
                                    double persistence = 0.5)
    : NoiseGenerator(seed, frequency, amplitude, lacunarity, persistence)
    { }
    
    virtual ~ClassicNoiseGenerator () = default;
    
    std::vector<double> generate (double x, size_t layers = 1, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, size_t layers = 1, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double z, size_t layers = 1, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double z, double w, size_t layers = 1, bool calcDerivatives = false) const override;
};

class SimpleNoiseGenerator : public NoiseGenerator
{
public:
    explicit SimpleNoiseGenerator (int seed = 0,
                                   double frequency = 1.0,
                                   double amplitude = 1.0,
                                   double lacunarity = 2.0,
                                   double persistence = 0.5)
    : NoiseGenerator(seed, frequency, amplitude, lacunarity, persistence)
    { }
    
    virtual ~SimpleNoiseGenerator () = default;
    
    std::vector<double> generate (double x, size_t layers = 1, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, size_t layers = 1, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double z, size_t layers = 1, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double z, double w, size_t layers = 1, bool calcDerivatives = false) const override;
};

} // namespace Noise
} // namespace TUCUT

#endif // TUCUT_Noise_Noise_h
