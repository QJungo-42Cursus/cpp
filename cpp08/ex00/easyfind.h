#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> int easyfind(T container, int i) {
  // TODO check si c'est un container / de int ?

  auto res = std::find(container.begin(), container.end(), i);
  if (res != container.end()) {
    return (*res);
  } else {
    throw std::exception();
  }
}

#endif /* EASYFIND_H */
