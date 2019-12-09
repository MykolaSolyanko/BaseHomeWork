#include <iostream>

// Recursive power function returning int type. For positive arguments.
int Power(int a, int b) {
  if (b == 0) {
    return 1;
  }
  return a * Power(a, b - 1);
}

void DigitsInNumber() {
  // Get input, make it positive
  std::cout << "\nEnter a number: ";
  int user_number{};
  std::cin >> user_number;
  if (user_number < 0) {
    user_number = -user_number;
  }
  // Calculate sum of digits in the number
  int digit_count{}, digit_sum{};
  do {
    digit_sum += user_number % 10;
    user_number /= 10;
    ++digit_count;
  } while (user_number != 0);
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
    std::cout << "Wrong input" << std::endl;
    return;
  }
  // Calculate sum of digits in first and second halves
  int first_half_sum{}, second_half_sum{}, current_digit{6};
  while (user_number != 0) {
    if (current_digit > 3) {
      second_half_sum += user_number % 10;
    }
    if (current_digit <= 3) {
      first_half_sum += user_number % 10;
    }
    user_number /= 10;
    --current_digit;
  }
  // Output
  std::cout << "First half: " << first_half_sum << std::endl;
  std::cout << "Second half: " << second_half_sum << std::endl;
  if (first_half_sum != second_half_sum) {
    std::cout << "It is not lucky bilet" << std::endl;
    ;
    return;
  }
  std::cout << "It is lucky bilet!!!" << std::endl;
}

void ReverseNumber() {
  // Get input
  std::cout << "\nEnter a number: ";
  int user_number{};
  std::cin >> user_number;
  // Find how many digits does the number have
  int digit_counter{}, temp{user_number};
  do {
    temp /= 10;
    ++digit_counter;
  } while (temp != 0);
  // Find reverse
  int reverse{};
  do {
    reverse += (user_number % 10) * Power(10, digit_counter - 1);
    user_number /= 10;
    --digit_counter;
  } while (digit_counter > 0);
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
  int odd_sum{};
  for (size_t i{0}; i < MAX_INPUTS; ++i) {
    // Get input, check if it is within the range. If not, get input again.
    int user_number{};
    std::cin >> user_number;
    while (user_number < INPUT_LOW_LIMIT || user_number > INPUT_HIGH_LIMIT) {
      std::cout << "Out of range.\n";
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
    std::cout << "Best Divider: " << user_number << std::endl;
    return;
  }
  /* For input "user_number", check all possible divisions:"user_number"/"divisor". 
  Example - for input 12: check 12/12, 12/11, 12/10 ...12/1
  If "user_number" is divisible by "divisor" (user_number%divisor==0), find sum of divisor digits.
  If sum provides highest value, make the divisor the best current divisor, and sum the best current sum */
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
  /*
  "spaces" : Number of empty space chars to the left of pyramid top
  "spaces" = user_number/2
  Examples:
  N = 7                                     N = 5
  ---*      "---"  ->  7/2 = 3 spaces       --*     "--" -> 5/2 = 2 spaces
  --***                                     -*** 
  -*****                                    *****
  *******                                                 */
  int spaces{user_number / 2};
  /* Solution:

  blank[n] = "----...n"
  full[n]  = "****...n"

  Line n:    Pyramid        =   blank[spaces-n]  +     full[user_number-(spaces-n)*2] 
  0           ---*          =   blank[3]         +     full[7-3*2] 
  1           --***         =   blank[2]         +     full[7-2*2]
  2           -*****        =   blank[1]         +     full[7-1*2]
  3           *******       =   blank[0]         +     full[7-0*2] */
  while (spaces >= 0) {
    char *blank = new char[spaces + 1];
    char *full = new char[user_number - spaces * 2 + 1];
    for (int i{0}; i < spaces; ++i) {
      blank[i] = ' ';
    }
    blank[spaces] = '\0'; // null terminator
    for (int i{0}; i < user_number - spaces * 2; ++i) {
      full[i] = '*';
    }
    full[user_number - spaces * 2] = '\0'; // null terminator
    std::cout << blank << full << "\n";
    --spaces;
    delete[] blank;
    delete[] full;
  }
}

void BitsInNumber() {
  std::cout << "\nEnter a positive number: ";
  unsigned int user_number{}, bit_counter{};
  std::cin >> user_number;
  while (user_number != 0) {
    if ((user_number & 1) != 0) {
      ++bit_counter;
    }
    user_number = user_number >> 1;
  }
  std::cout << "Number of Ones: " << bit_counter << std::endl;
}

/*Solution example:
N=54; Location = 3

comparison_var = 2^(L-1) = 2^2 = 4 = 000100

Locations:            6   5   4   3   2   1
User Location:        -   -   -   x   -   -
N(binary):            1   1   0   1   1   0
comparison var:       0   0   0   1   0   0

N & comparsion var == comparison var, if bit at x locaton is 1           */
void CheckBit() {
  std::cout << "\nEnter a number and bit location: ";
  unsigned int user_number{}, bit_location{};
  std::cin >> user_number >> bit_location;
  unsigned int comparison_var = Power(2, bit_location - 1);
  if ((user_number & comparison_var) == comparison_var) {
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
