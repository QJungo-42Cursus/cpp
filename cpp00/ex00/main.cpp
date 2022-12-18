#include <cstring>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " \"sentence\"" << std::endl;
    return 0;
  }

  while (argc > 1) {
    std::string s1 = argv[1];
    for (std::string::iterator it = s1.begin(); it != s1.end(); it++)
      *it = toupper(*it);

    std::cout << s1 << " ";
    argc--;
    argv++;
  }

  std::cout << std::endl;
}
