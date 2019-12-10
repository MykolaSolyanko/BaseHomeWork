#include <cmath>
#include <iostream>

int main() {
  int n;
  int m;
  int s = 1;
  int f = 0;
  std::cout << "enter ***" << std::endl;
  std::cin >> n;
  m = abs(n);
  while (m != 0) {
    m /= 10;
    s *= 10;
    if (m > 0 && m < 9) {
      m = 0;
    }
  }
  while (n != 0) {
    f = f + s * (n % 10);
    n /= 10;
    s /= 10;
  }
  std::cout << "reverse number-" << f;
  return 0;
}
