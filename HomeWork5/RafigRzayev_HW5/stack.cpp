#include "stack.hpp"

// Check if stack is empty
bool is_empty(const Stack_ &S_) {
  return S_.top_index_ == 0 && S_.data_[0].empty();
}

// Check if stack is full
bool is_full(const Stack_ &S_) { return S_.top_index_ == S_.STACK_SIZE_; }

// Get top element of the stack
const std::string &top(const Stack_ &S_) {
  return S_.data_[S_.top_index_ == 0 ? S_.top_index_ : S_.top_index_ - 1];
}

// Push element into stack
void push(Stack_ &s_, const std::string &DATA) {
  if (is_full(s_)) {
    std::cout << "Can't push. Stack full\n";
    return;
  }
  s_.data_[s_.top_index_++] = DATA;
  std::cout << "Pushed succesfully\n";
}

// Pop element from the stack
void pop(Stack_ &s_) {
  if (is_empty(s_)) {
    std::cout << "Can't pop. Bottom of stack\n";
    return;
  }
  if (s_.top_index_-- == 1) {
    s_.data_[s_.top_index_] = "";
  }
  std::cout << "Popped successfully\n";
}

// Clear the stack
void clear_stack(Stack_ &s_) {
  s_.top_index_ = 0;
  s_.data_[s_.top_index_] = "";
  std::cout << "Stack has been flushed\n";
}

