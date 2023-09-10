#ifndef CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H
#define CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H

#include <string>

namespace s21 {
class Element {
public:
  Element() = default;
  ~Element() = default;

  explicit Element(std::string value);

  Element(const Element &e);
  Element &operator=(const Element &e);

  Element(Element &&e);
  Element &operator=(Element &&e);

  std::string GetData() const noexcept;
  bool IsNumber() const noexcept;
  bool IsOperator() const noexcept;
  bool IsPlus() const noexcept;
  bool IsMinus() const noexcept;
  bool IsMul() const noexcept;
  bool IsDiv() const noexcept;
  bool IsExp() const noexcept;
  bool IsMod() const noexcept;
  bool IsFunciotn() const noexcept;
  bool IsSin() const noexcept;
  bool IsCos() const noexcept;
  bool IsTan() const noexcept;
  bool IsAsin() const noexcept;
  bool IsAcos() const noexcept;
  bool IsAtan() const noexcept;
  bool IsSqrt() const noexcept;
  bool IsLn() const noexcept;
  bool IsLog() const noexcept;
  bool IsSeparator() const noexcept;
  bool IsLeftPriority() const noexcept;
  bool OperatorCheck(Element &other) const noexcept;
  void SetData(std::string value) noexcept;
  bool IsOpenBracket() const noexcept;
  bool IsClosedBracket() const noexcept;
  bool IsEq() const noexcept;
  bool IsPoint() const noexcept;
  bool IsX() const noexcept;

private:
  std::string data_;

private:
  void swap(Element &other);
  int GetPriority() const noexcept;
  bool PriorityComparsion(Element &other) const noexcept;
  bool IsEqualPriority(Element &other) const noexcept;
};
}; // namespace s21

#endif // CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H
