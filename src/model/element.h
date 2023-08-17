#ifndef CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H
#define CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H

#include<string>

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
  
  std::string GetData() noexcept;
  bool IsNumber() noexcept;
  bool IsOperator() noexcept;
  bool IsPlus() noexcept;
  bool IsMinus() noexcept;
  bool IsMul() noexcept;
  bool IsDiv() noexcept;
  bool IsExp() noexcept;
  bool IsMod() noexcept;
  bool IsFunciotn() noexcept;
  bool IsSin() noexcept;
  bool IsCos() noexcept;
  bool IsTan() noexcept;
  bool IsAsin() noexcept;
  bool IsAcos() noexcept;
  bool IsAtan() noexcept;
  bool IsSqrt() noexcept;
  bool IsLn() noexcept;
  bool IsLog() noexcept;
  bool IsSeparator() noexcept;
  bool IsLeftPriority() noexcept;

  private:
  std::string data_;
    
  private:

  void swap(Element &other);
  


    };
};

#endif // CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H