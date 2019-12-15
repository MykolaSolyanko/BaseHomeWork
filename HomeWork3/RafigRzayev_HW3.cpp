#include <iostream>
#include <cstdlib>
#include <ctime>

// Print array to console
void PrintArray(const int *array, const unsigned int ARRAY_SIZE) {
    // Exceptions
    if(array == nullptr) {
        std::cout << "PrintArray() - EXCEPTION: array == nullptr" << std::endl;
        return;
    }
    if (ARRAY_SIZE == 0) {
        std::cout << "PrintArray() - EXCEPTION: ARRAY_SIZE == 0" << std::endl;
        return;
    }
    // Print in the form "[a, b, c, ...]"
    const int *BEGIN{array};
    const int *const END{array + ARRAY_SIZE};
    std::cout << "[";
    while (BEGIN != END) {
        std::cout << *(BEGIN++);
        if(BEGIN < END) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

// Sort first N elements("entered_elements") of array("array") of size "ARRAY_SIZE"
void SortArray(int *array, const unsigned int ARRAY_SIZE, const unsigned int entered_elements) {
    // Skip sorting on fist input
    if (entered_elements < 2) {
        return;
    }
    // Exceptions
    if (entered_elements > ARRAY_SIZE) {
        std::cout << "SortArray() - EXCEPTION: entered elements > ARRAY_SIZE" << std::endl;
        return;
    }
    if (array == nullptr) {
        std::cout << "SortArray() - EXCEPTION: array == nullptr" << std::endl;
        return;
    }
    if (ARRAY_SIZE == 0) {
        std::cout << "SortArray() - EXCEPTION: ARRAY_SIZE == 0" << std::endl;
        return;
    }
    /*                                          ALGORITHM   
    1) Loop from BEGIN+0 to END. Find minimum. Put the minimum inside BEGIN+0. Put old value inside minimum's location.
    2) Loop from BEGIN+1 to END. Find minimum. Put the minimum inside BEGIN+1. Put old value inside minimum's location.
    ... */
    const int *const END{array + entered_elements};
    for (size_t i{0}; i < entered_elements; ++i) {
        int *BEGIN{array + i};
        int min{*BEGIN};
        unsigned int index{0}, min_index{0};
        while (BEGIN != END) {
            if (*BEGIN < min) {
                min = *BEGIN;
                min_index = index;
            }
            ++BEGIN;
            ++index;
        }
        int temp = *(array + i);
        *(array + i) = *(array + i + min_index);
        *(array + i + min_index) = temp;
    }
}

// For array[ARRAY_SIZE], fill it with random numbers between [LOW_LIMIT; HIGH_LIMIT]
void GenerateRandomArray(int* array, const unsigned int ARRAY_SIZE, const int LOW_LIMIT, const int HIGH_LIMIT) {
    int* BEGIN{array};
    const int* const END{array+ARRAY_SIZE};
    srand(time(0));
    while(BEGIN != END) {
        *(BEGIN++) = rand()%(HIGH_LIMIT-LOW_LIMIT+1) + LOW_LIMIT;
    }
}

// Returns how many times a number "num" is found in the array. Replace all found with a number "REPLACE_FOUND".
unsigned int Search(const int num, int* array, const unsigned int ARRAY_SIZE) {
    int* BEGIN {array};
    const int* const END{array+ARRAY_SIZE};
    const int REPLACE_FOUND{77};
    unsigned int found_count{0};
    while(BEGIN != END) {
        if((*BEGIN) == num){
            *BEGIN = REPLACE_FOUND;
            found_count++;
        }
        ++BEGIN;
    }
    std::cout << "Found: " << found_count << "\n";
    return found_count;
}

// Task 1
void ReverseInput()
{
    std::cout << "\n\t\t\tREVERSE THE INPUT\n\n";
    const unsigned int INPUT_LENGTH{200};
    char user_text[INPUT_LENGTH]{};
    std::cout << "Enter user text: ";
    std::cin >> user_text;
    int length{};
    while (user_text[length] != '\0')
    {
        ++length;
    }
    std::cout << "Reverse: ";
    while (length != -1)
    {
        std::cout << user_text[length];
        --length;
    }
    std::cout << std::endl;
}

// Task 2
void InsertSortPrint()
{
    std::cout << "\n\t\t\tADD NUMBERS TO ARRAY AND SORT THEM\n";
    const unsigned int ARRAY_SIZE{10};
    int numbers[ARRAY_SIZE]{};
    int *BEGIN{numbers};
    const int *const END{numbers + ARRAY_SIZE};
    unsigned int entered_elements{0};
    while (BEGIN != END) {
        std::cout << "\nEnter number: ";
        std::cin >> *(BEGIN++);
        SortArray(numbers, ARRAY_SIZE, ++entered_elements);
        PrintArray(numbers, ARRAY_SIZE);
    }
}

// Task 3
void SearchAndDelete() {
    std::cout << "\n\t\t\tSEARCH FOR NUMBERS INSIDE ARRAY\n\n";
    const unsigned int ARRAY_SIZE{10};
    std::cout << "Search for values in the generated array["<< ARRAY_SIZE <<"]\n";
    const int stop{77};
    std::cout << "Program will stop when all values are found or if you type " << stop << "\n";
    const int LOW_LIMIT{-10}, HIGH_LIMIT{30};
    int numbers[ARRAY_SIZE]{};
    GenerateRandomArray(numbers, ARRAY_SIZE, LOW_LIMIT, HIGH_LIMIT);
    std::cout << "Generated array: ";
    PrintArray(numbers, ARRAY_SIZE);
    unsigned int found{0};
    while(found != ARRAY_SIZE) {
        std::cout << "\nEnter a number between [" << LOW_LIMIT << "; " << HIGH_LIMIT<< "]: ";
        int user_number{};
        std::cin >> user_number;
        while(  (user_number < LOW_LIMIT || user_number > HIGH_LIMIT) && user_number != stop ) {
            std::cout << "Input out of bounds. Try again\n";
            std::cout << "Enter a number between [" << LOW_LIMIT << "; " << HIGH_LIMIT<< "]: ";
            std::cin >> user_number;
        }
        if(user_number == stop) {
            std::cout << "\nExiting SearchAndDelete()\n";
            return;
        }
        found += Search(user_number, numbers, ARRAY_SIZE);
        PrintArray(numbers, ARRAY_SIZE);
    }
    std::cout << "\nFinished\n";
}

// Task 4
void Lowercase() {
    std::cout << "\n\t\t\tMAKE INPUT LOWERCASE\n\n";
    const unsigned int INPUT_LENGTH{200};
    char user_text[INPUT_LENGTH]{};
    std::cout << "Enter user text: ";
    std::cin >> user_text;
    unsigned int length{};
    while (user_text[length] != '\0')
    {
        ++length;
    }
    char* BEGIN{user_text};
    const char* const END{user_text + length};
    while(BEGIN != END) {
        if(*BEGIN >= 'A' && *BEGIN <= 'Z') {
            *BEGIN += 32;
        }
        std::cout << *BEGIN++;
    }
    std::cout << std::endl;
}

// Task 5
void Uppercase() {
    std::cout << "\n\t\t\tMAKE INPUT UPPERCASE\n\n";
    const unsigned int INPUT_LENGTH{200};
    char user_text[INPUT_LENGTH]{};
    std::cout << "Enter user text: ";
    std::cin >> user_text;
    unsigned int length{};
    while (user_text[length] != '\0')
    {
        ++length;
    }
    char* BEGIN{user_text};
    const char* const END{user_text + length};
    while(BEGIN != END) {
        if(*BEGIN >= 'a' && *BEGIN <= 'z') {
            *BEGIN -= 32;
        }
        std::cout << *BEGIN++;
    }
    std::cout << std::endl;
}

// Task 6
void FindDigits() {
    std::cout << "\n\t\t\tFIND DIGITS IN THE INPUT\n\n";
    const unsigned int INPUT_LENGTH{200};
    char user_text[INPUT_LENGTH]{};
    std::cout << "Enter user text: ";
    std::cin >> user_text;
    unsigned int length{};
    while (user_text[length] != '\0')
    {
        ++length;
    }
    char* BEGIN{user_text};
    const char* const END{user_text + length};
    std::cout << "Digits: ";
    while(BEGIN != END) {
        if(*BEGIN >= '0' && *BEGIN <= '9') {
            std::cout << *BEGIN << " ";
        }
        ++BEGIN;
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
  std::cout << REVERSE_INPUT     << " - REVERSE THE INPUT                    \n";
  std::cout << INSERT_SORT_PRINT << " - ADD NUMBERS TO ARRAY AND SORT THEM   \n";
  std::cout << SEARCH_AND_DELETE << " - SEARCH FOR NUMBERS INSIDE ARRAY      \n";
  std::cout << LOWERCASE         << " - MAKE INPUT LOWERCASE                 \n";
  std::cout << UPPERCASE         << " - MAKE INPUT UPPERCASE                 \n";
  std::cout << FIND_DIGITS       << " - FIND DIGITS IN THE INPUT             \n";
  std::cout << QUIT              << " - QUIT                                 \n";
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