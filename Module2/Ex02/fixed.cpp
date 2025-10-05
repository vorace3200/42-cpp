#include "fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value << factor;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << factor)); 
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = other.value;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.value;
    return *this;
}

float Fixed::toFloat() const
{
    return (float)this->value / (1 << factor);
}

int Fixed::toInt() const
{
    return this->value / (1 << factor);
}

int Fixed::getRawBits() const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

bool Fixed::operator>(const Fixed& other) const { return this->value > other.value; }
bool Fixed::operator<(const Fixed& other) const { return this->value < other.value; }
bool Fixed::operator>=(const Fixed& other) const { return this->value >= other.value; }
bool Fixed::operator<=(const Fixed& other) const { return this->value <= other.value; }
bool Fixed::operator==(const Fixed& other) const { return this->value == other.value; }
bool Fixed::operator!=(const Fixed& other) const { return this->value != other.value; }


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

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->value * other.value) >> factor);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->value << factor) / other.value);
    return result;
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
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->value--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}