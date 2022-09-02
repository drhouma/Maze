/**
 * @file    maze_core.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#include <functional>

#include "maze.h"

namespace s21 {

auto Maze::FillLineSetEmpty() -> void {
    for (int i {0}; i < m_cols; ++i) {
        m_lineSet.push_back(0);
    }
}

auto Maze::FillLineSet() -> void {
    for (int i {0}; i < m_cols; ++i) {
        if (m_lineSet[i] == 0) {
            m_lineSet[i] = m_setCounter;
            ++m_setCounter;
        }
    }
}

auto Maze::MergeSet(const int index, const int value) -> void {
    int newSetValue = m_lineSet[index + 1];
    for (int i {0}; i < m_cols; ++i) {
        if (m_lineSet[i] == newSetValue) {
            m_lineSet[i] = value;
        }
    }
}

auto Maze::IsUniqSet(const int value) -> bool {
    int counter {0};
    for (auto& item: m_lineSet) {
        if (item == value) {
            ++counter;
        }
        if (counter > 1) {
            return false;
        }
    }
    return true;
}

auto Maze::IsOneSetWithoutBorder(const int row, const int value) -> bool {
    for (int i {0}, counter {0}; i < m_cols; ++i) {
        if (m_lineSet[i] == value && !m_horizontalWalls(row, i)) {
            ++counter;
        }
        if (counter > 1) {
            return false;
        }
    }
    return true;
}

auto Maze::PrepareNewLine(const int row) -> void {
    for (int i {0}; i < m_cols; ++i) {
        if (m_horizontalWalls(row, i) == 1.) {
            m_lineSet[i] = 0;
        }
    }
}

auto Maze::AddEndLine() -> void {
    FillLineSet();
    AddVerticalWalls(m_rows - 1);
}

auto Maze::EndLineProcessing() -> void {
    for (int i {0}; i < m_cols - 1; ++i) {
        if (m_lineSet[i] != m_lineSet[i + 1]) {
            m_verticalWalls(m_rows - 1, i) = false;
            MergeSet(i, m_lineSet[i]);
        }
        m_horizontalWalls(m_rows - 1, i) = true;
    }
    m_horizontalWalls(m_rows - 1, m_cols - 1) = true;
}

auto Maze::Clear() -> void {
    m_setCounter = 1;
    m_lineSet.clear();
    m_verticalWalls.clear();
    m_horizontalWalls.clear();
}

auto Maze::Rows() const -> int {
    return m_rows;
}

auto Maze::Cols() const -> int {
    return m_cols;
}

auto Maze::VerticalWalls() const -> const Matrix<bool>& {
    return m_verticalWalls;
}

auto Maze::HorizontalWalls() const -> const Matrix<bool>& {
    return m_horizontalWalls;
}

} // namespace s21
