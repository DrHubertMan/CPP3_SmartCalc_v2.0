#include "calccontrol.h"
// #include "../view/viewcreditcalc.h"
#include "../view/viewsmartcalc.h"

s21::CalcControl::CalcControl(ExpressionConverter *converter_model)
    : converter_model_(converter_model) {}

s21::CalcControl::CalcControl(const CalcControl &c)
    : calculator_(c.calculator_), converter_model_(c.converter_model_) {}

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

s21::CalcControl::~CalcControl() { calculator_ = nullptr; };

void s21::CalcControl::SetView(ViewSmartCalc *e) noexcept { calculator_ = e; }

void s21::CalcControl::swap(CalcControl &other) {
  std::swap(calculator_, other.calculator_);
  std::swap(converter_model_, other.converter_model_);
};

void s21::CalcControl::Dot() const noexcept { calculator_->SetDotOnDisplay(); };

void s21::CalcControl::Clear() const noexcept {
  calculator_->DisplayInputClear();
};

void s21::CalcControl::XVar(QString text) const noexcept {
  calculator_->SetXVarOnDisplay(text);
};

void s21::CalcControl::Num(QString text) const noexcept {
  calculator_->SetNumOnDisplay(text);
};

void s21::CalcControl::UnarClicked() const noexcept {
  calculator_->SetUnarSign();
}

void s21::CalcControl::Function(QString text) const noexcept {
  calculator_->SetFunction(text);
}

void s21::CalcControl::OperPressed(QString text) const noexcept {
  calculator_->SetOper(text);
}

void s21::CalcControl::OpenBraketPressed(QString text) const noexcept {
  calculator_->SetOpenBracket(text);
}

void s21::CalcControl::ClosedBraketPressed(QString text) const noexcept {
  calculator_->SetClosedBracket(text);
}

void s21::CalcControl::AddValueInModel(QString text) noexcept {
  converter_model_->AddTokenInModel(text.toStdString());
}

void s21::CalcControl::EqualPressed() {
  calculator_->CalculateCase();

  if (CheckConversion()) {
    if (calculator_->XvarIsChecked()) {
      Calculation expression_calculate(converter_model_->GetOut(),
                                       calculator_->GetDisplayXvarValue());
      calculator_->SetAnswer(
          QString::number(expression_calculate.GetValue(), 'f', 7)
              .remove(QRegularExpression("0+$"))
              .remove(QRegularExpression("\\.$")));
    } else {
      Calculation expression_calculate(converter_model_->GetOut());
      calculator_->SetAnswer(
          QString::number(expression_calculate.GetValue(), 'f', 7)
              .remove(QRegularExpression("0+$"))
              .remove(QRegularExpression("\\.$")));
    }
  } else {
    calculator_->SetAnswer("Wrong expression");
  }
  // ClearModel();
  Clear();
}

void s21::CalcControl::MemoryClear() const noexcept {
  calculator_->ClearHystoryDisplay();
}

void s21::CalcControl::ClearModel() noexcept { converter_model_->Clear(); }

void s21::CalcControl::ModeSelect() noexcept { calculator_->RadioClicked(); }

void s21::CalcControl::GraphPressed() {
  calculator_->CalculateCase();

  if (CheckConversion()) {
    GraphModel graph_data(calculator_->GetXMin(), calculator_->GetXmax(),
                          converter_model_->GetOut());
    calculator_->UpdateGraph(graph_data.GetX(), graph_data.GetY());
    calculator_->SetAnswer("graph");
  } else {
    calculator_->SetAnswer("Wrong expression");
  }
  Clear();
}

bool s21::CalcControl::CheckConversion() {
  bool check_conversion = true;
  try {
    converter_model_->Conversion();
  } catch (std::invalid_argument) {
    check_conversion = false;
  }
  return check_conversion;
}

void s21::CalcControl::ScientificNotation() noexcept {
  calculator_->ScientificCase();
}

// void s21::CalcControl::StartCredit() noexcept {
//   calculator_->CreditCaclStart();
// }

// void s21::CalcControl::SetCreditView(ViewCreditCalc *cred) noexcept {
//   if (credit_calc_ != cred) {
//     credit_calc_ = cred;
//   }
// }

// void s21::CalcControl::ClearCredit() noexcept {
//   std::cout << this << std::endl;
//   // std::cout << credit_calc_ << std::endl;
//   credit_calc_->ClearView();
// }