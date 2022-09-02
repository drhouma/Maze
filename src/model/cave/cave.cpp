/**
 * @file    cave.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    26/08/22
 */

#include "cave.h"

#include "../core/core.h"

namespace s21 {

Cave::Cave() : m_chance{50} {
  m_directions[0] = std::make_pair<int, int>(-1, -1);
  m_directions[1] = std::make_pair<int, int>(0, -1);
  m_directions[2] = std::make_pair<int, int>(1, -1);
  m_directions[3] = std::make_pair<int, int>(1, 0);
  m_directions[4] = std::make_pair<int, int>(1, 1);
  m_directions[5] = std::make_pair<int, int>(0, 1);
  m_directions[6] = std::make_pair<int, int>(-1, 1);
  m_directions[7] = std::make_pair<int, int>(-1, 0);
}

auto Cave::Cells() const -> const Matrix<bool> & { return m_cells; }

auto Cave::CheckBorder(const int num, const int max) const -> int {
  if (num < 0)
    return max - 1;
  else if (num == max)
    return 0;
  return num;
}

auto Cave::CountNeighbours(const int row, const int col, const bool whatCount)
    -> int {
  int counter{0};
  for (auto &dir : m_directions) {
    int x = CheckBorder(row + dir.first, m_cells.rows());
    int y = CheckBorder(col + dir.second, m_cells.cols());
    if (m_cells(x, y) == whatCount) ++counter;
  }
  return counter;
}

/// @return true если генерация закончилась

auto Cave::NewEpoch() -> bool {
  Matrix<bool> tmp(m_cells.rows(), m_cells.cols());
  for (int i{0}; i < m_cells.rows(); ++i) {
    for (int j{0}; j < m_cells.cols(); ++j) {
      if (m_cells(i, j)) {  // если живая
        if (CountNeighbours(i, j, ALIVE) < m_dead) {
          tmp(i, j) = DEAD;
        } else {
          tmp(i, j) = ALIVE;
        }
      } else {
        if (CountNeighbours(i, j, ALIVE) > m_alive) {
          tmp(i, j) = ALIVE;
        } else {
          tmp(i, j) = DEAD;
        }
      }
    }
  }
  m_previousEpochCells = m_cells;
  m_cells = tmp;
  return (tmp == m_previousEpochCells);
  ;
}

auto Cave::Generate(const int alive, const int dead, const int rows,
                    const int cols, const int chance) -> void {
  Clear();
  m_alive = alive;
  m_dead = dead;
  m_chance = chance;
  m_cells.resize(rows, cols);
  for (int i{0}; i < rows; ++i) {
    for (int j{0}; j < cols; ++j) {
      m_cells(i, j) = PercentRandomBool(m_chance);
    }
  }
}

auto Cave::Rows() const -> int { return m_cells.rows(); }

auto Cave::Cols() const -> int { return m_cells.cols(); }

auto Cave::Clear() -> void {
  m_cells.clear();
  m_previousEpochCells.clear();
  m_alive = 0;
  m_dead = 0;
  m_chance = 0;
}

auto Cave::SetParametersAfterLoad(const int alive, const int death) -> void {
  m_alive = alive;
  m_dead = death;
}

}  // namespace s21
