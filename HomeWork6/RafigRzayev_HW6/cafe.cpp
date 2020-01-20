#include "cafe.hpp"

void Order(Queue &Cafe) {
  std::cout << "Enter an order: ";
  std::string user_input;
  std::cin >> user_input;
  Cafe.push(user_input);
  std::cout << user_input << " order has been accepted\n";
  Logger::get_instance().add_logs("Order has been accepted\n");
}

void Cook(Queue &Cafe) {
  if (Cafe.pop()) {
    std::cout << "Order has been served to the customer\n";
    Logger::get_instance().add_logs("Order has been served\n");
  }
}

void Clear(Queue &Cafe) {
  if (Cafe.is_empty()) {
    std::cout << "Queue is already empty\n";
    return;
  }
  while (!Cafe.is_empty()) {
    Cafe.pop();
  }
  std::cout << "Queue has been cleared\n";
  Logger::get_instance().add_logs("All orders have been cancelled\n");
}