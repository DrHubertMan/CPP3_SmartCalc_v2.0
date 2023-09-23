#include "diferentcalc.h"

s21::DiferenttCalc::DiferenttCalc()
    : all_sum_(0), percent_(0), term_(0), mountly_pay_(0), all_pay_(0),
      overpay_(0) {}

s21::DiferenttCalc::DiferenttCalc(double all_sum, double percent, int term)
    : all_sum_(all_sum), percent_(percent), term_(term),
      mountly_pay_(0), all_pay_(0), overpay_(0) {
  Calculation();
}

double s21::DiferenttCalc::GetMountlyPay(int mounth) {
  double everymonth = all_sum_/static_cast<double>(term_);
  return everymonth + (all_sum_ - (static_cast<double>(mounth) * everymonth)) * ( percent_ / 100) * 31 / 365;
  ;
}

double s21::DiferenttCalc::GetAllPay() { return all_pay_; }

double s21::DiferenttCalc::GetOverPay() { return overpay_; }

void s21::DiferenttCalc::Calculation() {
  for (int i = 0; i <= term_; ++i) {
    double current_mounth =  GetMountlyPay(i);
    all_pay_ += current_mounth;
  }

  overpay_ = all_pay_ - all_sum_;
}
