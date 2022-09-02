/**
 * @file    coordinate.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    22/08/22
 */

#include "coordinate.h"

namespace s21 {

Coordinate::Coordinate(int newX, int newY):
    x{newX},
    y{newY}
{}

auto Coordinate::operator=(const Coordinate &other) -> Coordinate& {
    x = other.x;
    y = other.y;
    return *this;
}

auto operator==(const Coordinate& lhs, const Coordinate& rhs) -> bool {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

auto operator!=(const Coordinate& lhs, const Coordinate& rhs) -> bool {
    return  lhs.x != rhs.x || lhs.y != rhs.y;
}

auto operator+(const Coordinate& lhs, const Coordinate& rhs) -> Coordinate {
    return  Coordinate(lhs.x + rhs.x, lhs.y + rhs.y);
}

} //s21
