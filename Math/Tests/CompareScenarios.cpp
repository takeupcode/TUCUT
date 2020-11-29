//
//  CompareScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/28/20.
//  Copyright © 2020 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../Compare.h"

#include <limits>

using namespace std;
using namespace TUCUT;

SCENARIO( Compare, "Operation/Normal", "unit,math", "Templated values can be compared." )
{
    bool result;

    // Ints should compare okay.
    result = Math::compareEq(1, 1);
    VERIFY_TRUE(result);

    result = Math::compareEq(1, 2);
    VERIFY_FALSE(result);

    // Chars should compare okay.
    result = Math::compareEq('a', 'a');
    VERIFY_TRUE(result);

    result = Math::compareEq('a', 'b');
    VERIFY_FALSE(result);

    // Bools should compare okay.
    result = Math::compareEq(true, true);
    VERIFY_TRUE(result);

    result = Math::compareEq(true, false);
    VERIFY_FALSE(result);

    // Strings should compare okay.
    string s1 = "pass";
    string s2 = "fail";
    result = Math::compareEq(s1, s1);
    VERIFY_TRUE(result);

    result = Math::compareEq(s1, s2);
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Special float values can be compared." )
{
    bool result;

    float posZero = 0.0f;
    result = std::signbit(posZero);
    VERIFY_FALSE(result);

    float negZero = -0.0f;
    result = std::signbit(negZero);
    VERIFY_TRUE(result);

    float posInfinity = std::numeric_limits<float>::infinity();
    result = std::signbit(posInfinity);
    VERIFY_FALSE(result);

    float negInfinity = -posInfinity;
    result = std::signbit(negInfinity);
    VERIFY_TRUE(result);

    float nan1 = std::nanf("1");
    result = std::isnan(nan1);
    VERIFY_TRUE(result);

    float nan2 = std::nanf("2");
    result = std::isnan(nan2);
    VERIFY_TRUE(result);

    // Zero should always compare equal.
    result = Math::compareEq(posZero, posZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(negZero, negZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(posZero, negZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(negZero, posZero);
    VERIFY_TRUE(result);

    // Infinities with same sign should be equal.
    result = Math::compareEq(posInfinity, posInfinity);
    VERIFY_TRUE(result);

    result = Math::compareEq(negInfinity, negInfinity);
    VERIFY_TRUE(result);

    result = Math::compareEq(posInfinity, negInfinity);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, posInfinity);
    VERIFY_FALSE(result);

    // NaN should always compare not equal even with itself.
    result = Math::compareEq(nan1, nan1);
    VERIFY_FALSE(result);

    result = Math::compareEq(nan1, nan2);
    VERIFY_FALSE(result);

    result = Math::compareEq(nan2, nan1);
    VERIFY_FALSE(result);

    // Infinities can be compared with small values.
    float fractionMinPos = FLT_MIN * FLT_EPSILON;
    float fractionMinNeg = -fractionMinPos;

    result = Math::compareEq(posInfinity, fractionMinPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, fractionMinPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(posInfinity, fractionMinNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, fractionMinNeg);
    VERIFY_FALSE(result);

    // Infinities can be compared with large values.
    float maxPos = FLT_MAX;
    float maxNeg = -maxPos;

    result = Math::compareEq(posInfinity, maxPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, maxPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(posInfinity, maxNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, maxNeg);
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Special double values can be compared." )
{
    bool result;

    double posZero = 0.0;
    result = std::signbit(posZero);
    VERIFY_FALSE(result);

    double negZero = -0.0;
    result = std::signbit(negZero);
    VERIFY_TRUE(result);

    double posInfinity = std::numeric_limits<double>::infinity();
    result = std::signbit(posInfinity);
    VERIFY_FALSE(result);

    double negInfinity = -posInfinity;
    result = std::signbit(negInfinity);
    VERIFY_TRUE(result);

    double nan1 = std::nan("1");
    result = std::isnan(nan1);
    VERIFY_TRUE(result);

    double nan2 = std::nan("2");
    result = std::isnan(nan2);
    VERIFY_TRUE(result);

    // Zero should always compare equal.
    result = Math::compareEq(posZero, posZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(negZero, negZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(posZero, negZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(negZero, posZero);
    VERIFY_TRUE(result);

    // Infinities with same sign should be equal.
    result = Math::compareEq(posInfinity, posInfinity);
    VERIFY_TRUE(result);

    result = Math::compareEq(negInfinity, negInfinity);
    VERIFY_TRUE(result);

    result = Math::compareEq(posInfinity, negInfinity);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, posInfinity);
    VERIFY_FALSE(result);

    // NaN should always compare not equal even with itself.
    result = Math::compareEq(nan1, nan1);
    VERIFY_FALSE(result);

    result = Math::compareEq(nan1, nan2);
    VERIFY_FALSE(result);

    result = Math::compareEq(nan2, nan1);
    VERIFY_FALSE(result);

    // Infinities can be compared with small values.
    double fractionMinPos = DBL_MIN * DBL_EPSILON;
    double fractionMinNeg = -fractionMinPos;

    result = Math::compareEq(posInfinity, fractionMinPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, fractionMinPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(posInfinity, fractionMinNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, fractionMinNeg);
    VERIFY_FALSE(result);

    // Infinities can be compared with large values.
    double maxPos = DBL_MAX;
    double maxNeg = -maxPos;

    result = Math::compareEq(posInfinity, maxPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, maxPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(posInfinity, maxNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, maxNeg);
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Special long double values can be compared." )
{
    bool result;

    long double posZero = 0.0L;
    result = std::signbit(posZero);
    VERIFY_FALSE(result);

    long double negZero = -0.0L;
    result = std::signbit(negZero);
    VERIFY_TRUE(result);

    long double posInfinity = std::numeric_limits<long double>::infinity();
    result = std::signbit(posInfinity);
    VERIFY_FALSE(result);

    long double negInfinity = -posInfinity;
    result = std::signbit(negInfinity);
    VERIFY_TRUE(result);

    long double nan1 = std::nanl("1");
    result = std::isnan(nan1);
    VERIFY_TRUE(result);

    long double nan2 = std::nanl("2");
    result = std::isnan(nan2);
    VERIFY_TRUE(result);

    // Zero should always compare equal.
    result = Math::compareEq(posZero, posZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(negZero, negZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(posZero, negZero);
    VERIFY_TRUE(result);

    result = Math::compareEq(negZero, posZero);
    VERIFY_TRUE(result);

    // Infinities with same sign should be equal.
    result = Math::compareEq(posInfinity, posInfinity);
    VERIFY_TRUE(result);

    result = Math::compareEq(negInfinity, negInfinity);
    VERIFY_TRUE(result);

    result = Math::compareEq(posInfinity, negInfinity);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, posInfinity);
    VERIFY_FALSE(result);

    // NaN should always compare not equal even with itself.
    result = Math::compareEq(nan1, nan1);
    VERIFY_FALSE(result);

    result = Math::compareEq(nan1, nan2);
    VERIFY_FALSE(result);

    result = Math::compareEq(nan2, nan1);
    VERIFY_FALSE(result);

    // Infinities can be compared with small values.
    long double fractionMinPos = LDBL_MIN * DBL_EPSILON;
    long double fractionMinNeg = -fractionMinPos;

    result = Math::compareEq(posInfinity, fractionMinPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, fractionMinPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(posInfinity, fractionMinNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, fractionMinNeg);
    VERIFY_FALSE(result);

    // Infinities can be compared with large values.
    long double maxPos = LDBL_MAX;
    long double maxNeg = -maxPos;

    result = Math::compareEq(posInfinity, maxPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, maxPos);
    VERIFY_FALSE(result);

    result = Math::compareEq(posInfinity, maxNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(negInfinity, maxNeg);
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Normal float values can be compared." )
{
    bool result;

    float pointOne = 0.1f;
    float wholeOne = 1.0f;
    float wholeOneSum = 0.0f;

    for (int i = 0; i < 10; ++i)
    {
        wholeOneSum += pointOne;
    }

    result = wholeOne == wholeOneSum;
    VERIFY_FALSE(result);

    result = Math::compareEq(wholeOne, wholeOneSum);
    VERIFY_TRUE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Large float values can be compared." )
{
    bool result;

    float pointOne = 0.1f;
    float wholeOneSum = 0.0f;
    float wholeThousandSum = 0.0f;
    float wholeMillionSum = 0.0f;
    float wholeMillionCalc = 0.0f;
    float speedOfSound = 343;
    float speedOfSoundMultiple = 2915.452f;

    for (int i = 0; i < 10; ++i)
    {
        wholeOneSum += pointOne;
    }

    for (int i = 0; i < 1000; ++i)
    {
        wholeThousandSum += wholeOneSum;
    }

    for (int i = 0; i < 1000; ++i)
    {
        wholeMillionSum += wholeThousandSum;
    }

    wholeMillionCalc = speedOfSound * speedOfSoundMultiple;

    result = wholeMillionSum == wholeMillionCalc;
    VERIFY_FALSE(result);

    result = Math::compareEq(wholeMillionSum, wholeMillionCalc);
    VERIFY_TRUE(result);

    float wholeMillionSumNeg = -wholeMillionSum;
    result = wholeMillionSum == wholeMillionSumNeg;
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Large double values can be compared." )
{
    bool result;

    double pointOne = 0.1;
    double wholeOneSum = 0.0;
    double wholeThousandSum = 0.0;
    double wholeMillionSum = 0.0;
    double wholeBillionSum = 0.0;
    double wholeTenBillionSum = 0.0;
    double wholeTenBillionCalc = 0.0;
    double speedOfSound = 343;
    double speedOfSoundMultiple = 29'154'518.95043732;

    for (int i = 0; i < 10; ++i)
    {
        wholeOneSum += pointOne;
    }

    for (int i = 0; i < 1000; ++i)
    {
        wholeThousandSum += wholeOneSum;
    }

    for (int i = 0; i < 1000; ++i)
    {
        wholeMillionSum += wholeThousandSum;
    }

    for (int i = 0; i < 1000; ++i)
    {
        wholeBillionSum += wholeMillionSum;
    }

    for (int i = 0; i < 10; ++i)
    {
        wholeTenBillionSum += wholeBillionSum;
    }

    wholeTenBillionCalc = speedOfSound * speedOfSoundMultiple;

    result = wholeTenBillionSum == wholeTenBillionCalc;
    VERIFY_FALSE(result);

    result = Math::compareEq(wholeTenBillionSum, wholeTenBillionCalc);
    VERIFY_TRUE(result);

    double wholeTenBillionSumNeg = -wholeTenBillionSum;
    result = wholeTenBillionSum == wholeTenBillionSumNeg;
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Large long double values can be compared." )
{
    bool result;

    long double pointOne = 0.1L;
    long double wholeOneSum = 0.0L;
    long double wholeThousandSum = 0.0L;
    long double wholeMillionSum = 0.0L;
    long double wholeBillionSum = 0.0L;
    long double wholeTenBillionSum = 0.0L;
    long double wholeTenBillionCalc = 0.0L;
    long double speedOfSound = 343L;
    long double speedOfSoundMultiple = 29'154'518.9504373178L;

    for (int i = 0; i < 10; ++i)
    {
        wholeOneSum += pointOne;
    }

    for (int i = 0; i < 1000; ++i)
    {
        wholeThousandSum += wholeOneSum;
    }

    for (int i = 0; i < 1000; ++i)
    {
        wholeMillionSum += wholeThousandSum;
    }

    for (int i = 0; i < 1000; ++i)
    {
        wholeBillionSum += wholeMillionSum;
    }

    for (int i = 0; i < 10; ++i)
    {
        wholeTenBillionSum += wholeBillionSum;
    }
    
    wholeTenBillionCalc = speedOfSound * speedOfSoundMultiple;

    result = wholeTenBillionSum == wholeTenBillionCalc;
    VERIFY_FALSE(result);

    result = Math::compareEq(wholeTenBillionSum, wholeTenBillionCalc);
    VERIFY_TRUE(result);

    long double wholeTenBillionSumNeg = -wholeTenBillionSum;
    result = wholeTenBillionSum == wholeTenBillionSumNeg;
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Small float values can be compared." )
{
    bool result;

    float fractionMinPos = FLT_MIN * FLT_EPSILON;
    float fractionMinNeg = -fractionMinPos;

    result = fractionMinPos == 0.0f;
    VERIFY_FALSE(result);

    result = Math::compareEq(fractionMinPos, 0.0f);
    VERIFY_TRUE(result);

    result = Math::compareEq(fractionMinNeg, 0.0f);
    VERIFY_TRUE(result);

    result = Math::compareEq(fractionMinPos, fractionMinNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(fractionMinNeg, fractionMinPos);
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Small double values can be compared." )
{
    bool result;

    double fractionMinPos = DBL_MIN * DBL_EPSILON;
    double fractionMinNeg = -fractionMinPos;

    result = fractionMinPos == 0.0;
    VERIFY_FALSE(result);

    result = Math::compareEq(fractionMinPos, 0.0);
    VERIFY_TRUE(result);

    result = Math::compareEq(fractionMinNeg, 0.0);
    VERIFY_TRUE(result);

    result = Math::compareEq(fractionMinPos, fractionMinNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(fractionMinNeg, fractionMinPos);
    VERIFY_FALSE(result);
}

SCENARIO( Compare, "Operation/Normal", "unit,math", "Small long double values can be compared." )
{
    bool result;

    long double fractionMinPos = LDBL_MIN * DBL_EPSILON;
    long double fractionMinNeg = -fractionMinPos;

    result = fractionMinPos == 0.0L;
    VERIFY_FALSE(result);

    result = Math::compareEq(fractionMinPos, 0.0L);
    VERIFY_TRUE(result);

    result = Math::compareEq(fractionMinNeg, 0.0L);
    VERIFY_TRUE(result);

    result = Math::compareEq(fractionMinPos, fractionMinNeg);
    VERIFY_FALSE(result);

    result = Math::compareEq(fractionMinNeg, fractionMinPos);
    VERIFY_FALSE(result);
}
