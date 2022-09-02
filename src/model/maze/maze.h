/**
 * @file    maze.h
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <utility>
#include <vector>

#include "../core/coordinate.h"
#include "../core/matrix.h"

namespace s21 {

/**
 * @class Maze
 * @brief That class implements generation and solving ideal maze by Eller
 * algorithm
 */

class Maze final {
 public:
  Maze() = default;
  ~Maze() = default;
  Maze(const Maze&) = delete;
  Maze(Maze&&) = delete;
  auto operator=(const Maze&) -> Maze& = delete;
  auto operator=(Maze&&) -> Maze&& = delete;

 public:
  auto Generate(int rows, int cols) -> void;

  auto Load(const std::string& fileName) -> bool;
  auto Save(const std::string& fileName) -> void;
  auto CheckFile(std::ifstream& file) const -> bool;
  [[nodiscard]] auto Rows() const -> int;
  [[nodiscard]] auto Cols() const -> int;
  [[nodiscard]] auto VerticalWalls() const -> const Matrix<bool>&;
  [[nodiscard]] auto HorizontalWalls() const -> const Matrix<bool>&;
  [[nodiscard]] auto FindPath(const std::pair<int, int>& start,
                              const std::pair<int, int>& finish)
      -> std::vector<std::pair<int, int>>;

 private:
  /**
   * @brief Maze generation methods
   */

  [[nodiscard]] auto IsUniqSet(int value) -> bool;
  [[nodiscard]] auto IsOneSetWithoutBorder(int row, int value) -> bool;
  auto FillLineSetEmpty() -> void;
  auto FillLineSet() -> void;
  auto MergeSet(int index, int value) -> void;
  auto AddEndLine() -> void;
  auto AddVerticalWalls(int row) -> void;
  auto AddHorizontalWalls(int row) -> void;
  auto EndLineProcessing() -> void;
  auto PrepareNewLine(int row) -> void;
  auto Clear() -> void;

 private:
  /**
   * @brief Maze solution methods
   */

  [[nodiscard]] auto Step(std::vector<Coordinate>& newPoints,
                          const Coordinate& pos, const Coordinate& dir,
                          int length) -> Coordinate;
  [[nodiscard]] auto IsCanStep(const Coordinate& position, int dx, int dy)
      -> bool;
  [[nodiscard]] auto Wave(std::vector<Coordinate>& points,
                          const Coordinate& end, int length) -> Coordinate;
  [[nodiscard]] auto RestorePath(const Coordinate& begin, const Coordinate& end)
      -> std::vector<Coordinate>;
  [[nodiscard]] auto StepBack(const Coordinate& position,
                              const Coordinate& direction, int length) -> bool;
  auto FillDirection(std::vector<Coordinate>& direction) const -> void;

 private:
  std::vector<int> m_lineSet{};
  Matrix<bool> m_horizontalWalls{};
  Matrix<bool> m_verticalWalls{};
  Matrix<int> m_grid{};
  int m_rows{};
  int m_cols{};
  int m_setCounter{};

 private:
  static constexpr int DOWN = 1;
  static constexpr int RIGHT = 1;
  static constexpr int UP = -1;
  static constexpr int LEFT = -1;
  static constexpr int IDLE = 0;
};

}  // namespace s21

#endif  // MAZE_H
