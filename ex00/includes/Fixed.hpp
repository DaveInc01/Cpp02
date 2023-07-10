#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed( void );
    Fixed( Fixed& obj );
private:
    int x;
    static const int w;
};

#endif