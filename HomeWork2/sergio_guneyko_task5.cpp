//ОПРЕДЕЛЕНИЕ ДЕЛИТЕЛЯ                ( Лучший делитель) № 5
#include "iostream"
#include "stdafx.h"
using namespace std;

int main(int argc, _TCHAR *argv[]) {
  setlocale(LC_ALL, "Russian");
  int n;
  cout << "Введите число: ";
  cin >> n;
  for (int i = 1; i <= n / 2; i++)
    if (n % i == 0)
      cout << i << " ";
  cout << endl;
  system("pause");
  return 0;
}
// Здесь можно было выводить в обратном порядке на уменьшение(i--) и т.д
// пропустить не нужные continue. И вывести нужное с break
