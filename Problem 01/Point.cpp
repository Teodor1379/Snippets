#include "Point.hpp"

#include "Utility.hpp"



Point::Point() {
    this->x =   0.0;
    this->y =   0.0;
    this->z =   0.0;
}

Point::Point(float x, float y, float z) {
    if (
        !Utility::validateNumber(x) ||
        !Utility::validateNumber(y) ||
        !Utility::validateNumber(z)
    ) {
        throw std::invalid_argument("Invalid Point Constructor Arguments!");
    }

    this->x =   x;
    this->y =   y;
    this->z =   z;
}



unsigned int Point::findPositiveCoordinates()   const noexcept {
    return  Utility::isPositive(this->x)    +
            Utility::isPositive(this->y)    +
            Utility::isPositive(this->z);
}

unsigned int Point::findNegativeCoordinates()   const noexcept {
    return  Utility::isNegative(this->x)    +
            Utility::isNegative(this->y)    +
            Utility::isNegative(this->z);
}

unsigned int Point::findZeroNumbCoordinates()   const noexcept {
    return  Utility::isZeroNumb(this->x)    +
            Utility::isZeroNumb(this->y)    +
            Utility::isZeroNumb(this->z);
}



void Point::printInformation(std::ostream& stream) const noexcept {
    stream << "Point Information: ";

    stream << "( ";

    stream << "X: " << this->x << "; ";
    stream << "Y: " << this->y << "; ";
    stream << "Z: " << this->z << "; ";

    stream << " )";

    stream << '\n';
}

void Point::printStatisticsP(std::ostream& stream) const noexcept {
    stream << "Point Statistics: " << '\n';

    stream << "Number of Positive Coordinates: " << this->findPositiveCoordinates() << '\n';
    stream << "Number of Negative Coordinates: " << this->findNegativeCoordinates() << '\n';
    stream << "Number of ZeroNumb Coordinates: " << this->findZeroNumbCoordinates() << '\n';

    stream << '\n';
}
