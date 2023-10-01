#ifndef CPP3_SMARTCALC_V2_1_CONTROLLER_MAINCONTROL_H
#define CPP3_SMARTCALC_V2_1_CONTROLLER_MAINCONTROL_H

#include "calccontrol.h"
#include "creditcontrol.h"
#include "depositcontrol.h"

namespace s21 {
class ViewSmartCalc;
class ViewDepositCalc;
class ViewCreditCalc;

class MainControl {
public:
  MainControl(ViewSmartCalc *calc);
private:
  CalcControl *calc_;
  // CreditControl *credit_;
  // DepositControl *deposit_;
};
} // namespace s21

#endif // CPP3_SMARTCALC_V2_1_CONTROLLER_MAINCONTROL_H
