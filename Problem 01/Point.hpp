#ifndef POINT_HEADER_INCLUDED
#define POINT_HEADER_INCLUDED



#include <exception>
#include <stdexcept>



#include <fstream>



class Point {
public:
    Point();

    Point(float, float, float);


public:
    inline float    getX()  const   noexcept    {   return this->x; }
    inline float    getY()  const   noexcept    {   return this->y; }
    inline float    getZ()  const   noexcept    {   return this->z; }


public:
    unsigned int findPositiveCoordinates() const    noexcept;
    unsigned int findNegativeCoordinates() const    noexcept;
    unsigned int findZeroNumbCoordinates() const    noexcept;


public:
    void printInformation(std::ostream&)    const noexcept;
    void printStatisticsP(std::ostream&)    const noexcept;


private:
    float x;
    float y;
    float z;
};

#endif
