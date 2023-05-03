#include "Time.h"
#include <sstream>
#include <cstdlib>

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

bool operator==(const Time &lhs, const Time &rhs)
{
	return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}

bool operator<(const Time &lhs, const Time &rhs)
{
	if (lhs == rhs)
		return false;
	if (lhs.year < rhs.year)
		return true;
	if (lhs.year > rhs.year)
		return false;
	if (lhs.month < rhs.month)
		return true;
	if (lhs.month > rhs.month)
		return false;
	return lhs.day < rhs.day;
}

bool operator>(const Time &lhs, const Time &rhs)
{
	return !(lhs < rhs) && !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const Time &time)
{
	os << time.year << "-" << time.month << "-" << time.day;
	return os;
}