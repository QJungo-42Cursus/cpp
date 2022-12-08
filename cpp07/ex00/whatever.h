#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T> T min(T a, T b) {
  T result = b;
  if (a < b)
    result = a;
  return result;
}

template <typename T> T max(T a, T b) {
  T result = b;
  if (a > b)
    result = a;
  return result;
}

#endif /* WHATEVER_H */
