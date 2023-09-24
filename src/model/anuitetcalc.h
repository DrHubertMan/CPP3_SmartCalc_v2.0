#ifndef CPP3_SMARTCALC_V2_1_MODEL_ANUITETCALC_H
#define CPP3_SMARTCALC_V2_1_MODEL_ANUITETCALC_H

#include <cmath>
#include <iostream>

namespace s21 {
class AnuitetCalc {
public:
  AnuitetCalc();
  AnuitetCalc(double all_sum, double percent, int term);

  double GetMountlyPay();
  double GetAllPay();
  double GetOverPay();

private:
  void Calculation();

private:
  double all_sum_;
  double percent_;
  int term_;
  double mountly_pay_;

  double all_pay_;
  double overpay_;
};
}; // namespace s21

#endif //  CPP3_SMARTCALC_V2_1_MODEL_ANUITETCALC_H