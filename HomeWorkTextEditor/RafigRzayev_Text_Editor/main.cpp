#include "text_editor.hpp"
#include <functional>

enum OPTIONS {
  QUIT,
  TYPE,
  DISPLAY,
  MOVE_LEFT,
  MOVE_RIGHT,
  SELECT,
  COPY,
  CUT,
  PASTE,
  DEFAULT
};

void menu() {
  std::cout << "--------------------\n";
  std::cout << TYPE << " - TYPE\n";
  std::cout << DISPLAY << " - DISPLAY\n";
  std::cout << MOVE_LEFT << " - MOVE LEFT\n";
  std::cout << MOVE_RIGHT << " - MOVE RIGHT\n";
  std::cout << SELECT << " - SELECT\n";
  std::cout << COPY << " - COPY\n";
  std::cout << CUT << " - CUT\n";
  std::cout << PASTE << " - PASTE\n";
  std::cout << QUIT << " - QUIT\n";
  std::cout << "Command: ";
}

std::function<void(TextEditor &)> user_commands[DEFAULT - 1]{
    type, display, move_left, move_right, select_, copy, cut, paste};

int main() {
  TextEditor Editor;
  while (true) {
    menu();
    size_t user_input;
    std::cin >> user_input;
    std::cout << "--------------------\n";
    clear_istream();
    if (user_input == QUIT) {
      std::cout << "Quitting\n";
      return 0;
    }
    if (user_input >= DEFAULT) {
      std::cout << "Unknown command\n";
      continue;
    }
    user_commands[user_input - 1](Editor);
  }
  return 0;
}