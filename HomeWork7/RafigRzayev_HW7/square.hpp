#pragma once

#include "shape.hpp"

class Square : public Shape {
public:
  Square(const double A);
  Square(const Square &RHS);
  Square &operator=(const Square &RHS);
  void calculate_area() const override;
  void draw() const override;

private:
  void init(const double A);
};