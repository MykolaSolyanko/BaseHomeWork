#include <functional>
#include <iostream>
#include <random>
#include <string>

// prototypes - for better code flow in the first part
std::string *generate_deck();

/*************************** Generate 52 Cards Deck - Not related to stack data structure **********************/

const size_t DECK_SIZE = 52;
const std::string *DECK = generate_deck();

// generate 52 cards deck on a heap
std::string *generate_deck() {
  // Card values: 2 -> Ace
  const size_t VALUE_COUNT{13};
  std::string values[VALUE_COUNT]{"2", "3",  "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  // Card symbols: Spade, Heart, Diamond, Club
  const size_t SYMBOL_COUNT{4};
  std::string symbols[SYMBOL_COUNT]{"\u2660", "\u2665", "\u2666", "\u2663"};
  // Allocate memory for 52 card deck
  std::string *deck = new std::string[DECK_SIZE];
  // Fill deck
  for (size_t i{0}; i < SYMBOL_COUNT; ++i) {
    for (size_t j{0}; j < VALUE_COUNT; ++j) {
      deck[i * VALUE_COUNT + j] = values[j] + symbols[i];
    }
  }
  return deck;
}

// returns a random card from deck
std::string get_random_card() {
  std::random_device seed;
  std::default_random_engine rng(seed());
  std::uniform_int_distribution<int> distr(0, DECK_SIZE - 1);
  return DECK[distr(rng)]; 
}

/******************************************* CARD STACK DATA STRUCTURE *****************************************/

// INTERNAL DATA

const size_t STACK_SIZE{10};
size_t top_index{0};
std::string Cards[STACK_SIZE]{};
bool empty(std::string s) { return s == ""; }

// FUNCTIONS FOR EXTERNAL USE

bool is_empty() { return top_index == 0 && empty(Cards[0]); }

bool is_full() { return top_index == STACK_SIZE; }

std::string &top() { return (top_index == 0 ? Cards[top_index] : Cards[top_index - 1]); }

void push() {
  if (is_full()) {
    std::cout << "Can't push. Stack full\n";
    return;
  }
  Cards[top_index++] = get_random_card();
}

void pop() {
  if (is_empty()) {
    std::cout << "Can't pop. Bottom of stack\n";
    return;
  }
  if (top_index-- == 1) {
    Cards[0] = "";
  }
}

void print_stack() {
  if (is_empty()) {
    std::cout << "No cards in the stack\n";
    return;
  }
  std::cout << "Cards:\n";
  for (size_t i{0}; i < top_index; ++i) {
    std::cout << i + 1 << " : " << Cards[i] << std::endl;
  }
}

/***************************************************** MAIN ****************************************************/

void update_top() {
  if (is_empty()) {
    std::cout << "Nothing to update\n";
    return;
  }
  top() = get_random_card();
}

void clear_stack() {
  top_index = 0;
  Cards[top_index] = "";
  std::cout << "Stack has been flushed\n";
}

void fill_stack() {
  if (is_full()) {
    std::cout << "Stack already full\n";
    return;
  }
  while (!is_full()) {
    push();
  }
  std::cout << "Stack has been filled\n";
}

enum Options {
  QUIT,
  POP,
  PUSH,
  SHOW_TOP,
  PRINT_STACK,
  UPDATE_TOP,
  CLEAR_STACK,
  FILL_STACK,
  END
};

std::function<void()> user_commands[END]{
    pop,
    push,
    []() { std::cout << top() << std::endl; },
    print_stack,
    update_top,
    clear_stack,
    fill_stack,
    []() { std::cout << "Unknown command. Try again\n"; }};

void menu_text() {
  std::cout << "---------------------------------------------\n";
  std::cout << "\t\tCARD STACK\n";
  std::cout << POP << " - Pop\n";
  std::cout << PUSH << " - Push\n";
  std::cout << SHOW_TOP << " - Show top card\n";
  std::cout << PRINT_STACK << " - Print the stack\n";
  std::cout << UPDATE_TOP << " - Update top with new card\n";
  std::cout << CLEAR_STACK << " - Clear the stack\n";
  std::cout << FILL_STACK << " - Fill the stack\n";
  std::cout << QUIT << " - Quit\n";
  std::cout << "Enter selection: ";
}

int main() {
  while (true) {
    menu_text();
    int user_selection;
    std::cin >> user_selection;
    if (user_selection == QUIT) {
      return 0;
    }
    if (user_selection > END) {
      user_selection = END;
    }
    user_commands[user_selection - 1]();
  }
  delete [] DECK;
}