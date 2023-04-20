#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
#include <iostream>
#include <map>
#include "Time.h"

class BitcoinExchange {
public:
  /* ... */
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &orig);
  virtual ~BitcoinExchange();
  BitcoinExchange &operator=(const BitcoinExchange &orig);

private:
  static std::map<Time, float> _CSVtoMap(std::string filename);
  std::map<Time, float> _prices_time;
};

#endif /* BITCOINEXCHANGE_H */
