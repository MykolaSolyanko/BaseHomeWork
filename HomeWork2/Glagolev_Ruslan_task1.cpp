#include <iostream>

int main() {
  int number;
  int sum = 0;
  int count_digit_in_number = 0;

  std::cout << "Please enter any number, this program will calculate the sum "
               "of the\n";
  std::cout << "digits in the number, and Arithmetic mean of the digits of "
               "your number-";
  std::cin >> number;

  while (number != 0) {
    sum += number % 10;
    number /= 10;
    count_digit_in_number++;
  }
  auto avarage = static_cast<double>(sum) / count_digit_in_number;
  std::cout << "The sum of the digits of your number- " << sum << std::endl;
  std::cout << "Arithmetic mean of the digits of your number - " << avarage
            << std::endl;

  return 0;
}
