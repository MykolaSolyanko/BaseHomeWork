/**
 * Home Work #3. ITEA C++ Basic Courses.
 *
 * This program inserts elements in array of chars
 *
 * Author:  Andrii Samozvon
 * Date:    13 Dec 2019
 */

// g++ AndriiSamozvon_task_2_insert.cpp -std=c++17 -Wall -pedantic -o insert

#include <iostream>

void print_array(const unsigned int array[], const size_t size) {
  std::cout << '[';
  for (size_t i=0; i<size; i++) {
    std::cout << array[i];
    if (i != size-1) {
      std::cout << ", ";
    }
  }
  std::cout << ']' << std::endl;
}

void insert_element (unsigned int * const parray, const size_t size, const unsigned int element) {
  
  // Iterate all array and find position where larger elements start
  auto *begin = parray, *end = begin + size - 1;
  while (*begin < element && *begin != 0 && begin <= end) {
    ++begin;
  }

  // Move all larger elements to the right
  while (begin < end) {
    *end = *(end-1);
    --end;
  }

  // Insert new element
  *begin = element;
}

int main(int argc, char **argv) {
  const size_t kArraySize = 20;
  unsigned int array[kArraySize]{};

  std::cout << "This program inserts elements in array" << std::endl;

  for (size_t i = 0; i < kArraySize; i++) {
    unsigned int element;
    do {
      std::cout << "Insert element (" << i << ") of (" << kArraySize << "), greater than 0: ";
      std::cin >> element;
    } while (element == 0);

    insert_element(array, kArraySize, element);
    
    print_array(array, kArraySize);  
  }

  return 0;
}
