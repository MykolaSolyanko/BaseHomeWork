/**
 * Home Work #3. ITEA C++ Basic Courses.
 *
 * This program reverses array of chars
 *
 * Author:  Andrii Samozvon
 * Date:    13 Dec 2019
 */

// g++ AndriiSamozvon_task_1_reverse.cpp -std=c++17 -Wall -pedantic -o reverse

#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
  std::cout << "This program reverses string that user inputs" << std::endl;

  if (argc != 2) {
    std::cout << "Wrong number of parameters" << std::endl;
    std::cout << "Usage: ./reverse <string>" << std::endl;
    return 0;
  }
  
  const size_t kMaxLength = 100;
  const size_t kLength = strlen(argv[1]);

  if (kLength > kMaxLength) {
    std::cout << "Error! Input string should be less than " << kMaxLength << " characters" << std::endl;
    return 0;
  }

  char reversed[kMaxLength + 1]{};  // string should contain termination zero (+1 byte)
  char *pReversed = reversed;    

  // Reverse the string
  for (auto *begin = argv[1], *end = begin + kLength, *limit = end; begin < limit; ++begin) {
    *pReversed++ = *--end;
  }

  std::cout << "Initial string:  " << argv[1] << std::endl;
  std::cout << "Reversed string: " << reversed << std::endl;
  
  return 0;
}
