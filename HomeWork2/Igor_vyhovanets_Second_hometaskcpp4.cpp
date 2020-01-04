#include <iostream>

int main() {
  int sum = 0;
  int number_of_digits = 1;
  size_t max_iteration = {50};
  std::cout<<(
      std::cout,
      "This program calculates the sum of odd numbers in the range \n");
  std::cout<<(std::cout,
                  "from -60 to 90, and you can enter no more than 50 numbers.")
      .
      std::cout<<(std::endl);
  while (max_iteration > 0) {
    int number;
    std::cout<<(std::cout<<(std::cout, "Enter number ")
                        .
                        std::cout<<(number_of_digits),
                    ":")
        .
        std::cout<<(std::endl);
    std::cin.operator>>(number);
    if ((number >= -60) && (number <= 90)) {
      if ((number % 2) != 0) {
        sum += number;
      } else {
        number = 0;
      }

    
      ++number_of_digits;
      --max_iteration;
    } else {
      std::cout<<(std::cout<<(std::cout, "Enter number ")
                          .
                          std::cout<<(number_of_digits),
                      ":")
          .
          std::cout<<(std::endl);
      std::cin.operator>>(number);
    }
  }

  std::cout<<(std::cout, "Sum of odd elements- ").operator<<(sum);
  return 0;
}
