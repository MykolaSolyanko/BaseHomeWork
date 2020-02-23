// Счастливый билетик  №2

//                          Если вводить по одному елементу + enter - то
//                          работает  пр № 2
// Может как-то GET Char() и т.д !!!!!!!!
#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  setlocale(LC_ALL, "Russian");
  cout << " Ввести 6- ти значное число с клавиатуры и проверить его ввод"
       << endl;

  int length = 6, a[6], b, c;
  for (int i = 0; i < length; i++) {
    cin >> a[i];
    cout << setw(9) << "a"
         << "[" << i << "]" << setw(10) << a[i] << endl;
    b = a[0] + a[1] + a[2];
    c = a[3] + a[4] + a[5];
    if (b == c)
      cout << "Левая и правая часть имеют суммарно одинаковое значение "
           << endl;
    else
      cout << "Левая и правая часть суммарно не соответствуют " << endl;
  }
  system("pause");
  return 0;
}
