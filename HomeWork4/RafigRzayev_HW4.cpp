#include <chrono>
#include <functional>
#include <iostream>
#include <limits>
#include <random>

using Comp = std::function<bool(long, long)>;
using CompDouble = std::function<bool(double, double)>;
using CharSettings = std::function<bool(char)>;

void clear_stream() {
  std::cin.clear();
  std::cin.ignore();
}

void swap(int &a, int &b) {
  int temp = b;
  b = a;
  a = temp;
}

void swap(char &a, char &b) {
  char temp = b;
  b = a;
  a = temp;
}

/***************************** PRINT ARRAYS (<INT>, <DOUBLE>, <UNSIGNED>, <CHAR>) ******************************/

// prints sequence of integers
void print_sequence(const int *begin, const int *const end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "print_sequence() - Exception\n";
    return;
  }
  while (begin != end) {
    std::cout << *begin++ << ' ';
  }
  std::cout << std::endl;
}

// prints sequence of doubles
void print_sequence(const double *begin, const double *const end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "print_sequence() - Exception\n";
    return;
  }
  while (begin != end) {
    std::cout << *begin++ << ' ';
  }
  std::cout << std::endl;
}

// prints sequence of unsigned int
void print_sequence(const unsigned *begin, const unsigned *const end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "print_sequence() - Exception\n";
    return;
  }
  while (begin != end) {
    std::cout << *begin++ << ' ';
  }
  std::cout << std::endl;
}

// prints sequence of char
void print_sequence(const char *begin) {
  if (begin == nullptr) {
    std::cout << "print_sequence() - Exception\n";
    return;
  }
  while (*begin != '\0') {
    std::cout << *begin++;
  }
  std::cout << std::endl;
}

/******************** COPY ARRAY, USER-INPUT ARRAY, RANDOM GENERATED ARRAY, RANDOM NUMBER ************************/

// copies contents from a source integer sequence into the destination integer sequence
void copy_sequence(const int *src_begin, const int *const src_end, int *dst_begin) {
  if (src_begin == nullptr || src_end == nullptr || dst_begin == nullptr) {
    std::cout << "copy_sequence() - Exception\n";
    return;
  }
  while (src_begin != src_end) {
    *dst_begin++ = *src_begin++;
  }
}

// changes the values of integer sequence to user provided numbers
void fill_sequence_with_user_input(int *begin, const int *const end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "fill_sequence_with_user_input() - Exception\n";
    return;
  }
  size_t index{};
  while (begin != end) {
    std::cout << "Enter element #" << ++index << ": ";
    std::cin >> *begin++;
    clear_stream();
  }
}

// changes the values of integer sequence to random numbers
void fill_sequence_with_random_numbers(int *begin, const int *const end, const int LOW_LIMIT, const int HIGH_LIMIT) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "fill_sequence_with_random_numbers() - Exception\n";
    return;
  }
  std::random_device seed;
  std::default_random_engine rng(seed());
  std::uniform_int_distribution<int> distr(LOW_LIMIT, HIGH_LIMIT);
  while (begin != end) {
    *begin++ = distr(rng);
  }
}

// returns a random number between 0 and N-1
int random_number(const size_t N) {
  std::random_device seed;
  std::default_random_engine rng(seed());
  std::uniform_int_distribution<int> distr(0, N - 1);
  return distr(rng);
}

/********************************** BUBBLE SORT for <INT>, <DOUBLE>, <UNSIGNED> *************************************/

// sorts an integer sequence according to the bubble sort algorithm
void bubble_sort(int *begin, int *const end, Comp predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  while (true) {
    int *it{begin};
    size_t swap_counter{0};
    while (it != end - 1) {
      if (predicate(*it, *(it + 1))) {
        swap(*it, *(it + 1));
        ++swap_counter;
      }
      ++it;
    }
    if (swap_counter == 0) {
      break;
    }
  }
}

// sorts a double sequence according to the bubble sort algorithm
void bubble_sort(double *begin, const double *const end, CompDouble predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  while (true) {
    double *it{begin};
    size_t swap_counter{0};
    while (it != end - 1) {
      if (predicate(*it, *(it + 1))) {
        double temp{*it};
        *it = *(it + 1);
        *(it + 1) = temp;
        ++swap_counter;
      }
      ++it;
    }
    if (swap_counter == 0) {
      break;
    }
  }
}

// sorts an unsigned sequence according to the bubble sort algorithm
void bubble_sort(unsigned *begin, const unsigned *const end, Comp predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  while (true) {
    unsigned *it{begin};
    size_t swap_counter{0};
    while (it != end - 1) {
      if (predicate(*it, *(it + 1))) {
        unsigned temp{*it};
        *it = *(it + 1);
        *(it + 1) = temp;
        ++swap_counter;
      }
      ++it;
    }
    if (swap_counter == 0) {
      break;
    }
  }
}

/****************************************** BUBBLE SORT for <CHAR> ********************************************/

// returns address of null terminator in char sequence
char *find_null_terminator(char *begin, char *end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "find_null_terminator() - Exception\n";
    return end;
  }
  while (begin != end) {
    if (*begin == '\0') {
      return begin;
    }
    ++begin;
  }
  return end;
}

char *find_first_occurence(char * begin, char *end, CharSettings predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "find_first_occurence() - Exception\n";
    return end;
  }
  while (*begin != '\0') {
    if (predicate(*begin)) {
      return begin;
    }
    ++begin;
  }
  return end;  
}

// moves digits to the end of char sequence
void shift(char *begin, char *end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "shift() - Exception\n";
    return;
  }
  char *it = begin;
  char *first_digit = find_first_occurence(it, end, [] (char c) { return c >= '0' && c <= '9'; });
  char *first_non_digit = find_first_occurence(it, end, [] (char c) { return c < '0' || c > '9'; });
  const ptrdiff_t SHIFT = first_non_digit - first_digit;
  char *digits = new char[SHIFT];
  for(ptrdiff_t i{0}; i < SHIFT; ++i) {
    *(digits + i) = *(first_digit + i);
  }
  it = begin;
  while(it != end - SHIFT) {
    *it = *(it + SHIFT);
    ++it;
  }
  while(it != end) {
    *it++ = *digits++;
  }
}

// reverse a char sequence
void reverse(char *begin, char *terminator) {
  if (begin == nullptr || terminator == nullptr) {
    std::cout << "reverse() - Exception\n";
    return;
  }
  if (begin > terminator) {
    std::cout << "reverse() - Exception\n";
    return;
  }
  const size_t SEQUENCE_HALF = (terminator - begin) / 2;
  for (size_t i{0}; i < SEQUENCE_HALF; ++i) {
    swap(*(begin + i), *(terminator - 1 - i));
  }
}

// sorts a char sequence according to the bubble sort algorithm
void bubble_sort(char *begin, char *end, Comp predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  // find null terminator adress. stop sorting if sequence has just one element
  char *terminator = find_null_terminator(begin, end);
  if (terminator - begin < 2) {
    return;
  }
  // Bubble sort
  while (true) {
    char *it = begin;
    size_t swap_counter{0};
    while (*(it + 1) != '\0') {
      if (predicate(*it, *(it + 1))) {
        swap(*it, *(it + 1));
        ++swap_counter;
      }
      ++it;
    }
    if (swap_counter == 0) {
      break;
    }
  }
  // if all elements are same stop
  if (*(terminator - 1) == *begin) {
    return;
  }
  // increasing order implementation
  if (*(terminator - 1) > *begin) {
    shift(begin, terminator);
  }
  // decreasing order implementation
  else {
    reverse(begin, terminator);
    shift(begin, terminator);
    reverse(begin, terminator);
  }
}

/************************************* QUICKSORT ALGORITHM **********************************/

// methods to choose pivot number in quicksort algorithm
enum PIVOT_CHOISE { FIRST, MIDDLE, LAST, RANDOM, SIZE };

// returns first, middle, last, or random element from a sequence
std::function<int *(int *, int *)> choose_pivot[SIZE]{
    [](int *begin, int *end) { return begin; },
    [](int *begin, int *end) { return begin + (end - begin) / 2; },
    [](int *begin, int *end) { return end - 1; },
    [](int *begin, int *end) { return begin + random_number(end - begin); }};

// sorts an integer sequence according to the quicksort algorithm
void quick_sort(int *begin, int *end, Comp predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "quick_sort() - Exception\n";
    return;
  }
  if (begin >= end - 1) {
    return;
  }
  // Choose reference pivot, then move it to the end
  int *pivot = choose_pivot[FIRST](begin, end);
  swap(*pivot, *(end - 1));
  pivot = end - 1;
  // it - general iterator, it2 - set to first number >= pivot. (<= for decreasing order)
  int *it{begin};
  int *it2{nullptr};
  while (it != end) {
    if (predicate(*it, *pivot)) {
      it2 = it++;
      break;
    }
    ++it;
  }
  // Swap it2 with any number < pivot, then incremenet it2. (> for decreasing order)
  while (it != end) {
    if (!predicate(*it, *pivot)) {
      swap(*it, *it2);
      ++it2;
    }
    ++it;
  }
  // Move pivot from end to proper location
  swap(*pivot, *it2);
  pivot = it2;
  // Repeat process for parts before and after the pivot
  quick_sort(begin, pivot, predicate);
  quick_sort(pivot + 1, end, predicate);
}

/********************************************** TASK 1 **************************************************/

// Sets "random/manual array", and "print/don't print array" flags, show general
// info about test
void task_1_user_IO(const size_t _ARRAY_SIZE, const size_t _NUMBER_OF_TESTS, bool &_ENABLE_PRINT, bool &_RANDOM_ARRAY) {
  std::cout << "------------------------------------\n";
  std::cout << "\n\t\tBenchmark for Bubblesort and Quicksort Algorithms\n" << std::endl;
  std::cout << "Array size: " << _ARRAY_SIZE << std::endl;
  std::cout << "Number of tests: " << _NUMBER_OF_TESTS << std::endl;
  std::cout << "------------------------------------\n";
  std::cout << "Do you want to show arrays or hide them?\n";
  std::cout << " - Type 0 to hide arrays\n";
  std::cout << " - Type 1 to print arrays \n";
  std::cout << "Enter your selection: ";
  std::cin >> _ENABLE_PRINT;
  clear_stream();
  std::cout << "You have selected to " << (_ENABLE_PRINT ? "print arrays\n" : "hide arrays\n");
  std::cout << "------------------------------------\n";
  std::cout << "Do you want to fill arrays manually or randomly?\n";
  std::cout << " - Type 0 to fill array manually\n";
  std::cout << " - Type 1 to fill array randomly\n";
  std::cout << "Enter your selection: ";
  std::cin >> _RANDOM_ARRAY;
  std::cout << "You have selected to " << (_RANDOM_ARRAY ? "fill array randomly\n" : "fill array manually\n");
  clear_stream();
  std::cout << "------------------------------------\n";
  std::cout << "Processing..." << std::endl;
}

// Task 1 - Comparison of Bubble-Sort and Quick-Sort algorithms
void task_1() {

  // benchmark settings
  bool ENABLE_PRINT{}, RANDOM_ARRAY{};
  const size_t ARRAY_SIZE{10}, NUMBER_OF_TESTS{1};
  const int LOW_LIMIT{-10}, HIGH_LIMIT{10};
  int array[ARRAY_SIZE]{}, array_copy[ARRAY_SIZE]{};
  int* const array_end = array + ARRAY_SIZE;
  int* const array_copy_end = array_copy + ARRAY_SIZE;
  std::chrono::duration<double> bubble_sort_duration{}, quick_sort_duration{};

  // arrange user settings and provide general info
  task_1_user_IO(ARRAY_SIZE, NUMBER_OF_TESTS, ENABLE_PRINT, RANDOM_ARRAY);
  // disable manual input for large arrays or many tests
  if (RANDOM_ARRAY == false && (ARRAY_SIZE > 20 || NUMBER_OF_TESTS > 2)) {
    std::cout << "task_1(): Exception - Can't allow manual input. Requires too much time. Exiting\n";
    return;
  }
  // benchmark loop
  for (size_t i{0}; i < NUMBER_OF_TESTS; ++i) {

    // Fill array. Copy values to array_copy, so both algorithms process same data.
    if (RANDOM_ARRAY) {
      fill_sequence_with_random_numbers(array, array_end, LOW_LIMIT, HIGH_LIMIT);
    } else {
      fill_sequence_with_user_input(array, array_end);
    }
    copy_sequence(array, array_end, array_copy);

    // Show arrays before sorting
    if (ENABLE_PRINT) {
      std::cout << "------------------------------------\n";
      std::cout << "\t\t\tTEST " << i + 1 << std::endl;
      std::cout << "ARRAY BEFORE BUBBLESORT: ";
      print_sequence(array, array_end);
      std::cout << "ARRAY BEFORE QUICKSORT : ";
      print_sequence(array_copy, array_copy_end);
    }

    // Bubble sort duration
    auto bubble_start_time = std::chrono::system_clock::now();
    bubble_sort(array, array_end, [](int p1, int p2) { return p1 > p2; });
    auto bubble_end_time = std::chrono::system_clock::now();
    bubble_sort_duration += bubble_end_time - bubble_start_time;

    // Quick sort duration
    auto quick_start_time = std::chrono::system_clock::now();
    quick_sort(array_copy, array_copy_end, [](int p1, int p2) { return p1 >= p2; });
    auto quick_end_time = std::chrono::system_clock::now();
    quick_sort_duration += quick_end_time - quick_start_time;

    // Show arrays after sorting
    if (ENABLE_PRINT) {
      std::cout << "ARRAY AFTER BUBBLESORT : ";
      print_sequence(array, array_end);
      std::cout << "ARRAY AFTER QUICKSORT  : ";
      print_sequence(array_copy, array_copy_end);
    }
  }
  bubble_sort_duration /= NUMBER_OF_TESTS;
  quick_sort_duration /= NUMBER_OF_TESTS;

  // Test results
  std::cout << "------------------------------------\n";
  std::cout << "Bubble Sort: " << bubble_sort_duration.count() << " seconds" << std::endl;
  std::cout << "Quick Sort: " << quick_sort_duration.count() << " seconds" << std::endl;
  double ratio = bubble_sort_duration / quick_sort_duration;
  if (ratio > 1) {
    std::cout << "Quicksort is " << ratio << " times faster" << std::endl;
  } else {
    std::cout << "Bubble sort is " << 1 / ratio << "times faster" << std::endl;
  }
}

/************************************************* TASK 2 **********************************************************/

// generates an unsigned array. shows it before and after the sorting process
void print_and_sort_unsigned(Comp predicate) {
  const size_t UNSIGNED_ARRAY_SIZE{10};
  unsigned unsigned_array[UNSIGNED_ARRAY_SIZE]{1,  0, 300, 522, 6, 41, 0, 10,  155, 2222};
  unsigned *begin = unsigned_array;
  const unsigned *const end = unsigned_array + UNSIGNED_ARRAY_SIZE;
  std::cout << "unsigned array before sort: ";
  print_sequence(begin, end);
  bubble_sort(begin, end, predicate);
  std::cout << "unsigned array after sort : ";
  print_sequence(begin, end);
  std::cout << "------------------------------------\n";
}

// generates a double array. shows it before and after the sorting process
void print_and_sort_double(CompDouble predicate) {
  const size_t DOUBLE_ARRAY_SIZE{5};
  double double_array[DOUBLE_ARRAY_SIZE]{-4.75, 5.11, 7.45, -4, 0};
  double *begin = double_array;
  const double *const end = double_array + DOUBLE_ARRAY_SIZE;
  std::cout << "double array before sort: ";
  print_sequence(begin, end);
  bubble_sort(begin, end, predicate);
  std::cout << "double array after sort : ";
  print_sequence(begin, end);
  std::cout << "------------------------------------\n";
}

// generates a char array. shows it before and after the sorting process
void print_and_sort_char(Comp predicate) {
  const size_t CHAR_ARRAY_SIZE{1000};
  char char_array[CHAR_ARRAY_SIZE] = "zA1xB2yC3";
  char *begin = char_array;
  char *end = char_array + CHAR_ARRAY_SIZE;
  std::cout << "char array before sort: ";
  print_sequence(begin);
  bubble_sort(begin, end, predicate);
  std::cout << "char array after sort : ";
  print_sequence(begin);
}

// Task 2 - Sorting unsigned, double, and char arrays
void task_2() {
  std::cout << "------------------------------------\n";
  std::cout << "\n\t\tSort unsigned, double, and char arrays\n" << std::endl;
  std::cout << "------------------------------------\n";
  print_and_sort_unsigned([](unsigned p1, unsigned p2) { return p1 < p2; });
  print_and_sort_double([](double p1, double p2) { return p1 < p2; });
  print_and_sort_char([](char p1, char p2) { return p1 > p2; });
}

/*********************************************** MENU *************************************************/

enum MENU { QUIT, TASK_1, TASK_2};

int main() {
  std::function<void()> menu[TASK_2]{task_1, task_2};
  while (true) {
    std::cout << "------------------------------------\n";
    std::cout << "               MENU                 \n";
    std::cout << TASK_1 << " - TASK 1\n";
    std::cout << TASK_2 << " - TASK 2\n";
    std::cout << QUIT << " - QUIT  \n";
    std::cout << "Enter your selection: ";
    size_t selection;
    std::cin >> selection;
    if (selection != QUIT && selection != TASK_1 && selection != TASK_2) {
      std::cout << "Unknown command\n";
      continue;
    }
    if (selection == QUIT) {
      std::cout << "Quitting...\n";
      return 0;
    }
    menu[selection - 1]();
  }
  return 1;
}