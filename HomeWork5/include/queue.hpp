#pragma once
#include "container.hpp"

template <typename T>
class Queue : public Container<T> {
  using Container<T>::containerLength;
  using Container<T>::array;
  using Container<T>::toPrintMessages; 
  
  public:
    Queue() = delete;
    Queue(size_t size_) : Container<T>(size_) {};

    T front() {
      if (index < 0) {
        Container<T>::printMsg(Container<T>::msgIsEmpty, toPrintMessages);
        return 0;
      }
      return array[index];
    }

    T back() {
      if (index < 0) {
        Container<T>::printMsg(Container<T>::msgIsEmpty, toPrintMessages);
        return 0;
      }
      return array[0];
    }

    void push(T item) {
      if (index >= Container<T>::kMaxLength) {
        Container<T>::printMsg(Container<T>::msgErrorIsFull, toPrintMessages);
        return;
      }
      int iterator = index;
      while (iterator >= 0) {
        array[iterator+1] = array[iterator];
        --iterator;
      }
      array[0] = item;
      ++index;
    }

    void pop() {
      if (index < 0) {
        Container<T>::printMsg(Container<T>::msgIsEmpty, toPrintMessages);
        return;
      }
      --index;
    }

    int length() const {
      if (index < 0) {
        Container<T>::printMsg(Container<T>::msgIsEmpty, toPrintMessages);
      }
      return (index + 1);
    }

    int size() const override {
      return containerLength;
    }
    
    bool empty() const override {
      return (index == -1);
    }
    
  private:
    int index = -1;
};
