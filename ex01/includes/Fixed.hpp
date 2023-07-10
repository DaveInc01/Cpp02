#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed( void );
    Fixed( Fixed& obj );
    ~Fixed();
    void operator = (const Fixed& obj);
    int  getRawBits( void ) const;
    void setRawBits( int const raw );
private:
    int x;
    static const int w;
};

#endif