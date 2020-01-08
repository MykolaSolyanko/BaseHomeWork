/**
 * Home Work #5. ITEA C++ Basic Courses.
 *
 * This program implements basic data structures - stack, queue and linked list
 *
 * Author:  Andrii Samozvon
 * Date:    08 Jan 2020
 */
// g++ -Wall -Werror -std=c++17 AndriiSamozvon_HomeWork5_data_structure.cpp -o AndriiSamozvon_HomeWork5_data_structure

#include <iostream>

class Stack {
  private:
    int *array = nullptr;
    int pos = -1;
    const int kStackSize;

    static const int kMaxStackSize = 1000;
    static constexpr char errorNotAllocated[] = "Error! Stack is not allocated";
    static constexpr char errorStackFull[] = "Stack is full";
    static constexpr char msgStackIsEmpty[] = "Stack is empty";

    static void printMsg(const char *msg) {
      std::cout << std::endl << msg << std::endl;
    }

  public:
    Stack() = delete;
    
    Stack(int size) : kStackSize(size) {
      if (size > kMaxStackSize) {   // Preventing allocating very large data volumes on heap
        printMsg(errorNotAllocated);
      } else {
        if (kStackSize > 0) {
          array = new int[kStackSize]{};
        }
        if (array == nullptr) {     // In case if something goes wrong - inform the user
          printMsg(errorNotAllocated);
        }
      }
    }
    
    ~Stack() {
      if (array != nullptr) {
        delete[] array;
      }
    }

    bool push(int num) {
      if (array == nullptr) {
        printMsg(errorNotAllocated);
        return false;
      }
      if (pos == kStackSize) {
        printMsg(errorStackFull);
        return false;
      }
      array[++pos] = num;
      return true;
    }
    
    bool pop() {
      if (array == nullptr) {
        printMsg(errorNotAllocated);
        return false;
      }
      if (pos == -1) {
        printMsg(msgStackIsEmpty);
        return false;
      }
      pos--;
      return true;
    }

    int top() const {
      if (array == nullptr) {
        printMsg(errorNotAllocated);
        return 0;
      }
      if (pos == -1) {
        printMsg(msgStackIsEmpty);
        return 0;
      }
      return array[pos];
    }

    /**
     * If stack is empty - returns (-1)
     */
    int length() const {
      return pos;
    }

    int getStackSize() const {
      return kStackSize;
    }

    static int getMaxStackSize() {
      return kMaxStackSize;
    }
};

class Queue {
  private:
    
  public:
    Queue ();
    ~Queue ();
};

class LinkedList {
  private:

  public:
    LinkedList();
    ~LinkedList();
};

LinkedList::LinkedList(/* args */)
{
}

LinkedList::~LinkedList()
{
}


int main() {
  const int num = 10;

  /**
   * 1. Stack
   */
  Stack stack(10);

  // Fill the stack
  for (int i=0; i<= num+1; i++) {
    std::cout << "Before pushing: length = " << stack.length()
              << " top = " << stack.top() << " | ";
    stack.push(i);
    std::cout << "After pushing: length = " << stack.length()
              << " top = " << stack.top() << std::endl;
  }
  std::cout << std::endl;

  // Empty the stack
  for (int i=0; i<= num; i++) {
    std::cout << "Before poping: length = " << stack.length()
              << " top = " << stack.top() << " | ";
    stack.pop();
    std::cout << "After poping: length = " << stack.length()
              << " top = " << stack.top() << std::endl;
  }
  // Try to allocate large stack
  Stack largeStack(Stack::getMaxStackSize() + 1);

  /**
   * 2. Queue
   */


  return 0;
}
