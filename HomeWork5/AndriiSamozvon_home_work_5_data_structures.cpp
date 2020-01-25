#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
#include "linked_list.hpp"


int main() {
  // 1. Stack test
  Stack<size_t> stack(10);
  std::cout << "Stack size: "   << stack.size() << std::endl;
  std::cout << "Is skack empty: " << std::boolalpha << stack.empty() << std::endl;
  stack.push(123);
  std::cout << "Element pushed."  << std::endl;
  std::cout << "Is stack empty: " << std::boolalpha << stack.empty() << std::endl;
  std::cout << "Stack position: " << stack.getPosition() << std::endl;
  std::cout << "Stack length: "   << stack.length() << std::endl;
  std::cout << "Top element: "    << stack.top() << std::endl;
  std::cout << "Popping stack"    << std::endl;
  stack.pop();
  std::cout << "Stack poped. Top element: " << stack.top() << std::endl;
  std::cout << "Is stack empty: " << std::boolalpha << stack.empty() << std::endl;
  std::cout << "Stack position: " << stack.getPosition() << std::endl;
  std::cout << "Try to allocate large stack" << std::endl;
  Stack<int> large_stack(Container<int>::getMaxLength() + 1);
  std::cout << std::endl << std::endl;
  
  // 2. Queue test
  Queue<int> queue(10);
  queue.isMessagesPrinted(false);   // Switch off messages

  std::cout << "Queue size: "     << queue.size() << std::endl;
  std::cout << "Is queue empty: " << std::boolalpha << queue.empty() << std::endl;
  queue.push(10);
  queue.push(20);
  queue.push(30);
  std::cout << "Pushed 3 elements. Length: " << queue.length() << std::endl;
  std::cout << "Is queue empty: " << std::boolalpha << queue.empty() << std::endl;
  std::cout << "Front: " << queue.front() << ", back: " << queue.back() << ", length = " << queue.length() << std:: endl;
  queue.pop();
  std::cout << "One element poped. Front: " << queue.front() << ", back: " << queue.back() << ", length = " << queue.length() << std:: endl;
  queue.pop();
  std::cout << "Another one element poped. Front: " << queue.front() << ", back: " << queue.back() << ", length = " << queue.length() << std:: endl;
  queue.pop();
  std::cout << "Another one element poped. Front: " << queue.front() << ", back: " << queue.back() << ", length = " << queue.length() << std:: endl;
  std::cout << "Try to allocate large queue" << std::endl;
  Queue<long> large_queue(Container<long>::getMaxLength() + 1);
  std::cout << std::endl << std::endl;

  // Linked list test
  LinkedList<float> list{};
  std::cout << "List created. Length = " << list.size() << std::endl;
  list.push_back(444);
  std::cout << "Element 444 added to back. Length = " << list.size() << std::endl;
  list.print();
  list.push_back(555);
  std::cout << "Element 555 added to back. Length = " << list.size() << std::endl;
  list.print();
  list.push_front(222);
  std::cout << "Element 222 added to front. Length = " << list.size() << std::endl;
  list.print();
  list.push_front(111);
  std::cout << "Element 111 added to front. Length = " << list.size() << std::endl;
  list.print();
  list.insert(3, 333);
  std::cout << "Element 333 inserted to <3>. Length = " << list.size() << std::endl;
  list.print();
  list.insert(2, 987);
  std::cout << "Element 987 inserted to <2>. Length = " << list.size() << std::endl;
  list.print();
  list.insert(5, 321);
  std::cout << "Element 321 inserted to <5>. Length = " << list.size() << std::endl;
  list.print();
  std::cout << "Element 2 is " << list.get_value(2) << std::endl;
  std::cout << "Element 5 is " << list.get_value(5) << std::endl;
  list.pop_back();
  std::cout << "List poped back. Length = " << list.size() << std::endl;
  list.print();
  list.pop_front();
  std::cout << "List poped front. Length = " << list.size() << std::endl;
  list.print();
  list.erase();
  std::cout << "List erased. Length = " << list.size() << std::endl;
  list.print();
}
