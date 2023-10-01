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

void s21::CalcControl::Num(QString text) {
  calculator_->SetDisplayUpText(calculator_->GetDisplayUpText() + text);
}