#include "queue.hpp"

// Push node
void Queue::push(const std::string &DATA) {
  if (is_empty()) {
    head = tail = new Node{DATA};
    return;
  }
  Node *new_tail = new Node(DATA, nullptr, tail);
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

// Check if queue is empty
bool Queue::is_empty() const { return is_node_empty(tail); }

// Check if node is empty
bool Queue::is_node_empty(const Node *node) const { return node == nullptr; }

// Print node
std::ostream &operator<<(std::ostream &os, const Queue::Node &node) {
  os << node.data_;
  if (node.next_ != nullptr) {
    os << " -> ";
  }
  return os;
}