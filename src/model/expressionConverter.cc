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