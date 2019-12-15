#include <iostream>

int main() {
  auto sum = 0;
  int number_of_digits = 1;
  size_t max_iteration{50};
  std::cout << "This program calculates the sum of odd numbers in the range \n";
  std::cout << "from -60 to 90, and you can enter no more than 50 numbers."
            << std::endl;
  while (max_iteration > 0) {
    int number;
    std::cout << "Enter number " << number_of_digits << ":" << std::endl;
    std::cin >> number;
    if (number >= -60 && number <= 90) {
      if (number % 2 != 0) {
        sum += number;
      } else {
        number = 0;
      };
      ++number_of_digits;
      --max_iteration;
    } else {
      std::cout << "Enter number " << number_of_digits << ":" << std::endl;
      std::cin >> number;
    }
  }
  std::cout << "Sum of odd elements- " << sum;
  return 0;
}
