#include <iostream>

int main() {
  int n;
  int first = 0;
  int second = 0;
  int i = 0;
  std::cout << "Please enter number type ******" << std::endl;
  std::cin >> n;
  while (i < 3) {
    first += n % 10;
    n /= 10;
    i++;
  }
  while (n != 0) {
    second += n % 10;
    n /= 10;
  }
  if (second == first) {
    std::cout << "Lucky ticket";
  } else {
    std::cout << "No Lucky ticket";
  }

  return 0;
}
 
