#include <iostream>

#include "Person.hpp"



int main() {
    Person empty;

    empty.print(std::cout);

    Person person = Person("John", "Wick", 52, true);

    person.print(std::cout);

    Person someone(person);

    someone.print(std::cout);

    someone = empty;

    return 0;
}
