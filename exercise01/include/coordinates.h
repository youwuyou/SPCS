#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>

/*
simple helper struct for coordinates
*/
template<typename T>
struct coordinates {
  std::pair<T, T> coords;
  coordinates() : coords({0, 0}) {}
  coordinates(T x, T y) : coords({x, y}) {}
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

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T>& pair) {
  os << pair.first << " " << pair.second;
  return os;
}

template<typename T, typename R>
coordinates<T> operator+(const coordinates<T>& c1, const coordinates<R>& c2) {
  return coordinates<T>(c1.x() + c2.x(), c1.y() + c2.y());
}

template<typename T>
coordinates<T> operator/(const coordinates<T>& c1, const double d) {
  return coordinates<T>(c1.x() / d, c1.y() / d);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const coordinates<T>& c) {
  os << c.coords;
  return os;
}

#endif
