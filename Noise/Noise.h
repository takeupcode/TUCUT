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
    
    virtual std::vector<double> generate (double x, double angle = 0.0, bool calcDerivatives = false) const = 0;

    virtual std::vector<double> generate (double x, double y, double angle = 0.0, bool calcDerivatives = false) const = 0;
    
    virtual std::vector<double> generate (double x, double y, double z, double angle = 0.0, bool calcDerivatives = false) const = 0;
    
    virtual std::vector<double> generate (double x, double y, double z, double w, double angle = 0.0, bool calcDerivatives = false) const = 0;

protected:
    NoiseGenerator () = default;
};

class ClassicNoiseGenerator : public NoiseGenerator
{
public:
    ClassicNoiseGenerator () = default;
    
    virtual ~ClassicNoiseGenerator () = default;
    
    std::vector<double> generate (double x, double angle = 0.0, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double angle = 0.0, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double z, double angle = 0.0, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double z, double w, double angle = 0.0, bool calcDerivatives = false) const override;
};

class SimpleNoiseGenerator : public NoiseGenerator
{
public:
    SimpleNoiseGenerator () = default;
    
    virtual ~SimpleNoiseGenerator () = default;
    
    std::vector<double> generate (double x, double angle = 0.0, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double angle = 0.0, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double z, double angle = 0.0, bool calcDerivatives = false) const override;
    
    std::vector<double> generate (double x, double y, double z, double w, double angle = 0.0, bool calcDerivatives = false) const override;
};

} // namespace Noise
} // namespace TUCUT

#endif // TUCUT_Noise_Noise_h
