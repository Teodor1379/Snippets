#include "Array.hpp"



Array::Array() {
    this->size = 0;
}



void Array::push(int element) {
    if (size == MAX) {
        throw std::logic_error("MAX size reached!");
    }

    this->data[this->size] = element;

    this->size = this->size + 1;
}

void Array::pop() {
    if (size == 0) {
        throw std::logic_error("MIN size reached!");
    }

    this->size = this->size - 1;
}



void Array::print(std::ostream& stream) const noexcept {
    stream << "The elements are: ";

    for (unsigned int i = 0; i < this->size; ++i) {
        stream << this->data[i] << ' ';
    }

    stream << '\n';
}
