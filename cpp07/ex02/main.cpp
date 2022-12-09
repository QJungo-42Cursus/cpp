#include "Array.h"
#include <iostream>

int main(void) {
  /// Empty list
  Array<int> intA(4);
  std::cout << "List size: " << intA.size() << std::endl;
  intA[0] = 2;
  for (int i = 0; i < intA.size(); i++) {
    std::cout << "intA[" << i << "]: " << intA[i] << std::endl;
  }
  std::cout << std::endl;

  /// deep copy of a list
  Array<int> intAcpy(intA);
  intAcpy[3] = 3453;
  intA[3] = -4;
  for (int i = 0; i < intAcpy.size(); i++) {
    std::cout << "intAcpy[" << i << "]: " << intAcpy[i] << std::endl;
  }
  for (int i = 0; i < intA.size(); i++) {
    std::cout << "intA[" << i << "]: " << intA[i] << std::endl;
  }
  std::cout << std::endl;

  /// asignation of a list
  intA = intAcpy;
  for (int i = 0; i < intAcpy.size(); i++) {
    std::cout << "intAcpy[" << i << "]: " << intAcpy[i] << std::endl;
  }
  for (int i = 0; i < intA.size(); i++) {
    std::cout << "intA[" << i << "]: " << intA[i] << std::endl;
  }
  std::cout << std::endl;

  /// Bug
  int index = 8;
  try {
    std::cout << "intA[" << index << "]: " << intA[index] << std::endl;
  } catch (std::exception &e) {
    std::cout << "oups : " << e.what() << std::endl;
  }
  index = -1;
  try {
    std::cout << "intA[" << index << "]: " << intA[index] << std::endl;
  } catch (std::exception &e) {
    std::cout << "oups : " << e.what() << std::endl;
  }
  // std::cout << "intA[" << 8 << "]: " << intA[8] << std::endl;
}
