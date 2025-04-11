#include <iostream>

#include "Vector.hpp"



int main() {
    try {
        Vector instance;

        for (unsigned int i = 0; i < 256; ++i) {
            instance.pushBack(i + 1);
        }

        Vector copy(instance);

        for (unsigned int i = 0; i < 256; ++i) {
            instance.popBack();
        }

        instance.print(std::cout);
        copy.print(std::cout);

        instance = copy;

        instance.print(std::cout);
    } catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;

        return 1;
    }

    return 0;
}
