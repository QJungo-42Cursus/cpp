#include "Fixed.h"
#include <cmath>
#include <iostream>

static int ft_pow(int value, unsigned int power) {
  if (power == 0)
    return 1;
  if (power == 1)
    return value;
  return pow(value, power - 1) * value;
}

/* Constructors */
Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
  std::cout << "Const int constructor called" << std::endl;
  this->_rawBits = n << Fixed::_fractionalBits;
}

Fixed::Fixed(const float n) {
  std::cout << "Const float constructor called" << std::endl;
  this->_rawBits = roundf(n * (float)ft_pow(2, Fixed::_fractionalBits));
}

Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy constructor called" << std::endl;
  this->_rawBits = src.getRawBits();
}

/* Operators overload */
Fixed &Fixed::operator=(Fixed const &rhs) {
  this->_rawBits = rhs.getRawBits();
  std::cout << "Assignation operator called" << std::endl;
  return *this;
}

/* Destructor */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/* Getters and setters */
int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_rawBits;
}
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = raw;
}

/* Converters */
int Fixed::toInt() const { return _rawBits >> Fixed::_fractionalBits; }

float Fixed::toFloat() const {
  return _rawBits / (float)ft_pow(2, Fixed::_fractionalBits);
}

/* Operators overload */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
