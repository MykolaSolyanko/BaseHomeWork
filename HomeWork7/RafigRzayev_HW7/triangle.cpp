#include "bubblesort.hpp"
#include "math.h"
#include "triangle.hpp"

// Allocate memory based on triangle info
void Triangle::init(const double A, const double B, const double C) {
  if (A <= 0 || B <= 0 || C <= 0) {
    std::cout << "Input cannot be zero or negative\n";
    return;
  }
  // cannot create if sum of 2 sides is smaller than third side
  if (A + B <= C || A + C <= B || B + C <= A) {
    std::cout << "Incorrect dimensions\n";
    return;
  }
  static const size_t TRIANGLE_DATA_SIZE{3};
  shape_data = new double[TRIANGLE_DATA_SIZE]{A, B, C};
  bubble_sort(shape_data, shape_data + TRIANGLE_DATA_SIZE,
              [](double x, double y) { return x < y; });
}

// User-Defined Constructor
Triangle::Triangle(const double A, const double B, const double C) {
  init(A, B, C);
}

//  Copy Constructor
Triangle::Triangle(const Triangle &RHS) {
  if (RHS.is_empty()) {
    return;
  }
  init(*RHS.shape_data, *(RHS.shape_data + 1), *(RHS.shape_data + 2));
}

// Copy Assignment
Triangle &Triangle::operator=(const Triangle &RHS) {
  if (this == &RHS) {
    return *this;
  }
  clear();
  if (RHS.is_empty()) {
    return *this;
  }
  init(*RHS.shape_data, *(RHS.shape_data + 1), *(RHS.shape_data + 2));
  return *this;
}

// Calculate area of Triangle
void Triangle::calculate_area() const {
  std::cout << "--------------------------------------\n";
  if (is_empty()) {
    std::cout << "Error: Empty triangle\n";
    return;
  }
  const double &A = *shape_data;
  const double &B = *(shape_data + 1);
  const double &C = *(shape_data + 2);
  // Half-Perimeter
  const double S{(A + B + C) / 2};
  // AREA FORMULA (Heron's formula)
  const double AREA{sqrt(S * (S - A) * (S - B) * (S - C))};
  std::cout << "Area of Triangle is " << AREA << std::endl;
}

// Print PADDING_CHAR x DISTANCE. Then print EDGE_CHAR
void print_edge(const char *PADDING, const char *EDGE, const size_t DISTANCE) {
  for (size_t i{0}; i < DISTANCE; ++i) {
    std::cout << PADDING;
  }
  std::cout << EDGE;
}

// Draw Triangle
void Triangle::draw() const {
  std::cout << "--------------------------------------\n";
  if (is_empty()) {
    std::cout << "Error: Empty triangle\n";
    return;
  }
  const double &A = *shape_data;
  const double &B = *(shape_data + 1);
  const double &C = *(shape_data + 2);

  // ANGLE OF THE LEFT CORNER (Law of cosines)
  const double COS_ALPHA{(A * A + C * C - B * B) / (2 * A * C)};
  // PRINT TOP EDGE - HORIZONTAL PADDING
  const double X{C * COS_ALPHA};
  const size_t TOP_PADDING{static_cast<const size_t>(X)};
  print_edge("  ", "*", TOP_PADDING);
  // PRINT LEFT EDGE - VERTICAL PADDING
  const double Y{sqrt(C * C - X * X)};
  const size_t LEFT_PADDING{static_cast<const size_t>(Y)};
  print_edge("\n", "*", LEFT_PADDING);
  // PRINT RIGHT EDGE - HORIZONTAL PADDING
  const size_t RIGHT_PADDING{static_cast<const size_t>(A)};
  print_edge("  ", "*", RIGHT_PADDING);

  std::cout << std::endl;
}
