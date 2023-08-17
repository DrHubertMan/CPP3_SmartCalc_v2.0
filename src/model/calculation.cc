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
      PlusCase(calc_stack);
    }
  }
};

void Calculation::PlusCase(std::stack<double> calc_stack) noexcept {
  double val_1 = calc_stack.top();
  calc_stack.pop();
  double val_2 = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(val_2 + val_1);
}

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

bool Calculation::IsMinus(std::string token) noexcept {
  return (token[0] == '-');
};

void Calculation::MinusCase(std::stack<double> calc_stack) noexcept{};

bool Calculation::IsMul(std::string token) noexcept {
  return (token[0] == '*');
};

void Calculation::MulCase(std::stack<double> calc_stack) noexcept {};

bool Calculation::IsDiv(std::string token) noexcept {
  return (token[0] == '/');
};
void Calculation::DivCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsExp(std::string token) noexcept {
  return (token[0] == '^');
};
void Calculation::ExpCase(std::stack<double> calc_stack) noexcept {};

bool Calculation::IsMod(std::string token) noexcept {
  return (token[0] == '%');
};

void Calculation::ModCase(std::stack<double> calc_stack) noexcept {};

bool Calculation::IsFunciotn(std::string token) noexcept {};
void Calculation::FuncCase(std::stack<double> calc_stack, std::string token) noexcept {};
bool Calculation::IsSin(std::string token) noexcept {};
void Calculation::SinCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsCos(std::string token) noexcept {};
void Calculation::CosCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsTan(std::string token) noexcept {};
void Calculation::TanCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsAsin(std::string token) noexcept {};
void Calculation::AsinCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsAcos(std::string token) noexcept {};
void Calculation::AcosCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsAtan(std::string token) noexcept {};
void Calculation::AtanCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsSqrt(std::string token) noexcept {};
void Calculation::SqrtCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsLn(std::string token) noexcept {};
void Calculation::LnCase(std::stack<double> calc_stack) noexcept {};
bool Calculation::IsLog(std::string token) noexcept {};
void Calculation::LogCase(std::stack<double> calc_stack) noexcept {};