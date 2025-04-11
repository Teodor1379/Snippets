#include <iostream>

#include "Array.hpp"



int main() {
    Array array;

    for (unsigned int i = 0; i < MAX / 2; ++i) {
        array.push(i + 1);
    }

    array.print(std::cout);

    for (unsigned int i = 0; i < MAX / 2; ++i) {
        array.pop();
    }

    array.print(std::cout);



    try {
        for (unsigned int i = 0; i < MAX + 1; ++i) {
            array.push(i + 1);
        }

        array.print(std::cout);
    } catch (std::logic_error& exception) {
        std::cout << exception.what() << std::endl;

        return 1;
    }



    return 0;
}
