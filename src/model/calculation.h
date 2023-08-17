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
  void PlusCase(std::stack<double> calc_stack) noexcept;
  bool IsMinus(std::string token) noexcept;
  void MinusCase(std::stack<double> calc_stack) noexcept;
  bool IsMul(std::string token) noexcept;
  void MulCase(std::stack<double> calc_stack) noexcept;
  bool IsDiv(std::string token) noexcept;
  void DivCase(std::stack<double> calc_stack) noexcept;
  bool IsExp(std::string token) noexcept;
  void ExpCase(std::stack<double> calc_stack) noexcept;
  bool IsMod(std::string token) noexcept;
  void ModCase(std::stack<double> calc_stack) noexcept;
  bool IsFunciotn(std::string token) noexcept;
  void FuncCase(std::stack<double> calc_stack, std::string token) noexcept;
  bool IsSin(std::string token) noexcept;
  void SinCase(std::stack<double> calc_stack) noexcept;
  bool IsCos(std::string token) noexcept;
  void CosCase(std::stack<double> calc_stack) noexcept;
  bool IsTan(std::string token) noexcept;
  void TanCase(std::stack<double> calc_stack) noexcept;
  bool IsAsin(std::string token) noexcept;
  void AsinCase(std::stack<double> calc_stack) noexcept;
  bool IsAcos(std::string token) noexcept;
  void AcosCase(std::stack<double> calc_stack) noexcept;
  bool IsAtan(std::string token) noexcept;
  void AtanCase(std::stack<double> calc_stack) noexcept;
  bool IsSqrt(std::string token) noexcept;
  void SqrtCase(std::stack<double> calc_stack) noexcept;
  bool IsLn(std::string token) noexcept;
  void LnCase(std::stack<double> calc_stack) noexcept;
  bool IsLog(std::string token) noexcept;
  void LogCase(std::stack<double> calc_stack) noexcept;
};
};
#endif