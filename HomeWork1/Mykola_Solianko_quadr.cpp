
#include <iostream>
int main(int argc, const char **argv) {

  int value = 10;
  std::cout << ++value << std::endl;

  std::cout << value++ << std::endl;
  std::cout << value << std::endl;

  i++;
  // ++i;

  // value++
  int temp = value;
  value = value + 1;
  std::cout << temp << std::endl;

  value--;
  --value;
  return 0;
}
