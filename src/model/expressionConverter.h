#ifndef CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H
#define CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H

#include <list>
#include <vector>
#include <stack>
#include <string>
// debug include:
#include <iostream>


namespace s21 {
class expressionConverter {
public:
  expressionConverter() = default;
  ~expressionConverter() = default;

  explicit expressionConverter(std::list<std::string> input);

  expressionConverter(const expressionConverter &e);
  expressionConverter &operator=(const expressionConverter &e);

  expressionConverter(expressionConverter &&e);
  expressionConverter &operator=(expressionConverter &&e);

  void Conversion() noexcept;
  void AddToExpression(std::string val) noexcept;

  // debug function
  std::vector<std::string> GetOut();

private:
  std::list<std::string> input_string_;
  std::vector<std::string> output_string_;

private:
  void swap(expressionConverter &other) noexcept;
  void AddOperatorInStack(std::stack<std::string> &transformator, std::string operator_input) noexcept;
  bool PriorityComparsion(std::string operator_one, std::string operator_two) noexcept;
  int GetPriority(std::string operator_input) noexcept;
  bool OperatorCheck(std::string one, std::string two) noexcept;
  void AddInOut(std::stack<std::string> &transformator) noexcept;
  void EmptyTheStack(std::stack<std::string> &transformator) noexcept;
  void PullOverStack(std::stack<std::string> &transformator) noexcept;

  bool IsOperand(std::string val) noexcept;
  bool IsOperator(std::string val) noexcept;
  bool IsEqualPriority(std::string one, std::string two) noexcept;
  bool IsLeftPriority(std::string oper) noexcept;
  bool IsOpenBracket(std::string val) noexcept;
  bool IsClosedBracket(std::string val) noexcept;
  bool IsFunction(std::string val) noexcept;
  bool IsSeparator(std::string val) noexcept;
};
}; // namespace s21

#endif