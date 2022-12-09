#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
    return 1;
  }
  std::string str = argv[1];
  double double_ = std::stod(str);
  // TODO gestion des expeptions !
  float float_ = static_cast<float>(double_);
  int int_ = static_cast<int>(double_);
  char char_ = static_cast<char>(int_);

  /// permet d'afficher un chiffre apres la virgule
  std::cout << std::fixed;
  std::cout << std::setprecision(1);

  if (isprint(char_)) {
    std::cout << "char: " << char_ << std::endl;
  } else if (std::isnan(double_)) {
    std::cout << "char: impossible" << std::endl;
  } else {
    std::cout << "char: non printable" << std::endl;
  }
  if (std::isnan(double_)) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << int_ << std::endl;
  }
  std::cout << "float: " << float_ << "f" << std::endl;
  std::cout << "double: " << double_ << std::endl;

  return 0;
}
