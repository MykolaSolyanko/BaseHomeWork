#include "stdafx.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  // # 1 ИНИЦИАЛИЗАЦИЯ ЧЕРЕЗ КЛАВИАТУРУ

  const int arr = 10;
  int a[arr], summ = 0, b[arr];
  int i = 0, sredn_arefm, m = 0;
  for (size_t j = 0; j < 10; j++) {
    cin >> a[j];
    cout << setw(9) << "a"
         << "[" << j << "]" << setw(9) << a[j] << endl;
    // суммируем все елементы массива  summ
    summ += a[j];
    cout << setw(9) << "summ" << setw(9) << summ << endl;
    m++;
    //
    // Cреднее арифметичесkое
    sredn_arefm = summ / m;
    cout << setw(9) << "average" << setw(9) << sredn_arefm << endl;
  }
  system("pause");
  return 0;
}
