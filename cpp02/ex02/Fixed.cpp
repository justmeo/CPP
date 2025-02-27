#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) 
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) 
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) 
{
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const 
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}


bool Fixed::operator>(const Fixed &other) const 
{
    return _fixedPointValue > other._fixedPointValue;
}
bool Fixed::operator<(const Fixed &other) const
{
    return _fixedPointValue < other._fixedPointValue;
}
bool Fixed::operator>=(const Fixed &other) const 
{
    return _fixedPointValue >= other._fixedPointValue;
}
bool Fixed::operator<=(const Fixed &other) const 
{
    return _fixedPointValue <= other._fixedPointValue;
}
bool Fixed::operator==(const Fixed &other) const 
{
    return _fixedPointValue == other._fixedPointValue;
}
bool Fixed::operator!=(const Fixed &other) const 
{
    return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const 
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const 
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const 
{
    Fixed result;
    long temp = static_cast<long>(this->_fixedPointValue) * other._fixedPointValue;
    result.setRawBits(static_cast<int>(temp >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const 
{
    Fixed result;
    if (other._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        result.setRawBits(0);
    } else {
        long temp = (static_cast<long>(this->_fixedPointValue) << _fractionalBits);
        result.setRawBits(static_cast<int>(temp / other._fixedPointValue));
    }
    return result;
}


Fixed &Fixed::operator++() 
{
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    _fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--() 
{
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    _fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}
