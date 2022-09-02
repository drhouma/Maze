/**
 * @file    maze_generator.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#include "maze.h"
#include "../core/core.h"

namespace s21 {

auto Maze::Generate(const int rows, const int cols) -> void {
    m_rows = rows;
    m_cols = cols;
    m_verticalWalls.resize(m_rows, m_cols);
    m_horizontalWalls.resize(m_rows, m_cols);
    Clear();
    FillLineSetEmpty();
    for (int i {0}; i < m_rows - 1; ++i) {
        FillLineSet();
        AddVerticalWalls(i);
        AddHorizontalWalls(i);
        PrepareNewLine(i);
    }
    AddEndLine();
    EndLineProcessing();
}

auto Maze::AddVerticalWalls(const int row) -> void {
    for (int i {0}; i < m_cols - 1; ++i) {
        bool needWall = RandomBool();
        if (needWall || m_lineSet[i] == m_lineSet[i + 1]) {
            m_verticalWalls(row, i) = true;
        } else {
            MergeSet(i, m_lineSet[i]);
        }
    }
    m_verticalWalls(row, m_cols - 1) = true;
}

auto Maze::AddHorizontalWalls(const int row) -> void {
    for (int i {0}; i < m_cols; ++i) {
        bool needWall = RandomBool();
        if (needWall && !IsUniqSet(m_lineSet[i]) && !IsOneSetWithoutBorder(row, m_lineSet[i])) {
            m_horizontalWalls(row, i) = true;
        }
    }
}

} // namespace s21
