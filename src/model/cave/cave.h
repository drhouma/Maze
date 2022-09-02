/**
 * @file    cave.h
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    26/08/22
 */

#ifndef CAVE_H
#define CAVE_H

#include <string>
#include <array>

#include "../core/matrix.h"

namespace s21 {

/**
 * @class Cave
 * @brief That class implements cave generation by cellular automaton
 */

class Cave final {

 public:
  Cave();
  ~Cave() = default;
  Cave(const Cave&) = delete;
  Cave(Cave&&) = delete;
  auto operator=(const Cave&) -> Cave& = delete;
  auto operator=(Cave&&) -> Cave&& = delete;

 public:
  auto NewEpoch() -> bool;
  auto SetParametersAfterLoad(int alive, int death) -> void;
  auto Generate(int alive, int death, int rows, int cols, int chance) -> void;

  auto SaveCave(const std::string &filename) -> void;
  auto LoadCave(const std::string &filename) -> bool;
  auto Clear() -> void;
  [[nodiscard]] auto Cells() const -> const Matrix<bool> &;
  [[nodiscard]] auto Rows() const -> int;
  [[nodiscard]] auto Cols() const -> int;

 private:
  [[nodiscard]]auto CheckBorder(int num, int max) const -> int;
  auto CountNeighbours(int row, int col, bool whatCount) -> int;

 private:
  Matrix<bool> m_cells;
  Matrix<bool> m_previousEpochCells;
  int m_alive{};
  int m_dead{};
  int m_chance{};
  std::array<std::pair<int, int>, 8> m_directions;

private:
  static constexpr bool ALIVE = true;
  static constexpr bool DEAD = false;
};

}  // namespace s21

#endif // CAVE_H
