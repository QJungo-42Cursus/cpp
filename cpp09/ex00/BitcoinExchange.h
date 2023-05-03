#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <map>
#include "Time.h"

class BitcoinExchange
{
public:
	typedef unsigned int day;
	typedef unsigned int month;
	typedef unsigned int year;
	typedef std::map <year, std::map<month, std::map < day, float> > >
	prices_time;

	BitcoinExchange();

	BitcoinExchange(const BitcoinExchange &orig);

	virtual ~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &orig);

	float getValFromTime(const Time &time, float btc) const;

private:
	static prices_time _CSVtoMap(const std::string &filename);
	prices_time _prices_time;
};

#endif /* BITCOINEXCHANGE_H */
