#include "Person.hpp"



unsigned int Person::ID = 1;



Person::Person() {
    try {
        this->firstName = this->allocateName(0);
        this->thirdName = this->allocateName(0);

        this->firstName[0] = '\0';
        this->thirdName[0] = '\0';
    } catch (std::bad_alloc& exception) {
        this->deallocateName(this->firstName);

        throw;
    }

    this->age   = 0                 ;
    this->sex   = false             ;
    this->self  = Person::getID()   ;
}

Person::Person(const char* firstName, const char* thirdName, unsigned int age, bool sex) {
    if (
        !validateName(firstName)    ||
        !validateName(thirdName)
    ) {
        throw std::invalid_argument("Invalid Person Names!");
    }

    try {
        this->firstName =   this->allocateName(strlen(firstName));
        this->thirdName =   this->allocateName(strlen(thirdName));
        
        strcpy(this->firstName, firstName);
        strcpy(this->thirdName, thirdName);
    } catch (std::bad_alloc& exception) {
        this->deallocateName(this->firstName);

        throw; 
    }

    this->age   =   age             ;
    this->sex   =   sex             ;
    this->self  =   Person::getID() ;
}

Person::Person(const Person& instance) {
    char*   newFirstName = nullptr;
    char*   newThirdName = nullptr;

    try {
        newFirstName    =   this->allocateName(strlen(instance.firstName));
        newThirdName    =   this->allocateName(strlen(instance.thirdName));

        strcpy(newFirstName, instance.firstName);
        strcpy(newThirdName, instance.thirdName);
    } catch (std::bad_alloc& exception) {
        this->deallocateName(newFirstName);

        throw; 
    }

    this->firstName = newFirstName;
    this->thirdName = newThirdName;

    this->age   =   instance.age    ;
    this->sex   =   instance.sex    ;
    this->self  =   Person::getID() ;
}

Person::~Person() {
    this->deallocateName(this->firstName);
    this->deallocateName(this->thirdName);
}



Person& Person::operator=(const Person& instance) {
    if (this != &instance) {
        char*   newFirstName    =   nullptr;
        char*   newThirdName    =   nullptr;

        try {
            newFirstName = this->allocateName(strlen(instance.firstName));
            newThirdName = this->allocateName(strlen(instance.thirdName));

            strcpy(newFirstName, instance.firstName);
            strcpy(newThirdName, instance.thirdName);
        } catch (std::bad_alloc& exception) {
            this->deallocateName(newFirstName);

            throw;
        }

        this->deallocateName(this->firstName);
        this->deallocateName(this->thirdName);

        this->firstName = newFirstName;
        this->thirdName = newThirdName;

        this->age   = instance.age  ;
        this->sex   = instance.sex  ;
        this->self  = instance.self ;
    }

    return *this;
}



char* Person::allocateName(unsigned int size) {
    char* name = new char[size + 1];

    return name;
}

void Person::deallocateName(char*& name) {
    delete[] name;

    name = nullptr;
}



bool Person::validateName(const char* name) const noexcept {
    if (name == nullptr) {
        return false;
    }

    if (name[0] == '\0') {
        return false;
    }

    if (name[0] < 'A' || name[0] > 'Z') {
        return false;
    }

    for (unsigned int i = 1; name[i] != '\0'; ++i) {
        if (name[i] < 'a' || name[i] > 'z') {
            return false;
        }
    }

    return true;
}



void Person::print(std::ostream& stream) const noexcept {
    stream << "Person Information: " << '\n';

    stream << "First Name   : " << this->firstName  << '\n';
    stream << "Third Name   : " << this->thirdName  << '\n';
    stream << "Age          : " << this->age        << '\n';
    stream << "Sex          : " << this->sex        << '\n';
    stream << "ID           : " << this->self       << '\n';

    stream << '\n';
}



unsigned int Person::getID() { return Person::ID++; }
