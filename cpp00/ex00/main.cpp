#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " \"sentence\"" << std::endl;
    return 0;
  }

  while (argc > 1) {
    std::string s1 = argv[1];
    // TODO trouver une autre fonction
    // std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    std::cout << s1 << " ";
    argc--;
    argv++;
  }

  std::cout << std::endl;
  return 0;
}
