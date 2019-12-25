#include <iostream>

int main() {
  char array[200];
  char array_reverse[200];
  int index_array_reverse = 0;
  std::cout << "This program expands the word you entered" << std::endl;
  std::cout << "Enter your word" << std::endl;
  std::cin >> array;
  size_t index_array = 0;
  while (array[index_array] != '\0') {
    index_array++;
  }
  int Index_array = index_array;
  while (index_array_reverse < index_array) {
    Index_array--;
    array_reverse[index_array_reverse] = array[Index_array];
    index_array_reverse++;
  }
  std::cout << "Your inverted word-";
  for (int i = 0; i < index_array; ++i) {
    std::cout << array_reverse[i];
  }
  return 0;
}
