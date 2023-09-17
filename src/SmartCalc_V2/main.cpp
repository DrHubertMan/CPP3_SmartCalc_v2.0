
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::MainWindow w;
  w.show();
  std::locale loc("en_US.utf8");
  std::locale::global(loc);
  return a.exec();
}
