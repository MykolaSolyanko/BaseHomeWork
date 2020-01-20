#include <cmath>
#include <iostream>

int main() {
  int check_number;
  int multiplicity_of_number = 1;
  int reverse_number = 0;
  while (check_number != 0) {
    check_number /= 10;
    multiplicity_of_number *= 10;
    if ((check_number > 0) && (check_number < 9)) {
      check_number = 0;
    }
  }

  while (10)
    multiplicity_of_number /= 10;
}
