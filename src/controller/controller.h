/**
 * @file    controller.h
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    19/08/22
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include "../model/cave/cave.h"
#include "../model/core/core.h"
#include "../model/maze/maze.h"

namespace s21 {

/**
 * @class Controller
 * @brief Controlling the model of mazes and caves to use them in view part
 */

class Controller {
 public:
  Controller();
  ~Controller() = default;
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  auto operator=(const Controller&) -> Controller& = delete;
  auto operator=(Controller&&) -> Controller&& = delete;

 public:
  /**
   * @brief Maze functional
   */
  /*-------------------------------------------------------------------*/
  auto GenerateMaze(int rows, int cols) -> void;
  [[nodiscard]] auto MazeRows() const -> int;
  [[nodiscard]] auto MazeCols() const -> int;
  [[nodiscard]] auto MazeVerticalWalls() const -> const Matrix<bool>&;
  [[nodiscard]] auto MazeHorizontalWalls() const -> const Matrix<bool>&;
  [[nodiscard]] auto MazeSolution(const std::pair<int, int>& begin,
                                  const std::pair<int, int>& end) const
      -> std::vector<std::pair<int, int>>;
  [[nodiscard]] auto GetMode() const -> Mode;

  auto LoadMaze(const std::string& filename) -> bool;
  auto SaveMaze(const std::string& filename) -> void;
  /*-------------------------------------------------------------------*/

  /**
   * @brief Cave functional
   */
  /*-------------------------------------------------------------------*/
  auto GenerateCave(int alive, int death, int rows, int cols, int chance)
      -> void;
  auto CaveNewEpoch() -> bool;
  auto CaveClear() -> void;
  auto CaveSetParametersAfterLoad(int alive, int death) -> void;
  [[nodiscard]] auto CaveCells() const -> const Matrix<bool>&;
  [[nodiscard]] auto CaveRows() const -> int;
  [[nodiscard]] auto CaveCols() const -> int;

  auto LoadCave(const std::string& filename) -> bool;
  auto SaveCave(const std::string& filename) -> void;
  /*-------------------------------------------------------------------*/

 private:
  std::unique_ptr<Maze> m_maze{};
  std::unique_ptr<Cave> m_cave{};
  Mode m_mode{};
};

}  // namespace s21

#endif  // CONTROLLER_H
