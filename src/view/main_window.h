/**
 * @file    main_window.h
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <memory>

#include "../controller/controller.h"
#include "cave_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Main window of application with render scene for maze and functional buttons
 */

class MainWindow final: public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(MainWindow)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() final;

private slots:
    void on_generateButton_clicked();
    void on_caveModeButton_clicked();


    void on_loadButtonMaze_clicked();

    void on_saveButtonMaze_clicked();

private:
    Ui::MainWindow* ui {};
    QScopedPointer<CaveWindow> m_caveWindow {};
    std::shared_ptr<s21::Controller> m_controller {};
};
#endif // MAIN_WINDOW_H
