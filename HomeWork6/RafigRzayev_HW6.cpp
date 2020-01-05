#include <iostream>

// get length of a string literal
size_t get_length(const char *text) {
  if (text == nullptr) {
    std::cout << "Exception\n";
    return 0;
  }
  size_t text_length{0};
  while (*text != '\0') {
    ++text_length;
    ++text;
  }
  return text_length;
}

// copy text
void copy_text(const char *src_text, char *dst_text) {
  if (src_text == nullptr || dst_text == nullptr) {
    std::cout << "Exception\n";
    return;
  }
  while (*src_text != '\0') {
    *dst_text++ = *src_text++;
  }
  *dst_text = '\0';
}

/**************************************** NODE FOR RESTAURANT ORDER ********************************************/

// Node for restaurant order
class Order {
public:
  // User-defined Constructor
  Order(const char ORDERED_FOOD[]) : next{nullptr} { set_food(ORDERED_FOOD); }
  // Destructor
  ~Order() { delete[] food; }
  // Get next order
  Order *get_next() const { return next; }
  // Get name of ordered food
  char *get_food() const { return food; };
  // Set next order
  void set_next(Order *NEXT_ORDER) { next = NEXT_ORDER; }
  // Set name of ordered food
  void set_food(const char[]);
  // Print the name of ordered food
  void print() const;

private:
  char *food = nullptr;
  Order *next = nullptr;
};

// Set name of ordered food
void Order::set_food(const char FOOD_NAME[]) {
  delete[] food;
  food = new char[get_length(FOOD_NAME)];
  copy_text(FOOD_NAME, food);
}

// Print the name of ordered food
void Order::print() const {
  std::cout << get_food();
  if (get_next() != nullptr) {
    std::cout << " -> ";
  }
}

/********************************* LINKED-LIST QUEUE FOR RESTAURANT ORDERS *************************************/

// Queue of restaurant orders
class Orders {
public:
  // shows current food orders in the queue
  void print_queue() const;
  // adds food order into the queue
  bool enqueue();
  // cook the order from the queue
  bool dequeue();
  bool update_order_by_index();
  bool cancel_order_by_index();
  bool cancel_all_orders();

private:
  size_t get_order_count() const;
  Order *search_previous_order(const Order *) const;
  Order *search_order_by_index(const size_t) const;
  size_t ask_index_from_user();
  bool delete_order(Order *);

  const size_t MAX_ORDERS = 5;
  Order *head = nullptr;
};

// Shows current food orders in the queue
void Orders::print_queue() const {
  std::cout << "--------------------------\n";
  const size_t COUNT{get_order_count()};
  if (COUNT == 0) {
    std::cout << "No orders pending\n";
    return;
  }
  std::cout << "Number of orders: " << COUNT << std::endl;
  Order *it{head};
  while (it != nullptr) {
    it->print();
    it = it->get_next();
  }
  std::cout << std::endl;
}

// Adds food order into the queue
bool Orders::enqueue() {
  std::cout << "--------------------------\n";
  if (get_order_count() == MAX_ORDERS) {
    std::cout << "Can't order. Queue is full\n";
    return false;
  }
  const size_t SIZE{100};
  char ordered_food[SIZE];
  std::cout << "Enter food name: ";
  std::cin >> ordered_food;
  std::cout << ordered_food << " order has been added to the queue\n";
  if (head == nullptr) {
    head = new Order{ordered_food};
    return true;
  }
  Order *tail = search_order_by_index(get_order_count());
  Order *new_tail = new Order{ordered_food};
  tail->set_next(new_tail);
  return true;
}

// Cook the order from the queue
bool Orders::dequeue() {
  std::cout << "--------------------------\n";
  if (delete_order(head)) {
    std::cout << "Order has been prepared\n";
    return true;
  } else {
    std::cout << "Nothing to be cooked\n";
    return false;
  }
}

// Update an order at user provided index
bool Orders::update_order_by_index() {
  const size_t INDEX = ask_index_from_user();
  if (INDEX == 0) {
    return false;
  }
  Order *order_to_update = search_order_by_index(INDEX);
  if (order_to_update == nullptr) {
    return false;
  }
  const size_t SIZE{100};
  char updated_food[SIZE];
  std::cout << "Enter food name: ";
  std::cin >> updated_food;
  order_to_update->set_food(updated_food);
  std::cout << "Order has been updated successfully\n";
  return true;
}

// Cancel an order at user provided index
bool Orders::cancel_order_by_index() {
  const size_t INDEX = ask_index_from_user();
  if (INDEX == 0) {
    return false;
  }
  Order *order_to_delete = search_order_by_index(INDEX);
  if (order_to_delete == nullptr) {
    return false;
  }
  if (delete_order(order_to_delete)) {
    std::cout << "Order has been cancelled successfully\n";
    return true;
  }
  return false;
}

// Cancel all orders in the queue
bool Orders::cancel_all_orders() {
  std::cout << "--------------------------\n";
  size_t count = get_order_count();
  if (count == 0) {
    std::cout << "Queue is empty. Can't process\n";
    return false;
  }
  while (count != 0) {
    delete_order(head);
    --count;
  }
  std::cout << "All orders has been cancelled\n";
  return true;
}

// Calculate current number of orders in the queue
size_t Orders::get_order_count() const {
  Order *it = head;
  if (it == nullptr) {
    return 0;
  }
  size_t count{};
  while (it != nullptr) {
    it = it->get_next();
    ++count;
  }
  return count;
}

// Find a previous order
Order *Orders::search_previous_order(const Order *order) const {
  if (order == head) {
    return head;
  }
  Order *previous = head;
  while (previous->get_next() != order) {
    previous = previous->get_next();
  }
  return previous;
}

// Find an order by its index(count)
Order *Orders::search_order_by_index(const size_t INDEX) const {
  if (INDEX == 0 || INDEX > get_order_count()) {
    std::cout << "Invalid order number. Try again\n";
    return nullptr;
  }
  Order *it = head;
  for (size_t i{INDEX}; i != 1; --i) {
    it = it->get_next();
  }
  return it;
}

// Ask for user to enter an index in the queue. Return 0 on exceptions
size_t Orders::ask_index_from_user() {
  std::cout << "--------------------------\n";
  const size_t COUNT = get_order_count();
  if (COUNT == 0) {
    std::cout << "Queue is empty. Can't process\n";
    return 0;
  }
  std::cout << "Enter an index: ";
  size_t index;
  std::cin >> index;
  if (index > COUNT || index == 0) {
    std::cout << "Invalid order number. Try again\n";
    return 0;
  }
  return index;
}

// Delete an order
bool Orders::delete_order(Order *order) {
  if (get_order_count() == 0) {
    std::cout << "Queue is empty\n";
    return false;
  }
  if (order == nullptr) {
    std::cout << "Passed order is empty. Can't process\n";
    return false;
  }
  if (order != head) {
    Order *previous = search_previous_order(order);
    previous->set_next(order->get_next());
  } else {
    head = order->get_next();
  }
  delete order;
  return true;
}

/********************************************* SINGLETON LOGGER ************************************************/

const size_t LOG_SIZE = 10000;

// Singleton simple logger to track restaurant activities
class Logger {
public:
  void add_log(const char[]);
  void read_log() const { std::cout << logs << std::endl; }
  static Logger *get_instance() {
    if (instance == nullptr) {
      instance = new Logger;
    }
    return instance;
  }
private:
  static Logger *instance;
  Logger() {};
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
  char logs[LOG_SIZE] = "\n\tACTIVITY LOGS";
};

Logger *Logger::instance = nullptr;

void Logger::add_log(const char TEXT[]) {
  const size_t CURRENT_INDEX = get_length(logs);
  size_t text_length = get_length(TEXT);
  if (CURRENT_INDEX + text_length + 2 > LOG_SIZE) {
    std::cout << "Unable to add log. Logbook is full\n";
    return;
  }
  // add newline before new message is entered into the logbook
  logs[CURRENT_INDEX] = '\n';
  // add null-terminator to the end of logbook
  logs[CURRENT_INDEX + text_length + 1] = '\0';
  // copy the text intto the log
  for (size_t i{0}; text_length != 0; ++i) {
    logs[CURRENT_INDEX + i + 1] = TEXT[i];
    --text_length;
  }
}

/************************************************** MAIN ******************************************************/

enum Menu {
  QUIT,
  ORDER,
  COOK,
  SHOW,
  UPDATE,
  CANCEL_BY_INDEX,
  CANCEL_ALL,
  READ_LOG
};

void show_menu() {
  std::cout << "--------------------------\n";
  std::cout << "\tOPTIONS\n";
  std::cout << ORDER << " - ACCEPT A NEW FOOD ORDER\n";
  std::cout << COOK << " - COOK THE ORDERED FOOD\n";
  std::cout << SHOW << " - SHOW ALL ORDERS IN THE QUEUE\n";
  std::cout << UPDATE << " - UPDATE ORDER BY INDEX\n";
  std::cout << CANCEL_BY_INDEX << " - CANCEL ORDER BY INDEX\n";
  std::cout << CANCEL_ALL << " - CANCEL ALL ORDERS\n";
  std::cout << READ_LOG << " - CHECK ACTIVITY LOGS\n";
  std::cout << QUIT << " - QUIT\n";
  std::cout << "Enter selection: ";
}

int main() {
  Orders PizzaQueue;
  while (true) {
    show_menu();
    int user_selection{};
    std::cin >> user_selection;
    std::cin.clear();
    std::cin.ignore();
    switch (user_selection) {
    case QUIT:
      std::cout << "--------------------------\n";
      std::cout << "Quitting\n";
      return 0;
    case ORDER:

      if (PizzaQueue.enqueue()) {
        Logger *Logger_of_Programmer_A = Logger::get_instance();
        Logger_of_Programmer_A->add_log("An order has been accepted");
      }
      continue;
    case COOK:
      if (PizzaQueue.dequeue()) {
        Logger *Logger_of_Programmer_B = Logger::get_instance();
        Logger_of_Programmer_B->add_log("An order was served to the customer");
      }
      continue;
    case SHOW:
      PizzaQueue.print_queue();
      continue;
    case UPDATE:
      if (PizzaQueue.update_order_by_index()) {
        Logger *Logger_of_Programmer_C = Logger::get_instance();
        Logger_of_Programmer_C->add_log("An order was updated succesffully");
      }
      continue;
    case CANCEL_BY_INDEX:
      if (PizzaQueue.cancel_order_by_index()) {
        Logger *Logger_of_Programmer_D = Logger::get_instance();
        Logger_of_Programmer_D->add_log("An order was cancelled");
      }
      continue;
    case CANCEL_ALL:
      if (PizzaQueue.cancel_all_orders()) {
        Logger *Logger_of_Programmer_E = Logger::get_instance();
        Logger_of_Programmer_E->add_log("All orders were cancelled");
      }
      continue;
    case READ_LOG: {
      Logger *Logger_of_Programmer_B = Logger::get_instance();
      Logger_of_Programmer_B->read_log();
      continue;
    }

    default:
      std::cout << "--------------------------\n";
      std::cout << "Unknown command. Try again\n";
      continue;
    }
  }
  return 1;
}