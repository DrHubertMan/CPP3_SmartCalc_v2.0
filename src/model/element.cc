#include "element.h"

s21::Element::Element(std::string value) : data_(value){};

s21::Element::Element(const Element &e) : data_(e.data_){};
s21::Element &s21::Element::operator=(const Element &e) {
  if (this != &e) {
    Element copy{e};
    swap(copy);
  }
  return *this;
};

s21::Element::Element(Element &&e) : Element() { swap(e); };
s21::Element &s21::Element::operator=(Element &&e) {
  if (this != &e) {
    Element moved{std::move(e)};
    swap(moved);
  }
  return *this;
};

void s21::Element::swap(Element &other) { std::swap(data_, other.data_); };

std::string s21::Element::GetData() noexcept { return data_; };

bool s21::Element::IsNumber() noexcept {
  return ((data_[0] >= '0' && data_[0] <= '9') ||
          (data_[0] == '-' && data_[1] >= '0' && data_[1] <= '9'));
};

bool s21::Element::IsOperator() noexcept {
  return (IsPlus() || IsMinus() || IsMul() || IsDiv() || IsExp() || IsMod());
};

bool s21::Element::IsPlus() noexcept { return (data_[0] == '+'); };
bool s21::Element::IsMinus() noexcept { return (data_[0] == '-'); };
bool s21::Element::IsMul() noexcept { return (data_[0] == '*'); };
bool s21::Element::IsDiv() noexcept { return (data_[0] == '/'); };
bool s21::Element::IsExp() noexcept { return (data_[0] == '^'); };
bool s21::Element::IsMod() noexcept { return (data_[0] == '%'); };

bool s21::Element::IsFunciotn() noexcept {
  return (IsSin() || IsCos() || IsTan() || IsAsin() || IsAcos() || IsAtan() ||
          IsSqrt() || IsLn() || IsLog());
}

bool s21::Element::IsSin() noexcept { return data_ == "sin"; }
bool s21::Element::IsCos() noexcept { return data_ == "cos"; }
bool s21::Element::IsTan() noexcept { return data_ == "tan"; };
bool s21::Element::IsAsin() noexcept { return data_ == "asin"; }
bool s21::Element::IsAcos() noexcept { return data_ == "acos"; }
bool s21::Element::IsAtan() noexcept { return data_ == "atan"; };
bool s21::Element::IsSqrt() noexcept { return data_ == "sqrt"; };
bool s21::Element::IsLn() noexcept { return data_ == "ln"; };
bool s21::Element::IsLog() noexcept { return data_ == "log"; };

bool s21::Element::IsSeparator() noexcept { return (data_[0] == ','); };
bool s21::Element::IsLeftPriority() noexcept { return (data_[0] != '^'); }

bool s21::Element::OperatorCheck(Element &other) noexcept {
  bool result = false;
  if (IsOperator() && other.IsOperator()) {
    result = (PriorityComparsion(other)) ||
             (IsEqualPriority(other) && other.IsLeftPriority());
  }
  return result;
};

int s21::Element::GetPriority() noexcept {
  int result = 0;
  if (IsOperator()) {
    if (IsExp()) {
      result = 2;
    } else if (IsMul() || IsDiv()) {
      result = 1;
    }
  }
  return result;
};

bool s21::Element::PriorityComparsion(Element &other) noexcept {
  return GetPriority() > other.GetPriority();
}
bool s21::Element::IsEqualPriority(Element &other) noexcept {
  return GetPriority() == other.GetPriority();
};

void s21::Element::SetData(std::string value) { 
  data_.clear();
  data_ = value;
}
bool s21::Element::IsOpenBracket() noexcept { return data_[0] == '('; };
bool s21::Element::IsClosedBracket() noexcept { return data_[0] == ')'; };
bool s21::Element::IsEq() noexcept { return data_[0] == '='; };