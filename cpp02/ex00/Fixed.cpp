#include "Fixed.h"
#include <iostream>

/* Constructors and destructor */
Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy constructor called" << std::endl;
  this->_rawBits = src.getRawBits();
}

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
