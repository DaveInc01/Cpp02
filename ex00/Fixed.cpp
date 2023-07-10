#include "./includes/Fixed.hpp"

Fixed::Fixed(){
    this->x = 0;
}

Fixed::Fixed(Fixed &obj)
{
    x = obj.x;
}