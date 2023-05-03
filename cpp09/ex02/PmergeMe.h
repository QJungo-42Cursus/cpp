#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>

class PmergeMe
{
public:
	~PmergeMe();

	PmergeMe(std::vector<unsigned int> &vector);

private:
	std::vector<unsigned int> _sorted;

	PmergeMe();

	PmergeMe(const PmergeMe &);

	PmergeMe &operator=(const PmergeMe &);
};

#endif
