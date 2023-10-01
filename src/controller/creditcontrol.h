#ifndef CPP3_SMARTCALC_V2_1_CONTROLLER_CREDITCALC_H
#define CPP3_SMARTCALC_V2_1_CONTROLLER_CREDITCALC_H

namespace s21 {
  class ViewCreditCalc;
  class CreditCalc {
    public:
    CreditCalc(ViewSmartCalc *parent);
    private:
    ViewCreditCalc *parent_;
  };
}

#endif // CPP3_SMARTCALC_V2_1_CONTROLLER_CREDITCALC_H