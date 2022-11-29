#include <iostream>
#include <bits/stdc++.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    // std::cout << "Usage: " << argv[0] << " \"sentence\"" << std::endl;
    return 0;
  }
  std::string s1 = argv[1];
  transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
  std::cout << s1 << std::endl;
  return 0;
}
