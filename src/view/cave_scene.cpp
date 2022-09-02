/**
 * @file    cave_scene.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    23/08/22
 */

#include <QPainter>
#include <QRectF>
#include <QPen>
#include <QColor>
#include <QBrush>

#include "cave_scene.h"

CaveScene::CaveScene(QWidget *parent)
    : QWidget{parent},
      m_mode{s21::Mode::NONE}
{}

auto CaveScene::SetController(const std::shared_ptr<s21::Controller>& controller) -> void {
    m_controller = controller;
}

auto CaveScene::paintEvent(QPaintEvent* event) -> void {
    QPainter painter {this};
    QPen pen {Qt::white};
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(1, 1, 1, windowSize - 1);
    painter.drawLine(1, 1, windowSize, 1);
    painter.drawLine(windowSize - 1, 1, windowSize - 1, windowSize - 1);
    painter.drawLine(1, windowSize - 1, windowSize - 1, windowSize - 1);
    m_mode = m_controller->GetMode();
    if (m_mode == s21::Mode::NONE) {
      return;
    }
    if (m_mode == s21::Mode::CAVE) {
        QBrush brush {Qt::white};
        painter.setBrush(brush);
        pen.setWidth(1);
        painter.setPen(pen);
        m_cells = m_controller->CaveCells();
        m_rows  = m_controller->CaveRows();
        m_cols  = m_controller->CaveCols();
        double width{windowSize / m_rows};
        double height{windowSize / m_cols};
        for (int i {0}; i < m_rows; ++i) {
            for (int j {0}; j < m_cols; ++j) {
                if (m_cells(i, j)) {
                    painter.drawRect(QRectF{i * width, j * height, width, height});
                }
            }
        }
    }
}
