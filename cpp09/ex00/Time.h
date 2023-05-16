#include <iostream>
#include <sstream>
#include <cstdlib>

struct Time {
public:
    Time(std::string time);

    Time(int year, int month, int day);

    Time(const Time &orig);

    ~Time();

    int year;
    int month;
    int day;

private:
    Time();

    Time &operator=(const Time &orig);
};

std::ostream &operator<<(std::ostream &os, const Time &time);
