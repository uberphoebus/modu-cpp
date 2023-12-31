#include <iostream>

int main() {
  // new = malloc, delete = free
  int *p = new int;
  *p = 10;
  std::cout << *p << std::endl;
  delete p;

  // array new-delete
  int arr_size = 5;
  int *list = new int[arr_size];
  for (int i = 0; i < arr_size; i++) {
    list[i] = i + 3;
  }
  for (int i = 0; i < arr_size; i++) {
    std::cout << i << "th el of list = " << list[i] << std::endl;
  }
  delete[] list;

  return 0;
}