#ifndef CPP3_SMARTCALC_V2_1_CALCULATION_H
#define CPP3_SMARTCALC_V2_1_CALCULATION_H

#include <string>
#include <vector>
#include <stack>

namespace s21 {
class Calculation {
  public:
  Calculation() = default;
  ~Calculation() = default;

  explicit Calculation(std::vector<std::string> input);

  Calculation(const Calculation &c);
  Calculation &operator=(const Calculation &c);

  Calculation(Calculation &&c);
  Calculation &operator=(Calculation &&c);

  private:
  std::vector<std::string> input_string_;
  double value_;

  private:
  void Calc() noexcept;
  void swap(Calculation &other);
};
};
#endif