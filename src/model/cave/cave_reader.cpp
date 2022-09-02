#include <fstream>

#include "cave.h"

namespace s21 {

auto Cave::SaveCave(const std::string &filename) -> void {
  std::fstream file;
  file.open(filename, std::fstream::out);
  file << "CAVE" << std::endl;
  file << m_cells.rows() << ' ' << m_cells.cols() << std::endl;
  for (int i {0}; i < m_cells.rows(); ++i) {
    for (int j {0}; j < m_cells.cols(); ++j) {
      file << m_cells(i, j) << ' ';
    }
    file << std::endl;
  }
}

auto Cave::LoadCave(const std::string &filename) -> bool {
  std::fstream file;
  file.open(filename, std::fstream::in);
  if (file.bad()) return false;
  std::string str;
  file >> str;
  if (str != "CAVE") return false;
  int row, col;
  file >> row;
  file >> col;
  if (row <= 0 || col <= 0) return false;
  m_cells.resize(row, col);
  for (int i {0}; i < m_cells.rows(); ++i) {
    for (int j {0}; j < m_cells.cols(); ++j) {
      int val;
      file >> val;
      m_cells(i, j) = val;
    }
  }
  return true;
}

}  // namespace s21
