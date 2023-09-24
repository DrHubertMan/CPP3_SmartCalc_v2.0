#include "deposit.h"

s21::DepositCalc::DepositCalc()
    : principal_(0),
      term_(0),
      percent_rate_(0),
      tax_rate_(0),
      payout_frequency_(Periodicity::kMonthly),
      capitalization_(0) {}

s21::DepositCalc::DepositCalc(double p, int t, double pr, double tax,
                              Periodicity freq, bool cap)
    : principal_(p),
      term_(t),
      percent_rate_(pr / 100),
      tax_rate_(tax),
      payout_frequency_(freq),
      capitalization_(cap) {}

void s21::DepositCalc::AddDeposit(int month, double amount) noexcept {
  deposits_[month] += amount;
}

void s21::DepositCalc::AddWithdrawal(int month, double amount) noexcept {
  withdrawals_[month] += amount;
}

void s21::DepositCalc::SetPrincipal(double p) noexcept { principal_ = p; }

void s21::DepositCalc::SetTerm(int t) noexcept { term_ = t; }

void s21::DepositCalc::SetPercentRate(double pr) noexcept {
  percent_rate_ = pr;
}

void s21::DepositCalc::SetTaxRate(double tr) noexcept { tax_rate_ = tr; }

void s21::DepositCalc::SetPeriodicity(int pf) noexcept {
  if (pf == 0) {
    payout_frequency_ = Periodicity::kMonthly;
  } else if (pf == 1) {
    payout_frequency_ = Periodicity::kQuarterly;
  } else {
    payout_frequency_ = Periodicity::kYerly;
  }
}

void s21::DepositCalc::SetCaptalization(bool c) noexcept {
  capitalization_ = c;
}

double s21::DepositCalc::CalculateInterest() {
  double total_interest = 0.0;
  double inital_principal = principal_;

  for (int i = 1; i <= term_; ++i) {
    double monthly_rate = percent_rate_ / 12.0;

    if (deposits_.count(i)) {
      principal_ += deposits_[i];
    }

    if (withdrawals_.count(i)) {
      principal_ -= withdrawals_[i];
    }

    if (capitalization_) {
      double interest_earned = principal_ * monthly_rate;
      principal_ += interest_earned;
      total_interest += interest_earned;
    } else {
      total_interest += inital_principal * monthly_rate;
    }

    if (payout_frequency_ == Periodicity::kMonthly ||
        (payout_frequency_ == Periodicity::kQuarterly && (i % 3) == 0) ||
        (payout_frequency_ == Periodicity::kYerly && (i % 12) == 0)) {
      double tax = total_interest * tax_rate_;
      principal_ += total_interest - tax;
      total_interest = 0.0;
    }
  }
  return total_interest;
}

double s21::DepositCalc::CalculateTax() {
  double total_interest = CalculateInterest();
  return total_interest * tax_rate_;
}

double s21::DepositCalc::CalculateFinalAmount() {
  double total_interest = CalculateInterest();
  return principal_ + total_interest - CalculateTax();
}
