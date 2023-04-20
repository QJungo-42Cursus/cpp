#include "BitcoinExchange.h"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() { _prices_time = _CSVtoMap("data.csv"); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig) {
  _prices_time = orig._prices_time;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &orig) {
  if (this != &orig) {
    _prices_time = orig._prices_time;
  }
  return *this;
}

std::map<Time, float> BitcoinExchange::_CSVtoMap(std::string filename) {
  std::map<Time, float> prices_time;
  std::string line;
  std::ifstream file(filename.c_str());
  std::getline(file, line); // skip first line
  while (std::getline(file, line)) {
    Time time(line.substr(0, 10));
    float price;
    try {
      std::stringstream(line.substr(11)) >> price;
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
      exit(1);
    }
    prices_time[time] = price;
  }
  return prices_time;
}
