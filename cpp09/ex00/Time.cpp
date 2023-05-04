#include "Time.h"
#include <sstream>

Time::Time(std::string time)
{
	try
	{
		std::istringstream(time.substr(0, 4)) >> year;
		std::istringstream(time.substr(5, 2)) >> month;
		std::istringstream(time.substr(8, 2)) >> day;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		exit(1);
	}
}

Time::Time(int year, int month, int day) : year(year), month(month), day(day)
{}

Time::Time(const Time &orig)
{
	year = orig.year;
	month = orig.month;
	day = orig.day;
}

Time::~Time()
{}

Time &Time::operator=(const Time &orig)
{
	if (this != &orig)
	{
		year = orig.year;
		month = orig.month;
		day = orig.day;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Time &time)
{
	os << time.year << "-" << time.month << "-" << time.day;
	return os;
}
