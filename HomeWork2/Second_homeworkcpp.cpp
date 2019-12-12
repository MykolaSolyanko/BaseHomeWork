#include <iostream>

int main() {
  int s = 0;
  int a;
  std::cout << "Enter number" << std::endl;
  for (int i = 0; i <= 50; i++) {
    std::cin >> a;

    if (a % 2 != 0) {
      s += a;
    }
    if (a <= -60 || a >= 90) {
      i = 52;
      s -= a;
    }
  }
  std::cout << "Sum of odd elements-" << s;
  return 0;
}