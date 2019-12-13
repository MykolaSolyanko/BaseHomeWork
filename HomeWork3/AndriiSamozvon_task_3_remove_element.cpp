/**
 * Home Work #3. ITEA C++ Basic Courses.
 *
 * This program removes elements from array of chars
 *
 * Author:  Andrii Samozvon
 * Date:    13 Dec 2019
 */

// g++ AndriiSamozvon_task_3_remove.cpp -std=c++17 -Wall -pedantic -o remove

#include <iostream>

void print_array(unsigned int * const parray, const size_t size) {
  std::cout << '[';
  for (size_t i = 0; i < size; i++){
    std::cout << *(parray + i);
    if (i != (size - 1)) {
      std::cout << ", ";
    }
  }
  std::cout << ']' << std::endl;
}

void remove_element (unsigned int * const parray, const size_t size, const unsigned int element) {
  
}

int main(int argc, char **argv) {
  
  std::cout << "This program removes elements from array" << std::endl;

  const size_t kArraySize = 20;
  int array[kArraySize]{};
  

  return 0;
}
