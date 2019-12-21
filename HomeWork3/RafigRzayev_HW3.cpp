#include <iostream>
#include <random>

// Print int sequence to console
void Print(const int *begin, const int *const end) {
  // Exceptions
  if (begin == nullptr || end == nullptr) {
    std::cout << "Print() - EXCEPTION: Null pointer passed as an argument" << std::endl;
    return;
  }
  if (begin == end) {
    std::cout << "[]" << std::endl;
    return;
  }
  // Print in the form "[1, 2, 3, ...]"
  std::cout << "[";
  while (begin != end) {
    std::cout << *begin++;
    if (begin < end) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
}

// Print char sequence to console
void Print(const char *begin, const char *const end) {
  // Exceptions
  if (begin == nullptr || end == nullptr) {
    std::cout << "Print() - EXCEPTION: Null pointer passed as an argument" << std::endl;
    return;
  }
  if (begin == end) {
    std::cout << "Print() - EXCEPTION: Sequence size is 0" << std::endl;
    return;
  }
  // Print in the form "abc..."
  while (begin != end) {
    std::cout << *begin++;
  }
  std::cout << "\n";
}

// Sort first N elements of array
void SortArray(int array[], const size_t ARRAY_SIZE, const size_t N) {
  // Skip sorting single element
  if (N < 2) {
    return;
  }
  // Exceptions
  if (N > ARRAY_SIZE) {
    std::cout << "SortArray() - EXCEPTION: N > ARRAY_SIZE" << std::endl;
    return;
  }
  if (ARRAY_SIZE == 0) {
    std::cout << "SortArray() - EXCEPTION: ARRAY_SIZE == 0" << std::endl;
    return;
  }
  // Algorithm
  for (size_t i{0}; i < N; ++i) {
    int min{array[i]};
    size_t min_index{i};
    for (size_t j{i}; j < N; ++j) {
      if (array[j] < min) {
        min = array[j];
        min_index = j;
      }
    }
    array[min_index] = array[i];
    array[i] = min;
  }
}

// Fill array with random numbers between [LOW_LIMIT;HIGH_LIMIT]
void RandomArray(int array[], const size_t ARRAY_SIZE, const int LOW_LIMIT, const int HIGH_LIMIT) {
  // Exceptions
  if (ARRAY_SIZE == 0) {
    std::cout << "RandomArray() - EXCEPTION: ARRAY_SIZE == 0" << std::endl;
    return;
  }
  if (LOW_LIMIT > HIGH_LIMIT) {
    std::cout << "RandomArray() - EXCEPTION: Limits are not correct" << std::endl;
    return;
  }
  // Algorithm
  std::random_device seed;
  std::mt19937 random_generator(seed());
  std::uniform_int_distribution<int> distribution(0, 10000);
  for (size_t i{0}; i < ARRAY_SIZE; ++i) {
    array[i] = distribution(random_generator) % (HIGH_LIMIT - LOW_LIMIT + 1) + LOW_LIMIT;
  }
}

// Finds a number in a sequence and returns its adress. Returns end if not found.
int* Search(const int num, int *begin, int *const end) {
  // Exceptions
  if (begin == nullptr || end == nullptr) {
    std::cout << "Search() - EXCEPTION: Invalid pointer passed as an argument" << std::endl;
    return end;
  }
  if (begin == end) {
    std::cout << "Search() - EXCEPTION: Sequence size is 0" << std::endl;
    return end;
  }
  // Algorithm
  while (begin != end) {
    if ((*begin) == num) {
      return begin;
    }
    ++begin;
  }
  return end;
}

// Swaps found number with last unfound number in the array. Make last unfound number 0.
void ReplaceFoundNumber(int *const found_number_adress, int *const last_non_deleted_address) {
  if (found_number_adress == nullptr || last_non_deleted_address == nullptr) {
    std::cout << "ReplaceFoundNumber() - EXCEPTION: Invalid pointer passed as an argument" << std::endl;
    return;
  }
  *found_number_adress = *last_non_deleted_address;
  *last_non_deleted_address = 0;
}

// Task 1
void ReverseInput() {
  std::cout << "\n\t\t\tREVERSE THE INPUT\n\n";
  const size_t INPUT_LENGTH{200};
  char user_text[INPUT_LENGTH]{};
  std::cout << "Enter user text: ";
  std::cin >> user_text;
  size_t length{};
  while (user_text[length] != '\0') {
    ++length;
  }
  size_t half_of_array{length / 2};
  char* begin = user_text;
  char* end = user_text + length - 1;
  while(begin != user_text + half_of_array) {
    char temp = *begin;
    *begin++  = *end;
    *end-- = temp;
  }
  Print(user_text, user_text + length);
  std::cout << std::endl;
}

// Task 2
void InsertSortPrint() {
  std::cout << "\n\t\t\tADD NUMBERS TO ARRAY AND SORT THEM\n";
  const size_t ARRAY_SIZE{10};
  int numbers[ARRAY_SIZE]{};
  unsigned int entered_elements_counter{0};
  for (auto &num : numbers) {
    std::cout << "\nEnter number: ";
    std::cin >> num;
    SortArray(numbers, ARRAY_SIZE, ++entered_elements_counter);
  }
  Print(numbers, numbers + ARRAY_SIZE);
}

// Task 3
void SearchAndDelete() {
  // Intro and Random Array Generation
  std::cout << "\n\t\t\tSEARCH FOR NUMBERS INSIDE ARRAY\n\n";
  const size_t ARRAY_SIZE{10};
  std::cout << "Search for values in the generated array[" << ARRAY_SIZE << "]\n";
  const int STOP{77};
  std::cout << "Program will stop when all values are found or if you type " << STOP << "\n";
  const int LOW_LIMIT{-10}, HIGH_LIMIT{10};
  int numbers[ARRAY_SIZE]{};
  RandomArray(numbers, ARRAY_SIZE, LOW_LIMIT, HIGH_LIMIT);
  std::cout << "Generated array: ";
  SortArray(numbers, ARRAY_SIZE, ARRAY_SIZE);
  Print(numbers, numbers + ARRAY_SIZE);
  // Algorithm
  size_t found_numbers_counter{0};
  while (found_numbers_counter != ARRAY_SIZE) {
    // User input handling
    std::cout << "\nEnter a number between [" << LOW_LIMIT << "; " << HIGH_LIMIT << "]: ";
    int user_number{};
    std::cin >> user_number;
    while ((user_number < LOW_LIMIT || user_number > HIGH_LIMIT) && user_number != STOP) {
      std::cout << "Input out of bounds. Try again\n";
      std::cout << "Enter a number between [" << LOW_LIMIT << "; " << HIGH_LIMIT << "]: ";
      std::cin >> user_number;
    }
    if (user_number == STOP) {
      std::cout << "\nExiting SearchAndDelete()\n";
      return;
    }
    // Search for value. If found, make it zero, swap with last value, then sort
    int *const end = numbers + ARRAY_SIZE - found_numbers_counter;
    int *const user_number_adress = Search(user_number, numbers, end);
    if (user_number_adress != end) {
      std::cout << "deleting " << user_number << " from array\n";
      ReplaceFoundNumber(user_number_adress, end - 1);
      ++found_numbers_counter;
      SortArray(numbers, ARRAY_SIZE, ARRAY_SIZE - found_numbers_counter);
      Print(numbers, end - 1);
    } else {
      std::cout << user_number << " not found in array\n";
    }
  }
  std::cout << "\nFinished\n";
}

// Task 4
void Lowercase() {
  std::cout << "\n\t\t\tMAKE INPUT LOWERCASE\n\n";
  const size_t INPUT_LENGTH{200};
  char user_text[INPUT_LENGTH]{};
  std::cout << "Enter user text: ";
  std::cin >> user_text;
  for (size_t i{0}; user_text[i] != '\0'; ++i) {
    if (user_text[i] >= 'A' && user_text[i] <= 'Z') {
      user_text[i] += 32;
    }
  }
  Print(user_text, user_text + INPUT_LENGTH);
  std::cout << std::endl;
}

// Task 5
void Uppercase() {
  std::cout << "\n\t\t\tMAKE INPUT UPPERCASE\n\n";
  const size_t INPUT_LENGTH{200};
  char user_text[INPUT_LENGTH]{};
  std::cout << "Enter user text: ";
  std::cin >> user_text;
  for (size_t i{0}; user_text[i] != '\0'; ++i) {
    if (user_text[i] >= 'a' && user_text[i] <= 'z') {
      user_text[i] -= 32;
    }
  }
  Print(user_text, user_text + INPUT_LENGTH);
  std::cout << std::endl;
}

// Task 6
void FindDigits() {
  std::cout << "\n\t\t\tFIND DIGITS IN THE INPUT\n\n";
  const size_t INPUT_LENGTH{200};
  char user_text[INPUT_LENGTH]{};
  std::cout << "Enter user text: ";
  std::cin >> user_text;
  std::cout << "Digits: ";
  for (size_t i{0}; user_text[i] != '\0'; ++i) {
    if (user_text[i] >= '0' && user_text[i] <= '9') {
      std::cout << user_text[i] << " ";
    }
  }
  std::cout << std::endl;
}

enum MENU {
  QUIT,
  REVERSE_INPUT,
  INSERT_SORT_PRINT,
  SEARCH_AND_DELETE,
  LOWERCASE,
  UPPERCASE,
  FIND_DIGITS
};

void MainMenuText() {
  std::cout << "-------------------------------------------------------------\n";
  std::cout << "                         MAIN MENU                           \n";
  std::cout << "                                                             \n";
  std::cout << REVERSE_INPUT      << " - REVERSE THE INPUT                   \n";
  std::cout << INSERT_SORT_PRINT  << " - ADD NUMBERS TO ARRAY AND SORT THEM  \n";
  std::cout << SEARCH_AND_DELETE  << " - SEARCH FOR NUMBERS INSIDE ARRAY     \n";
  std::cout << LOWERCASE          << " - MAKE INPUT LOWERCASE                \n";
  std::cout << UPPERCASE          << " - MAKE INPUT UPPERCASE                \n";
  std::cout << FIND_DIGITS        << " - FIND DIGITS IN THE INPUT            \n";
  std::cout << QUIT               << " - QUIT                                \n";
  std::cout << "-------------------------------------------------------------\n";
  std::cout << "Enter your command: ";
}

int main() {
  while (true) {
    MainMenuText();
    int user_selection;
    std::cin >> user_selection;
    switch (user_selection) {
    case REVERSE_INPUT:
      ReverseInput();
      break;
    case INSERT_SORT_PRINT:
      InsertSortPrint();
      break;
    case SEARCH_AND_DELETE:
      SearchAndDelete();
      break;
    case LOWERCASE:
      Lowercase();
      break;
    case UPPERCASE:
      Uppercase();
      break;
    case FIND_DIGITS:
      FindDigits();
      break;
    case QUIT:
      std::cout << "Goodbye" << std::endl;
      return 0;
    default:
      std::cout << "Unknown command. Please try again" << std::endl;
    }
  }
}