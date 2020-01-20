#pragma once

#include <iostream>
#include <string>

class Queue {
public:
  void push(const std::string &);
  bool pop();
  bool is_empty() const; 
private:
  class Node {
  public:
    Node(const std::string &data, Node *prev = nullptr, Node *next = nullptr)
        : data_{data}, prev_{prev}, next_{next} {}
    std::string data_;
    Node *prev_;
    Node *next_;
  };
  Node *head{nullptr};
  Node *tail{nullptr};
  bool is_node_empty(const Node *) const;
  friend std::ostream &operator<<(std::ostream &, const Node &);
};