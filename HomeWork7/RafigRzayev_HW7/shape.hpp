#pragma once

#include <iostream>

class Shape {
public:
  ~Shape();
  virtual void calculate_area() const = 0;
  virtual void draw() const = 0;
  bool is_empty() const;
  void clear();

protected:
  double *shape_data{nullptr};
};
