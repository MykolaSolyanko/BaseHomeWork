#pragma once

#include <iostream>
#include <string>

struct Stack_ {
  static const size_t STACK_SIZE_{10};
  size_t top_index_{0};
  std::string data_[STACK_SIZE_];
};

// Check if stack is empty
bool is_empty(const Stack_ &S_);
// Check if stack is full
bool is_full(const Stack_ &S_);
// Get top element of the stack
const std::string &top(const Stack_ &S_);
// Push element into stack
void push(Stack_ &s_, const std::string &DATA);
// Pop element from the stack
void pop(Stack_ &s_);
// Clear the stack
void clear_stack(Stack_ &s_);
