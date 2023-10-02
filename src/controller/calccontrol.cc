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
  calculator_ = nullptr;
};

void s21::CalcControl::swap(CalcControl &other) {
  std::swap(calculator_, other.calculator_);
};

void s21::CalcControl::Dot(QString text) noexcept {
  calculator_->SetDotOnDisplay();
};

void s21::CalcControl::Clear() noexcept {
  calculator_->DisplayInputClear();
};

void s21::CalcControl::XVar(QString text) noexcept {
  calculator_->SetXVarOnDisplay(text);
};

void s21::CalcControl::Num(QString text) noexcept {
  //clear oper
  calculator_->SetNumOnDisplay(text);
};

void s21::CalcControl::UnarClicked(QString text) noexcept {
  calculator_->SetUnarSign();
}

void s21::CalcControl::Function(QString text) noexcept {
  if (calculator_->SetFunction(text)) // add text in model;
}