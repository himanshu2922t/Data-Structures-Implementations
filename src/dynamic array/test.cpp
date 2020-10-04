#include <iostream>
#include "dynamic_array.h"

using namespace std;

int main() {
  DynamicArray<int> t;
  for (size_t i = 0; i < 9; i++) {
    t.append(i+1);
  }
  std::cout << t[3] << '\n';
  t.insert(10,1);
  t.remove(5);
  for (size_t i = 0; i < 9; i++) {
    std::cout << t[i] << '\n';
  }

  DynamicArray<int> a(9);
  a[3] = 2;
  std::cout << a[3] << '\n';
  a.insert(10,1);
  a.remove(5);
  for (size_t i = 0; i < 9; i++) {
    std::cout << a[i] << '\n';
  }

  DynamicArray<int> b(9,2);
  b[3] = 6;
  std::cout << b[3] << '\n';
  b.insert(10,1);
  b.remove(5);
  for (size_t i = 0; i < 9; i++) {
    std::cout << b[i] << '\n';
  }

  return 0;
}
