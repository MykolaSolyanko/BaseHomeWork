#include "square.hpp"

// Allocate memory based on square info
void Square::init(const double A) {
  if (A <= 0) {
    std::cout << "Input cannot be zero or negative\n";
    return;
  }
  shape_data = new double{A};
}

// User-Defined Constructor
Square::Square(const double A) { init(A); }

//  Copy Constructor
Square::Square(const Square &RHS) {
  if (RHS.is_empty()) {
    return;
  }
  init(*RHS.shape_data);
}

// Copy Assignment
Square &Square::operator=(const Square &RHS) {
  if (this == &RHS) {
    return *this;
  }
  clear();
  if (RHS.is_empty()) {
    return *this;
  }
  init(*RHS.shape_data);
  return *this;
}

// Calculate area of Square
void Square::calculate_area() const {
  std::cout << "--------------------------------------\n";
  if (is_empty()) {
    std::cout << "Error: Empty square\n";
    return;
  }
  const double &A = *shape_data;
  // AREA FORMULA
  const long double AREA{A * A};
  std::cout << "Area of Square is " << AREA << std::endl;
}

// Draw Square
void Square::draw() const {
  std::cout << "--------------------------------------\n";
  if (is_empty()) {
    std::cout << "Error: Empty square\n";
    return;
  }
  const size_t A{static_cast<size_t>(*shape_data)};
  for (size_t i{0}; i < A; ++i) {
    for (size_t j{0}; j < A; ++j) {
      std::cout << "* ";
    }
    std::cout << std::endl;
  }
}