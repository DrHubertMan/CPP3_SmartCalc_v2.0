#ifndef CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H
#define CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H

#include <list>
#include <stack>
#include <string>
#include <iostream>

#include "element.h"

namespace s21 {
class ExpressionConverter {
public:
  ExpressionConverter() = default;
  ~ExpressionConverter() = default;

  explicit ExpressionConverter(std::list<std::string> input);

  ExpressionConverter(const ExpressionConverter &e);
  ExpressionConverter &operator=(const ExpressionConverter &e);

  ExpressionConverter(ExpressionConverter &&e);
  ExpressionConverter &operator=(ExpressionConverter &&e);

  std::list<std::string> GetOut();

private:
  std::list<std::string> input_string_;
  std::list<std::string> output_string_;

private:
  void Conversion() ;
  
  void swap(ExpressionConverter &other) noexcept;
  void AddOperatorInStack(std::stack<std::string> &transformator, Element &op_one) noexcept;
  void AddInOut(std::stack<std::string> &transformator);
  void EmptyTheStack(std::stack<std::string> &transformator);
  void PullOverStack(std::stack<std::string> &transformator);

};
}; // namespace s21

#endif