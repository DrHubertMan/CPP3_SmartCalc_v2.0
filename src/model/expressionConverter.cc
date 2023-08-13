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
      if (IsOperand()){

      }
    }
}

bool expressionConverter::IsOperand(char val) {
  return (val > 47 && val < 58);
}

void expressionConverter::AddToExpression(char val) noexcept { input_string_.push_back(val); };