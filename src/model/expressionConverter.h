#ifndef CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H
#define CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H

#include <iostream>
#include <list>
#include <stack>
#include <string>

#include "element.h"

namespace s21 {
/// @brief  Класс служит для преобразования инфиксного выражения в постфиксное
class ExpressionConverter {
 public:
  ExpressionConverter() = default;
  ~ExpressionConverter() = default;

  /// @brief Конструктор класса принимающий на вход инфиксную строку целиком
  /// @param input Выражение в инфиксной записи
  explicit ExpressionConverter(std::list<std::string> input);

  // ExpressionConverter(const ExpressionConverter &e);
  // ExpressionConverter &operator=(const ExpressionConverter &e);

  // ExpressionConverter(ExpressionConverter &&e);
  // ExpressionConverter &operator=(ExpressionConverter &&e);

  /// @brief Метод доступа
  /// @return Возвращает преобразованное в постфиксную запись выражение
  std::list<std::string> GetOut();

  /// @brief Метод доступа, добавляет токен в строку для конвертации
  void AddTokenInModel(std::string token) noexcept;
  /// @brief Служит для очистки списков хранящих инфиксное и постфиксное
  /// выражения
  void Clear() noexcept;

  /// @brief Метод преобразующий инфиксное выражение в постфиксное
  void Conversion();

 private:
  /// @brief Список хранящий токены инфиксного выражения
  std::list<std::string> input_string_;
  /// @brief Список хранящий токены постфиксного выражения
  std::list<std::string> output_string_;

 private:
  // void swap(ExpressionConverter &other) noexcept;
  /// @brief Метод работающий с операторами в процессе конвертации, распределяет
  /// операторы исходя из приоритетов и асоциативности
  void AddOperatorInStack(std::stack<std::string> &transformator,
                          Element &op_one) noexcept;
  /// @brief Метод добавляющий в выходную строку токены в скобках
  void AddInOut(std::stack<std::string> &transformator);
  /// @brief Метод опустошающий стек после конвертации
  void EmptyTheStack(std::stack<std::string> &transformator);
  // void PullOverStack(std::stack<std::string> &transformator);
  /// @brief Проверка входногов выражения с одним токеном
  void Check();
  /// @brief Валидация выходного выражения
  bool Validation() const noexcept;
};
};  // namespace s21

#endif