#include "./includes/Fixed.hpp"

Fixed::Fixed(){
    this->x = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->x = obj.getRawBits();
}

Fixed::Fixed(const int x)
{
    this->x = x;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_x)
{
    int scaledValue = static_cast<int>(float_x * 256); 
    
    std::cout << "Float constructor called" << std::endl;
}

const int Fixed::w = 8;

void Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->x = obj.getRawBits();
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

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}