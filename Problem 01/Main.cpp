#include <iostream>

#include "Point.hpp"



int main() {
    Point point1 = Point( 1.0,  2.0,  3.0);
    Point point2 = Point(-1.0, -2.0, -3.0);
    Point point3 = Point( 0.0,  0.0,  0.0);


    point1.printInformation(std::cout); point1.printStatisticsP(std::cout);
    point2.printInformation(std::cout); point2.printStatisticsP(std::cout);
    point3.printInformation(std::cout); point3.printStatisticsP(std::cout);
    
    try {
        float invalid = 1.0 / 0.0;

        Point point(invalid, 0, 0);
    } catch (std::invalid_argument& exception) {
        std::cout << exception.what() << std::endl;
        
        // throw exception; - We do not do that here!

        return 1;
    }

    return 0;
}
