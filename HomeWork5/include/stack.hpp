#ifndef STACK_H_
#define STACK_H_

#include "container.hpp"

template <typename T>
class Stack : public Container<T> {
  using Container<T>::containerLength;
  using Container<T>::array;
  using Container<T>::toPrintMessages; 
  
  public:
    Stack() = delete;
    Stack(size_t size_) : Container<T>(size_) {};
    
    void push(int value) {
      if (containerLength == Container<T>::kMaxLength) {
        Container<T>::printMsg(Container<T>::msgErrorIsFull, toPrintMessages);
        return;
      }
      array[++index] = value;
    }

    int top() const {
      if (array == nullptr) {
        Container<T>::printMsg(Container<T>::msgErrorNotAllocated, toPrintMessages);
        return 0;
      }
      if (index < 0) {
        Container<T>::printMsg(Container<T>::msgIsEmpty, toPrintMessages);
        return 0;
      }
      return array[index];
    }

    void pop() {
      if (array == nullptr) {
        Container<T>::printMsg(Container<T>::msgErrorNotAllocated, toPrintMessages);
        return;
      }
      if (index < 0) {
        Container<T>::printMsg(Container<T>::msgIsEmpty, toPrintMessages);
        return;
      }
      --index;
    }

    int getPosition() const {
      if (index == -1) {
        Container<T>::printMsg(Container<T>::msgIsEmpty, toPrintMessages);
        return 0;
      }
      return index;
    }
    int length() const {
      if (index < 0) {
        Container<T>::printMsg(Container<T>::msgIsEmpty, toPrintMessages);
      }
      return (index+1);
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

#endif // STACK_H_
