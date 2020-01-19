#pragma once

#include "shape.hpp"

class Triangle : public Shape {
public:
  Triangle(const double A, const double B, const double C);
  Triangle(const Triangle &RHS);
  Triangle &operator=(const Triangle &RHS);
  void calculate_area() const override;
  void draw() const override;

private:
  void init(const double A, const double B, const double C);
};