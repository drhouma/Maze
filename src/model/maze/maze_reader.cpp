/**
 * @file    maze_reader.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#include <fstream>
#include <iostream>

#include "maze.h"

namespace s21 {

auto Maze::Load(const std::string &fileName) -> bool {
  std::ifstream file{fileName};
  if (!CheckFile(file)) {
    return false;
  }

  file >> m_rows;
  file >> m_cols;
  m_verticalWalls.resize(m_rows, m_cols);
  m_horizontalWalls.resize(m_rows, m_cols);

  int value {0};
  for (int i{0}; i < m_rows; ++i) {
    for (int j{0}; j < m_cols; ++j) {
      file >> value;
      m_verticalWalls(i, j) = value;
    }
  }
  for (int i{0}; i < m_rows; ++i) {
    for (int j{0}; j < m_cols; ++j) {
      file >> value;
      m_horizontalWalls(i, j) = value;
    }
  }
  return true;
}

auto Maze::CheckFile(std::ifstream &file) const -> bool {
  if (file.bad()) return false;
  std::string name;
  file >> name;
  if (name != "MAZE") return false;
  return true;
}

auto Maze::Save(const std::string &fileName) -> void {
  std::ofstream file{fileName};
  file << "MAZE" << std::endl;
  file << m_rows << ' ' << m_cols << std::endl;

  int value{};
  for (int i{0}; i < m_rows; ++i) {
    for (int j{0}; j < m_cols; ++j) {
      file << m_verticalWalls(i, j) << ' ';
    }
    file << std::endl;
  }
  file << std::endl;
  for (int i{0}; i < m_rows; ++i) {
    for (int j{0}; j < m_cols; ++j) {
      file << m_horizontalWalls(i, j) << ' ';
    }
    file << std::endl;
  }
}


}  // namespace s21
