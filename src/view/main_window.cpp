/**
 * @file    main_window.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#include <QFileDialog>
#include <QMessageBox>

#include "main_window.h"
#include "./ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent},
    ui{new Ui::MainWindow},
    m_caveWindow{new CaveWindow},
    m_controller{new s21::Controller}
{
    ui->setupUi(this);
    ui->mazeScene->SetController(m_controller);
    m_caveWindow->SetController(m_controller);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generateButton_clicked()
{
    if (ui->fileNameLabel->text() != "FILENAME") {
        ui->fileNameLabel->setText("FILENAME");
    }
    m_controller->GenerateMaze(ui->rowsSpinBox->value(), ui->colsSpinBox->value());
    ui->mazeScene->repaint();
}


void MainWindow::on_caveModeButton_clicked()
{
    m_caveWindow->exec();
}

void MainWindow::on_loadButtonMaze_clicked()
{
    QString filePath{QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"), "./", QFileDialog::tr("(*.txt)"))};
    if (!filePath.isEmpty()) {
        if (m_controller->LoadMaze(filePath.toStdString())) {
          ui->fileNameLabel->setText(filePath.mid(filePath.lastIndexOf("/") + 1, filePath.length()));
          ui->mazeScene->repaint();
        } else {
          QMessageBox::warning(this, "Error", "Bad file");
        }
      }
}


void MainWindow::on_saveButtonMaze_clicked()
{
    QString filePath {QFileDialog::getExistingDirectory(
             this, "Open directory to save file", "./",
             QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) + "/"};
     if (!filePath.isEmpty()) {
         QString filesInDir {"_" + QString::number(QDir(filePath).count() - 2)};
         QString fileName {filePath + "maze_" +
            QString::number(m_controller->MazeRows()) + "_" + QString::number(m_controller->MazeCols()) + filesInDir};
         m_controller->SaveMaze(fileName.toStdString() + ".txt");
     }
}

