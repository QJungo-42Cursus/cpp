#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

bool impossible(double d)
{
  return std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max();
}

double to_double(std::string str)
{
  if (str == "nan" || str == "nanf")
    return std::numeric_limits<double>::quiet_NaN();
  if (str == "+inf" || str == "+inff")
    return std::numeric_limits<double>::infinity();
  if (str == "-inf" || str == "-inff")
    return -std::numeric_limits<double>::infinity();
  if (str == "inf" || str == "inff")
    return std::numeric_limits<double>::infinity();

  try
  {
    double d;
    std::stringstream(str) >> d;
    return d;
  }
  catch (std::exception &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    exit(1);
  }
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
    return 1;
  }

  std::string str = argv[1];
  double double_ = to_double(str);

  float float_ = static_cast<float>(double_);
  int int_ = static_cast<int>(double_);
  char char_ = static_cast<char>(int_);

  if (isprint(char_))
    std::cout << "char: '" << char_ << "'" << std::endl;
  else if (impossible(double_))
    std::cout << "char: impossible" << std::endl;
  else
    std::cout << "char: non printable" << std::endl;

  if (impossible(double_))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << int_ << std::endl;

  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << float_ << "f" << std::endl;
  std::cout << "double: " << double_ << std::endl;
  return 0;
}
