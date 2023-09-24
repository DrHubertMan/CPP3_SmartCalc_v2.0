#ifndef CPP3_SMARTCALC_V2_1_VIEWDEPOSITCALC_H
#define CPP3_SMARTCALC_V2_1_VIEWDEPOSITCALC_H

#include <QCheckBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>

#include "calclulatorbutton.h"

namespace s21 {
class ViewDepositCalc : public QGraphicsView {

public:
  ViewDepositCalc();

  int GetBoxIndex() const noexcept;
  bool GetCapitalizationCheck() const noexcept;

  void SetUploadList() noexcept;
  void SetDropedList() noexcept;
  void SetOuput() noexcept;

private:
  void InitElement();
  void InitButton();
  void InitTextElement();
  void InitSpinBox();
  void AddAtScene();

private:
  QLabel *sum_deposit_label_;
  QDoubleSpinBox *sum_deposit_;

  QLabel *term_label_;
  QSpinBox *term_;

  QLabel *percent_rate_label_;
  QDoubleSpinBox *percent_rate_;

  QLabel *tax_rate_label_;
  QDoubleSpinBox *tax_rate_;

  QLabel *payment_frequency_label_;
  QComboBox *payment_frequency_;

  QCheckBox *capitalization_;

  QLabel *upload_mounth_label_;
  QSpinBox *upload_mounth_;

  QLabel *upload_sum_label_;
  QDoubleSpinBox *upload_sum_;

  CalculatorButton add_upload_{this};

  QTextEdit *upload_list_;
  std::map<int, double> upload_map_;

  QLabel *droped_mounth_label_;
  QSpinBox *droped_mounth_;

  QLabel *droped_sum_label;
  QDoubleSpinBox *droped_sum_;

  CalculatorButton add_drop_{this};

  QTextEdit *drop_list_;
  std::map<int, double> drop_map_;

  QTextEdit *output_;

  CalculatorButton btn_calc_{this};
  CalculatorButton btn_clear_{this};

  QGraphicsScene *scene_;
};
}; // namespace s21

#endif // CPP3_SMARTCALC_V2_1_VIEWDEPOSITCALC_H
