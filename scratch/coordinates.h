#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>

/*
simple helper struct for Coordinates
*/
template<typename T>
struct Coordinates {
  std::pair<T, T> coords;

  // Default constructor - create points of coordinates (0,0)
  Coordinates() : coords({0, 0}) {}
  Coordinates(T x, T y) : coords({x, y}) {}
  const T x() const {
    return coords.first;
  }
  const T y() const {
    return coords.second;
  }
  void set_x(const T x){
    coords.first = x;
  }
  void set_y(const T y){
    coords.second = y;
  }

};


// usage:  point << a_pair;
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T>& pair) {
  os << pair.first << " " << pair.second;
  return os;
}

// usage: point << other_point
template<typename T>
std::ostream& operator<<(std::ostream& os, const Coordinates<T>& c) {
  os << c.coords;
  return os;
}


// addition between points
template<typename T, typename R>
Coordinates<T> operator+(const Coordinates<T>& c1, const Coordinates<R>& c2) {
  return Coordinates<T>(c1.x() + c2.x(), c1.y() + c2.y());
}


// substration between points
template<typename T, typename R>
Coordinates<T> operator-(const Coordinates<T>& c1, const Coordinates<R>& c2) {
  return Coordinates<T>(c1.x() - c2.x(), c1.y() - c2.y());
}

// dividing a scalar value
template<typename T>
Coordinates<T> operator/(const Coordinates<T>& c1, const double d) {
  return Coordinates<T>(c1.x() / d, c1.y() / d);
}

// right multiplying a scalar value
template<typename T>
Coordinates<T> operator*(const Coordinates<T>& c1, const double d) {
  return Coordinates<T>(c1.x() * d, c1.y() * d);
}

// left multiplying a scalar value
template<typename T>
Coordinates<T> operator*(const double d, const Coordinates<T>& c1) {
  return Coordinates<T>(c1.x() * d, c1.y() * d);
}





#endif
