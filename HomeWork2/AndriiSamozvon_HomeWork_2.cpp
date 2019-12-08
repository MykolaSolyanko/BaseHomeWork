/**
 * Home Work #2. ITEA C++ Basic Courses.
 *
 * This program performs arithmetic, logical and bitwise operations with numbers.
 *
 * Author:  Andrii Samozvon
 * Date:    07 Dec 2019
 */
// g++ -Wall -std=c++17 Andrii_Samozvon_HomeWork_2 -o hw2

#include <iostream>
#include <stdint.h>
#include <limits>

/* 1 */
void sum_and_arith_mean() {
  uint16_t number, digits{0};
  std::cout << "Enter number from [" << std::numeric_limits<uint16_t>::min() << ".." << std::numeric_limits<uint16_t>::max() << "]: ";
  std::cin >> number;
  uint32_t sum{0};
  do {
    ++digits;
    sum += (number % 10);
    number /= 10;
  } while (number);
  float arith_mean = (float)sum / digits;
  std::cout << "Sum of digits: " << sum << std::endl;
  std::cout << "Arithmetic mean: " << arith_mean << std::endl;
}

/* 2 */
void happy_ticket() {
  int ticket;
  do {
    std::cout << "Enter a ticket number in range [100000..999999]: ";
    std::cin >> ticket;
  } while (ticket < 100000 || ticket > 999999);

  const int left_sum  =  (ticket / 100000)    + ((ticket / 10000) % 10) + ((ticket / 1000) % 10);
  const int right_sum = ((ticket / 100) % 10) + ((ticket / 10) % 10)    +  (ticket % 10);
  if (left_sum == right_sum) {
    std::cout << "Your have a happy ticket! :)" << std::endl;
  } else {
    std::cout << "Your have a regular ticket! :(" << std::endl;
  }
}

/* 3 */
void reverse_numbers() {
  std::cout << "Enter number in range ["
            << std::numeric_limits<int32_t>::min() << ".."
            << std::numeric_limits<int32_t>::max() << "]: ";
  int32_t number;
  std::cin >> number;
  int64_t reverse_number{0};
  do {
    reverse_number *= 10;
    reverse_number += number % 10;
    number /= 10;
  } while (number != 0);
  std::cout << reverse_number << std::endl;
}

/* 4 */
void sum_of_even() {
  size_t amount;
  do {
    std::cout << "Enter amount of numbers [1..50]: ";
    std::cin >> amount;
  } while (amount == 0 || amount > 50);

  int sum;
  for (size_t i = 1; i <= amount; i++) {
    int number;
    do {
      std::cout << i << ": ";
      std::cin >> number;
    } while (number < -60 || number > 90);
    if (number%2) {
      sum += number;
    }
  }
  std::cout << "Sum of even numbers: " << sum << std::endl;
}

/* 5 */
/* The program simply finds largest divisor.
   For example, 13 has only 1 and 13 as divisors, and if we add (1 + 3) we get 4,
   which is not a 13's divisor. Needs clarification. 
 */
void best_divider() {
  uint32_t number;
  do {
    std::cout << "Enter number in range ["
            << std::numeric_limits<uint32_t>::min() << ".."
            << std::numeric_limits<uint32_t>::max() << "]: ";
    std::cin >> number;
  } while (number > std::numeric_limits<uint32_t>::max());

  // Find best divisor
  uint32_t divisor{0};
  for (size_t i = 1; i < number; i++) {
    if (number % i == 0) {
      divisor = i;
      std::cout << divisor << ' ';
    }
  }
}

/* 6 */
void star_tree() {
  size_t base_width;
  do {
    std::cout << "Enter width of tree's base (from 1 to 50): " << std::endl;
    std::cin >> base_width;
  } while (base_width < 1 || base_width > 50);
  
  // If base_width is even - increment it
  if (base_width % 2 == 0) {
    ++base_width;
  }

  // Draw a tree
  for (size_t row = 0; row < (base_width/2)+1; row++) {
    for (size_t pos = 0; pos < base_width; pos++) {
      const size_t limit = (base_width / 2) - row;
      if (pos < limit || pos >= (base_width - limit)) {
        std::cout << ' ';
      } else {
        std::cout << '*';
      }
    }
    std::cout << std::endl;    
  }
}

/* 7 */
void num_of_bits() {
  uint32_t number;
  std::cout << "Enter a number in range [0.." << std::numeric_limits<uint32_t>::max() << "]: ";
  std::cin >> number;

  // Calculate number of set bits in a number
  size_t num_of_bits{0};
  for (size_t i = 0; i < 32; i++) {
    if (number & (1<<i)) {
      ++num_of_bits;
    }
  }
  std::cout << "Number of set bits in a number: " << num_of_bits << std::endl;
}

/* 8 */
void is_bit_set() {
  uint32_t number;
  do {
    std::cout << "Enter number in range ["
            << std::numeric_limits<uint32_t>::min() << ".."
            << std::numeric_limits<uint32_t>::max() << "]: ";
    std::cin >> number;
  } while (number > std::numeric_limits<uint32_t>::max());

  unsigned int bit;
  do {
    std::cout << "Enter bit [1..32]: ";
    std::cin >> bit;
  } while (bit == 0 || bit > 32);

  // Test entered bit in a number
  std::cout << ((number & (1 << --bit)) ? "Yes" : "No") << std::endl;
}

/* 9 */
void num_construction() {
  size_t amount;
  do {
    std::cout << "Enter amount of numbers in range [1..9]: ";
    std::cin >> amount;
  } while (amount == 0 || amount > 9);
  
  size_t constructed_number{0};

  for (size_t i = 1; i <= amount; i++) {
    // Enter next number
    std::cout << i << ": ";
    uint32_t new_number;
    std::cin >> new_number;
    
    // Shift out constructed number on number if new_number's digits
    size_t last_number = new_number;
    while (last_number > 0) {
      constructed_number *= 10;
      last_number /= 10;
    }

    // Add new number to it
    constructed_number += new_number;
  }
  std::cout << constructed_number << std::endl;    // Show the conostructed number
  std::cout << ( ((constructed_number % 3 ) == 0) ? "Yes" : "No" ) << std::endl;
}

int main(int argc, char **argv) {

  // Ask user to choose action
  int choice;
  do {
    std::cout << "Please enter action:" << std::endl;
    std::cout << "  1: Sum & arithmetic mean of digits in a number" << std::endl;
    std::cout << "  2: Happy ticket" << std::endl;
    std::cout << "  3: Reverse numbers" << std::endl;
    std::cout << "  4: Sum of even elements" << std::endl;
    std::cout << "  5: Best divider" << std::endl;
    std::cout << "  6: Star tree" << std::endl;
    std::cout << "  7: Number of bits in a number" << std::endl;
    std::cout << "  8: Is bit set?" << std::endl;
    std::cout << "  9: Constructing of the numer" << std::endl;
    std::cout << ">";
    std::cin >> choice;
  } while (choice < 1 || choice > 9);

  // Perform a chosen action
  switch (choice)
  {
    case 1: sum_and_arith_mean(); break;
    case 2: happy_ticket();       break;
    case 3: reverse_numbers();    break;
    case 4: sum_of_even();        break;
    case 5: best_divider();       break;
    case 6: star_tree();          break;
    case 7: num_of_bits();        break;
    case 8: is_bit_set();         break;
    case 9: num_construction();   break;
    default:  break;  // Shouldn't happen
  }
  return 0;
}
