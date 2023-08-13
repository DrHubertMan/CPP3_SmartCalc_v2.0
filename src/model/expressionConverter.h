#ifndef CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H
#define CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H

#include <list>
#include <stack>
#include <string>

namespace s21 {
class expressionConverter {
public:
  expressionConverter() = default;
  ~expressionConverter() = default;

  explicit expressionConverter(std::list<char> input);

  expressionConverter(const expressionConverter &e);
  expressionConverter &operator=(const expressionConverter &e);

  expressionConverter(expressionConverter &&e);
  expressionConverter &operator=(expressionConverter &&e);

  void Convert();
  void AddToExpression(char val) noexcept;

private:
  std::list<char> input_string_;
  std::string output_string_;

  void swap(expressionConverter &other) noexcept;
  bool IsOperand(char val) noexcept;
  bool IsOperator(char val) noexcept;
  void AddOperatorInStack(std::stack<char> &transformatior, char operator_input) noexcept;
  bool PriorityComparsion(char operator_one, char operator_two) noexcept;
  int GetPriority(char operator_input) noexcept;
  bool IsEqualPriority(char one, char two) noexcept;
  bool OperatorCheck(char one, char two) noexcept;
  bool IsLeftPriority(char oper) noexcept;
  bool IsOpenBracket(char val) noexcept;
};
}; // namespace s21

#endif