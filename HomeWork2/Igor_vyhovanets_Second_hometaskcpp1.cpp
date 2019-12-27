#include <cmath>
#include <iostream>

int main() {
  int normal_number;
  int check_number;
  int multiplicity_of_number = 1;
  int reverse_number = 0;
  std::cout << "This program reverses the digits of your number in places.\n";
  std::cout << "Enter your number-";
  std::cin >> normal_number;
  check_number = abs(normal_number);
  while (check_number != 0) {
    check_number /= 10;
    multiplicity_of_number *= 10;
    if (check_number > 0 && check_number < 9) {
      check_number = 0;
    }
  }
  while (normal_number != 0) {
    reverse_number =
        reverse_number + multiplicity_of_number * (normal_number % 10);
    normal_number /= 10;
    multiplicity_of_number /= 10;
  }
  std::cout << "reverse number-" << reverse_number;
  return 0;
}