#include "Fixed.h"
#include <iostream>

/// Debug helper
static void showbits(unsigned int x) {
  int i = 0;
  for (i = (sizeof(int) * 8) - 1; i >= 0; i--) {
    putchar(x & (1u << i) ? '1' : '0');
    if (i % 8 == 0)
      putchar(' ');
  }
  printf("\n");
}

// TODO 256 * 256 * 256 -1 -> le nouveau int max !!! (pour fixed)

int main() {
  {
    Fixed const b(256 * 256 * 256 - 1);
    int fractional = b._getIntegerValue();
	showbits(fractional);
	std::cout << fractional << std::endl;
  }
  /*
  Fixed a;
  Fixed const b(1);
  Fixed const c(42.42f);
  Fixed const d(b);

  a = Fixed(1234.4321f);
  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;
  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;
  */
}
