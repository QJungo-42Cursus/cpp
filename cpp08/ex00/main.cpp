#include "easyfind.h"
#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

#define INTS ints = {2, 5, 6, 5}

template <typename T> void test(T ints) {
  try {
    int res = easyfind(ints, 5);
    std::cout << "salut : " << res << std::endl;
  } catch (std::exception &e) {
    std::cout << "pas trouve :< " << std::endl;
  }
}

int main(void) {
  {
    std::vector<int> INTS;
    test<std::vector<int>>(ints);
  }
  {
    std::list<int> INTS;
    test<std::list<int>>(ints);
  }
  {
    std::array<int, 4> INTS;
    test<std::array<int, 4>>(ints);
  }
  {
    std::deque<int> INTS;
    test<std::deque<int>>(ints);
  }
  {
    std::forward_list<int> INTS;
    test<std::forward_list<int>>(ints);
  }
  return (0);
}
