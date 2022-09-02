/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "view/maze_scene.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    MazeScene *mazeScene;
    QPushButton *generateButton;
    QSpinBox *rowsSpinBox;
    QSpinBox *colsSpinBox;
    QLabel *widthLabel;
    QLabel *heightLabel;
    QLabel *fileNameLabel;
    QPushButton *loadButtonMaze;
    QPushButton *caveModeButton;
    QPushButton *saveButtonMaze;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 650);
        MainWindow->setMinimumSize(QSize(600, 650));
        MainWindow->setMaximumSize(QSize(600, 650));
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #0C090A;\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mazeScene = new MazeScene(centralwidget);
        mazeScene->setObjectName(QString::fromUtf8("mazeScene"));
        mazeScene->setGeometry(QRect(50, 10, 500, 500));
        mazeScene->setStyleSheet(QString::fromUtf8(""));
        generateButton = new QPushButton(centralwidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setGeometry(QRect(310, 600, 241, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono")});
        font.setBold(false);
        generateButton->setFont(font);
        generateButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 1,\n"
"											  stop:0 #CC0099, stop:1 #FF9933);\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-color: #FFFFFF;\n"
"	border-width: 0px;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-width: 4px;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-width: 0px;\n"
"	background-color:  #0C090A;\n"
"	color:  qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 1,\n"
"											  stop:0 #CC0099, stop:1 #FF9933);\n"
"}"));
        rowsSpinBox = new QSpinBox(centralwidget);
        rowsSpinBox->setObjectName(QString::fromUtf8("rowsSpinBox"));
        rowsSpinBox->setGeometry(QRect(420, 521, 131, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono")});
        rowsSpinBox->setFont(font1);
        rowsSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	color: #FFFFFF;\n"
"}"));
        rowsSpinBox->setMinimum(1);
        rowsSpinBox->setMaximum(50);
        rowsSpinBox->setValue(20);
        colsSpinBox = new QSpinBox(centralwidget);
        colsSpinBox->setObjectName(QString::fromUtf8("colsSpinBox"));
        colsSpinBox->setGeometry(QRect(420, 561, 131, 31));
        colsSpinBox->setFont(font1);
        colsSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	color: #FFFFFF;\n"
"}"));
        colsSpinBox->setMinimum(1);
        colsSpinBox->setMaximum(50);
        colsSpinBox->setValue(20);
        widthLabel = new QLabel(centralwidget);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));
        widthLabel->setGeometry(QRect(310, 520, 101, 31));
        widthLabel->setFont(font1);
        widthLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 20px;\n"
"}"));
        widthLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        heightLabel = new QLabel(centralwidget);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));
        heightLabel->setGeometry(QRect(310, 560, 101, 31));
        heightLabel->setFont(font1);
        heightLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 20px;\n"
"}"));
        heightLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fileNameLabel = new QLabel(centralwidget);
        fileNameLabel->setObjectName(QString::fromUtf8("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(40, 520, 241, 21));
        fileNameLabel->setFont(font1);
        fileNameLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 20px;\n"
"}"));
        fileNameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        loadButtonMaze = new QPushButton(centralwidget);
        loadButtonMaze->setObjectName(QString::fromUtf8("loadButtonMaze"));
        loadButtonMaze->setGeometry(QRect(40, 550, 111, 41));
        loadButtonMaze->setFont(font);
        loadButtonMaze->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 1,\n"
"											  stop:0 #CC0099, stop:1 #FF9933);\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-color: #FFFFFF;\n"
"	border-width: 0px;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-width: 4px;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-width: 0px;\n"
"	background-color:  #0C090A;\n"
"	color:  qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 1,\n"
"											  stop:0 #CC0099, stop:1 #FF9933);\n"
"}"));
        caveModeButton = new QPushButton(centralwidget);
        caveModeButton->setObjectName(QString::fromUtf8("caveModeButton"));
        caveModeButton->setGeometry(QRect(40, 600, 241, 41));
        caveModeButton->setFont(font);
        caveModeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 1,\n"
"											  stop:0 #CC0099, stop:1 #FF9933);\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-color: #FFFFFF;\n"
"	border-width: 0px;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-width: 4px;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-width: 0px;\n"
"	background-color:  #0C090A;\n"
"	color:  qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 1,\n"
"											  stop:0 #CC0099, stop:1 #FF9933);\n"
"}"));
        saveButtonMaze = new QPushButton(centralwidget);
        saveButtonMaze->setObjectName(QString::fromUtf8("saveButtonMaze"));
        saveButtonMaze->setGeometry(QRect(170, 550, 111, 41));
        saveButtonMaze->setFont(font);
        saveButtonMaze->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 1,\n"
"											  stop:0 #CC0099, stop:1 #FF9933);\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-color: #FFFFFF;\n"
"	border-width: 0px;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-width: 4px;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-width: 0px;\n"
"	background-color:  #0C090A;\n"
"	color:  qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 1,\n"
"											  stop:0 #CC0099, stop:1 #FF9933);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Maze", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "GENERATE", nullptr));
        widthLabel->setText(QCoreApplication::translate("MainWindow", "WIDTH", nullptr));
        heightLabel->setText(QCoreApplication::translate("MainWindow", "HEIGHT", nullptr));
        fileNameLabel->setText(QCoreApplication::translate("MainWindow", "FILENAME", nullptr));
        loadButtonMaze->setText(QCoreApplication::translate("MainWindow", "LOAD", nullptr));
        caveModeButton->setText(QCoreApplication::translate("MainWindow", "CAVE MODE", nullptr));
        saveButtonMaze->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
