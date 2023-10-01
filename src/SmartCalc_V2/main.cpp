
#include "../view/viewsmartcalc.h"
#include "../controller/calccontrol.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::ViewSmartCalc w;
  s21::CalcControl control(&w);
  w.SetController(control);
  w.show();
  std::locale loc("en_US.UTF-8");
  std::locale::global(loc);
  return a.exec();
}
