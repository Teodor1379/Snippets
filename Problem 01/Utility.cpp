#include "Utility.hpp"



float Utility::EPSILON = 1e-9;



bool Utility::validateNumber(float number) {
    return  !std::isinf(number) &&
            !std::isnan(number);
}



bool Utility::isPositive(float number) {
    return number > 0.0;
}

bool Utility::isNegative(float number) {
    return number < 0.0;
}

bool Utility::isZeroNumb(float number) {
    return std::fabs(number) < EPSILON;
}
