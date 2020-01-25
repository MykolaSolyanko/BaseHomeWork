#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <iostream>

#ifdef  __linux__
  #define RED     "\033[31m"
  #define GREEN   "\033[32m"
  #define NORMAL  "\033[0m"
#else
  #define RED
  #define GREEN
  #define NORMAL
#endif

template <typename T>
class Container {
  public:
    Container() = delete;
    Container(size_t size_) : containerLength{size_} {
      if (size_ > kMaxLength) {
        Container<T>::printMsg(Container<T>::msgErrorNotAllocated, toPrintMessages);
        return;
      }
      array = new T[containerLength];
    }

    ~Container() {
      if (array != nullptr) {
        delete[] array;
      }
    }

    void isMessagesPrinted(bool choice) {
      toPrintMessages = choice;
    }
    
    static size_t getMaxLength();
    virtual int size() const = 0;
    virtual bool empty() const = 0;

  protected:
    size_t containerLength;
    int index = -1;
    T *array = nullptr;
    bool toPrintMessages = true;

    static const int kMaxLength = 100;
    static const char msgErrorIsFull[];
    static const char msgErrorNotAllocated[];
    static const char msgIsEmpty[];
    static void printMsg(const char msg[], bool toPrint);

};

// Hard way to initialize template static methods and fields
template<typename T>
void Container<T>::printMsg(const char message[], bool toPrint) {
  if (toPrint) {
    std::cout << message;
  }
}

template<typename T>
size_t Container<T>::getMaxLength() {
  return Container<T>::kMaxLength;
}

template<typename T> const char Container<T>::msgErrorNotAllocated[] = RED "<Error. Container is not allocated> " NORMAL;
template<typename T> const char Container<T>::msgErrorIsFull[] = RED "<Error. Container is full> " NORMAL;
template<typename T> const char Container<T>::msgIsEmpty[] = GREEN "<Container is empty> " NORMAL;

#endif // CONTAINER_H_
