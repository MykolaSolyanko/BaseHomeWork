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
#include <limits>

enum {
  ACT_1_SUM_AND_ARITH_MEAN = 1,
  ACT_2_HAPPY_TICKET,
  ACT_3_REVERSE_NUMBERS,
  ACT_4_SUM_OF_EVEN,
  ACT_5_BEST_DIVIDER,
  ACT_6_STAR_TREE,
  ACT_7_NUM_OF_BITS,
  ACT_8_IS_BIT_SET,
  ACT_9_NUM_CONSTRUCTION
};

/* 1 */
void sum_and_arith_mean() {
  uint16_t number, digits{0};

  std::cout << "Enter number from [" << std::numeric_limits<uint16_t>::min() << ".." << std::numeric_limits<uint16_t>::max() << "]: ";
  std::cin >> number;
  
  uint32_t sum{0};

  if (number > 0) {
    do {
      ++digits;
      sum += (number % 10);
      number /= 10;
    } while (number);
  }
  float arith_mean = static_cast<float>(sum) / digits;
  std::cout << "Sum of digits: " << sum << std::endl;
  std::cout << "Arithmetic mean: " << arith_mean << std::endl;
}

/* 2 */
void happy_ticket() {
  int ticket;
  const int kMinTicket = 100000, kMaxTicket = 999999;

  do {
    std::cout << "Enter a ticket number in range [" << kMinTicket << ".." << kMaxTicket << "]: ";
    std::cin >> ticket;
  } while (ticket < kMinTicket || ticket > kMaxTicket);

  const int left_sum  =  (ticket / 100000)    + ((ticket / 10000) % 10) + ((ticket / 1000) % 10);
  const int right_sum = ((ticket / 100) % 10) + ((ticket / 10) % 10)    +  (ticket % 10);
  std::cout << "Your have a " << ((left_sum == right_sum) ? "happy" : "regular") << "ticket!" << std::endl;
}

/* 3 */
void reverse_numbers() {
  std::cout << "Enter number in range ["
            << std::numeric_limits<int32_t>::min() << ".."
            << std::numeric_limits<int32_t>::max() << "]: ";
  int32_t number;

  std::cin >> number;
  decltype(std::numeric_limits<int32_t>::max()+1) reverse_number{0};

  if ((number / 10) != 0) {   // Reverse number only if it has more than 1 digit
    do {
      reverse_number *= 10;
      reverse_number += number % 10;
      number /= 10;
    } while (number != 0);
  } else {
    reverse_number = number;
  }
  std::cout << reverse_number << std::endl;
}

/* 4 */
void sum_of_even() {
  size_t amount;
  const auto kMinAmount = 1, kMaxAmount = 50;

  do {
    std::cout << "Enter amount of numbers [" << kMinAmount << ".." << kMaxAmount << "]: ";
    std::cin >> amount;
  } while (amount == 0 || amount > kMaxAmount);

  long sum{0};
  const auto kMinNumber = -60, kMaxNumber = 90;

  std::cout << "Enter " << amount << " numbers in range [" << kMinNumber << ".." << kMaxNumber << "]" << std::endl;
  for (size_t i = 1; i <= amount; i++) {
    int number;

    do {
      std::cout << i << ": ";
      std::cin >> number;
    } while (number < kMinNumber || number > kMaxNumber);

    if (number % 2) {
      sum += static_cast<long>(number);
    }
  }
  std::cout << "Sum of even numbers: " << sum << std::endl;
}

/* 5 */
void best_divider() {
  uint32_t number;
  do {
    std::cout << "Enter number in range [1.." << std::numeric_limits<uint32_t>::max() << "]: ";
    std::cin >> number;
  } while (number > std::numeric_limits<uint32_t>::max() || number == 0);

  uint32_t divisor{1};
  size_t best_sum_of_digits{};
  decltype(divisor) best{divisor};

  // Find best divisor
  for (size_t i = 1; i <= number; i++) {
    size_t sum_of_digits{};

    if (number % i == 0) {
      divisor = i;
      decltype(number) temp{divisor};

      std::cout << divisor << ' ';
      
      do {
        sum_of_digits += (temp % 10);
        temp /= 10;
      } while (temp);

      if (sum_of_digits > best_sum_of_digits) {
        best_sum_of_digits = sum_of_digits;
        best = divisor;
      }
    }
  }
  std::cout << std::endl << "Best divisor: " << best << std::endl;
}

/* 6 */
void star_tree() {
  size_t base_width;
  const auto kMinBase = 1, kMaxBase = 50;

  do {
    std::cout << "Enter width of tree's base in range [" << kMinBase << ".." << kMaxBase << "]: " << std::endl;
    std::cin >> base_width;
  } while (base_width < kMinBase || base_width > kMaxBase);
  
  // If base_width is even - increment it
  if (base_width % 2 == 0) {
    ++base_width;
  }

  // Draw a tree
  const size_t kBaseHalf = base_width / 2;

  for (size_t row = 0; row < (kBaseHalf + 1); row++) {
    for (size_t pos = 0; pos < base_width; pos++) {
      const size_t limit = kBaseHalf - row;
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
  const auto kCountBits = sizeof(number) * 8;

  for (size_t i = 0; i < kCountBits; i++) {
    if (number & (1 << i)) {
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
  const auto kCountBits = sizeof(number) * 8;

  do {
    std::cout << "Enter bit [1.." << kCountBits << "]: ";
    std::cin >> bit;
  } while (bit == 0 || bit > kCountBits);

  // Test entered bit in a number
  std::cout << ((number & (1 << --bit)) ? "Yes" : "No") << std::endl;
}

/* 9 */
void num_construction() {
  size_t amount;
  const auto kMinAmount = 1, kMaxAmount = 9;
  
  do {
    std::cout << "Enter amount of numbers in range [" << kMinAmount << ".." << kMaxAmount << "]: ";
    std::cin >> amount;
  } while (amount < kMinAmount || amount > kMaxAmount);
  
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
  } while (choice < ACT_1_SUM_AND_ARITH_MEAN || choice > ACT_9_NUM_CONSTRUCTION);

  // Perform a chosen action
  switch (choice) {
    case ACT_1_SUM_AND_ARITH_MEAN:sum_and_arith_mean(); break;
    case ACT_2_HAPPY_TICKET:        happy_ticket();       break;
    case ACT_3_REVERSE_NUMBERS:     reverse_numbers();    break;
    case ACT_4_SUM_OF_EVEN:         sum_of_even();        break;
    case ACT_5_BEST_DIVIDER:        best_divider();       break;
    case ACT_6_STAR_TREE:           star_tree();          break;
    case ACT_7_NUM_OF_BITS:         num_of_bits();        break;
    case ACT_8_IS_BIT_SET:          is_bit_set();         break;
    case ACT_9_NUM_CONSTRUCTION:    num_construction();   break;
    default:  // Shouldn't happen
      std::cout << "Unnown error, exiting" << std::endl;
      break;  
  }
  return 0;
}
