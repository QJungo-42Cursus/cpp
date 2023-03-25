#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
#include <iostream>
#include <map>
#include <string>

class Time {
public:
  Time(std::string time);
  Time(int year, int month, int day);
  Time(const Time &orig);
  virtual ~Time();
  Time &operator=(const Time &orig);

  int year;
  int month;
  int day;
};

bool operator<(const Time &lhs, const Time &rhs);
bool operator>(const Time &lhs, const Time &rhs);
bool operator==(const Time &lhs, const Time &rhs);

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
