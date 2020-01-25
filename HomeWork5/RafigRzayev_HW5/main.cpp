#include "deck.hpp"
#include "stack.hpp"
#include <functional>

Stack_ CardStack;

enum Options { QUIT, PUSH, POP, TOP, CLEAR, END };

std::function<void()> user_commands[END]{
    []() { push(CardStack, get_random_card()); },
    []() { pop(CardStack); },
    []() { std::cout << top(CardStack) << std::endl; },
    []() { clear_stack(CardStack); },
    []() { std::cout << "Unknown command. Try again\n"; }};

void menu_text() {
  std::cout << "---------------------------------------------\n";
  std::cout << "\t\tCARD STACK\n";
  std::cout << PUSH << " - Push card\n";
  std::cout << POP << " - Pop card\n";
  std::cout << TOP << " - Top card\n";
  std::cout << CLEAR << " - Empty the deck\n";
  std::cout << QUIT << " - Quit\n";
  std::cout << "Enter selection: ";
}

int main() {

  while (true) {
    menu_text();
    int user_selection;
    std::cin >> user_selection;
    std::cout << "---------------------------------------------\n";
    if (user_selection == QUIT) {
      return 0;
    }
    if (user_selection > END) {
      user_selection = END;
    }
    user_commands[user_selection - 1]();
  }
}