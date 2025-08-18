#include "fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
}
Fixed::Fixed(const int value)
{
    this->value = value << 8;
}

Fixed::Fixed(const float value)
{
    this->value = roundf(value * (1 << 8)); 
}

float Fixed::toFloat() const
{
    return (float)this->value / (1 << 8);
}

int Fixed::toInt() const
{
    return this->value >> 8;
}


Fixed::Fixed(const Fixed& other)
{
    this->value = other.value;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->value = other.value;
    
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}


Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->value * other.value) >> 8);
    return result;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->value + other.value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->value - other.value);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(((this->value << 8) / other.value));
    return result;
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->value != other.value;
}

Fixed Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed result(*this);
    this->value++;
    return result;
}

Fixed Fixed::operator--(int)
{
    Fixed result(*this);
    this->value--;
    return result;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a > b ? a : b;
}

