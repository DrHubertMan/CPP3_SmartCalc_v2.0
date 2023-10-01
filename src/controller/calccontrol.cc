#include "calccontrol.h"
#include "../view/viewsmartcalc.h"

s21::CalcControl::CalcControl(ViewSmartCalc *calc) : calculator_(calc) {}

s21::CalcControl::CalcControl(const CalcControl &c)
    : calculator_(c.calculator_) {}

s21::CalcControl &s21::CalcControl::operator=(const CalcControl &c) {
  if (this != &c) {
    CalcControl copy{c};
    swap(copy);
  }
  return *this;
}

s21::CalcControl::CalcControl(CalcControl &&c) : CalcControl() { swap(c); }

s21::CalcControl &s21::CalcControl::operator=(CalcControl &&c) {
  if (this != &c) {
    CalcControl moved{std::move(c)};
    swap(moved);
  }
  return *this;
}

s21::CalcControl::~CalcControl() {
  // if (calculator_ != nullptr) {
  //   delete calculator_;
  // }
}

void s21::CalcControl::swap(CalcControl &other) {
  std::swap(calculator_, other.calculator_);
};

void s21::CalcControl::Dot(QString text) noexcept {
  if (calculator_->GetDisplayUpText().isEmpty()) {
    calculator_->SetDisplayUpText("0.");
  } else if (!calculator_->GetDisplayUpText().contains('.') &&
             !calculator_->GetDisplayUpText().contains('x')) {
    calculator_->SetDisplayUpText(calculator_->GetDisplayUpText() + text);
  }
}

void s21::CalcControl::Clear() noexcept {
  calculator_->ClearDisplayDown();
  calculator_->ClearDisplayUp();
  calculator_->ClearOperatorLabel();
  calculator_->SetStyleSheetXvar("background: #008080; color: white; font: 12pt");
}

void s21::CalcControl::XVar(QString text) noexcept {
  if (calculator_->GetDisplayUpText().isEmpty()) {
    calculator_->SetDisplayUpText(text);
  }
} 

void s21::CalcControl::Num(QString text) noexcept {
  calculator_->SetDisplayUpText(calculator_->GetDisplayUpText() + text);
}