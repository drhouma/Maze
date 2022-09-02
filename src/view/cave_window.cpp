/**
 * @file    cave_window.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    26/08/22
 */

#include <QFileDialog>
#include <QMessageBox>

#include "cave_window.h"
#include "ui_cave_window.h"

CaveWindow::CaveWindow(QWidget *parent) :
    QDialog{parent},
    ui{new Ui::CaveWindow},
    isGenerated{false}
{
    ui->setupUi(this);
}

CaveWindow::~CaveWindow()
{
    delete ui;
}

auto CaveWindow::SetController(const std::shared_ptr<s21::Controller>& controller) -> void {
    m_controller = controller;
    ui->caveScene->SetController(controller);
}

void CaveWindow::on_generateButton_clicked()
{
    isGenerated = true;
    if (ui->fileNameLabel->text() != "FILENAME") {
        ui->fileNameLabel->setText("FILENAME");
    }
    m_controller->GenerateCave(ui->birthSpinBox->value(), ui->deathSpinBox->value(),
                               ui->rowsSpinBox->value(), ui->colsSpinBox->value(),
                               ui->chanceSpinBox->value());
    ui->caveScene->repaint();
}


void CaveWindow::on_stepButton_clicked()
{
    m_controller->CaveNewEpoch();
    ui->caveScene->repaint();
}

void CaveWindow::on_autoButton_clicked()
{
    if (m_timer.isNull()) {
        m_timer.reset(new QTimer {this});
        if (!isGenerated) {
            emit ui->generateButton->clicked();
        }
        connect(m_timer.data(), &QTimer::timeout, this, &CaveWindow::on_stepButton_clicked);
        m_timer->start(ui->frequencySpinBox->value());
        ui->autoButton->setText("STOP");
    }
    else {
        m_timer->stop();
        disconnect(m_timer.data(), &QTimer::timeout, this, &CaveWindow::on_stepButton_clicked);
        m_timer.reset();
        ui->autoButton->setText("AUTO");
    }
}

void CaveWindow::closeEvent(QCloseEvent* event) {
    if (!m_timer.isNull() && m_timer->isActive()) m_timer->stop();
    isGenerated = false;
    m_controller->CaveClear();
}

void CaveWindow::on_saveButtonCave_clicked()
{
    QString filePath {QFileDialog::getExistingDirectory(
             this, "Open directory to save file", "./",
             QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) + "/"};

     if (!filePath.isEmpty()) {
         QString filesInDir {"_" + QString::number(QDir(filePath).count() - 2)};
         QString fileName {filePath + "cave_" +
         QString::number(m_controller->CaveRows()) + "_" +
         QString::number(m_controller->CaveCols()) + filesInDir};
         m_controller->SaveCave(fileName.toStdString() + ".txt");
     }
}


void CaveWindow::on_loadButtonCave_clicked()
{
    QString filePath {QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"), "./", QFileDialog::tr("(*.txt)"))};
    if (!filePath.isEmpty()) {
        if (m_controller->LoadCave(filePath.toStdString())) {
          m_controller->CaveSetParametersAfterLoad(ui->birthSpinBox->value(), ui->deathSpinBox->value());
          ui->fileNameLabel->setText(filePath.mid(filePath.lastIndexOf("/") + 1, filePath.length()));
          ui->colsSpinBox->setValue(m_controller->CaveCols());
          ui->rowsSpinBox->setValue(m_controller->CaveRows());
          ui->caveScene->repaint();
          isGenerated = true;
        } else {
          QMessageBox::warning(this, "Error", "Bad file");
        }
    }
}
