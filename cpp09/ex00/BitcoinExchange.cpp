#include "BitcoinExchange.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

/******** BitcoinExchange ********/

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

/******** Time ********/

Time::Time(std::string time) {
  try {
    std::istringstream(time.substr(0, 4)) >> year;
    std::istringstream(time.substr(5, 2)) >> month;
    std::istringstream(time.substr(8, 2)) >> day;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
    exit(1);
  }
}

Time::Time(int year, int month, int day) : year(year), month(month), day(day) {}

Time::Time(const Time &orig) {
  year = orig.year;
  month = orig.month;
  day = orig.day;
}

Time::~Time() {}

Time &Time::operator=(const Time &orig) {
  if (this != &orig) {
    year = orig.year;
    month = orig.month;
    day = orig.day;
  }
  return *this;
}

bool operator<(const Time &lhs, const Time &rhs) {
  if (lhs.year < rhs.year) {
    return true;
  } else if (lhs.year == rhs.year) {
    if (lhs.month < rhs.month) {
      return true;
    } else if (lhs.month == rhs.month) {
      if (lhs.day < rhs.day) {
        return true;
      }
    }
  }
  return false;
}

bool operator>(const Time &lhs, const Time &rhs) {
  if (lhs.year > rhs.year) {
    return true;
  } else if (lhs.year == rhs.year) {
    if (lhs.month > rhs.month) {
      return true;
    } else if (lhs.month == rhs.month) {
      if (lhs.day > rhs.day) {
        return true;
      }
    }
  }
  return false;
}

bool operator==(const Time &lhs, const Time &rhs) {
  if (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day) {
    return true;
  }
  return false;
}
