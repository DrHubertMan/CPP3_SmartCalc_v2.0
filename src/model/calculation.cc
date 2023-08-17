#include "calculation.h"

using s21::Calculation;

Calculation::Calculation(std::list<std::string> input) : input_string_(input), value_(0) {
  Calc();
};

Calculation::Calculation(const Calculation &c) : input_string_(c.input_string_), value_(c.value_) {
  Calc();
};

Calculation& Calculation::operator=(const Calculation &c) {
  if (this != &c) {
    Calculation copy{c};
    swap(copy);
  }
  return *this;
};

Calculation::Calculation(Calculation &&c) : Calculation() {
  swap(c);
  Calc();
};

Calculation& Calculation::operator=(Calculation &&c) {
  if (this != &c) {
    Calculation moved{std::move(c)};
    swap(moved);
  }
  return *this;
};

void Calculation::swap(Calculation &other) {
  std::swap(input_string_, other.input_string_);
  std::swap(value_, other.value_);
};

void Calculation::Calc() noexcept {
  std::stack<double> calc_stack;
  calc_stack.push(value_);
  while (!input_string_.empty()) {
    std::string token = input_string_.front();
    input_string_.pop_front();
    if (IsOperand(token)) {
      AddOperandInStack(token, calc_stack);
    } else if (IsPlus(token)) {

    }
  }
};

void Calculation::AddOperandInStack(std::string token, std::stack<double> calc_stack) noexcept {
  double num = std::stod(token);
  calc_stack.push(num);
};

bool Calculation::IsPlus(std::string token) noexcept {
  return (token[0] == '+');
};

bool Calculation::IsOperand(std::string token) noexcept {
  return ((token[0] >= '0' && token[0] <= 9) || (token[0] == '-' && token[1] >= '0' && token[1] <= 9));
};