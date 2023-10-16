#ifndef CPP3_SMARTCALC_V2_1_MODEL_DIFERENTCALC_H
#define CPP3_SMARTCALC_V2_1_MODEL_DIFERENTCALC_H

#include <cmath>
#include <iostream>

namespace s21 {
/// @brief Класс для расчета параметров дифференцированного кредита
class DiferenttCalc {
 public:
  DiferenttCalc();
  /// @brief Конструктор класса с входными параметрами
  /// @param all_sum Общая сумма займа
  /// @param percent Годовая процентная ставка
  /// @param term Срок в месяцах
  DiferenttCalc(double all_sum, double percent, int term);

  /// @brief Функция возвращает значение платежа в этом месяце
  /// @param mounth Месяц для которого требуется выполнить расчет
  double GetMountlyPay(int mounth);
  /// @brief Функция возвращает значение общей выплаты за кредит
  double GetAllPay();
  /// @brief Функция возвращает значение переплаты
  double GetOverPay();

 private:
  /// @brief Вычисляет параметры дифференцированного кредита
  void Calculation();

 private:
  /// @brief Сумма займа
  double all_sum_;
  /// @brief Годовая процентная ставка
  double percent_;
  /// @brief Срок кредитования в месяцах
  int term_;

  /// @brief Общая сумма выплат
  double all_pay_;
  /// @brief Переплата
  double overpay_;
};
};  // namespace s21

#endif  //  CPP3_SMARTCALC_V2_1_MODEL_ANUITETCALC_H