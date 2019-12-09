// Сумма нечетный елементов № 4
// Вывод из масива нечетных елементов
// Не записал сумирование !!!!!!!!!!!! ДОБАВИТЬ
#include "stdafx.h"
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Russian");
  srand(time(NULL));
  const int Size = 50;
  int a[Size];
  int b[Size], j = 0;
  for (int i = 0; i < Size; i++) {
    a[i] = -60 + rand() % 90;
  }
  cout << " вывод всего инициализированного массива" << endl;
  for (int i = 0; i < Size; i++) {
    cout << "i"
         << "[" << i << "]" << setw(10) << a[i] << endl
         << endl;
  }
  for (int i = 0; i < Size; i++) {
    if (a[i] % 2 > 0) {
      b[j] = a[i];
      j++;
    }
  }
  cout << " вывод всего отсортированного с нечетными элементами массива";
  for (size_t i = 0; i < j; i++)
    cout << setw(9) << "b"
         << "[" << i << "]" << setw(10) << b[i] << endl
         << endl;
  system("pause");
  return 0;
}
// Здесь в прогрм № 4 не суммировал  исправлю
// Ввыводятся все числа только со знаком (+). Может как то по модулю ??
//
