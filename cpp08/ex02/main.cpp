#include "MutantStack.h"
#include <iostream>
#include <vector>

void other_test() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  std::vector<int>::iterator it = v.begin();
  for (int i = 0; i < 50; i++) {
    std::cout << *it << std::endl;
    it++;
  }
}

int main(void) {
  other_test();
  return 0;

  MutantStack<int> my_stack;

  my_stack.push(87);
  my_stack.push(100);
  my_stack.push(98);
  std::cout << "top " << my_stack.top() << std::endl;
  std::cout << my_stack.size() << std::endl;
  my_stack.pop();
  std::cout << my_stack.size() << std::endl;

  // MutantStack<int>::iterator my_it = std::find(my_stack.begin(),
  // my_stack.end(), 100);
  MutantStack<int>::iterator my_it = my_stack.begin();
  std::cout << "*my_it " << *my_it << std::endl;
  my_it = my_stack.end();
  std::cout << "*my_it " << *my_it << std::endl;

  std::cout << std::endl << "ft tests: " << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  // mstack.push(0);
  mstack.push(1);
  mstack.push(2);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  return 0;
}
