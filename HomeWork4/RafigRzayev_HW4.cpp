#include <chrono>
#include <functional>
#include <iostream>
#include <limits>
#include <random>

/***************************** PRINT ARRAYS (<INT>, <DOUBLE>, <UNSIGNED>, <CHAR> ) **************************/

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
void print_sequence(const char *begin, const char *const end) {
  if (begin == nullptr || end == nullptr) {
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
void copy_sequence(int *dst_begin, const int *const dst_end, const int *src_begin, const int *const src_end) {
  if (dst_begin == nullptr || dst_end == nullptr || src_begin == nullptr || src_end == nullptr) {
    std::cout << "copy_sequence() - Exception\n";
    return;
  }
  while (dst_begin != dst_end) {
    *dst_begin++ = *src_begin++;
  }
}

// changes the values of integer sequence to user provided numbers
void user_sequence(int *begin, const int *const end) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "user_sequence() - Exception\n";
    return;
  }
  size_t index{};
  while (begin != end) {
    std::cout << "Enter element #" << ++index << ": ";
    std::cin >> *begin++;
    std::cin.clear();
    std::cin.ignore();
  }
}

// changes the values of integer sequence to random numbers
void random_sequence(int *begin, const int *const end, const int LOW_LIMIT, const int HIGH_LIMIT) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "random_sequence() - Exception\n";
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

/****************************** BUBBLE SORT for <INT>, <DOUBLE>, <UNSIGNED>, <CHAR> ************************/

// sorts an integer sequence according to the bubble sort algorithm
void bubble_sort(int *begin, int *const end, std::function<bool(int *, int *)> predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  int *it{begin};
  while (true) {
    size_t swap_counter{0};
    while (it != end - 1) {
      if (predicate(it, it + 1)) {
        int temp{*it};
        *it = *(it + 1);
        *(it + 1) = temp;
        ++swap_counter;
      }
      ++it;
    }
    if (swap_counter == 0) {
      break;
    }
    it = begin;
  }
  return;
}

// sorts a double sequence according to the bubble sort algorithm
void bubble_sort(double *begin, double *const end, std::function<bool(double *, double *)> predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  double *it{begin};
  while (true) {
    size_t swap_counter{0};
    while (it != end - 1) {
      if (predicate(it, it + 1)) {
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
    it = begin;
  }
  return;
}

// sorts an unsigned sequence according to the bubble sort algorithm
void bubble_sort(unsigned *begin, unsigned *const end, std::function<bool(unsigned *, unsigned *)> predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  unsigned *it{begin};
  while (true) {
    size_t swap_counter{0};
    while (it != end - 1) {
      if (predicate(it, it + 1)) {
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
    it = begin;
  }
  return;
}

// sorts a char sequence according to the bubble sort algorithm
void bubble_sort(char *begin, char *const end, std::function<bool(char *, char *)> predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  // find null terminator adress
  char *it{begin};
  char *terminator{end};
  while (it != end) {
    if (*it == '\0') {
      terminator = it;
      break;
    }
    ++it;
  }
  // stop sorting if sequence has just one element
  if (terminator - begin < 2) {
    return;
  }
  // start bubble sort
  it = begin;
  while (true) {
    size_t swap_counter{0};
    while (*(it + 1) != '\0') {
      if (predicate(it, it + 1)) {
        char temp{*it};
        *it = *(it + 1);
        *(it + 1) = temp;
        ++swap_counter;
      }
      ++it;
    }
    if (swap_counter == 0) {
      break;
    }
    it = begin;
  }
  // end of bubble sort

  // if first and last elements are same after sorting, no need for rearrangment
  if (*(terminator - 1) == *begin) {
    return;
  }
  //  IMPLEMENTATION FOR INCREASING ORDER
  /*  Example: "123ABCabc"
      first_digit = 1; first_non_digit = A
      Shift = &A - &1 = 3.
      Swap all neighbor elements 3 times (start from FIRST element)
      Result-> "ABCabc123"*/
  if (*(terminator - 1) > *begin) {
    // find first digit
    char *first_digit{begin};
    it = begin;
    while (*it != '\0') {
      if (*it >= '0' && *it <= '9') {
        first_digit = it;
        break;
      }
      ++it;
    }
    // find first non-digit
    char *first_non_digit{begin};
    while (*it != '\0') {
      if (*it < '0' || *it > '9') {
        first_non_digit = it;
        break;
      }
      ++it;
    }
    // find shift. Swap all elements "shift" times.
    const size_t shift = first_non_digit - first_digit;
    for (size_t i{}; i < shift; ++i) {
      it = begin;
      while (*(it + 1) != '\0') {
        char temp = *it;
        *it = *(it + 1);
        *(it + 1) = temp;
        ++it;
      }
    }
  }

  //  IMPLEMENTATION FOR DECREASING ORDER
  /*  Example: "cbaCBA321"
      last_digit = 1; last_non_digit = A
      Shift = &A - &1 = 3. 
      Swap all neighbor elements 3 times (start from LAST element). 
      Result-> "321cbaCBA"*/
  else {
    // find last digit
    char *last_digit{terminator};
    it = terminator - 1;
    while (it != begin - 1) {
      if (*it >= '0' && *it <= '9') {
        last_digit = it;
        break;
      }
      --it;
    }
    // find last non-digit
    char *last_non_digit{terminator};
    while (it != begin - 1) {
      if (*it < '0' || *it > '9') {
        last_non_digit = it;
        break;
      }
      --it;
    }
    // find shift. Swap all elements "shift" times.
    const size_t shift = last_digit - last_non_digit;
    for (size_t i{0}; i < shift; ++i) {
      it = terminator - 1;
      while (it != begin) {
        char temp = *it;
        *it = *(it - 1);
        *(it - 1) = temp;
        --it;
      }
    }
  }
  return;
}

/************************************* QUICKSORT ALGORITHM **********************************/

// methods to choose pivot number in quicksort algorithm 
enum class PIVOT_CHOISE { FIRST, MIDDLE, LAST, RANDOM, SIZE };

// returns first, middle, last, or random element from a sequence
std::function<int *(int *, int *)> choose_pivot[static_cast<size_t>(PIVOT_CHOISE::SIZE)]{
    [](int *begin, int *end) { return begin; },
    [](int *begin, int *end) { return begin + (end - begin) / 2; },
    [](int *begin, int *end) { return end - 1; },
    [](int *begin, int *end) { return begin + random_number(end - begin); }};

// sorts an integer sequence according to the quicksort algorithm
void quick_sort(int *begin, int *end, std::function<bool(int *, int *)> predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "quick_sort() - Exception\n";
    return;
  }
  if (begin >= end - 1) {
    return;
  }
  // Choose reference pivot, then move it to the end
  int *pivot = choose_pivot[static_cast<size_t>(PIVOT_CHOISE::FIRST)](begin, end);
  int temp1 = *(end - 1);
  *(end - 1) = *pivot;
  *pivot = temp1;
  pivot = end - 1;
  // it - general iterator, it2 - set to first number >= pivot. (<= for decreasing order)
  int *it{begin};
  int *it2{nullptr};
  while (it != end) {
    if (predicate(it, pivot)) {
      it2 = it++;
      break;
    }
    ++it;
  }
  // Swap it2 with any number < pivot, then incremenet it2. (> for decreasing order)
  while (it != end) {
    if (!predicate(it, pivot)) {
      int temp = *it2;
      *it2++ = *it;
      *it = temp;
    }
    ++it;
  }
  // Move pivot from end to proper location
  int temp2 = *it2;
  *it2 = *pivot;
  *pivot = temp2;
  pivot = it2;
  // Repeat process for parts before and after the pivot
  quick_sort(begin, pivot, predicate);
  quick_sort(pivot + 1, end, predicate);
}

/********************************************** TASK 1 **************************************************/

// Sets "random/manual array", and "print/don't print array" flags, show general info about test
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
  std::cin.clear();
  std::cin.ignore();
  std::cout << "You have selected to " << (_ENABLE_PRINT ? "print arrays\n" : "hide arrays\n");
  std::cout << "------------------------------------\n";
  std::cout << "Do you want to fill arrays manually or randomly?\n";
  std::cout << " - Type 0 to fill array manually\n";
  std::cout << " - Type 1 to fill array randomly\n";
  std::cout << "Enter your selection: ";
  std::cin >> _RANDOM_ARRAY;
  std::cout << "You have selected to " << (_RANDOM_ARRAY ? "fill array randomly\n" : "fill array manually\n");
  std::cin.clear();
  std::cin.ignore();
  std::cout << "------------------------------------\n";
  std::cout << "Processing..." << std::endl;
}

// Task 1 - Comparison of Bubble-Sort and Quick-Sort algorithms
void task_1() {

  // benchmark settings
  bool ENABLE_PRINT{}, RANDOM_ARRAY{};
  const size_t ARRAY_SIZE{5000}, NUMBER_OF_TESTS{5};
  const int LOW_LIMIT{std::numeric_limits<int>::min()}, HIGH_LIMIT{std::numeric_limits<int>::max()};
  int array[ARRAY_SIZE]{}, array_copy[ARRAY_SIZE]{};
  std::chrono::duration<double> bubble_sort_duration{}, quick_sort_duration{};

  // arrange user settings and provide general info
  task_1_user_IO(ARRAY_SIZE, NUMBER_OF_TESTS, ENABLE_PRINT, RANDOM_ARRAY);
  // disable manual input for large arrays or many tests
  if (RANDOM_ARRAY == false && (ARRAY_SIZE > 20 || NUMBER_OF_TESTS > 2) ) {
    std::cout << "task_1(): Exception - Can't allow manual input. Requires too much time. Exiting\n";
    return;
  }
  // benchmark loop
  for (size_t i{0}; i < NUMBER_OF_TESTS; ++i) {

    // Fill array. Copy values to array_copy, so both algorithms process same data.
    if (RANDOM_ARRAY) {
      random_sequence(array, array + ARRAY_SIZE, LOW_LIMIT, HIGH_LIMIT);
    }
    if (!RANDOM_ARRAY) {
      user_sequence(array, array + ARRAY_SIZE);
    }
    copy_sequence(array_copy, array_copy + ARRAY_SIZE, array, array + ARRAY_SIZE);

    // Show arrays before sorting
    if (ENABLE_PRINT) {
      std::cout << "------------------------------------\n";
      std::cout << "\t\t\tTEST " << i + 1 << std::endl;
      std::cout << "ARRAY BEFORE BUBBLESORT: ";
      print_sequence(array, array + ARRAY_SIZE);
      std::cout << "ARRAY BEFORE QUICKSORT : ";
      print_sequence(array_copy, array_copy + ARRAY_SIZE);
    }

    // Bubble sort duration
    auto bubble_start_time = std::chrono::system_clock::now();
    bubble_sort(array, array + ARRAY_SIZE, [](int *p1, int *p2) { return *p1 > *p2; });
    auto bubble_end_time = std::chrono::system_clock::now();
    bubble_sort_duration += bubble_end_time - bubble_start_time;

    // Quick sort duration
    auto quick_start_time = std::chrono::system_clock::now();
    quick_sort(array_copy, array_copy + ARRAY_SIZE, [](int *p1, int *p2) { return *p1 >= *p2; });
    auto quick_end_time = std::chrono::system_clock::now();
    quick_sort_duration += quick_end_time - quick_start_time;

    // Show arrays after sorting
    if (ENABLE_PRINT) {
      std::cout << "ARRAY AFTER BUBBLESORT : ";
      print_sequence(array, array + ARRAY_SIZE);
      std::cout << "ARRAY AFTER QUICKSORT  : ";
      print_sequence(array_copy, array_copy + ARRAY_SIZE);
    }
  }
  bubble_sort_duration /= NUMBER_OF_TESTS;
  quick_sort_duration /= NUMBER_OF_TESTS;

  // Test results
  std::cout << "------------------------------------\n";
  std::cout << "Bubble Sort: " << bubble_sort_duration.count() << " seconds" << std::endl;
  std::cout << "Quick Sort: " << quick_sort_duration.count() << " seconds" << std::endl;
  double ratio = bubble_sort_duration / quick_sort_duration;
  std::cout << "Quick Sort is ";
  ratio >= 1 ? std::cout << ratio << " times faster\n" : std::cout << 1 / ratio << " times slower\n";
}

/************************************************* TASK 2 ***********************************************************/

// Task 2 - Sorting unsigned, double, and char arrays
void task_2() {
  std::cout << "------------------------------------\n";
  std::cout << "\n\t\tSort unsigned, double, and char arrays\n" << std::endl;
  // Unsigned Array
  const size_t UNSIGNED_ARRAY_SIZE{10};
  unsigned unsigned_array[UNSIGNED_ARRAY_SIZE]{1, 0, 300,  522, 6, 41, 0, 10, 155, 2222};
  std::cout << "unsigned array before sort: ";
  print_sequence(unsigned_array, unsigned_array + UNSIGNED_ARRAY_SIZE);
  bubble_sort(unsigned_array, unsigned_array + UNSIGNED_ARRAY_SIZE, [](unsigned *p1, unsigned *p2) { return *p1 > *p2; });
  std::cout << "unsigned array after sort : ";
  print_sequence(unsigned_array, unsigned_array + UNSIGNED_ARRAY_SIZE);
  std::cout << "------------------------------------\n";
  // Double Array
  const size_t DOUBLE_ARRAY_SIZE{5};
  double double_array[DOUBLE_ARRAY_SIZE]{-4.75, 5.11, 7.45, -4, 0};
  std::cout << "double array before sort: ";
  print_sequence(double_array, double_array + DOUBLE_ARRAY_SIZE);
  bubble_sort(double_array, double_array + DOUBLE_ARRAY_SIZE, [](double *p1, double *p2) { return *p1 > *p2; });
  std::cout << "double array after sort : ";
  print_sequence(double_array, double_array + DOUBLE_ARRAY_SIZE);
  std::cout << "------------------------------------\n";
  // Char Array
  const size_t CHAR_ARRAY_SIZE{1000};
  char char_array[CHAR_ARRAY_SIZE] = "zA1xB2yC3";
  std::cout << "char array before sort: ";
  print_sequence(char_array, char_array + CHAR_ARRAY_SIZE);
  bubble_sort(char_array, char_array + CHAR_ARRAY_SIZE, [](char *p1, char *p2) { return *p1 > *p2; });
  std::cout << "char array after sort : ";
  print_sequence(char_array, char_array + CHAR_ARRAY_SIZE);
}

/*********************************************** MENU *************************************************/

enum MENU { QUIT, TASK_1, TASK_2, SIZE };

int main() {
  while (true) {
    std::cout << "------------------------------------\n";
    std::cout << "               MENU                 \n";
    std::cout << TASK_1 << " - TASK 1\n";
    std::cout << TASK_2 << " - TASK 2\n";
    std::cout << QUIT   << " - QUIT  \n";
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
    std::function<void()> menu[static_cast<size_t>(MENU::SIZE)]{task_1, task_2};
    menu[selection - 1]();
  }
  return 1;
}