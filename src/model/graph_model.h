#ifndef CPP3_SMARTCALC_V2_1_MODEL_GRAPH_MODEL_H
#define CPP3_SMARTCALC_V2_1_MODEL_GRAPH_MODEL_H

#include <list>
#include <string>
#include <vector>

#include "calculation.h"

namespace s21 {
/// @brief  Класс служит для создания векторов определения и значения графика
/// функции
class GraphModel {
 public:
  /// @brief Конструктор принимает область определения и список токенов функции
  /// в постфиксном формате
  GraphModel(double min, double max, std::list<std::string> input_line);
  /// @brief Метод доступа
  /// @return Вектор определения графика функции
  std::vector<double> GetX() const noexcept;
  /// @brief Метод доступа
  /// @return Вектор значения графика функции
  std::vector<double> GetY() const noexcept;

 private:
  /// @brief Метод производит расчет определения и значения функции
  void Calculate() noexcept;

 private:
  /// @brief Минимальное определение функции
  double x_min_;
  /// @brief Максимальное определение функции
  double x_max_;
  /// @brief Список токенов функции в постфиксной записи
  std::list<std::string> postfix_expression_;
  /// @brief Вектор определений
  std::vector<double> x_coordinate_;
  /// @brief Вектор значений
  std::vector<double> y_coordinate;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_1_MODEL_GRAPH_MODEL_H