#include <iostream>

int main() {
  int sum = 0;
  int number_of_digits = 1;
  size_t max_iteration = {50};
  std::cout<<std::endl;
  while (max_iteration > 0) {
    int number;
    std::cout<< "Enter number \n";
                        
   std::cout<<number_of_digits<<std::endl:             
    std::cin>>number;
    if ((number >= -60) && (number <= 90)) {
      if ((number % 2) != 0) {
        sum += number;
      } else {
        number = 0;
      }

      ++number_of_digits;
      --max_iteration;
    } else {
      std::cout<< "Enter number ";
      
       std::cin>>number;   
      std::cout<<number_of_digits;
         
    }
  }

  std::cout<< "Sum of odd elements- ";
  return 0;
}

