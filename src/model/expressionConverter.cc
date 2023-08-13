#include "expressionConverter.h"

using s21::expressionConverter;

expressionConverter::expressionConverter(std::list<char> input)
    : input_string_(input){};

expressionConverter::expressionConverter(const expressionConverter &e)
    : input_string_(e.input_string_), output_string_(e.output_string_){};

expressionConverter &
expressionConverter::operator=(const expressionConverter &e) {
  if (this != &e) {
    expressionConverter copy{e};
    swap(copy);
  }
  return *this;
};

expressionConverter::expressionConverter(expressionConverter &&e)
    : expressionConverter() {
  swap(e);
};

expressionConverter &expressionConverter::operator=(expressionConverter &&e) {
  if (this != &e) {
    expressionConverter moved{std::move(e)};
    swap(moved);
  }
  return *this;
};

void expressionConverter::swap(expressionConverter &other) noexcept {
  std::swap(input_string_, other.input_string_);
  std::swap(output_string_, other.output_string_);
};

void expressionConverter::Convert() noexcept {
  std::stack<char> transformator;
  while (!input_string_.empty()) {
    char char_in_string = input_string_.front();

    if (IsOperand(char_in_string)) {
      output_string_ += char_in_string;
      input_string_.pop_front();
    } else if (IsOperator(char_in_string)) {
      AddOperatorInStack(transformator, char_in_string);
    }
  }
};

void expressionConverter::AddOperatorInStack(std::stack<char> &transformator,
                                             char operator_input) noexcept {
  while (!transformator.empty() && OperatorCheck(transformator.top(), operator_input)) {
    output_string_ += operator_input;
  }
};

bool expressionConverter::OperatorCheck(char one, char two) noexcept {
  return (PriorityComparsion(one, two) ||
          (IsEqualPriority(one, two)) && IsLeftPriority(two));
};

bool expressionConverter::IsLeftPriority(char oper) noexcept {
  bool result = false;
  if (oper != 94) {
    result = true;
  }
  return result;
};

bool expressionConverter::IsEqualPriority(char one, char two) noexcept {
  return (GetPriority(one) == GetPriority(two));
};

bool expressionConverter::PriorityComparsion(char one,
                                             char two) noexcept {
  return (GetPriority(one) > GetPriority(two));
};

int expressionConverter::GetPriority(char operator_input) {
  int result = 0;
  if (operator_input == 94) {
    result = 2;
  } else if (operator_input == 42 || operator_input == 47) {
    result = 1;
  }
  return result;
};

bool expressionConverter::IsOperand(char val) {
  return (val > 47 && val < 58);
};

bool expressionConverter::IsOperator(char val) noexcept {
  return ((val > 41 && val < 48 && val != 44 && val != 46) || (val == 94));
};

void expressionConverter::AddToExpression(char val) noexcept {
  input_string_.push_back(val);
};