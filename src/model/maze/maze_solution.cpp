/**
 * @file    maze_solution.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#include <array>

#include "maze.h"

namespace s21 {

auto Maze::IsCanStep(const Coordinate& position, const int dx, const int dy)
    -> bool {
  if (position.x + dx < 0 || position.y + dy < 0) return false;
  if (dy == RIGHT && !m_verticalWalls(position.x, position.y)) return true;
  if (dy == LEFT && !m_verticalWalls(position.x, position.y + dy)) return true;
  if (dx == UP && !m_horizontalWalls(position.x + dx, position.y)) return true;
  if (dx == DOWN && !m_horizontalWalls(position.x, position.y)) return true;
  return false;
}

auto Maze::Step(std::vector<Coordinate>& newPoints, const Coordinate& pos,
                const Coordinate& direction, int length) -> Coordinate {
  Coordinate check{pos + direction};
  Coordinate result{-1, -1};
  if (IsCanStep(pos, direction.x, direction.y) &&
      m_grid(check.x, check.y) == -1) {
    newPoints.push_back(check);
    m_grid(check.x, check.y) = length;
    result = check;
  }
  return result;
}

auto Maze::Wave(std::vector<Coordinate>& points, const Coordinate& end,
                const int length) -> Coordinate {
  std::vector<Coordinate> newPoints;
  std::vector<Coordinate> directionVector;
  FillDirection(directionVector);
  for (auto& position : points) {
    for (auto& direction : directionVector) {
      auto point = Step(newPoints, position, direction, length);
      if (point == end) {
        points.clear();
        return end;
      }
    }
  }
  points = newPoints;
  return Coordinate{-1, -1};
}

auto Maze::StepBack(const Coordinate& position, const Coordinate& direction,
                    const int length) -> bool {
  if (position.x + direction.x < 0 || position.y + direction.y < 0 ||
      position.x + direction.x >= m_grid.rows() ||
      position.y + direction.y >= m_grid.cols())
    return false;
  bool conclusion = m_grid(position.x + direction.x,
                           position.y + direction.y) == length - 1 &&
                    IsCanStep(position, direction.x, direction.y);
  return conclusion;
}

auto Maze::RestorePath(const Coordinate& begin, const Coordinate& end)
    -> std::vector<Coordinate> {
  std::vector<Coordinate> points;
  std::vector<Coordinate> direction;
  FillDirection(direction);
  if (m_grid(end.x, end.y) != -1) {
    Coordinate position = end;
    points.push_back(position);
    while (position != begin) {
      for (auto& dir : direction) {
        if (StepBack(position, dir, m_grid(position.x, position.y))) {
          position = position + dir;
          points.push_back(position);
          break;
        }
      }
    }
  }
  return points;
}

auto Maze::FindPath(const std::pair<int, int>& start,
                    const std::pair<int, int>& finish)
    -> std::vector<std::pair<int, int>> {
  int length{1};
  std::vector<Coordinate> points;
  Coordinate begin{start.first, start.second};
  Coordinate end{finish.first, finish.second};
  points.push_back(begin);
  m_grid.resize(m_rows, m_cols);
  m_grid.fill(-1);
  m_grid(begin.x, begin.y) = 0;
  while (!points.empty()) {
    Coordinate checkEnd = Wave(points, end, length);
    if (checkEnd == end) {
      points.clear();
    }
    ++length;
  }
  auto coordinateVector = RestorePath(begin, end);
  std::vector<std::pair<int, int>> pathVector;
  for (auto& item : coordinateVector) {
    pathVector.emplace_back(item.x, item.y);
  }
  return pathVector;
}

auto Maze::FillDirection(std::vector<Coordinate>& direction) const -> void {
  direction.emplace_back(UP, IDLE);
  direction.emplace_back(DOWN, IDLE);
  direction.emplace_back(IDLE, RIGHT);
  direction.emplace_back(IDLE, LEFT);
}

}  // namespace s21
