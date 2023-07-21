#include "./includes/Fixed.hpp"

const int Fixed::w = 8;

Fixed::Fixed(){
    this->x = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->x = obj.x;
}

Fixed::Fixed(const int int_x)
{
    this->x = (int_x * 256);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_x)
{
    this->x = (float_x * 256);
    std::cout << "Float constructor called" << std::endl;
}


void Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->x = other.x;
}

float Fixed::toFloat (void) const
{
    float result = this->x / 256;
    int fractional = this->x % 256;
    result += (float )fractional / 256;

    return(result);
}

int Fixed::toInt( void ) const
{
    return (this->x / 256);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" <<std::endl;
    return (this->x);
}

void Fixed::setRawBits( int const raw )
{
    this->x = raw;
    std::cout << "setRawBits member function called";
}

std::ostream &operator<<(std::ostream &os, Fixed const &fix_point)
{
    return os << fix_point.toFloat();
}

//Logical operators

bool Fixed::operator==(Fixed &other){
    if (this->x == other.x)
        return(true);
    return(false);
}

bool Fixed::operator>(Fixed &other){
    if (this->x > other.x)
        return(true);
    return(false);
}
bool Fixed::operator<(Fixed &other){
    if (this->x < other.x)
        return(true);
    return(false);
}
bool Fixed::operator>=(Fixed &other){
    if (this->x >= other.x)
        return(true);
    return(false);
}
bool Fixed::operator<=(Fixed &other){
    if (this->x <= other.x)
        return(true);
    return(false);
}
bool Fixed::operator!=(Fixed &other){
    if (this->x != other.x)
        return(true);
    return(false);
}

// Math operators

const Fixed& Fixed::operator+(const Fixed &other)
{
    Fixed *res = new(Fixed);
    res->x = this->x + other.x;

    return (*res);
}

const Fixed& Fixed::operator-(const Fixed &other)
{
    Fixed *res = new(Fixed);
    res->x = this->x - other.x;

    return (*res);
}

const Fixed& Fixed::operator*(const Fixed &other)
{
    Fixed *res = new(Fixed);
    res->x = (this->x * other.x) / 256;
    return (*res);
}

const Fixed& Fixed::operator/(const Fixed &other)
{
    Fixed *res = new(Fixed);
    res->x = (this->toFloat() / other.toFloat()) * 256;
    return (*res);
}

// Itarators

float Fixed::operator++( void )
{
    this->x += 1;
    return this->toFloat();
}

float Fixed::operator++( int )
{
    float tmp = this->toFloat();
    this->x += 1;
    return tmp; 
}

float Fixed::operator--( void )
{
    this->x -= 1;
    return this->toFloat();
}

float Fixed::operator--( int )
{
    float tmp = this->toFloat();
    this->x -= 1;
    return tmp; 
}

// static member functions

Fixed& Fixed::min(Fixed &x, Fixed &y)
{
    if (x < y){
        return (x);
    }
    return (y); 
}

const Fixed& Fixed::min(const Fixed &x, const Fixed &y)
{
    if (x.toFloat() < y.toFloat()){
        return (x);
    }
    return (y); 
}

const Fixed& Fixed::max(const Fixed &x, const Fixed &y)
{
    if (x.toFloat() > y.toFloat()){
        return (x);
    }
    return (y); 
}

Fixed& Fixed::max(Fixed &x, Fixed &y)
{
    if (x < y){
        return (x);
    }
    return (y); 
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}