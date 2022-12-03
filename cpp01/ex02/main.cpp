#include <iostream>

int main() {
  std::string hi = "HI THIS IS BRAIN";
  std::string *stringPTR = &hi;
  std::string &stringREF = hi;

  std::cout << &hi << std::endl;
  std::cout << stringPTR << std::endl;
  std::cout << &stringREF << std::endl;

  std::cout << hi << std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;
  return 0;
}
