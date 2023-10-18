#include "calculation.h"

s21::Calculation::Calculation(std::list<std::string> input)
    : input_string_(input), value_(0) {
  Calc();
};

s21::Calculation::Calculation(std::list<std::string> input, double x_var)
    : input_string_(input) {
  for (auto &item : input_string_) {
    if (item == "x") {
      item = std::to_string(x_var);
    }
  }
  Calc();
}

// s21::Calculation::Calculation(const Calculation &c)
//     : input_string_(c.input_string_), value_(c.value_){};

// s21::Calculation &s21::Calculation::operator=(const Calculation &c) {
//   if (this != &c) {
//     Calculation copy{c};
//     swap(copy);
//   }
//   return *this;
// };

// s21::Calculation::Calculation(Calculation &&c) : Calculation() { swap(c); };

// s21::Calculation &s21::Calculation::operator=(Calculation &&c) {
//   if (this != &c) {
//     Calculation moved{std::move(c)};
//     swap(moved);
//   }
//   return *this;
// };

double s21::Calculation::GetValue() const noexcept { return value_; };

// void s21::Calculation::swap(Calculation &other) {
//   std::swap(input_string_, other.input_string_);
//   std::swap(value_, other.value_);
// };

void s21::Calculation::Calc() noexcept {
  std::stack<double> calc_stack;
  calc_stack.push(value_);
  while (!input_string_.empty()) {
    Element token(input_string_.front());
    input_string_.pop_front();
    if (token.IsNumber()) {
      AddOperandInStack(token, calc_stack);
    } else if (token.IsPlus()) {
      PlusCase(calc_stack);
    } else if (token.IsMinus()) {
      MinusCase(calc_stack);
    } else if (token.IsMul()) {
      MulCase(calc_stack);
    } else if (token.IsDiv()) {
      DivCase(calc_stack);
    } else if (token.IsExp()) {
      ExpCase(calc_stack);
    } else if (token.IsMod()) {
      ModCase(calc_stack);
    } else if (token.IsFunciotn()) {
      FuncCase(calc_stack, token);
    }
  }
  value_ = calc_stack.top();
};

void s21::Calculation::AddOperandInStack(
    Element &token, std::stack<double> &calc_stack) noexcept {
  double num = std::stod(token.GetData());
  calc_stack.push(num);
};

void s21::Calculation::PlusCase(std::stack<double> &calc_stack) noexcept {
  double val_1 = calc_stack.top();
  calc_stack.pop();
  double val_2 = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(val_2 + val_1);
}

void s21::Calculation::MinusCase(std::stack<double> &calc_stack) noexcept {
  double val_1 = calc_stack.top();
  calc_stack.pop();
  double val_2 = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(val_2 - val_1);
};

void s21::Calculation::MulCase(std::stack<double> &calc_stack) noexcept {
  double val_1 = calc_stack.top();
  calc_stack.pop();
  double val_2 = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(val_2 * val_1);
};

void s21::Calculation::DivCase(std::stack<double> &calc_stack) noexcept {
  double val_1 = calc_stack.top();
  calc_stack.pop();
  double val_2 = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(val_2 / val_1);
};

void s21::Calculation::ExpCase(std::stack<double> &calc_stack) noexcept {
  double val_1 = calc_stack.top();
  calc_stack.pop();
  double val_2 = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(pow(val_2, val_1));
};

void s21::Calculation::ModCase(std::stack<double> &calc_stack) noexcept {
  double val_1 = calc_stack.top();
  calc_stack.pop();
  double val_2 = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(static_cast<int>(val_2) % static_cast<int>(val_1));
};

void s21::Calculation::FuncCase(std::stack<double> &calc_stack,
                                Element &token) noexcept {
  if (token.IsSin()) {
    SinCase(calc_stack);
  } else if (token.IsCos()) {
    CosCase(calc_stack);
  } else if (token.IsTan()) {
    TanCase(calc_stack);
  } else if (token.IsAsin()) {
    AsinCase(calc_stack);
  } else if (token.IsAcos()) {
    AcosCase(calc_stack);
  } else if (token.IsAtan()) {
    AtanCase(calc_stack);
  } else if (token.IsSqrt()) {
    SqrtCase(calc_stack);
  } else if (token.IsLn()) {
    LnCase(calc_stack);
  } else if (token.IsLog()) {
    LogCase(calc_stack);
  }
};

void s21::Calculation::SinCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(sin(val /** M_PI / 180*/));
};

void s21::Calculation::CosCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(cos(val /** M_PI / 180*/));
};

void s21::Calculation::TanCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(tan(val /** M_PI / 180*/));
};

void s21::Calculation::AsinCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(asin(val /** M_PI / 180*/));
};

void s21::Calculation::AcosCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(acos(val /** M_PI / 180*/));
};

void s21::Calculation::AtanCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(atan(val /** M_PI / 180*/));
};

void s21::Calculation::SqrtCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(sqrt(val));
};

void s21::Calculation::LnCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(log(val));
};

void s21::Calculation::LogCase(std::stack<double> &calc_stack) noexcept {
  double val = calc_stack.top();
  calc_stack.pop();
  calc_stack.push(log10(val));
};
