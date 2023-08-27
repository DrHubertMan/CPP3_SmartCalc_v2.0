#ifndef CPP3_SMARTCALC_V2_1_CALCULATION_H
#define CPP3_SMARTCALC_V2_1_CALCULATION_H

#include <list>
#include <stack>
#include <string>
#include <cmath>

#include "element.h"

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

  double GetValue() const noexcept;
  
private:
  std::list<std::string> input_string_;
  double value_;

private:
  void Calc() noexcept;
  void swap(Calculation &other);

  void AddOperandInStack(Element &token,
                         std::stack<double> &calc_stack) noexcept;

  void PlusCase(std::stack<double> &calc_stack) noexcept;
  void MinusCase(std::stack<double> &calc_stack) noexcept;
  void MulCase(std::stack<double> &calc_stack) noexcept;
  void DivCase(std::stack<double> &calc_stack) noexcept;
  void ExpCase(std::stack<double> &calc_stack) noexcept;
  void ModCase(std::stack<double> &calc_stack) noexcept;
  void FuncCase(std::stack<double> &calc_stack, Element &token) noexcept;
  void SinCase(std::stack<double> &calc_stack) noexcept;
  void CosCase(std::stack<double> &calc_stack) noexcept;
  void TanCase(std::stack<double> &calc_stack) noexcept;
  void AsinCase(std::stack<double> &calc_stack) noexcept;
  void AcosCase(std::stack<double> &calc_stack) noexcept;
  void AtanCase(std::stack<double> &calc_stack) noexcept;
  void SqrtCase(std::stack<double> &calc_stack) noexcept;
  void LnCase(std::stack<double> &calc_stack) noexcept;
  void LogCase(std::stack<double> &calc_stack) noexcept;
};
}; // namespace s21
#endif