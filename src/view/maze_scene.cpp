/**
 * @file    maze_scene.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#include "maze_scene.h"

#include <QColor>
#include <QPainter>
#include <QPen>

MazeScene::MazeScene(QWidget *parent)
    : QWidget{parent}, m_mode{s21::Mode::NONE} {}

auto MazeScene::SetController(
    const std::shared_ptr<s21::Controller> &controller) -> void {
  m_controller = controller;
}

auto MazeScene::mousePressEvent(QMouseEvent *event) -> void {
  if (m_controller->GetMode() != s21::Mode::MAZE) return;
  if (event->button() == Qt::LeftButton) {
    if (m_clickCounter > 1)
      return;
    else if (m_clickCounter == 0)
      m_beginPosition = event->pos();
    else
      m_endPosition = event->pos();
    ++m_clickCounter;
    isNeedSolution = true;
  } else if (event->button() == Qt::RightButton) {
    isNeedSolution = false;
    m_clickCounter = 0;
  }
  repaint();
}

auto MazeScene::paintEvent(QPaintEvent *event) -> void {
  QPainter painter{this};
  QPen pen{Qt::white};
  pen.setStyle(Qt::SolidLine);
  pen.setWidth(lineWidth);
  painter.setPen(pen);
  painter.drawLine(1, 1, 1, windowSize - 1);
  painter.drawLine(1, 1, windowSize, 1);
  painter.drawLine(windowSize - 1, 1, windowSize - 1, windowSize - 1);
  painter.drawLine(1, windowSize - 1, windowSize - 1, windowSize - 1);
  m_mode = m_controller->GetMode();
  if (m_mode == s21::Mode::NONE) {
    return;
  }
  if (m_mode == s21::Mode::MAZE) {
    m_rows = m_controller->MazeRows();
    m_cols = m_controller->MazeCols();
    m_verticalWalls.resize(m_rows, m_cols);
    m_horizontalWalls.resize(m_rows, m_cols);
    m_verticalWalls = m_controller->MazeVerticalWalls();
    m_horizontalWalls = m_controller->MazeHorizontalWalls();

    double width{windowSize / m_cols};
    double height{windowSize / m_rows};
    for (int i{1}; i <= m_rows; ++i) {
      for (int j{1}; j <= m_cols; ++j) {
        if (m_verticalWalls(i - 1, j - 1) && j != m_cols) {
          painter.drawLine(QPointF{j * width, (i - 1) * height},
                           QPointF{j * width, i * height});
        }
        if (m_horizontalWalls(i - 1, j - 1) && i != m_rows) {
          painter.drawLine(QPointF{(j - 1) * width, i * height},
                           QPointF{j * width, i * height});
        }
      }
    }

    if (m_mode == s21::Mode::MAZE) {
      m_rows = m_controller->MazeRows();
      m_cols = m_controller->MazeCols();
      m_verticalWalls.resize(m_rows, m_cols);
      m_horizontalWalls.resize(m_rows, m_cols);
      m_verticalWalls = m_controller->MazeVerticalWalls();
      m_horizontalWalls = m_controller->MazeHorizontalWalls();
      painter.drawLine(1, 1, 1, windowSize - 1);
      painter.drawLine(1, 1, windowSize, 1);
      painter.drawLine(windowSize - 1, 1, windowSize - 1, windowSize - 1);
      painter.drawLine(1, windowSize - 1, windowSize - 1, windowSize - 1);
      for (int i{1}; i <= m_rows; ++i) {
        for (int j{1}; j <= m_cols; ++j) {
          if (m_verticalWalls(i - 1, j - 1) && j != m_cols) {
            painter.drawLine(QPointF{j * width, (i - 1) * height},
                             QPointF{j * width, i * height});
          }
          if (m_horizontalWalls(i - 1, j - 1) && i != m_rows) {
            painter.drawLine(QPointF{(j - 1) * width, i * height},
                             QPointF{j * width, i * height});
          }
        }
      }
      if (isNeedSolution) {
        double cellWidth{width - lineWidth};
        double cellHeight{height - lineWidth};
        int cellBeginRowPosition{static_cast<int>(m_beginPosition.x() / width)};
        int cellBeginColPosition{
            static_cast<int>(m_beginPosition.y() / height)};
        int cellEndRowPostition{static_cast<int>(m_endPosition.x() / width)};
        int cellEndColPosition{static_cast<int>(m_endPosition.y() / height)};
        pen.setColor(QColor{purpleColor});
        painter.setPen(pen);
        if (m_clickCounter == 2) {
          auto path = m_controller->MazeSolution(
              std::make_pair(cellBeginColPosition, cellBeginRowPosition),
              std::make_pair(cellEndColPosition, cellEndRowPostition));

          for (int i{0}; i < path.size() - 1; ++i) {
            painter.drawLine(
                QPointF{path[i].second * width + cellWidth / 2,
                        path[i].first * height + cellHeight / 2},
                QPointF{path[i + 1].second * width + cellWidth / 2,
                        path[i + 1].first * height + cellHeight / 2});
          }

        } else if (m_clickCounter == 1) {
          painter.drawLine(
              QPointF{cellBeginRowPosition * width + cellWidth / 2 - 1,
                      cellBeginColPosition * height + cellHeight / 2 - 1},
              QPointF{cellBeginRowPosition * width + cellWidth / 2,
                      cellBeginColPosition * height + cellHeight / 2});
        }
      }
    }
  }
}
