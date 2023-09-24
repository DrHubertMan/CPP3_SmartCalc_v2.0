#ifndef CPP3_SMARTCALC_V2_1_MODEL_DEPOSIT_H
#define CPP3_SMARTCALC_V2_1_MODEL_DEPOSIT_H

#include <cmath>
#include <map>

namespace s21 {
enum class Periodicity { kMonthly = 0, kQuarterly, kYerly };

class DepositCalc {
 public:
  DepositCalc();
  DepositCalc(double p, int t, double pr, double tax, Periodicity freq,
              bool cap);

  double CalculateInterest();
  double CalculateTax();
  double CalculateFinalAmount();

  void AddDeposit(int month, double amount) noexcept;
  void AddWithdrawal(int month, double amount) noexcept;

  void SetPrincipal(double p) noexcept;
  void SetTerm(int t) noexcept;
  void SetPercentRate(double pr) noexcept;
  void SetTaxRate(double tr) noexcept;
  void SetPeriodicity(int pf) noexcept;
  void SetCaptalization(bool c) noexcept;

 private:
  double principal_;
  int term_;
  double percent_rate_;
  double tax_rate_;
  Periodicity payout_frequency_;
  bool capitalization_;
  std::map<int, double> deposits_;
  std::map<int, double> withdrawals_;
};
};  // namespace s21

#endif  // CPP3_SMARTCALC_V2_1_MODEL_DEPOSIT_H
