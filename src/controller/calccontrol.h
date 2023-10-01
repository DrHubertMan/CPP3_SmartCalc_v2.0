#ifndef CPP3_SMARTCALC_V2_1_CONTROLLER_CALCCONTROL_H
#define CPP3_SMARTCALC_V2_1_CONTROLLER_CALCCONTROL_H

#include <QObject>
#include <iostream>

namespace s21 {
class ViewSmartCalc;
class CalcControl : public QObject {
  Q_OBJECT
public:
  CalcControl() = default;
  explicit CalcControl(ViewSmartCalc *calc);

  CalcControl(const CalcControl &c);
  CalcControl &operator=(const CalcControl &c);

  CalcControl(CalcControl &&c);
  CalcControl &operator=(CalcControl &&c);
  ~CalcControl();
public slots:
  void Num(QString text);

private:
  ViewSmartCalc *calculator_ = nullptr;

private:
  void swap(CalcControl &other);
};
} // namespace s21

#endif // CPP3_SMARTCALC_V2_1_CONTROLLER_CALCCONTROL_H