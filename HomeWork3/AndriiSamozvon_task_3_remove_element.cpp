/**
 * Home Work #3. ITEA C++ Basic Courses.
 *
 * This program removes elements from array of ints
 *
 * Author:  Andrii Samozvon
 * Date:    13 Dec 2019
 */

// g++ AndriiSamozvon_task_3_remove.cpp -std=c++17 -Wall -pedantic -o remove

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

void print_array(const int * const parray, const size_t size) {
  std::cout << '[';
  auto *begin = parray, *end = begin + size;
  while (begin < end) {
    std::cout << *begin++;
    if (begin != end) {
      std::cout << ", ";
    }
  }
  std::cout << ']' << std::endl;
}

void remove_element (int * const parray, const size_t size, const int element) {
  bool shiftTriggered{};
  for (auto *begin = parray, *end = begin + size - 1; begin < end; ++begin) {
    // If we achieved wanted number then remove it and shift rest of the numbers to the left
    if (*begin == element) {
      shiftTriggered = true;
    }
    if (shiftTriggered) {
      *begin = *(begin+1);
      *(begin+1) = 0;
    }
  }
}

bool is_array_empty(int *const parray, const size_t size) {
  for (auto *begin = parray, *end = begin + size; begin < end; begin++) {
    if (*begin != 0) {
      return false;
    }
  }
  return true;
}

enum {
  METHOD_1_BY_HAND = 1,
  METHOD_2_WITH_RAND,
  METHOD_3_WITH_MT19937
};

int main(int argc, char **argv) {
  
  std::cout << "This program removes elements from array" << std::endl;

  std::cout << std::endl << "Choose method of array initializing: " << std::endl;
  std::cout << "  1: By hand" << std::endl << "  2: With rand()" << std::endl << "  3: With mt19937" << std::endl;

  const size_t kArraySize = 20;
  int array[kArraySize]{};
  const int kMaxRandomNumber = 20;

  int method;
  do {
    std::cin >> method;
  } while (method < METHOD_1_BY_HAND || method > METHOD_3_WITH_MT19937);

  // Start RNG
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<int> distribution(0,kMaxRandomNumber);
  srand(time(0));
  
  switch (method) {
    case METHOD_1_BY_HAND:
      for (size_t i = 0; i < kArraySize; i++) {
        std::cout << "array[" << i << "]: ";
        std::cin >> array[i];
      }
      break;
    case METHOD_2_WITH_RAND:
      for (size_t i = 0; i < kArraySize; i++) {
        array[i] = rand() % kMaxRandomNumber;
      }
      break;
    case METHOD_3_WITH_MT19937:      
      for (size_t i = 0; i < kArraySize; ++i) {
          array[i] = distribution(generator);
      }
      break;
    default:
      std::cout << "Unknown error, exiting" << std::endl;
      return 0;
  }

  print_array(array, kArraySize);

  while ( !is_array_empty(array, kArraySize) ) {
    int number;
    std::cout << "Enter number to delete: ";
    std::cin >> number;
    remove_element(array, kArraySize, number);
    print_array(array, kArraySize);
  }

  return 0;
}
