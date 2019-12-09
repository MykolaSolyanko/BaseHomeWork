// Обратные числа  № 3
#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int Num;
  cout << "Enter number: ";
  cin >> Num;
  cout << setw(9) << "reverse " << setw(9) << Num << endl << endl;
  for (int n = 0; Num > 0; Num /= 10) {
    n = Num % 10;
    cout << setw(8) << "n" << setw(9) << n << endl << endl;
  }
  system("pause");
  return 0;
}
