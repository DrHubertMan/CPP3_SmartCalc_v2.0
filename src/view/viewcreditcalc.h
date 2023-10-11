#ifndef CPP3_SMARTCALC_V2_1_VIEWCREDITCALC_H
#define CPP3_SMARTCALC_V2_1_VIEWCREDITCALC_H

#include <QButtonGroup>
#include <QDoubleSpinBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QSpinBox>
#include <QTextEdit>

#include "calclulatorbutton.h"
#include "../controller/calccontrol.h"

namespace s21 {
class CalcControl;

class ViewCreditCalc : public QGraphicsView {
public:
  ViewCreditCalc();

  bool GetChecked() const noexcept;
  double GetAllSum() const noexcept;
  double GetPercent() const noexcept;
  int GetTerm() const noexcept;

  void SetEveryMonthPay(double mounthly_pay) noexcept;
  void SetOverpay(double overpay) noexcept;
  void SetOverpaySum(double overpay_sum) noexcept;

  void SetDiferentEveryMountPayGraph() noexcept;
  void SetDifMounthPay(int mounth, double pay) noexcept;

  void SetZeroSpin() noexcept;
  void SetControl(CalcControl &control) noexcept;
  void ClearView() noexcept;

private:
  void InitElement();
  void InitRadioButton();
  void InitLabel();
  void InitSpinBox();
  void InitButton();
  void AddAtScene();

private:
  CalcControl control_;
  QTextEdit diferent_pay_;

  QLineEdit everymonth_pay_text_;
  QLineEdit overpay_text_;
  QLineEdit overpay_sum_text_;

  QLabel all_sum_;
  QLabel term_;
  QLabel percent_;

  QLabel everymonth_pay_;
  QLabel overpay_;
  QLabel overpay_sum_;

  QDoubleSpinBox credit_sum_;
  QSpinBox mounth_;
  QDoubleSpinBox double_percent_;

  QGraphicsScene *scene_;
  CalculatorButton btn_ac_{this};
  CalculatorButton btn_calculate_{this};

  QRadioButton anuitet_;
  QRadioButton diferent_;
  QButtonGroup credit_mode_;
};
} // namespace s21

#endif // CPP3_SMARTCALC_V2_1_VIEWCREDITCALC_H
