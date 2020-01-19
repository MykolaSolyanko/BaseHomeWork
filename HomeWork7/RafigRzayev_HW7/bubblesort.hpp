// BUBBLE SORT FROM HW4
#pragma once

#include <functional>
#include <iostream>

using CompDouble = std::function<bool(double, double)>;

void bubble_sort(double *begin, const double *const end, CompDouble predicate) {
  if (begin == nullptr || end == nullptr) {
    std::cout << "bubble_sort() - Exception\n";
    return;
  }
  while (true) {
    double *it{begin};
    size_t swap_counter{0};
    while (it != end - 1) {
      if (predicate(*it, *(it + 1))) {
        double temp{*it};
        *it = *(it + 1);
        *(it + 1) = temp;
        ++swap_counter;
      }
      ++it;
    }
    if (swap_counter == 0) {
      break;
    }
  }
}