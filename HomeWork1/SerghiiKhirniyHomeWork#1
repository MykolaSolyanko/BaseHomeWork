// Homework1 Khirniy Serghii
//

#include <cmath>
#include <iostream>

int main() {
  //Задание переменных.
  double a{0};
  double b{0};
  double c{0};
  double x{0};

  //Задание констант.
  const int ConstTwo{2};
  const int ConstFour{4};

  //Установка русской локали, для корректного отображения в консоли.
  setlocale(LC_ALL, "Rus");

  //Ввод данных с клавиатуры.
  std::cout << "Введите значение a: ";
  while (!(std::cin >> a)) {
    std::cin.clear(); //Функция, которая восстанавливает поток, если что-то
                      //пошло не так. Например хотел получить число, а получил
                      //букву. Поток впадает в ступор Чтобы восстановить работу
                      //потока вызывается cin.clear().
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); //Функция, которая считывает символ и игнорирует его.
    std::cout << "Ошибка ввода. Повторите ввод: ";
  }

  std::cout << "Введите значение b: ";
  while (!(std::cin >> b)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка ввода. Повторите ввод: ";
  }

  std::cout << "Введите значение c: ";
  while (!(std::cin >> c)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка ввода. Повторите ввод: ";
  }

  //Вычисление дискриминанта. И вывод его в консоль.
  if ((b * b - ConstFour * a * c) >= 0) {
    x = (-1 * b + sqrt(b * b - ConstFour * a * c)) / (ConstTwo * a);
    std::cout << "Первый корень равен" << x << std::endl;
    x = (-1 * b - sqrt(b * b - ConstFour * a * c)) / (ConstTwo * a);
    std::cout << "Второй корень равен" << x << std::endl;
  } else {
    std::cout << "Дискриминант меньше 0, корни невещественные." << std::endl;
  }
}
