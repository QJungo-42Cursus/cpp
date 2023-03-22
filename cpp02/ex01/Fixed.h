#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed {
public:
  /* Constructors and destructor */
  Fixed();
  Fixed(const int n);
  Fixed(const float n);
  Fixed(Fixed const &src);
  ~Fixed();

  /* Operators overload */
  Fixed &operator=(Fixed const &rhs);

  /* Getters and setters */
  int getRawBits() const;
  void setRawBits(int const raw);

  /* Converters */
  int toInt() const;
  float toFloat() const;

private:
  /// entier qui contient la valeur de la partie fixe
  int _rawBits;
  /// nombre de bits de la partie fractionnaire
  static const int _fractionalBits = 8;

public: // TODO private
  int _getFractionalValue() const;
  int _getIntegerValue() const;

  static const int _intMax = 256 * 256 * 256 - 1;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif /* FIXED_H */
