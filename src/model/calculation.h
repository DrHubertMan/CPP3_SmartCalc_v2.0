#ifndef CPP3_SMARTCALC_V2_1_CALCULATION_H
#define CPP3_SMARTCALC_V2_1_CALCULATION_H

#include <string>
#include <list>
#include <stack>

namespace s21 {
class Calculation {
  public:
  Calculation() = default;
  ~Calculation() = default;

  explicit Calculation(std::list<std::string> input);

  Calculation(const Calculation &c);
  Calculation &operator=(const Calculation &c);

  Calculation(Calculation &&c);
  Calculation &operator=(Calculation &&c);

  private:
  std::list<std::string> input_string_;
  double value_;

  private:
  void Calc() noexcept;
  void swap(Calculation &other);
  bool IsOperand(std::string token) noexcept;
  void AddOperandInStack(std::string token, std::stack<double> calc_stack) noexcept;
  bool IsPlus(std::string token) noexcept;
};
};
#endif