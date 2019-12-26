#include <cmath>
#include <iostream>

int main() {
  long a;
  long b;
  long c;
  const short four = 4;
  const short two = 2;
  const short one = 1;
  std::cout << "An equation of the form ax2 + bx + c = 0. Enter integers a, b, "
               "and c.\n Please enter number in range ["
            << std::numeric_limits<short>::min() << ".."
            << std::numeric_limits<short>::max() << "]\n";
  std::cin >> a;
  if (a < std::numeric_limits<short>::min() ||
      a > std::numeric_limits<short>::max()) {
    std::cout
        << " You entered an incorrect number, try entering the number again";
    return 0;
  }
  std::cout << " Please enter number in range ["
            << std::numeric_limits<short>::min() << ".."
            << std::numeric_limits<short>::max() << "]\n";
  std::cin >> b;
  if (b < std::numeric_limits<short>::min() ||
      b > std::numeric_limits<short>::max()) {
    std::cout
        << " You entered an incorrect number, try entering the number again";
    return 0;
  }
  std::cout << " Please enter number in range ["
            << std::numeric_limits<short>::min() << ".."
            << std::numeric_limits<short>::max() << "]\n";
  std::cin >> c;
  if (c < std::numeric_limits<short>::min() ||
      c > std::numeric_limits<short>::max()) {
    std::cout
        << " You entered an incorrect number, try entering the number again";
    return 0;
  }
  auto D = (std::pow(b, two) - (four * a * c));
  std::cout << " Discriminant = " << D << std::endl;
  if (a != 0) {
    if (D >= 0) {
      auto X1 = ((-b) + (std::sqrt(D))) / (two * a);
      auto X2 = ((-b) - (std::sqrt(D))) / (two * a);
      std::cout << " X1 = " << X1 << std::endl;
      std::cout << " X2 = " << X2 << std::endl;

    } else {
      std::cout << " The discriminant is 0. There is no root.\n" << std::endl;
    }
  } else {
    auto X = (-c) / b;
    std::cout << " X = " << X << std::endl;
  }
  return 0;
}
