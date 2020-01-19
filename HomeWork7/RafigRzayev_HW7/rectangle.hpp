#pragma once

#include "shape.hpp"

class Rectangle : public Shape {
public:
  Rectangle(const double A, const double B);
  Rectangle(const Rectangle &RHS);
  Rectangle &operator=(const Rectangle &RHS);
  void calculate_area() const override;
  void draw() const override;

private:
  void init(const double A, const double B);
};