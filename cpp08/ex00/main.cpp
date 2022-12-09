#include "easyfind.h"
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

#include <stack>

template <typename T> void test() {
  int to_find = 2;
  T ints = {2, 5, 6, 5};
  try {
    std::cout << "trouve : " << easyfind(ints, to_find) << std::endl;
  } catch (std::exception &e) {
    std::cout << "pas trouve :< " << std::endl;
  }
}

template <typename T> void test_fail() {
  int to_find = 9;
  T ints = {2, 5, 6, 5};
  try {
    std::cout << "trouve : " << easyfind(ints, to_find) << std::endl;
  } catch (std::exception &e) {
    std::cout << "pas trouve :< " << std::endl;
  }
}

int main(void) {
  test_fail<std::vector<int>>();
  test_fail<std::list<int>>();
  test_fail<std::array<int, 4>>();
  test_fail<std::deque<int>>();
  test_fail<std::forward_list<int>>();

  test<std::vector<int>>();
  test<std::list<int>>();
  test<std::array<int, 4>>();
  test<std::deque<int>>();
  test<std::forward_list<int>>();

  /*  Pas d'iterator sur les stack
std::stack<int> ints;
int to_find = 2;
ints.push(2);
ints.push(5);
try {
std::cout << "trouve : " << easyfind(ints, to_find) << std::endl;
} catch (std::exception &e) {
std::cout << "pas trouve :< " << std::endl;
}
return (0);
  */
}
