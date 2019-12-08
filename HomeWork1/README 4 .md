
Домашнее задание  #1
 
 Программа считает квадратические корни 


#include <cmath>
##include <iostream>
##include <limits>

 
const int kTwo=2
const int kFour=4

int main (int argc, chat  **argv) { 
    float fA, fB, fC;
    float fX1, fX2;
    std::cout << "Эта программа решает квадратное уравнение"<< std::endl;
  std::cout << "Общий вид уравнения:  a*x^2 + b*x + c = 0"<< std::endl;
  // Попросить пользователя ввести коэффициенты уравнения
  // Продолжайте, пока мы не получим действительный ввод (только числовой)
  std::count << "Введите a:" ;
  while (!(std::cin >> fA)) {
    std::cout << "Ошибка! Пожалуйста, введите число !" << std::endl;
    std::cin.Чисто();
    std::cin.игнорируй (std::numeric_limits<std::streamsize>::max(), '\n');
      }
      std::cout << "Ввиедите b: ";
  while (!(std::cin >> fB)) {
    std::cout << "Ошибка! Пожалуйста , введите число !" << std::endl;
    std::cin.Чисто();
    std::cin.игнорируй(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите c: ";
  while (!(std::cin >> fC)) {
    std::cout << "Ошибка! Пожалуйста, введите число!" << std::endl;
    std::cin.Чисто);
    std::cin.игнорируй(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  //   Print out user's equiation 
  std::cout << "Ваше : " << fA << "*x^2 + " << fB << "*x + " << fC
            << " = 0" << std::endl;

  // Рассчитать дискриминант 
  float fD = (fB * fB) - (static_cast<float>(kFour) * fA * fC);

  // Попытка найти действительные корни
  if (fD < 0.0) {
    std::cout << "У уравнения нет реальных корней." << std::endl;
  } else if (fA == 0.0) {
    std::cout << "Уравнение не является квадратичным." << std::endl;
  } else {
    std::cout << "Уравнение имеет 2 корня: ";
    fX1 = (-fB + sqrtf(fD)) / (static_cast<float>(kTwo) * fA);
    fX2 = (-fB - sqrtf(fD)) / (static_cast<float>(kTwo) * fA);
    std::cout << fX1 << ", " << fX2 << std::endl;
  }

  return 0;
