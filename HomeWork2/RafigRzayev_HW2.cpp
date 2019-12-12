#include <iostream>
#include <limits>

// Recursive power function returning int type. For positive arguments.
int Power(int a, int b) {
  if (b == 0) {
    return 1;
  }
  return a * Power(a, b - 1);
}

void DigitsInNumber() {
  // Get input, make it positive, 0 case
  std::cout << "\nEnter a number: ";
  int user_number{};
  std::cin >> user_number;
  if (user_number == 0) {
    std::cout << "Sum/average of digits is a zero" << std::endl;
    return;
  }
  if (user_number < 0) {
    user_number = -user_number;
  }
  // Calculate sum of digits in the number
  int digit_count{}, digit_sum{};
  while (user_number != 0) {
    digit_sum += user_number % 10;
    user_number /= 10;
    ++digit_count;
  }
  // Output
  std::cout << "Sum of Digits: " << digit_sum << std::endl;
  std::cout << "Average of Digits: " << static_cast<double>(digit_sum) / digit_count << std::endl;
}

void LuckyBilet() {
  // Get input, check if it is within the range
  const int INPUT_LOW_LIMIT{100'000}, INPUT_HIGH_LIMIT{999'999};
  std::cout << "\nInput range: [" << INPUT_LOW_LIMIT << ";" << INPUT_HIGH_LIMIT << "]";
  std::cout << "\nEnter a number: ";
  int user_number{};
  std::cin >> user_number;
  if (user_number < INPUT_LOW_LIMIT || user_number > INPUT_HIGH_LIMIT) {
    std::cout << "Wrong input, please try again" << std::endl;
    return;
  }
  // Calculate sum of digits in first and second halves
  int first_half_sum{}, second_half_sum{}, current_digit{6};
  while (user_number != 0) {
    (current_digit > 3 ? second_half_sum : first_half_sum) += user_number % 10;
    user_number /= 10;
    --current_digit;
  }
  // Output
  std::cout << "First half: " << first_half_sum << std::endl;
  std::cout << "Second half: " << second_half_sum << std::endl;
}

void ReverseNumber() {
  // Get input, 0 exception
  std::cout << "\nEnter a number: ";
  int user_number{};
  std::cin >> user_number;
  if (user_number == 0) {
    std::cout << "Reverse: 0" << std::endl;
    return;
  }
  // Find how many digits does the number have
  int digit_counter{}, temp{user_number};
  while (temp != 0) {
    temp /= 10;
    ++digit_counter;
  }
  // Find reverse
  int reverse{};
  while (digit_counter > 0) {
    reverse += (user_number % 10) * Power(10, digit_counter - 1);
    user_number /= 10;
    --digit_counter;
  }
  // Output
  std::cout << "Reverse: " << reverse << std::endl;
}

void OddNumbers() {
  // Intro message
  const int INPUT_LOW_LIMIT{-60}, INPUT_HIGH_LIMIT{90}, MAX_INPUTS{50};
  std::cout << "\nInput range: [" << INPUT_LOW_LIMIT << ";" << INPUT_HIGH_LIMIT << "]";
  std::cout << "\nMax inputs: " << MAX_INPUTS;
  std::cout << "\nEnter numbers and type 0 to process" << std::endl;
  // Iterate 50 times
  long long odd_sum{};
  for (size_t i{0}; i < MAX_INPUTS; ++i) {
    // Get input, check if it is within the range. If not, get input again.
    int user_number{};
    std::cin >> user_number;
    while (user_number < INPUT_LOW_LIMIT || user_number > INPUT_HIGH_LIMIT) {
      std::cout << user_number << " is out of range. Please try again\n";
      std::cin >> user_number;
    }
    // Press 0 to stop asking input and show result before 50 iterations are finished
    if (user_number == 0) {
      break;
    }
    // If user number is odd, add it to the odd_sum
    if (user_number % 2 == 1 || user_number % 2 == -1) {
      odd_sum += user_number;
    }
  }
  // Output
  std::cout << "Sum of Odd Numbers: " << odd_sum << std::endl;
  // Delete any input entered after MAX_INPUTS times
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void BestDivisor() {
  // Get input, make it positive, 0 exception
  std::cout << "\nEnter a number: ";
  int user_number{};
  std::cin >> user_number;
  if (user_number < 0) {
    user_number = -user_number;
  }
  if (user_number == 0) {
    std::cout << "Best Divisor: " << user_number << std::endl;
    return;
  }
  // Find Best Divisor
  int best_digit_sum{}, best_divisor{}, divisor{user_number};
  while (divisor != 0) {
    if (user_number % divisor == 0) {
      int digit_sum{}, temp_divisor{divisor};
      while (temp_divisor != 0) {
        digit_sum += temp_divisor % 10;
        temp_divisor /= 10;
      }
      if (digit_sum > best_digit_sum) {
        best_divisor = divisor;
        best_digit_sum = digit_sum;
      }
      std::cout << "Divisor: " << divisor << std::endl;
    }
    --divisor;
  }
  // Output
  std::cout << "Best Divisor: " << best_divisor << std::endl;
}

void Tree() {
  // Get input, if even: add 1 to input for symmetry
  std::cout << "\nEnter a number: ";
  int user_number{};
  std::cin >> user_number;
  std::cout << "\n";
  if (user_number % 2 == 0) {
    ++user_number;
  }
  // Display Tree
  int spaces{user_number / 2};
  while (spaces >= 0) {
    for (int i{0}; i < spaces; ++i) {
      std::cout << ' ';
    }
    for (int i{0}; i < user_number - spaces * 2; ++i) {
      std::cout << '*';
    }
    std::cout << "\n";
    --spaces;
  }
}

void BitsInNumber() {
  std::cout << "\nEnter a positive number: ";
  unsigned int user_number{}, bit_counter{};
  std::cin >> user_number;
  while (user_number != 0) {
    bit_counter += user_number & 1;
    user_number = user_number >> 1;
  }
  std::cout << "Number of Ones: " << bit_counter << std::endl;
}

void CheckBit() {
  std::cout << "\nEnter a positive number and bit location: ";
  unsigned int user_number{}, bit_location{};
  std::cin >> user_number >> bit_location;
  if (((user_number >> (bit_location - 1)) & 1) == 1) {
    std::cout << "Yes, there is a bit here" << std::endl;
    return;
  }
  std::cout << "No, there is no bit on this location" << std::endl;
}

enum menu_options {
  QUIT,
  DIGITS_IN_NUMBER,
  LUCKY_BILET,
  REVERSE_NUMBER,
  ODD_NUMBERS,
  BEST_DIVISOR,
  TREE,
  BITS_IN_NUMBER,
  CHECK_BIT,
};

void MainMenuText() {
  std::cout << "-------------------------------------------------------------\n";
  std::cout << "                         MAIN MENU                           \n";
  std::cout << "                                                             \n";
  std::cout << DIGITS_IN_NUMBER << " - SUM AND AVERAGE OF DIGITS IN A NUMBER \n";
  std::cout << LUCKY_BILET      << " - LUCKY BILET CHECK                     \n";
  std::cout << REVERSE_NUMBER   << " - REVERSE OF NUMBER                     \n";
  std::cout << ODD_NUMBERS      << " - SUM OF ODD NUMBERS                    \n";
  std::cout << BEST_DIVISOR     << " - BEST DIVISOR                          \n";
  std::cout << TREE             << " - TREE                                  \n";
  std::cout << BITS_IN_NUMBER   << " - NUMBER OF ONES IN BIT REPRESENTATION  \n";
  std::cout << CHECK_BIT        << " - CHECK BIT ON NUMBER LOCATION          \n";
  std::cout << QUIT             << " - QUIT                                  \n";
  std::cout << "-------------------------------------------------------------\n";
  std::cout << "Enter your command: ";
}

int main() {
  while (true) {
    MainMenuText();
    int user_selection;
    std::cin >> user_selection;
    switch (user_selection) {
    case DIGITS_IN_NUMBER:
      DigitsInNumber();
      break;
    case LUCKY_BILET:
      LuckyBilet();
      break;
    case REVERSE_NUMBER:
      ReverseNumber();
      break;
    case ODD_NUMBERS:
      OddNumbers();
      break;
    case BEST_DIVISOR:
      BestDivisor();
      break;
    case TREE:
      Tree();
      break;
    case BITS_IN_NUMBER:
      BitsInNumber();
      break;
    case CHECK_BIT:
      CheckBit();
      break;
    case QUIT:
      std::cout << "Goodbye" << std::endl;
      return 0;
    default:
      std::cout << "Unknown command. Please try again" << std::endl;
    }
  }
}
