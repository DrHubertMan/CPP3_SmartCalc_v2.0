
#include "viewsmartcalc.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::ViewSmartCalc w;
  w.show();
  std::locale loc("en_US.utf8");
  std::locale::global(loc);
  return a.exec();
}
