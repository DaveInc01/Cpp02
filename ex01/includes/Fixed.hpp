#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed( void );
    Fixed(const Fixed& obj );
    // Fixed(Fixed *obj);
    Fixed( const int x );
    Fixed( const float float_x);
    ~Fixed();
    void operator = (const Fixed& obj);
    float toFloat (void) const;
    int toInt( void ) const;
    int  getRawBits( void ) const;
    void setRawBits( int const raw );
private:
    int x;
    static const int w;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fix_point);

#endif