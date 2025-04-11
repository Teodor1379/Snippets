#ifndef UTILITY_HEADER_INCLUDED
#define UTILITY_HEADER_INCLUDED



#include <cmath>



class Utility {
public:
    static bool validateNumber(float);


public:
    static bool isPositive(float);
    static bool isNegative(float);
    static bool isZeroNumb(float);


public:
    static float EPSILON;
};

#endif
