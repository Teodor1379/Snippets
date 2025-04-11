#ifndef ARRAY_HEADER_INCLUDED
#define ARRAY_HEADER_INCLUDED



#include <exception>
#include <stdexcept>

#include <fstream>



#define MAX 256



class Array {
public:
    Array();


public:
    void push   (int);
    void pop    (   );

public:
    inline bool empty()    const    { return this->size == 0;   };


public:
    inline int& front   ()  noexcept  { return this->data[0]        ;   }   // No throw guarantee!
    inline int& back    ()  noexcept  { return this->data[MAX - 1]  ;   }   // No throw guarantee!

    const int& front()  const noexcept  { return this->data[0]      ;   }   // No throw guarantee!
    const int& back ()  const noexcept  { return this->data[MAX - 1];   }   // No throw guarantee!


public:
    void print(std::ostream&) const noexcept;

private:
    unsigned int    size        ;
    int             data[256]   ;
};


#endif
