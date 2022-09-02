/**
 * @file    coordinate.h
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    22/08/22
 */

#ifndef COORDINATE_H
#define COORDINATE_H

namespace s21 {

/**
 * @struct Coordinate
 * @brief  Defines struct for point with two coordinates
 */

struct Coordinate final {
  int x{};
  int y{};

  Coordinate() = default;
  ~Coordinate() = default;
  Coordinate(const Coordinate&) = default;
  Coordinate(int newX, int newY);
  auto operator=(const Coordinate& other) -> Coordinate&;
};

auto operator==(const Coordinate& lhs, const Coordinate& rhs) -> bool;
auto operator!=(const Coordinate& lhs, const Coordinate& rhs) -> bool;
auto operator+(const Coordinate& lhs, const Coordinate& rhs) -> Coordinate;

}  // namespace s21

#endif  // COORDINATE_H
