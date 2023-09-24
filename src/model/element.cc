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

std::string s21::Element::GetData() const noexcept { return data_; };

bool s21::Element::IsNumber() const noexcept {
  return ((data_[0] >= '0' && data_[0] <= '9') ||
          (data_[0] == '-' && data_[1] >= '0' && data_[1] <= '9'));
};

bool s21::Element::IsOperator() const noexcept {
  return (IsPlus() || IsMinus() || IsMul() || IsDiv() || IsExp() || IsMod());
};

bool s21::Element::IsPlus() const noexcept { return (data_[0] == '+'); };
bool s21::Element::IsMinus() const noexcept { return (data_[0] == '-'); };
bool s21::Element::IsMul() const noexcept { return (data_[0] == '*'); };
bool s21::Element::IsDiv() const noexcept { return (data_[0] == '/'); };
bool s21::Element::IsExp() const noexcept { return (data_[0] == '^'); };
bool s21::Element::IsMod() const noexcept { return (data_[0] == '%'); };

bool s21::Element::IsFunciotn() const noexcept {
  return (IsSin() || IsCos() || IsTan() || IsAsin() || IsAcos() || IsAtan() ||
          IsSqrt() || IsLn() || IsLog());
}

bool s21::Element::IsSin() const noexcept { return data_ == "sin"; }
bool s21::Element::IsCos() const noexcept { return data_ == "cos"; }
bool s21::Element::IsTan() const noexcept { return data_ == "tan"; };
bool s21::Element::IsAsin() const noexcept { return data_ == "asin"; }
bool s21::Element::IsAcos() const noexcept { return data_ == "acos"; }
bool s21::Element::IsAtan() const noexcept { return data_ == "atan"; };
bool s21::Element::IsSqrt() const noexcept { return data_ == "sqrt"; };
bool s21::Element::IsLn() const noexcept { return data_ == "ln"; };
bool s21::Element::IsLog() const noexcept { return data_ == "log"; };

bool s21::Element::IsSeparator() const noexcept { return (data_[0] == ','); };
bool s21::Element::IsLeftPriority() const noexcept { return (data_[0] != '^'); }

bool s21::Element::OperatorCheck(Element &other) const noexcept {
  bool result = false;
  if (IsOperator() && other.IsOperator()) {
    result = (PriorityComparsion(other)) ||
             (IsEqualPriority(other) && other.IsLeftPriority());
  }
  return result;
};

int s21::Element::GetPriority() const noexcept {
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

bool s21::Element::PriorityComparsion(Element &other) const noexcept {
  return GetPriority() > other.GetPriority();
}
bool s21::Element::IsEqualPriority(Element &other) const noexcept {
  return GetPriority() == other.GetPriority();
};

void s21::Element::SetData(std::string value) noexcept {
  data_.clear();
  data_ = value;
}
bool s21::Element::IsOpenBracket() const noexcept { return data_[0] == '('; };
bool s21::Element::IsClosedBracket() const noexcept { return data_[0] == ')'; };
bool s21::Element::IsEq() const noexcept { return data_[0] == '='; }
bool s21::Element::IsPoint() const noexcept { return data_[0] == '.'; }

bool s21::Element::IsX() const noexcept { return data_[0] == 'x'; };
