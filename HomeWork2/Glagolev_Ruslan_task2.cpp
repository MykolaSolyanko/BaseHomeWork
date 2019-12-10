#include <iostream>

int main() {
  int n;
  int sum = 0;
  int i = 0;

  std::cout << "please, enter n = ";
  std::cin >> n;

  while (n != 0) {
    sum += n % 10;
    n /= 10;
    i++;
  }
  double avarage = (double)sum / (double)i;
  std::cout << "sum = " << sum << std::endl;
  std::cout << "avarage = " << avarage << std::endl;

  return 0;
}
