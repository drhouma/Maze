/**
 * @file    controller.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    19/08/22
 */

#include "controller.h"

namespace s21 {

Controller::Controller()
    : m_maze{new Maze}, m_cave{new Cave}, m_mode{Mode::NONE} {}

auto Controller::MazeRows() const -> int { return m_maze->Rows(); }

auto Controller::MazeCols() const -> int { return m_maze->Cols(); }

auto Controller::MazeVerticalWalls() const -> const Matrix<bool>& {
  return m_maze->VerticalWalls();
}

auto Controller::MazeHorizontalWalls() const -> const Matrix<bool>& {
  return m_maze->HorizontalWalls();
}

auto Controller::GenerateMaze(const int rows, const int cols) -> void {
  m_mode = Mode::MAZE;
  m_maze->Generate(rows, cols);
}

auto Controller::MazeSolution(const std::pair<int, int>& begin,
                              const std::pair<int, int>& end) const
    -> std::vector<std::pair<int, int>> {
  return m_maze->FindPath(begin, end);
}

auto Controller::GetMode() const -> Mode { return m_mode; }

auto Controller::GenerateCave(const int alive, const int death, const int rows,
                              const int cols, const int chance) -> void {
  m_mode = Mode::CAVE;
  m_cave->Generate(alive, death, rows, cols, chance);
}

auto Controller::CaveNewEpoch() -> bool { return m_cave->NewEpoch(); }

auto Controller::CaveCells() const -> const Matrix<bool>& {
  return m_cave->Cells();
}

auto Controller::CaveRows() const -> int { return m_cave->Rows(); }

auto Controller::CaveCols() const -> int { return m_cave->Cols(); }

auto Controller::CaveClear() -> void { m_cave->Clear(); }

auto Controller::LoadMaze(const std::string& filename) -> bool {
    m_mode = Mode::MAZE;
    return m_maze->Load(filename);
}

void Controller::SaveMaze(const std::string &filename)
{
    m_maze->Save(filename);
}

auto Controller::LoadCave(const std::string& filename) -> bool {
    m_mode = Mode::CAVE;
    return m_cave->LoadCave(filename);
}

auto Controller::SaveCave(const std::string &filename) -> void {
    m_cave->SaveCave(filename);
}

auto Controller::CaveSetParametersAfterLoad(int alive, int death) -> void {
    m_cave->SetParametersAfterLoad(alive, death);
}

}  // namespace s21
