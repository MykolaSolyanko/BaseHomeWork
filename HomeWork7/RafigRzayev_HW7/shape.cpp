#include "shape.hpp"

Shape::~Shape() { delete[] shape_data; }

bool Shape::is_empty() const { return shape_data == nullptr; }

void Shape::clear() {
  delete[] shape_data;
  shape_data = nullptr;
}