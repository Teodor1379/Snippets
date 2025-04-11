#ifndef PERSON_HEADER_INCLUDED
#define PERSON_HEADER_INCLUDED



#include <cassert>
#include <cstring>


#include <exception>
#include <stdexcept>


#include <fstream>



class Person {
public:
    Person();

    Person(const char*, const char*, unsigned int, bool);

    Person(const Person&);

    ~Person();


public:
    Person& operator=(const Person&);


public:
    inline  const char* getFirstName()  const noexcept  { return this->firstName;   }
    inline  const char* getThirdName()  const noexcept  { return this->thirdName;   }
    
    inline  unsigned int    getAge()    const noexcept  { return this->age; }
    inline  bool            getSex()    const noexcept  { return this->sex; }


public:
    char*   allocateName    (unsigned int   );
    void    deallocateName  (char*&         );


public:
    bool    validateName(const char*) const noexcept;


public:
    void print(std::ostream&) const noexcept;


public:
    static unsigned int getID();


private:
    char* firstName;
    char* thirdName;

    unsigned int    age ;
    bool            sex ;

    unsigned int    self;

    static unsigned int ID;
};

#endif
