#include "easyfind.h"
#include <iostream>
#include <deque>
#include <list>
#include <vector>

template <typename T>
void test(int to_find)
{
  T ints(4);
  ints.push_back(2);
  ints.push_back(5);
  ints.push_back(6);
  ints.push_back(5);
  try
  {
    std::cout << "trouve : " << easyfind(ints, to_find) << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "pas trouve :< " << std::endl;
  }
}

int main(void)
{
  test<std::vector<int> >(2);
  test<std::list<int> >(2);
  test<std::deque<int> >(2);

  test<std::vector<int> >(88);
  test<std::list<int> >(88);
  test<std::deque<int> >(88);
  return (0);
}