#ifndef CPP3_SMARTCALC_V2_1_MODEL_DEPOSIT_H
#define CPP3_SMARTCALC_V2_1_MODEL_DEPOSIT_H

#include <cmath>
#include <map>

namespace s21 {
/// @brief Класс перечислений переодичности выплат
enum class Periodicity { kMonthly = 0, kQuarterly, kYerly };
/// @brief Класс вычилсяющий основные параметры депозитного вклада
class DepositCalc {
 public:
  /// @brief Конструктор по умолчанию, в нем все поля заполняются нулевыми
  /// значениями
  DepositCalc();
  /// @brief Конструктор класса с входными параметрами
  /// @param p Сумма влкада
  /// @param t Срок в месяцах
  /// @param pr Годовая процентная ставка
  /// @param tax Налог на проценты
  /// @param freq Периодичность выплат
  /// @param cap Капитализация
  DepositCalc(double p, int t, double pr, double tax, Periodicity freq,
              bool cap);

  /// @brief Функция возвращает значение начисленных процентов
  double CalculateInterest();
  /// @brief Функция возвращает значение начисленных налогов
  double CalculateTax();
  /// @brief Функция возвращает итоговую сумму на счете
  double CalculateFinalAmount();

  /// @brief Функция добавляет пополнение вклада
  /// @param month  Месяц пополнения
  /// @param amount Сумма пополнения
  void AddDeposit(int month, double amount) noexcept;
  /// @brief Функция добавляет снятие с вклада
  /// @param month Месяц снятия
  /// @param amount Месяц пополнения
  void AddWithdrawal(int month, double amount) noexcept;

  /// @brief Устанавливает сумму вклада
  void SetPrincipal(double p) noexcept;
  /// @brief Устанавливает срок вклада
  void SetTerm(int t) noexcept;
  /// @brief Устанавливает годовую процентную ставку вклада
  void SetPercentRate(double pr) noexcept;
  /// @brief Устанавливает налог на проценты
  void SetTaxRate(double tr) noexcept;
  /// @brief  Устанавливает периодичность выплат
  void SetPeriodicity(int pf) noexcept;
  /// @brief Устанавливает капитализацию
  void SetCaptalization(bool c) noexcept;

 private:
  /// @brief Хранит начальную сумму вклада
  double principal_;
  /// @brief Срок вклада в месяцах
  int term_;
  /// @brief Годовая процентная ставка
  double percent_rate_;
  /// @brief Налог на проценты
  double tax_rate_;
  /// @brief Периодичность выплат
  Periodicity payout_frequency_;
  /// @brief Капитализация
  bool capitalization_;
  /// @brief Пополнения
  std::map<int, double> deposits_;
  /// @brief Снятия
  std::map<int, double> withdrawals_;
};
};  // namespace s21

#endif  // CPP3_SMARTCALC_V2_1_MODEL_DEPOSIT_H
