#ifndef CPP3_SMARTCALC_V2_1_CALCULATION_H
#define CPP3_SMARTCALC_V2_1_CALCULATION_H

#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <string>

#include "element.h"

namespace s21 {
/// @brief Класс служащий для вычисления выражения записаного в постфиксной
/// нотации
class Calculation {
 public:
  /// @brief Конструктор по умолчанию
  Calculation() = default;
  ~Calculation() = default;

  /// @brief Конструктор класса принимающий на вход список токенов для
  /// вычисления
  /// @param input список токенов для вычисления типа std::string
  explicit Calculation(std::list<std::string> input);

  Calculation(std::list<std::string> input, double x_var);

  // /// @brief Конструктор копирования
  // Calculation(const Calculation &c);
  // /// @brief Перегрузка оператора присваивания копированием
  // Calculation &operator=(const Calculation &c);

  // /// @brief Конструктор присваивания
  // Calculation(Calculation &&c);
  // /// @brief  Перегрузка оператора присваивания перемещением
  // Calculation &operator=(Calculation &&c);

  /// @brief Функция возвращающая вычисленное значение
  double GetValue() const noexcept;

 private:
  std::list<std::string> input_string_;
  /// @brief Список токенов выражения для вычисления
  /// @brief Вычисленное значение
  double value_;

 private:
  /// @brief Вычисление выражения
  void Calc() noexcept;
  /// @brief Функция осуществляет обмен значениями между экземплярами класса
  // void swap(Calculation &other);

  /// @brief Функция добавляющая оператор в стэк
  /// @param token Токен хранящий в себе оператор
  void AddOperandInStack(Element &token,
                         std::stack<double> &calc_stack) noexcept;

  /// @brief Функция сложения
  void PlusCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычитания
  void MinusCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция умножения
  void MulCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция деления
  void DivCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция возведения в степень
  void ExpCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисляющая остаток от деления
  void ModCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция отвещающая за вычисление траганометрических функция
  void FuncCase(std::stack<double> &calc_stack, Element &token) noexcept;
  /// @brief Функция вычисления синуса
  void SinCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисления косинуса
  void CosCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисления тангенса
  void TanCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисления арксинуса
  void AsinCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисления арккосинуса
  void AcosCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисления арктангенса
  void AtanCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисления корня
  void SqrtCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисления натурального логарифма
  void LnCase(std::stack<double> &calc_stack) noexcept;
  /// @brief Функция вычисления логарифма
  void LogCase(std::stack<double> &calc_stack) noexcept;
};
};  // namespace s21
#endif