#include <cmath>
#include <iostream>

// OLD, NON-OBJECT ORIENTED 
// WAY OF DOING THINGS
// DO NOT WRITE CODE LIKE THIS!

enum ShapeType {
  CIRCLE = 0,
  SQUARE = 1,
  RECTANGLE = 2,
  TRIANGLE = 3
};

struct Shape {
  ShapeType type;
  double a, b, c, d;
};

double area( const Shape &shape ) {
  switch( shape.type ) {
    case CIRCLE: return M_PI * shape.a * shape.a;
    case SQUARE: return shape.a * shape.a;
    case RECTANGLE: return shape.a * shape.b;
    case TRIANGLE: return 0.5 * shape.a * shape.b;
    default: std::cerr << "Error, invalid shape!\n";
  }
  return 0.0;
}

int main() {
  Shape circle; circle.type = CIRCLE;
  circle.a = 1.0;
  std::cout << "Circle of radius " << circle.a;
  std::cout <<  " has area " << area( circle ) << "\n";

  Shape tri; tri.type = TRIANGLE;
  tri.a = 2.0; // height
  tri.b = 3.0; // base
  std::cout << "Triangle has area ";
  std::cout << area( tri ) << "\n";
  return 0;
}
