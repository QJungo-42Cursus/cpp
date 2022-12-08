#include "Fixed.h"
#include <cmath>
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  // TODO rendre ca reel
  os << fixed.toFloat();
  return os;
}

/* Constructors */
Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

// TODO
Fixed::Fixed(const int n) : _rawBits(n) {
  std::cout << "Const int constructor called" << std::endl;
}

// TODO
Fixed::Fixed(const float n) : _rawBits(n) {
  std::cout << "Const float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy constructor called" << std::endl;
  this->_rawBits = src.getRawBits();
}

/* Destructor */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/* Operators overload */
Fixed &Fixed::operator=(Fixed const &rhs) {
  this->_rawBits = rhs.getRawBits();
  std::cout << "Assignation operator called" << std::endl;
  return *this;
}

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

// TODO
int Fixed::toInt() const { return (_rawBits); }

// TODO
float Fixed::toFloat() const { return (_rawBits); }