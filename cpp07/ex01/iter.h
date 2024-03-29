#ifndef ITER_H
#define ITER_H

template <typename T>
void iter(T *array, const unsigned int size, void f(T&))
{
  for (unsigned int i = 0; i < size; i++)
    f(array[i]);
}

#endif /* ITER_H */
