/**
 * @file    cave_window.h
 * @authors Savin A.     <telvina<at>student.21-school.ru
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    23/08/22
 */

#ifndef CAVE_WINDOW_H
#define CAVE_WINDOW_H

#include <QDialog>
#include <QScopedPointer>
#include <QTimer>
#include <QCloseEvent>

#include <memory>

#include "../controller/controller.h"

namespace Ui {
class CaveWindow;
}

/**
 * @class CaveWindow
 * @brief Window with scene for visualization caves and controlls for them
 */

class CaveWindow final: public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(CaveWindow)

public:
    explicit CaveWindow(QWidget *parent = nullptr);
    ~CaveWindow() final;

public:
    auto SetController(const std::shared_ptr<s21::Controller>& controller) -> void;

private slots:
    void on_generateButton_clicked();
    void on_stepButton_clicked();
    void on_autoButton_clicked();
    void closeEvent(QCloseEvent* event) override;


    void on_saveButtonCave_clicked();

    void on_loadButtonCave_clicked();

private:
    Ui::CaveWindow *ui;
    std::shared_ptr<s21::Controller> m_controller;
    QScopedPointer<QTimer> m_timer {};
    bool isGenerated {};
};

#endif // CAVE_WINDOW_H
