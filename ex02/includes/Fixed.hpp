#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed( void );
    Fixed(const Fixed& obj );
    Fixed( const int x );
    Fixed( const float float_x);
    ~Fixed();
    float toFloat (void) const;
    int toInt( void ) const;
    int  getRawBits( void ) const;
    void setRawBits( int const raw );
    void operator=(const Fixed& other);
    // math operators
    const Fixed& operator-(const Fixed &other);
    const Fixed& operator+(const Fixed &other);
    const Fixed& operator*(const Fixed &other);
    const Fixed& operator/(const Fixed &other);
    // logical opertors
    bool operator==(Fixed &other);
    bool operator>(Fixed &other);
    bool operator<(Fixed &other);
    bool operator>=(Fixed &other);
    bool operator<=(Fixed &other);
    bool operator!=(Fixed &other);
    // iterators
    float operator++( void );
    float operator++( int );
    float operator--(void );
    float operator--(int );
    // Math methods
    int sum(Fixed &other);
    int minus(Fixed &other);
    int divide(Fixed &other);
    int multiple(Fixed &other);
    // static memmber functions
    static Fixed& min(Fixed &x, Fixed &y);
    static const Fixed& min(const Fixed &x, const Fixed &y);
    static Fixed& max(Fixed &x, Fixed &y);
    static const Fixed& max(const Fixed &x, const Fixed &y);
private:
    int x;
    static const int w;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fix_point);

#endif