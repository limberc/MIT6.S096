#include <cmath>
#include <iostream>

// These class definitions would really be in another
// header file, but they're all in here for demonstration
// purposes.

class Shape {
public:
  virtual double area() const = 0;
  virtual ~Shape() {}
};

class Circle : public Shape {
  double _radius;
public:
  Circle( double theRadius ) : _radius{theRadius} {}
  ~Circle() {}
  inline double radius() const { return _radius; }

  double area() const {
    return _radius * _radius * M_PI;
  }
};

class Square : public Shape {
  double _side;
public:
  Square( double sideLength ) : _side{sideLength} {}
  ~Square() {}
  inline double side() const { return _side; }

  double area() const {
    return _side * _side;
  }
};

class Rectangle : public Shape {
  double _width, _height;
public:
  Rectangle( double theWidth, double theHeight ) 
    : _width{theWidth}, _height{theHeight} {}
  ~Rectangle() {}
  inline double height() const { return _height; }
  inline double width() const { return _width; }

  double area() const {
    return _width * _height;
  }
};

class Triangle : public Shape {
  double _base, _height;
public:
  Triangle( double theBase, double theHeight ) 
    : _base{theBase}, _height{theHeight} {}
  ~Triangle() {}
  inline double base() const { return _base; }
  inline double height() const { return _height; }

  double area() const {
    return 0.5 * _base * _height;
  }
};

int main() {
  auto circle = Circle{ 1.0 };
  auto tri = Triangle{ 2.0, 3.0 };

  std::cout << "Circle of radius ";
  std::cout << circle.radius();
  std::cout <<  " has area ";
  std::cout << circle.area() << "\n";

  std::cout << "Triangle has area ";
  std::cout << tri.area() << "\n";

  return 0;
}
