#include "iter.h"
#include <iostream>

void set_to_5(int &i)
{
	i = 5;
}

void set_to_hello(std::string &i)
{
	i = "hello";
}

void print(int &i)
{
	std::cout << i << std::endl;
}

void print2(std::string &i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	int *list = new int[5];
	std::string *list2 = new std::string[5];

	iter(list, 5, set_to_5);
	iter(list, 5, print);

	list2[0] = "goodbye";
	iter(list2, 5, set_to_hello);
	list2[2] = "world";
	iter(list2, 5, print2);

	delete[] list;
	delete[] list2;
}
