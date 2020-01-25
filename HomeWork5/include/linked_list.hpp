#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

template <typename T>
class LinkedList {
  public:

    void push_back(T value) {
      node *tmp = new node;
      tmp->data = value;
      tmp->next = nullptr;
      if (head == nullptr) {
        head = tmp;
        tail = tmp;
      } else {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
      }
      ++length;
    }

    void push_front(T value) {
      node *tmp = new node;
      tmp->data = value;
      tmp->prev = nullptr;

      if (head == nullptr) {
        head = tmp;
        tail = tmp;
      } else {
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
      }
      ++length;

    }

    void pop_back() {
      if (tail != nullptr) {
        node *tmp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
          tail->next = nullptr;
        }
        delete tmp;
        --length;
      }
    }

    void pop_front() {
      if (head != nullptr) {
        node *tmp = head;
        head = head->next;
        if (head != nullptr) {
          head->prev = nullptr;
        }
        delete tmp;
        --length;
      }
    }

    T get_value(size_t position) const {
      if (position > length) {
        return 0;
      }
      if (position == 1) {
        return head->data;
      }
      if (position == length) {
        return tail->data;
      }

      node *tmp = head;
      size_t iter = 0;
      while (++iter < position) {
        tmp = tmp->next;
      }
      return tmp->data;
    }

    void insert(size_t position, T value) {
      if (position > length) {
        return;
      }
      if (position == 1) {
        push_front(value);
        return;
      }
      if (position == length) {
        push_back(value);
        return;
      }

      node *tmp = new node;
      tmp->data = value;

      node *iter = head;
      size_t iterator = 0;
      while (++iterator < position) {
        iter = iter->next;
      }
      tmp->prev = iter->prev;
      tmp->next = iter;
      iter->prev->next = tmp;
      iter->prev = tmp;
      
      ++length;
    }

    void remove(size_t position) {
      if (position > length) {
        return;
      }

      if (position == 1) {
        pop_front();
        return;
      }

      if (position == length) {
        pop_back();
        return;
      }

      node *tmp = head;
      size_t iterator = 0;
      while (iterator != position) {
        tmp = tmp->next;
      }
      if (tmp->next != nullptr) {
        tmp->next->prev = tmp->prev;
      }
      if (tmp->prev != nullptr) {
        tmp->prev->next = tmp->next;
      }
      delete tmp;
      --length;
    }

    void erase() {
      while (tail != nullptr) {
        pop_back();
      }
      head = nullptr;
      length = 0;
    }

    size_t size() const {
      return length;
    }
    
    void print() {
      if (head == nullptr) {
        return;
      }
      node *iter = head;
      while (1) {
        // std::cout << '|' << iter->prev << '|' ;
        std::cout << iter->data << ' ';
        // std::cout << '(' << iter << ')' <<'|' << iter->next << "|" << std::endl;
        if (iter->next == nullptr) {
          break;
        }
        iter = iter->next;
      }
      std::cout << std::endl;
    }
  private:
    struct node {
      T data;
      node *next;
      node *prev;
    } *head = nullptr, *tail = nullptr;
    size_t length = 0;
};

#endif  // LINKED_LIST_H_
