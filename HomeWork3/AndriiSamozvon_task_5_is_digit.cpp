/**
 * Home Work #3. ITEA C++ Basic Courses.
 *
 * This program checks char array and outputs digit from it
 *
 * Author:  Andrii Samozvon
 * Date:    13 Dec 2019
 */

// g++ AndriiSamozvon_task_5_is_digit.cpp -std=c++17 -Wall -pedantic -o is_digit

#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "This progtam checks char array and outputs digit from it" << std::endl;

  const size_t kMaxArrayLen = 100;
  char array[kMaxArrayLen]{};

  std::cout << "Enter string (max " << kMaxArrayLen << " elements): ";
  std::cin >> array;

  std::cout << "Digits in array: ";
  bool isNumFound = false;
  char *ptr = array;
  
  while (*ptr != '\0') {
    if (*ptr >= '0' && *ptr <= '9') {
      if (!isNumFound) {
        isNumFound = true;
        std::cout << '[';
      }
      std::cout << *ptr << ", ";
    }
    ++ptr;
  }
  // if (isNumFound) {
  //   std::cout << "\b\b]";
  // } else {
  //   std::cout << "none";
  // }
  // std::cout << std::endl;

  std::cout << ((isNumFound) ? "\b\b]" : "none") << std::endl;

  return 0;
}
