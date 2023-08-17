#include "expressionConverter.h"

std::list<std::string> s21::ExpressionConverter::GetOut() {
  return output_string_;
}

s21::ExpressionConverter::ExpressionConverter(std::list<std::string> input)
    : input_string_(input) {
  Conversion();
};

s21::ExpressionConverter::ExpressionConverter(const ExpressionConverter &e)
    : input_string_(e.input_string_), output_string_(e.output_string_) {
  Conversion();
};

s21::ExpressionConverter &
s21::ExpressionConverter::operator=(const ExpressionConverter &e) {
  if (this != &e) {
    ExpressionConverter copy{e};
    swap(copy);
  }
  return *this;
};

s21::ExpressionConverter::ExpressionConverter(ExpressionConverter &&e)
    : ExpressionConverter() {
  swap(e);
  Conversion();
};

s21::ExpressionConverter &s21::ExpressionConverter::operator=(ExpressionConverter &&e) {
  if (this != &e) {
    ExpressionConverter moved{std::move(e)};
    swap(moved);
  }
  return *this;
};

void s21::ExpressionConverter::swap(ExpressionConverter &other) noexcept {
  std::swap(input_string_, other.input_string_);
  std::swap(output_string_, other.output_string_);
};

void s21::ExpressionConverter::Conversion() noexcept {
  std::stack<std::string> transformator;
  while (!input_string_.empty()) {
    Element token(input_string_.front());

    input_string_.pop_front();
    if (token.IsNumber()) {
      output_string_.push_back(token.GetData());
    } else if (token.IsFunciotn()) {

      transformator.push(token.GetData());
    } else if (token.IsSeparator()) {
      PullOverStack(transformator);
    } else if (token.IsOperator()) {
      AddOperatorInStack(transformator, symbol);
      transformator.push(symbol);
    } else if (IsOpenBracket(symbol)) {
      transformator.push(symbol);
    } else if (IsClosedBracket(symbol)) {
      AddInOut(transformator);
    }
  }
  EmptyTheStack(transformator);
};

void s21::ExpressionConverter::PullOverStack(
    std::stack<std::string> &transformator) noexcept {
  while (!IsOpenBracket(transformator.top())) {

    output_string_.push_back(transformator.top());
    transformator.pop();
  }
}

void s21::ExpressionConverter::EmptyTheStack(
    std::stack<std::string> &transformator) noexcept {

  while (!transformator.empty()) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
}

void s21::ExpressionConverter::AddInOut(
    std::stack<std::string> &transformator) noexcept {

  while (!IsOpenBracket(transformator.top())) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
  transformator.pop();
  if (IsFunction(transformator.top())) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
};

bool s21::ExpressionConverter::IsClosedBracket(std::string val) noexcept {
  return val[0] == 41;
};

bool s21::ExpressionConverter::IsOpenBracket(std::string val) noexcept {
  return val[0] == 40;
};

void s21::ExpressionConverter::AddOperatorInStack(
    std::stack<std::string> &transformator,
    std::string operator_input) noexcept {
  while (!transformator.empty() && IsOperator(transformator.top()) &&
         OperatorCheck(transformator.top(), operator_input)) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
};

bool s21::ExpressionConverter::OperatorCheck(std::string one,
                                        std::string two) noexcept {
  return (PriorityComparsion(one, two) ||
          (IsEqualPriority(one, two)) && IsLeftPriority(two));
};

bool s21::ExpressionConverter::IsLeftPriority(std::string oper) noexcept {
  bool result = false;
  if (oper[0] != 94) {
    result = true;
  }
  return result;
};

bool s21::ExpressionConverter::IsEqualPriority(std::string one,
                                          std::string two) noexcept {
  return (GetPriority(one) == GetPriority(two));
};

bool s21::ExpressionConverter::PriorityComparsion(std::string one,
                                             std::string two) noexcept {
  return (GetPriority(one) > GetPriority(two));
};

int s21::ExpressionConverter::GetPriority(std::string operator_input) noexcept {
  int result = 0;
  if (operator_input[0] == 94) {
    result = 2;
  } else if (operator_input[0] == 42 || operator_input[0] == 47) {
    result = 1;
  }
  return result;
};

bool s21::ExpressionConverter::IsOperand(std::string val) noexcept {
  return (val[0] > 47 && val[0] < 58);
};

bool s21::ExpressionConverter::IsOperator(std::string val) noexcept {
  return ((val[0] > 41 && val[0] < 48 && val[0] != 44 && val[0] != 46) ||
          (val[0] == 94));
};

void s21::ExpressionConverter::AddToExpression(std::string val) noexcept {
  input_string_.push_back(val);
};

bool s21::ExpressionConverter::IsFunction(std::string val) noexcept {
  return (val == "cos" || val == "sin" || val == "tan" || val == "acos" ||
          val == "asin" || val == "atan" || val == "sqrt" || val == "ln" ||
          val == "log");
};

bool s21::ExpressionConverter::IsSeparator(std::string val) noexcept {
  return (val[0] == 44);
};