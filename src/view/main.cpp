/**
 * @file    main.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    18/08/22
 */

#include <QApplication>
#include <QIcon>

#include "main_window.h"

int main(int argc, char *argv[]) {
  // setlocale(LC_NUMERIC, "C");
  QApplication a(argc, argv);
  a.setWindowIcon(QIcon{":/icon.svg"});
  MainWindow w;
  w.show();
  return a.exec();
}
