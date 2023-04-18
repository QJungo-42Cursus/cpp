#include <iostream>
#include <stdint.h>
#include "data.h"

/// le type "uintptr_t" est un (long) int qui contiendra un pointeur
uintptr_t serialize(Data *ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

/// avec le reinterpret_cast je reprend exactement les memes valeurs en memoire
Data *deserialize(uintptr_t raw) { return (reinterpret_cast<Data *>(raw)); }

int main()
{
  Data my_data = {5};
  std::cout << "Value in my_data.value: " << my_data.value << std::endl;

  Data *my_data_ptr = &my_data;
  std::cout << "Position of my_data: " << my_data_ptr << std::endl;

  uintptr_t serialized_data = serialize(my_data_ptr);
  std::cout << "Position of serialized_data: " << serialized_data << " ("
            << std::hex << serialized_data << ")" << std::endl;

  Data *my_data_ptr_cpy = deserialize(serialized_data);
  std::cout << "Value in my_data_ptr_cpy->value: " << my_data_ptr_cpy->value
            << std::endl;
  std::cout << "Position of my_data_ptr_cpy: " << my_data_ptr_cpy << std::endl;

  return (0);
}
