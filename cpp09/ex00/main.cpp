#include "BitcoinExchange.h"






int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
  BitcoinExchange bitcoinExchange;
  return 0;
}
