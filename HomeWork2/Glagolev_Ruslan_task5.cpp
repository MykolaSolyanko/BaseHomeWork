#include <iostream>

int main() {
  long long number;
  long long divisor = 0;
  long long best_sum_number_divisor = 0;
  long long sum_number_divisor = 0;
  long long divisor_1;
  long long best_divisor;
  std::cout << "This program calculates the best divisor of your number, as "
               "well as the best divisor,\n";
  std::cout << "based on the sum of the divisor.\n";
  std::cout << "Enter tour number- ";
  std::cin >> number;
  for (long long i = 1; i <= number; ++i) {
    if (number % i == 0) {
      std::cout << "Divisor- " << i << "\n";
      if (divisor < i) {
        divisor = i;
      }
      divisor_1 = divisor;
      while (divisor_1 > 0) {
        sum_number_divisor += divisor_1 % 10;
        divisor_1 /= 10;
      }
      if (sum_number_divisor > best_sum_number_divisor) {
        best_sum_number_divisor = sum_number_divisor;
        sum_number_divisor = 0;
        best_divisor = divisor;
      }
    }
  }
  std::cout << "The best divisor your number- " << best_divisor << std::endl;
  std::cout << "The best divisor by the sum of the digits -" << best_divisor;
  return 0;
}
