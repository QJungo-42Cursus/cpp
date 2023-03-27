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
  Fixed operator+(Fixed const &rhs) const;
  Fixed operator-(Fixed const &rhs) const;
  Fixed operator*(Fixed const &rhs) const;
  Fixed operator/(Fixed const &rhs) const;
  bool operator>(Fixed const &rhs) const;
  bool operator<(Fixed const &rhs) const;
  bool operator>=(Fixed const &rhs) const;
  bool operator<=(Fixed const &rhs) const;
  bool operator==(Fixed const &rhs) const;
  bool operator!=(Fixed const &rhs) const;
  // pre-incrementation
  Fixed &operator++();
  Fixed &operator--();
  // post-incrementation
  Fixed operator++(int);
  Fixed operator--(int);

  /* Getters and setters */
  int getRawBits() const;
  void setRawBits(int const raw);

  /* Converters */
  int toInt() const;
  float toFloat() const;

  /* Comparators */
  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static Fixed const &min(Fixed const &a, Fixed const &b);
  static Fixed const &max(Fixed const &a, Fixed const &b);

private:
  /// entier qui contient la valeur de la partie fixe
  int _rawBits;
  /// nombre de bits de la partie fractionnaire
  static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif /* FIXED_H */
