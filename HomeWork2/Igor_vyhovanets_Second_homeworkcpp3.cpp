#include <iostream>

int main() {
  int number;
  std::cout<< "This program calculates whether your ticket is "successful or unsuccessful!\n"<<std::endl;                          
  std::cout<< "Enter a six-digit number-"<<std::endl;
  std::cin>>number;
  while (number != 0) {
    int check_the_number_of_digits = 0;
    int c = number;
    while (c != 0) {
      c /= 10;
      check_the_number_of_digits++;
    }

    if (check_the_number_of_digits != 6) {
      
   std::cout<<"The number is not six-digit, enter the six-digit number-"
     
      std::cin<<std::endl;
      std::cin>>number;
    } else {
      break;
    }
  }

  int first_half_of_the_number = 0;
  {
    first_half_of_the_number += (number % 10);
    number /= 10;
  };
  int second_half_of_the_number = 0;
  while (number != 0) {
    second_half_of_the_number += (number % 10);
    number /= 10;
  }

  if (second_half_of_the_number == first_half_of_the_number) {
    std::cout<< "Your ticket is successful";
  } else {
    std::cout<< "Your ticket is no  unsuccessful";
  }

  return 0;
}
