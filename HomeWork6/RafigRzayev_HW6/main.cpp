#include <functional>
#include "logger.hpp"
#include "queue.hpp"
#include "cafe.hpp"

enum Menu { QUIT, ORDER, COOK, CLEAR, READ_LOGS, DEFAULT };

void show_menu() {
  std::cout << "--------------------------\n";
  std::cout << "\tOPTIONS\n";
  std::cout << ORDER << " - ACCEPT A NEW FOOD ORDER\n";
  std::cout << COOK << " - COOK THE ORDERED FOOD\n";
  std::cout << CLEAR << " - CLEAR THE QUEUE\n";
  std::cout << READ_LOGS << " - READ ACTIVITY LOGS\n";
  std::cout << QUIT << " - QUIT\n";
  std::cout << "Enter selection: ";
}

std::function<void(Queue &)> user_commands[DEFAULT - 2]{Order, Cook, Clear};

int main() {
  Queue Cafe;
  while (true) {
    show_menu();
    size_t user_input;
    std::cin >> user_input;
    std::cout << "--------------------------\n";
    if (user_input == QUIT) {
      std::cout << "Quitting\n";
      return 0;
    }
    if (user_input == READ_LOGS) {
      Logger::get_instance().read_logs();
      continue;
    }
    if (user_input >= DEFAULT) {
      std::cout << "Unknow command. Try again\n";
      continue;
    }
    user_commands[user_input - 1](Cafe);
  }
  return 0;
}