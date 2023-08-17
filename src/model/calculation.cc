#include "calculation.h"

using s21::Calculation;

Calculation::Calculation(std::vector<std::string> input) : input_string_(input), value_(0) {
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
}

void Calculation::Calc() noexcept {};
void Calculation::swap(Calculation &other) {
  std::swap(input_string_, other.input_string_);
  std::swap(value_, other.value_);
};