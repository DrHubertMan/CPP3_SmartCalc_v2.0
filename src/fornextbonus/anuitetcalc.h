#ifndef CPP3_SMARTCALC_V2_1_MODEL_ANUITETCALC_H
#define CPP3_SMARTCALC_V2_1_MODEL_ANUITETCALC_H

#include <cmath>
#include <iostream>
/// @brief Пространство имен s21 в котором находятся все классы модели
namespace s21 {
/// @brief Класс вычисляющий основный параметры ануитетного кредита
class AnuitetCalc {
 public:
  /// @brief Конструктор класса по умолчанию
  AnuitetCalc();

  /// @brief Конструктор класса с параметрами
  /// @param all_sum Сумма кредита
  /// @param percent Годовая ставка
  /// @param term Срок кредитования
  AnuitetCalc(double all_sum, double percent, int term);

  /// @brief  Функция возвращающая месячный платеж
  double GetMountlyPay();
  /// @brief  Функция возвращающая полную сумму выплат
  double GetAllPay();
  /// @brief Функция возвращающая сумму переплат
  double GetOverPay();

 private:
  /// @brief Производит расчет кредитных параметров
  /// \details Вычисляется месячный платеж, полная сумма выплат и сумма переплат
  void Calculation();

 private:
  /// @brief Сумма кредита 
  double all_sum_;
  /// @brief Годовая ставка
  double percent_;
  /// @brief Срок кредитования в месяцах
  int term_;

  /// @brief Ежемесячный платеж
  double mountly_pay_;
  /// @brief Полная сумма выплат
  double all_pay_;
  /// @brief Переплаты
  double overpay_;
};
};  // namespace s21

#endif  //  CPP3_SMARTCALC_V2_1_MODEL_ANUITETCALC_H