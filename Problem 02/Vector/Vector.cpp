#include "Vector.hpp"



Vector::Vector() {
    this->capacity  =   2           ;
    this->size      =   0           ;
    this->data      =   new int[2]  ;
}

Vector::Vector(const Vector& instance) {
    this->allocateData(instance);

    this->size      =   instance.size       ;
    this->capacity  =   instance.capacity   ;
}

Vector::~Vector() {
    this->deallocateData();
}



Vector& Vector::operator=(const Vector& instance) {
    if (this != &instance) {
        int* temporary = new int[instance.capacity];

        try {
            for (unsigned int i = 0; i < instance.size; ++i) {
                temporary[i] = instance.data[i];
            }

            // Here there would not be any exceptions.
            // But, if the container is used for other
            // types, the operator = can throw a one.
        } catch (std::exception& exception) {
            delete[] temporary;

            temporary = nullptr;

            throw exception;
        }

        this->deallocateData();

        this->data      =   temporary           ;
        this->size      =   instance.size       ;
        this->capacity  =   instance.capacity   ;
    }

    return *this;
}



void Vector::pushBack(int element) {
    if (this->size == this->capacity) {
        this->resize();
    }

    this->data[this->size] = element;

    this->size = this->size + 1;
}

void Vector::popBack() {
    if (this->size == 0) {
        throw std::runtime_error("Empty Data Structure!");
    }

    this->size = this->size - 1;
}



void Vector::allocateData(const Vector& instance) {
    this->data = new int[instance.capacity];

    try {
        for (unsigned int i = 0; i < instance.size; ++i) {
            this->data[i] = instance.data[i];
        }

        // Here there would not be any exceptions.
        // But, if the container is used for other
        // types, the operator = can throw a one.
    } catch (std::exception& exception) {
        delete[] this->data;

        this->data = nullptr;

        throw exception;
    }
}

void Vector::deallocateData() {
    delete[] this->data;

    this->data = nullptr;
}



void Vector::resize() {
    int* temporary = new int[this->capacity * 2];

    try {
        for (unsigned int i = 0; i < size; ++i) {
            temporary[i] = this->data[i];
        }

        // Here there would not be any exceptions.
        // But, if the container is used for other
        // types, the operator = can throw a one.
    } catch (std::exception& exception) {
        delete[] temporary;

        temporary = nullptr;

        throw exception;
    }

    delete[] this->data;

    this->data = temporary;

    this->capacity = this->capacity * 2;
}



void Vector::print(std::ostream& stream) const noexcept {
    stream << "Vector Information: " << '\n';

    stream << "Size     :   "   << this->size       << '\n';
    stream << "Capacity :   "   << this->capacity   << '\n';
    
    stream << "Elements: ";

    for (unsigned int i = 0; i < this->size; ++i) {
        stream << this->data[i] << ' ';
    }

    stream << '\n';
}
