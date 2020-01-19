#include "rectangle.hpp"

// Allocate memory based on rectangle info
void Rectangle::init(const double A, const double B) {
  if (A <= 0 || B <= 0) {
    std::cout << "Input cannot be zero or negative\n";
    return;
  }
  static const size_t RECTANGLE_DATA_SIZE{2};
  shape_data = new double[RECTANGLE_DATA_SIZE]{A, B};
}

// User-Defined Constructor
Rectangle::Rectangle(const double A, const double B) { init(A, B); }

//  Copy Constructor
Rectangle::Rectangle(const Rectangle &RHS) {
  if (RHS.is_empty()) {
    return;
  }
  init(*RHS.shape_data, *(RHS.shape_data + 1));
}

// Copy Assignment
Rectangle &Rectangle::operator=(const Rectangle &RHS) {
  if (this == &RHS) {
    return *this;
  }
  clear();
  if (RHS.is_empty()) {
    return *this;
  }
  init(*RHS.shape_data, *(RHS.shape_data + 1));
  return *this;
}

// Calculate area of Rectangle
void Rectangle::calculate_area() const {
  std::cout << "--------------------------------------\n";
  if (is_empty()) {
    std::cout << "Error: Empty rectangle\n";
    return;
  }
  const double &A = *shape_data;
  const double &B = *(shape_data + 1);
  // AREA FORMULA
  const long double AREA{A * B};
  std::cout << "Area of Rectangle is " << AREA << std::endl;
}

// Draw Rectangle
void Rectangle::draw() const {
  std::cout << "--------------------------------------\n";
  if (is_empty()) {
    std::cout << "Error: Empty rectangle\n";
    return;
  }
  const double &A = *shape_data;
  const double &B = *(shape_data + 1);
  const size_t ROWS{static_cast<size_t>(A > B ? A : B)};
  const size_t COLUMNS{static_cast<size_t>(A < B ? A : B)};
  for (size_t i{0}; i < COLUMNS; ++i) {
    for (size_t j{0}; j < ROWS; ++j) {
      std::cout << "* ";
    }
    std::cout << std::endl;
  }
}