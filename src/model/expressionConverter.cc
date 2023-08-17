#include "expressionConverter.h"

using s21::expressionConverter;

/// DEBUG FUNCTION ///////////////

std::vector<std::string> expressionConverter::GetOut() { return output_string_; }

//////////////////////////////////

expressionConverter::expressionConverter(std::list<std::string> input)
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

void expressionConverter::Conversion() noexcept {
  std::stack<std::string> transformator;
  // for (auto & item: input_string_) {
  //   std::cout << item;
  // }
  while (!input_string_.empty()) {
    std::string symbol = input_string_.front();
    
    input_string_.pop_front();
    if (IsOperand(symbol)) {
      output_string_.push_back(symbol);
    } else if (IsClosedBracket(symbol)) {
      AddInOutline(transformator);
    } else if (IsOpenBracket(symbol)) {
      transformator.push(symbol);
    } else if (IsOperator(symbol)) {
      AddOperatorInStack(transformator, symbol);
      transformator.push(symbol);
    }
  }
  EmptyTheStack(transformator);
};

void expressionConverter::EmptyTheStack(
    std::stack<std::string> &transformator) noexcept {

  while (!transformator.empty()) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
}

void expressionConverter::AddInOutline(
    std::stack<std::string> &transformator) noexcept {
  
  while (!IsOpenBracket(transformator.top())) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
  transformator.pop();
};

bool expressionConverter::IsClosedBracket(std::string val) noexcept {
  return val[0] == 41;
};

bool expressionConverter::IsOpenBracket(std::string val) noexcept {
  return val[0] == 40;
};

void expressionConverter::AddOperatorInStack(std::stack<std::string> &transformator,
                                             std::string operator_input) noexcept {
  while (!transformator.empty() &&
         OperatorCheck(transformator.top(), operator_input)) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
};

bool expressionConverter::OperatorCheck(std::string one, std::string two) noexcept {
  return (PriorityComparsion(one, two) ||
          (IsEqualPriority(one, two)) && IsLeftPriority(two));
};

bool expressionConverter::IsLeftPriority(std::string oper) noexcept {
  bool result = false;
  if (oper[0] != 94) {
    result = true;
  }
  return result;
};

bool expressionConverter::IsEqualPriority(std::string one, std::string two) noexcept {
  return (GetPriority(one) == GetPriority(two));
};

bool expressionConverter::PriorityComparsion(std::string one, std::string two) noexcept {
  return (GetPriority(one) > GetPriority(two));
};

int expressionConverter::GetPriority(std::string operator_input) noexcept {
  int result = 0;
  if (operator_input[0] == 94) {
    result = 2;
  } else if (operator_input[0] == 42 || operator_input[0] == 47) {
    result = 1;
  }
  return result;
};

bool expressionConverter::IsOperand(std::string val) noexcept {
  return (val[0] > 47 && val[0] < 58);
};

bool expressionConverter::IsOperator(std::string val) noexcept {
  return ((val[0] > 41 && val[0] < 48 && val[0] != 44 && val[0] != 46) || (val[0] == 94));
};

void expressionConverter::AddToExpression(std::string val) noexcept {
  input_string_.push_back(val);
};

bool expressionConverter::IsFunction(std::string val) noexcept {
  return (val == "cos" || val == "sin" || val == "tan" || val == "acos" || val == "asin" || val == "atan" || val == "sqrt" || val == "ln" || val == "log");
};