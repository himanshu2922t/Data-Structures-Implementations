#include<iostream>
using namespace std;

template <typename T>
class DynamicArray {
  T *a = NULL;
  int size, capacity;
  private:
    void expand() {
      T *b = new T[2*capacity];
      capacity = 2*capacity;
      for (size_t i = 0; i < capacity; i++) {
        if (i < size)
          b[i] = a[i];
        else
          b[i] = 0;
      }
      for (size_t i = 0; i < capacity; i++) {
      	a[i] = b[i];
      }
    }

  public:

    DynamicArray(size_t capacity = 0, size_t intializer = 0) {
      a = new T[capacity];
      size = capacity;
      this->capacity = capacity;
      for (size_t i = 0; i < capacity; i++) {
        a[i] = intializer;
      }
    }

    T &operator[] (size_t i) {
      if (i >= size and i < 0) {
        cerr << "Index out of bound!" << '\n';
      }
      else {
        return a[i];
      }
    }

    size_t search(T target) {
      for (size_t i = 0; i < size; i++) {
        if (a[i] == target)
          return i;
      }
      return -1;
    }

    void insert(T val, size_t index) {
      if (size == capacity)
        expand();
      for (size_t i = size; i > index; i--) {
        a[i] = a[i-1];
      }
      a[index] = val;
      size++;
    }

    void append(T val) {
      if (size == capacity)
        expand();
      a[size] = val;
      size++;
    }

    void remove(size_t index) {
      if (index >= size and index < 0) {
        cerr << "Index out of bound!" << '\n';
        return;
      }
      for (size_t i = index; i < size-1; i++) {
        a[i] = a[i+1];
      }
      a[size] = 0;
      size--;
    }
};
