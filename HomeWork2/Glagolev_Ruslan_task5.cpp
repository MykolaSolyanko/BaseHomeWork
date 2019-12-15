#include <iostream>

int main() {
  long long number;
  long long best_divisor = 0;
  std::cout << "This program calculates the best divisor of your number.\n";
  std::cout << "Enter tour number- ";
  std::cin >> number;
  for (long long i = 1; i <= number; i++) {
    if (number % i == 0 && i != number) {
      std::cout << "Divisor- " << i << "\n";
      if (best_divisor < i) {
        best_divisor = i;
      }
    }
  }
  std::cout << "The best divisor your number- " << best_divisor;
  return 0;
}
