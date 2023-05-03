#include "PmergeMe.h"


typedef std::vector<std::vector<unsigned int> > t_groups;

static const unsigned int GROUP_SIZE = 5;


static t_groups merge(const t_groups &a, const t_groups &b)
{
	if (a[0][0] > b[0][0])
	{
		t_groups n = b;
		n.insert(n.end(), a.begin(), a.end());
		return n;
	}
	else
	{
		t_groups n = a;
		n.insert(n.end(), b.begin(), b.end());
		return n;
	}
}

static void insert_sort(std::vector<unsigned int> &vec)
{

}

static t_groups merge_sort(t_groups &groups)
{
	if (groups.empty())
	{
		throw std::exception();
	}
	if (groups.size() == 1)
	{
		return groups;
	}
	unsigned int left_size = groups.size() / 2;
//	unsigned int right_size = groups.size() / 2 + groups.size() % 2;

	t_groups left(groups.begin(), groups.begin() + left_size);
	left = merge_sort(left);
	t_groups right(groups.begin() + left_size, groups.end());
	right = merge_sort(right);
	return merge(left, right);
}

PmergeMe::PmergeMe(std::vector<unsigned int> &vector)
{
	/// Splitting into groups
	t_groups groups;
	for (unsigned int i = 0; i < vector.size(); i += GROUP_SIZE)
	{
		std::vector<unsigned int> group;
		for (unsigned int j = 0; j < GROUP_SIZE && i + j < vector.size(); j++)
			group.push_back(vector[i + j]);
		groups.push_back(group);
	}

	/// Insert sort all groups
	for (unsigned int i = 0; i < groups.size(); i++)
		insert_sort(groups[i]);

	/// Merge sort the groups
}

PmergeMe::~PmergeMe()
{

}
