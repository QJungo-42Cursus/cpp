#include <cstdlib>
#include "BitcoinExchange.h"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
	_prices_time = _CSVtoMap("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig)
{
	_prices_time = orig._prices_time;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &orig)
{
	if (this != &orig)
	{
		_prices_time = orig._prices_time;
	}
	return *this;
}

BitcoinExchange::prices_time BitcoinExchange::_CSVtoMap(const std::string &filename)
{
	BitcoinExchange::prices_time prices_time;
	std::string line;
	std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Could not open file" << std::endl;
        exit(1);
    }
	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		Time time(line.substr(0, 10));
		float price;
		try
		{
			std::stringstream(line.substr(11)) >> price;
		} catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			exit(1);
		}
		prices_time[time.year][time.month][time.day] = price;
	}
    file.close();
	return prices_time;
}

template<typename T>
unsigned int find_latest(T map, unsigned int i, unsigned int min)
{
	for (; i >= min; i--)
		if (map.count(i) != 0)
			return i;
	return 0;
}

float find_from_last_day(const BitcoinExchange::prices_time &prices_time, const Time &time)
{
	unsigned int latest_day = find_latest(prices_time.at(time.year).at(time.month), time.day, 1);
	if (latest_day == 0)
		throw std::runtime_error("no data for this date (too early)");
	return prices_time.at(time.year).at(time.month).at(latest_day);
}

float find_from_last_month(const BitcoinExchange::prices_time &prices_time, const Time &time)
{
	unsigned int latest_month = find_latest(prices_time.at(time.year), time.month, 1);
	if (latest_month == 0)
		throw std::runtime_error("no data for this date (too early)");
	return find_from_last_day(prices_time, Time(time.year, (int) latest_month, 32));
}

float find_from_last_year(const BitcoinExchange::prices_time &prices_time, const Time &time)
{
	unsigned int latest_year = find_latest(prices_time, time.year, 2009);
	if (latest_year == 0)
		throw std::runtime_error("no data for this date (too early)");
	return find_from_last_month(prices_time, Time((int) latest_year, 13, 32));
}


float BitcoinExchange::getValFromTime(const Time &time, float btc) const
{
	if (_prices_time.count(time.year) == 0)
	{
		return find_from_last_year(_prices_time, time) * btc;
	}
	if (_prices_time.at(time.year).count(time.month) == 0)
	{
		return find_from_last_month(_prices_time, time) * btc;
	}
	if (_prices_time.at(time.year).at(time.month).count(time.day) == 0)
	{
		return find_from_last_day(_prices_time, time) * btc;
	}
	return _prices_time.at(time.year).at(time.month).at(time.day) * btc;
}
