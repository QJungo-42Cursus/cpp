#include <iostream>

struct Time {
public:
  Time(std::string time);
  Time(int year, int month, int day);
  Time(const Time &orig);
  virtual ~Time();
  Time &operator=(const Time &orig);

  int year;
  int month;
  int day;

private:
  Time();
};

bool operator<(const Time &lhs, const Time &rhs);
bool operator>(const Time &lhs, const Time &rhs);
bool operator==(const Time &lhs, const Time &rhs);
