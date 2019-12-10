#include <cmath>
#include <cstdio>
#include <iostream>
int main(int argc, char const *argv[]) {
  std::cout << "Вас приветствует програма Quadratic_equation." << std::endl;
  std::cout
      << "Данная програма предназначена для опредиления решений квадратного "
         "уравнения типа А*х^2+B*х+С=0 над полем действительных чисел."
      << std::endl;
  const short kShortMin = std::numeric_limits<short>::min();
  const short kShortMax = std::numeric_limits<short>::max();
  short A;
  std::cout << "Введите значение параметра А в виде целого ненулевого числа в "
               "диапазоне от "
            << kShortMin << " до " << kShortMax << std::endl;
  std::cin >> A;
  // Если А=0, то у нас нет квадратного уравнения
  while ((A < kShortMin) && (A > kShortMax) && (A == 0)) {
    std::cout << "Параметр А задан не верно\n";
    return 1;
  }
  short B;
  std::cout
      << "Введите значение параметра B в виде целого числа в диапазоне от "
      << kShortMin << " до " << kShortMax << std::endl;
  std::cin >> B;
  while ((B < kShortMin) && (B > kShortMax)) {
    std::cout << "Параметр B задан не верно\n";
    return 1;
  }
  short C;
  std::cout
      << "Введите значение параметра B в виде целого числа в диапазоне от "
      << kShortMin << " до " << kShortMax << std::endl;
  std::cin >> C;
  while ((C < kShortMin) && (C > kShortMax)) {
    std::cout << "Параметр С задан не верно\n";
    return 1;
  }
  auto D = B ^ 2 - 4 * A * C;
  if (D < 0) {
    std::cout
        << "Заданое квадратное уравнение не имеет действительных решеий\n";
  }
  auto X1 = (-B + std::sqrt(D)) / (2 * A);
  auto X2 = (-B - std::sqrt(D)) / (2 * A);
  std::cout << "Заданое квадратное уравнение имеет 2 действительных решеий\n";
  std::cout << "Первое решение Х1=" << X1 << std::endl;
  std::cout << "Второе решение Х2=" << X2 << std::endl;

  return 0;
}
