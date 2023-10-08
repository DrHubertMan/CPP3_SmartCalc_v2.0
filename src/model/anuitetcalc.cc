#include "anuitetcalc.h"

s21::AnuitetCalc::AnuitetCalc()
    : all_sum_(0), percent_(0), term_(0), mountly_pay_(0), all_pay_(0){};

s21::AnuitetCalc::AnuitetCalc(double all_sum, double percent, int term)
    : all_sum_(all_sum),
      percent_(percent / 100),
      term_(term),
      mountly_pay_(0),
      all_pay_(0),
      overpay_(0) {
  Calculation();
}

double s21::AnuitetCalc::GetMountlyPay() { return mountly_pay_; }

double s21::AnuitetCalc::GetAllPay() { return all_pay_; }

double s21::AnuitetCalc::GetOverPay() { return overpay_; }

void s21::AnuitetCalc::Calculation() {
  double mountly_s = percent_ / 12;
  mountly_pay_ = all_sum_ * (mountly_s * pow(1 + mountly_s, term_) /
                             (pow(1 + mountly_s, term_) - 1));

  all_pay_ = mountly_pay_ * term_;

  overpay_ = all_pay_ - all_sum_;
}
