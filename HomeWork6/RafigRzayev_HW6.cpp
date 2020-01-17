#include <functional>
#include <iostream>
#include <string>

// Node class
class Node {
public:
  friend class Queue;
  friend std::ostream &operator<<(std::ostream &, const Node &);
  Node(const std::string &data, Node *prev = nullptr, Node *next = nullptr)
      : data_{data}, prev_{prev}, next_{next} {}

private:
  std::string data_;
  Node *prev_;
  Node *next_;
};

// Print node
std::ostream &operator<<(std::ostream &os, const Node &node) {
  os << node.data_;
  if (node.next_ != nullptr) { os << " -> "; }
  return os;
}

// Queue class
class Queue {
public:
  void push(const Node &);
  bool pop();
  Node *search(const std::string &) const;
  bool update(Node *, const std::string &);
  bool cancel(Node *);
  void cancel_all() { while(pop()); }
  bool is_empty() const { return is_node_empty(tail); }

private:
  Node *head{nullptr};
  Node *tail{nullptr};
  bool is_node_empty(const Node *node) const { return node == nullptr; }
  
};

// Push node
void Queue::push(const Node &node) {
  if (is_empty()) {
    head = tail = new Node{node.data_};
    return;
  }
  Node *new_tail = new Node(node.data_, nullptr, tail);
  tail->prev_ = new_tail;
  tail = new_tail;
}

// Pop node
bool Queue::pop() {
  if (is_empty()) {
    std::cout << "Queue is already empty\n";
    return false;
  }
  Node *new_head = head->prev_;
  delete head;
  if (is_node_empty(new_head)) {
    tail = head = nullptr;
    return true;
  }
  new_head->next_ = nullptr;
  head = new_head;
  return true;
}

// Search queue for specific data
Node *Queue::search(const std::string &DATA) const {
  Node *it = tail;
  while (!is_node_empty(it)) {
    if (it->data_ == DATA) {
      return it;
    }
    it = it->next_;
  }
  return it;
}

// Update a node
bool Queue::update(Node *node, const std::string &new_data) {
  if (is_node_empty(node)) {
    std::cout << "Invalid input\n";
    return false;
  }
  node->data_ = new_data;
  return true;
}

// Cancel a node
bool Queue::cancel(Node *node) {
  if (is_node_empty(node)) {
    std::cout << "Invalid input\n";
    return false;
  }
  Node *prev = node->prev_;
  Node *next = node->next_;
  delete node;
  if (is_node_empty(prev)) {
    tail = next;
  } else {
    prev->next_ = next;
  }
  if (is_node_empty(next)) {
    head = prev;
  } else {
    next->prev_ = prev;
  }
  return true;
}


/********************************************* SINGLETON LOGGER ************************************************/

class Logger {
public:
  void add_logs(const std::string &log) { logs += log; }
  void read_logs() { std::cout << logs << std::endl; }
  static Logger& get_instance() {
    static Logger instance;
    return instance;
  }

private:
  Logger() = default;
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
  std::string logs{"\tActivity Logs\n"};
};

/************************************************** MAIN ******************************************************/

enum Menu {
  QUIT,
  ORDER,
  COOK,
  UPDATE,
  CANCEL,
  CANCEL_ALL,
  READ_LOGS,
  DEFAULT
};

void show_menu() {
  std::cout << "--------------------------\n";
  std::cout << "\tOPTIONS\n";
  std::cout << ORDER << " - ACCEPT A NEW FOOD ORDER\n";
  std::cout << COOK << " - COOK THE ORDERED FOOD\n";
  std::cout << UPDATE << " - UPDATE AN ORDER\n";
  std::cout << CANCEL << " - CANCEL AN ORDER\n";
  std::cout << CANCEL_ALL << " - CANCEL ALL ORDERS\n";
  std::cout << READ_LOGS << " - READ ACTIVITY LOGS\n";
  std::cout << QUIT << " - QUIT\n";
  std::cout << "Enter selection: ";
}

void Order(Queue &Cafe) {
  std::cout << "Enter an order: ";
  std::string user_input;
  std::cin >> user_input;
  Cafe.push(Node{user_input});
  std::cout << user_input << " order has been accepted\n";
  Logger::get_instance().add_logs("Order has been accepted\n");
}

void Cook(Queue &Cafe) {
  if (Cafe.pop()) {
    std::cout << "Order has been served to the customer\n";
    Logger::get_instance().add_logs("Order has been served\n");
  }
}

void Update(Queue &Cafe) {
  std::cout << "Enter order to update: ";
  std::string user_input;
  std::cin >> user_input;
  Node *location = Cafe.search(user_input);
  if (location == nullptr) {
    std::cout << "There is no order like this\n";
    return;
  }
  std::cout << "Enter updated order: ";
  std::cin >> user_input;
  if (Cafe.update(location, user_input)) {
    std::cout << "Order has been updated succesfully\n";
    Logger::get_instance().add_logs("Order has been updated\n");
  }
}

void Cancel(Queue &Cafe) {
  std::cout << "Enter order to cancel: ";
  std::string user_input;
  std::cin >> user_input;
  Node *location = Cafe.search(user_input);
  if (location == nullptr) {
    std::cout << "There is no order like this\n";
    return;
  }
  if (Cafe.cancel(location)) {
    std::cout << "Order has been cancelled succesfully\n";
    Logger::get_instance().add_logs("Order has been cancelled\n");
  }
}

void Cancel_All(Queue &Cafe) {
  Cafe.cancel_all();
  std::cout << "All orders have been cancelled\n";
  Logger::get_instance().add_logs("All orders have been cancelled\n");
}

std::function<void(Queue &)> user_commands[DEFAULT - 2]{
    Order, Cook, Update, Cancel, Cancel_All
};

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