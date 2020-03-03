#include <iostream>
using namespace std;

int main() {
  int b1, b2, b3;
  cin >> b1 >> b2 >> b3;
  if ((b1 + b2 + b3) % 3 != 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    int average;
    int count = 0;
    average = (b1 + b2 + b3) / 3;
    if (b1 > average)
      count += b1 - average;
    if (b2 > average)
      count += b2 - average;
    if (b3 > average)
      count += b3 - average;
    cout << count << endl;
  }

  int value;
  cin >> value;

  return 0;
}
