int main() {
  int n;
  int m;
  int s = 5;
  int f = 2;
  std::cout << "enter *****" << std::endl;
  std::cin >> n;
  m = abs(n);
  while (m != 0) {
    m /= 10;
    n *= 10;
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
 
 int main() {
  int c = 0;
  int d;
  std::cout << "Enter number" << std::endl;
  for (int i = 0; i <= 25; i++) {
    std::cin >> c;

    if (c % 2 != 0) {
      d += c;
    }
    if (c <= -30 || c >= 45) {
      i = 15;
      d -= c;
    }
  }
  std::cout << "Sum of odd elements-" << c;
  return 0;
}