#include "PmergeMe.h"
#include <stdexcept>
#include <iostream>

typedef std::vector<std::vector<unsigned int> > t_groups;


static t_groups merge(const t_groups &left, const t_groups &right) {
    t_groups result;
    unsigned i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i][0] < right[j][0]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }
    for (; i < left.size(); i++)
        result.push_back(left[i]);
    for (; j < right.size(); j++)
        result.push_back(right[j]);
    return result;
}

static void insert_sort(std::vector<unsigned int> &vec) {
    unsigned int tmp;
    for (unsigned int i = 1; i < vec.size(); i++) {
        unsigned int j = i;
        while (j > 0 && vec[j - 1] > vec[j]) {
            tmp = vec[j - 1];
            vec[j - 1] = vec[j];
            vec[j] = tmp;
            j--;
        }
    }
}

static t_groups merge_sort(t_groups &groups) {
    if (groups.empty())
        throw std::runtime_error("Empty vector");
    if (groups.size() == 1)
        return groups;
    t_groups left(groups.begin(), groups.begin() + groups.size() / 2);
    t_groups right(groups.begin() + groups.size() / 2, groups.end());
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
}

static const unsigned int GROUP_SIZE = 5;

PmergeMe::PmergeMe(std::vector<unsigned int> &vector) {
    std::vector<unsigned int> result = vector;
    for (unsigned int group_size = GROUP_SIZE; group_size > 0; group_size /= 2) {
        /// Splitting into groups
        t_groups groups;
        for (unsigned int i = 0; i < result.size(); i += group_size) {
            std::vector<unsigned int> group;
            for (unsigned int j = 0; j < group_size && i + j < result.size(); j++)
                group.push_back(result[i + j]);
            groups.push_back(group);
        }
        result.clear();

        /// Insert sort all groups
        for (unsigned int i = 0; i < groups.size(); i++)
            insert_sort(groups[i]);

        /// Merge sort the groups
        groups = merge_sort(groups);
        for (unsigned int i = 0; i < groups.size(); i++)
            for (unsigned int j = 0; j < groups[i].size(); j++)
                result.push_back(groups[i][j]);
    }

    /// Display the result
//    std::cout << "PmergeMe: ";
//    for (unsigned int i = 0; i < result.size(); i++) {
//        std::cout << result[i] << " ";
//    }
//    std::cout << std::endl;
}

PmergeMe::~PmergeMe() {}
