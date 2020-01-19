#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"
#include "triangle.hpp"

void calc_and_draw(const Shape *SHAPE) {
  if (SHAPE == nullptr) {
    std::cout << "Invalid argument\n";
    return;
  }
  SHAPE->calculate_area();
  SHAPE->draw();
}

int main() {

  Square s(5);
  Rectangle r(3, 7);
  Triangle t(6, 10, 8);

  const size_t SIZE{3};
  Shape *figures[SIZE];

  figures[0] = &s;
  figures[1] = &r;
  figures[2] = &t;

  for (size_t i{0}; i < SIZE; ++i) {
    calc_and_draw(figures[i]);
  }
  return 0;
}
