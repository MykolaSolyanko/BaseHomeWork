#include <iostream>

int main() {
  int number;
  int b = 0;
  std::cout << "This program draws a Christmas tree with the symbol '*', which "
               "will be based on the number you specify.\n";
  std::cout << "You need to enter only odd numbers from 0 to 100." << std::endl;
  std::cout << "Enter your number-";
  std::cin >> number;
  while (number % 2 == 0 || number < 0 || number > 100) {
    std::cout << "Enter the correct number- ";
    std::cin >> number;
  }
  for (int a = 0; a != (number + 1) / 2; a++) {
    for (int i = 0; i < number; i++) {
      int max = i + b;
      int min = i - b;
      if (max >= number / 2 && min <= number / 2) {
        std::cout << "*";
      } else {
        std::cout << " ";
      }
    }
    std::cout << "\n";
    b++;
  }
  return 0;
}
