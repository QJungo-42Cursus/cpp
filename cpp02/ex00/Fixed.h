#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed {
public:
  /* Constructors and destructor */
  Fixed();
  Fixed(Fixed const &src);
  ~Fixed();

  /* Operators overload */
  Fixed &operator=(Fixed const &rhs);

  /* Getters and setters */
  int getRawBits() const;
  void setRawBits(int const raw);

private:
  /// entier qui contient la valeur de la partie fixe
  int _rawBits;
  /// nombre de bits de la partie fractionnaire
  static const int _fractionalBits = 8;
};

#endif /* FIXED_H */
