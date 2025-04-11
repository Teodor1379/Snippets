#ifndef VECTOR_HEADER_INCLUDED
#define VECTOR_HEADER_INCLUDED



#include <exception>
#include <stdexcept>

#include <fstream>



class Vector {
public:
    Vector();

    Vector(const Vector&);

    ~Vector();


public:
    Vector& operator=(const Vector&);


public:
    inline  unsigned int    getSize     ()  const noexcept  {   return this->size       ;   }
    inline  unsigned int    getCapacity ()  const noexcept  {   return this->capacity   ;   }


public:
    void pushBack(int element   );
    void  popBack(              );


private:
    void   allocateData (const Vector&  );
    void deallocateData (               );


private:
    void resize();


public:
    int&    front   ()  {   return this->data[0]                ;   }   // No throw guarantee!
    int&    back    ()  {   return this->data[this->size - 1]   ;   }   // No throw guarantee!

    const int&  front   ()  const   {   return this->data[0]                ;   }   // No throw guarantee!
    const int&  back    ()  const   {   return this->data[this->size - 1]   ;   }   // No throw guarantee!



public:
    void print(std::ostream&) const noexcept;


private:
    unsigned int    size    ;
    unsigned int    capacity;
    int*            data    ;
};

#endif
