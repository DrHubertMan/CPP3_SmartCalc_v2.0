#include "expressionConverter.h"

using s21::ExpressionConverter;

std::list<std::string> ExpressionConverter::GetOut() { return output_string_; }

ExpressionConverter::ExpressionConverter(std::list<std::string> input)
    : input_string_(input) { Conversion(); };

ExpressionConverter::ExpressionConverter(const ExpressionConverter &e)
    : input_string_(e.input_string_), output_string_(e.output_string_){ Conversion(); };

ExpressionConverter &
ExpressionConverter::operator=(const ExpressionConverter &e) {
  if (this != &e) {
    ExpressionConverter copy{e};
    swap(copy);
  }
  return *this;
};

ExpressionConverter::ExpressionConverter(ExpressionConverter &&e)
    : ExpressionConverter() {
  swap(e);
  Conversion();
};

ExpressionConverter &ExpressionConverter::operator=(ExpressionConverter &&e) {
  if (this != &e) {
    ExpressionConverter moved{std::move(e)};
    swap(moved);
  }
  return *this;
};

void ExpressionConverter::swap(ExpressionConverter &other) noexcept {
  std::swap(input_string_, other.input_string_);
  std::swap(output_string_, other.output_string_);
};

void ExpressionConverter::Conversion() noexcept {
  std::stack<std::string> transformator;
  while (!input_string_.empty()) {
    std::string symbol = input_string_.front();

    input_string_.pop_front();
    if (IsOperand(symbol)) {
      
      output_string_.push_back(symbol);
    } else if (IsFunction(symbol)) {
      
      transformator.push(symbol);
    } else if (IsSeparator(symbol)) {
      
      PullOverStack(transformator);
    } else if (IsOperator(symbol)) {
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

void ExpressionConverter::PullOverStack(std::stack<std::string> &transformator) noexcept {
  while (!IsOpenBracket(transformator.top())) {
    
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
}

void ExpressionConverter::EmptyTheStack(
    std::stack<std::string> &transformator) noexcept {

  while (!transformator.empty()) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
}

void ExpressionConverter::AddInOut(
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

bool ExpressionConverter::IsClosedBracket(std::string val) noexcept {
  return val[0] == 41;
};

bool ExpressionConverter::IsOpenBracket(std::string val) noexcept {
  return val[0] == 40;
};

void ExpressionConverter::AddOperatorInStack(std::stack<std::string> &transformator,
                                             std::string operator_input) noexcept {
  while (!transformator.empty() && IsOperator(transformator.top()) &&
         OperatorCheck(transformator.top(), operator_input)) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
};

bool ExpressionConverter::OperatorCheck(std::string one, std::string two) noexcept {
  return (PriorityComparsion(one, two) ||
          (IsEqualPriority(one, two)) && IsLeftPriority(two));
};

bool ExpressionConverter::IsLeftPriority(std::string oper) noexcept {
  bool result = false;
  if (oper[0] != 94) {
    result = true;
  }
  return result;
};

bool ExpressionConverter::IsEqualPriority(std::string one, std::string two) noexcept {
  return (GetPriority(one) == GetPriority(two));
};

bool ExpressionConverter::PriorityComparsion(std::string one, std::string two) noexcept {
  return (GetPriority(one) > GetPriority(two));
};

int ExpressionConverter::GetPriority(std::string operator_input) noexcept {
  int result = 0;
  if (operator_input[0] == 94) {
    result = 2;
  } else if (operator_input[0] == 42 || operator_input[0] == 47) {
    result = 1;
  }
  return result;
};

bool ExpressionConverter::IsOperand(std::string val) noexcept {
  return (val[0] > 47 && val[0] < 58);
};

bool ExpressionConverter::IsOperator(std::string val) noexcept {
  return ((val[0] > 41 && val[0] < 48 && val[0] != 44 && val[0] != 46) || (val[0] == 94));
};

void ExpressionConverter::AddToExpression(std::string val) noexcept {
  input_string_.push_back(val);
};

bool ExpressionConverter::IsFunction(std::string val) noexcept {
  return (val == "cos" || val == "sin" || val == "tan" || val == "acos" || val == "asin" || val == "atan" || val == "sqrt" || val == "ln" || val == "log");
};

bool ExpressionConverter::IsSeparator(std::string val) noexcept {
  return (val[0] == 44);
};