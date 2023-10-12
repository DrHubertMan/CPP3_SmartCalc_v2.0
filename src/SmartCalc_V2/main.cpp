
#include "../view/viewsmartcalc.h"
#include "../controller/calccontrol.h"
#include "../model/expressionConverter.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::ExpressionConverter model;
  s21::CalcControl control(&model);
  s21::ViewSmartCalc view(&control);
  control.SetView(&view);
  view.show();
  std::locale loc("en_US.UTF-8");
  std::locale::global(loc);
  return a.exec();
}
