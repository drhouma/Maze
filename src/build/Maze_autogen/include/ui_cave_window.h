/********************************************************************************
** Form generated from reading UI file 'cave_window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAVE_WINDOW_H
#define UI_CAVE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include "view/cave_scene.h"

QT_BEGIN_NAMESPACE

class Ui_CaveWindow
{
public:
    CaveScene *caveScene;
    QPushButton *loadButtonCave;
    QLabel *fileNameLabel;
    QPushButton *generateButton;
    QLabel *widthLabel;
    QSpinBox *rowsSpinBox;
    QLabel *heightLabel;
    QSpinBox *colsSpinBox;
    QPushButton *stepButton;
    QPushButton *autoButton;
    QLabel *frequencyLabel;
    QSpinBox *frequencySpinBox;
    QPushButton *saveButtonCave;
    QLabel *deathLabel;
    QSpinBox *deathSpinBox;
    QLabel *birthLabel;
    QSpinBox *birthSpinBox;
    QLabel *chanceLabel;
    QSpinBox *chanceSpinBox;

    void setupUi(QDialog *CaveWindow)
    {
        if (CaveWindow->objectName().isEmpty())
            CaveWindow->setObjectName(QString::fromUtf8("CaveWindow"));
        CaveWindow->resize(950, 650);
        CaveWindow->setMinimumSize(QSize(950, 650));
        CaveWindow->setMaximumSize(QSize(950, 650));
        CaveWindow->setBaseSize(QSize(950, 650));
        CaveWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #0C090A;\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        caveScene = new CaveScene(CaveWindow);
        caveScene->setObjectName(QString::fromUtf8("caveScene"));
        caveScene->setGeometry(QRect(80, 50, 500, 500));
        caveScene->setMinimumSize(QSize(0, 0));
        caveScene->setBaseSize(QSize(0, 0));
        loadButtonCave = new QPushButton(CaveWindow);
        loadButtonCave->setObjectName(QString::fromUtf8("loadButtonCave"));
        loadButtonCave->setGeometry(QRect(670, 70, 261, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Mono")});
        font.setBold(false);
        loadButtonCave->setFont(font);
        loadButtonCave->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        fileNameLabel = new QLabel(CaveWindow);
        fileNameLabel->setObjectName(QString::fromUtf8("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(670, 10, 261, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono")});
        fileNameLabel->setFont(font1);
        fileNameLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 20px;\n"
"}"));
        fileNameLabel->setAlignment(Qt::AlignCenter);
        generateButton = new QPushButton(CaveWindow);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setGeometry(QRect(670, 440, 260, 40));
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
        widthLabel = new QLabel(CaveWindow);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));
        widthLabel->setGeometry(QRect(670, 180, 120, 40));
        widthLabel->setFont(font1);
        widthLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 20px;\n"
"}"));
        widthLabel->setAlignment(Qt::AlignCenter);
        rowsSpinBox = new QSpinBox(CaveWindow);
        rowsSpinBox->setObjectName(QString::fromUtf8("rowsSpinBox"));
        rowsSpinBox->setGeometry(QRect(800, 180, 110, 40));
        rowsSpinBox->setFont(font1);
        rowsSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	color: #FFFFFF;\n"
"}"));
        rowsSpinBox->setMinimum(1);
        rowsSpinBox->setMaximum(50);
        rowsSpinBox->setValue(20);
        heightLabel = new QLabel(CaveWindow);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));
        heightLabel->setGeometry(QRect(670, 230, 120, 40));
        heightLabel->setFont(font1);
        heightLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 20px;\n"
"}"));
        heightLabel->setAlignment(Qt::AlignCenter);
        colsSpinBox = new QSpinBox(CaveWindow);
        colsSpinBox->setObjectName(QString::fromUtf8("colsSpinBox"));
        colsSpinBox->setGeometry(QRect(800, 230, 110, 40));
        colsSpinBox->setFont(font1);
        colsSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	color: #FFFFFF;\n"
"}"));
        colsSpinBox->setMinimum(1);
        colsSpinBox->setMaximum(50);
        colsSpinBox->setValue(20);
        stepButton = new QPushButton(CaveWindow);
        stepButton->setObjectName(QString::fromUtf8("stepButton"));
        stepButton->setGeometry(QRect(670, 490, 261, 41));
        stepButton->setFont(font);
        stepButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        autoButton = new QPushButton(CaveWindow);
        autoButton->setObjectName(QString::fromUtf8("autoButton"));
        autoButton->setGeometry(QRect(670, 600, 261, 41));
        autoButton->setFont(font);
        autoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frequencyLabel = new QLabel(CaveWindow);
        frequencyLabel->setObjectName(QString::fromUtf8("frequencyLabel"));
        frequencyLabel->setGeometry(QRect(670, 550, 121, 40));
        frequencyLabel->setFont(font1);
        frequencyLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 16px;\n"
"}"));
        frequencyLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        frequencySpinBox = new QSpinBox(CaveWindow);
        frequencySpinBox->setObjectName(QString::fromUtf8("frequencySpinBox"));
        frequencySpinBox->setGeometry(QRect(799, 550, 111, 40));
        frequencySpinBox->setFont(font1);
        frequencySpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	color: #FFFFFF;\n"
"}"));
        frequencySpinBox->setMinimum(300);
        frequencySpinBox->setMaximum(2000);
        frequencySpinBox->setValue(500);
        saveButtonCave = new QPushButton(CaveWindow);
        saveButtonCave->setObjectName(QString::fromUtf8("saveButtonCave"));
        saveButtonCave->setGeometry(QRect(670, 120, 260, 40));
        saveButtonCave->setFont(font);
        saveButtonCave->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        deathLabel = new QLabel(CaveWindow);
        deathLabel->setObjectName(QString::fromUtf8("deathLabel"));
        deathLabel->setGeometry(QRect(670, 280, 120, 40));
        deathLabel->setFont(font1);
        deathLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 16px;\n"
"}"));
        deathLabel->setAlignment(Qt::AlignCenter);
        deathSpinBox = new QSpinBox(CaveWindow);
        deathSpinBox->setObjectName(QString::fromUtf8("deathSpinBox"));
        deathSpinBox->setGeometry(QRect(800, 280, 110, 40));
        deathSpinBox->setFont(font1);
        deathSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	color: #FFFFFF;\n"
"}"));
        deathSpinBox->setMinimum(0);
        deathSpinBox->setMaximum(7);
        birthLabel = new QLabel(CaveWindow);
        birthLabel->setObjectName(QString::fromUtf8("birthLabel"));
        birthLabel->setGeometry(QRect(670, 330, 120, 40));
        birthLabel->setFont(font1);
        birthLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 16px;\n"
"}"));
        birthLabel->setAlignment(Qt::AlignCenter);
        birthSpinBox = new QSpinBox(CaveWindow);
        birthSpinBox->setObjectName(QString::fromUtf8("birthSpinBox"));
        birthSpinBox->setGeometry(QRect(800, 330, 110, 40));
        birthSpinBox->setFont(font1);
        birthSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	color: #FFFFFF;\n"
"}"));
        birthSpinBox->setMinimum(0);
        birthSpinBox->setMaximum(7);
        chanceLabel = new QLabel(CaveWindow);
        chanceLabel->setObjectName(QString::fromUtf8("chanceLabel"));
        chanceLabel->setGeometry(QRect(670, 380, 120, 40));
        chanceLabel->setFont(font1);
        chanceLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FFFFFF;\n"
"	font-size: 16px;\n"
"}"));
        chanceLabel->setAlignment(Qt::AlignCenter);
        chanceSpinBox = new QSpinBox(CaveWindow);
        chanceSpinBox->setObjectName(QString::fromUtf8("chanceSpinBox"));
        chanceSpinBox->setGeometry(QRect(800, 380, 110, 40));
        chanceSpinBox->setFont(font1);
        chanceSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	color: #FFFFFF;\n"
"}"));
        chanceSpinBox->setMinimum(1);
        chanceSpinBox->setMaximum(100);
        chanceSpinBox->setValue(50);

        retranslateUi(CaveWindow);

        QMetaObject::connectSlotsByName(CaveWindow);
    } // setupUi

    void retranslateUi(QDialog *CaveWindow)
    {
        CaveWindow->setWindowTitle(QCoreApplication::translate("CaveWindow", "Cave", nullptr));
        loadButtonCave->setText(QCoreApplication::translate("CaveWindow", "LOAD", nullptr));
        fileNameLabel->setText(QCoreApplication::translate("CaveWindow", "FILENAME", nullptr));
        generateButton->setText(QCoreApplication::translate("CaveWindow", "GENERATE", nullptr));
        widthLabel->setText(QCoreApplication::translate("CaveWindow", "WIDTH", nullptr));
        heightLabel->setText(QCoreApplication::translate("CaveWindow", "HEIGHT", nullptr));
        stepButton->setText(QCoreApplication::translate("CaveWindow", "NEXT STEP", nullptr));
        autoButton->setText(QCoreApplication::translate("CaveWindow", "AUTO", nullptr));
        frequencyLabel->setText(QCoreApplication::translate("CaveWindow", "FREQUENCY(MS)", nullptr));
        saveButtonCave->setText(QCoreApplication::translate("CaveWindow", "SAVE", nullptr));
        deathLabel->setText(QCoreApplication::translate("CaveWindow", "DEATH LIMIT", nullptr));
        birthLabel->setText(QCoreApplication::translate("CaveWindow", "BIRTH LIMIT", nullptr));
        chanceLabel->setText(QCoreApplication::translate("CaveWindow", "BIRTH CHANCE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CaveWindow: public Ui_CaveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAVE_WINDOW_H
