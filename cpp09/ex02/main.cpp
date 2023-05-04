#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <set>
#include <csignal>
#include <ctime>
#include <iomanip>
#include <sys/time.h>
#include "PmergeMe.h"

static bool is_valid_arg(char *arg)
{
	int i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (false);
		i++;
	}
	long val = atol(arg);
	if (val < 0 || val > std::numeric_limits<unsigned int>::max())
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	struct timeval start, end, start_vector, end_vector;
	gettimeofday(&start, NULL);

	if (argc == 1)
	{
		std::cout << "No arguments" << std::endl;
		return (1);
	}

	std::set<unsigned int> set;
	std::vector<unsigned int> vector;
	for (int i = 1; i < argc; i++)
	{
		if (!is_valid_arg(argv[i]))
		{
			std::cout << "Invalid argument" << std::endl;
			return (1);
		}
		unsigned int val = atol(argv[i]);
		if (set.count(val) == 0)
		{
			vector.push_back(val);
			set.insert(val);
		}
		else
		{
			std::cout << "Duplicate argument" << std::endl;
			return (1);
		}
	}

	std::cout << "before: ";
	for (std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	gettimeofday(&end, NULL);
	double common_time_us = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	
	std::cout << "after: ";
	for (std::set<unsigned int>::iterator it = set.begin(); it != set.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time for set: \t\t" << std::fixed << std::setprecision(3) << common_time_us / 1000.0 << " ms" << std::endl;
	
	gettimeofday(&start_vector, NULL);
	PmergeMe pmerge_me(vector);
	gettimeofday(&end_vector, NULL);
	double vec_time_us = (end_vector.tv_sec - start_vector.tv_sec) * 1000000.0 + (end_vector.tv_usec - start_vector.tv_usec) + common_time_us;
	std::cout << "Time for vector: \t" << std::fixed << std::setprecision(3) << vec_time_us / 1000.0 << " ms" << std::endl;
}
