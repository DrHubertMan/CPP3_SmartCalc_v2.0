#ifndef CPP3_SMARTCALC_V2_1_VIEWSMARTCALC_H
#define CPP3_SMARTCALC_V2_1_VIEWSMARTCALC_H

#include <QButtonGroup>
#include <QColor>
#include <QDebug>
#include <QErrorMessage>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QRadioButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QWidget>
#include <vector>

#include "../controller/calccontrol.h"
#include "calclulatorbutton.h"
#include "qcustomplot.h"
// #include "viewcreditcalc.h"
// #include "viewdepositcalc.h"

namespace s21 {
class CalcControl;
class ViewSmartCalc : public QGraphicsView {
 public:
  ViewSmartCalc(CalcControl *control, QWidget *parent = nullptr);

 public:
  void GraphShow() noexcept;
  void SetNumOnDisplay(QString text) noexcept;
  void SetXVarOnDisplay(QString text) noexcept;
  void DisplayInputClear() noexcept;
  void SetDotOnDisplay() noexcept;
  void SetUnarSign() noexcept;
  void SetFunction(QString text) noexcept;
  void SetOper(QString text) noexcept;
  void SetOpenBracket(QString text) noexcept;
  void SetClosedBracket(QString text) noexcept;
  void ClearHystoryDisplay() noexcept;
  void CalculateCase() noexcept;
  void RadioClicked();
  void SetAnswer(QString value) noexcept;
  void UpdateGraph(std::vector<double> x, std::vector<double> y) noexcept;
  void ScientificCase() noexcept;
  // void CreditCaclStart() noexcept;

  double GetXMin();
  double GetXmax();
  double GetDisplayXvarValue() const noexcept;
  bool XvarIsChecked() const noexcept;
  // bool DisplayUpIsDisplayXvar();
  // bool DisplayUpIsNull();
  // bool DefaultModeIsChecked();

  // void SetController(CalcControl &control);

 private:
  void InitViewElement();
  void InitNumberButtton();
  void InitOperatorButton();
  void InitFunctionButton();
  void InitTextElement();
  void InitQCheckBox();
  void InitSpinBox();
  void InitModeButton();

  void AddWidgetAtScene();
  void AddLineAtScene();
  void DisplayChange();
  void AddNumber() noexcept;
  bool CheckState() const noexcept;
  // bool CharIsOper(QChar c) noexcept;

 private:
  CalcControl *control_;

  QRadioButton *x_var_;
  QRadioButton *x_func_;
  QRadioButton *default_mode_;

  QLabel *nickname_;
  QLabel *x_min_label_;
  QLabel *x_max_label_;
  QLabel *y_min_label_;
  QLabel *y_max_label_;
  QLabel *oper_;

  QTextEdit *display_hystory_;
  QLineEdit *display_x_var_;
  QLineEdit *display_down_;
  QLineEdit *fake_display;
  QLineEdit *display_up_;

  QCustomPlot *graph_;

  QSpinBox *x_min_;
  QSpinBox *x_max_;
  QSpinBox *y_min_;
  QSpinBox *y_max_;

  // ViewCreditCalc credit_calc_;
  // ViewDepositCalc deposit_calc_;

  CalculatorButton btn_eq_{this};
  CalculatorButton btn_e_{this};

  CalculatorButton btn_show_credit_{this};
  CalculatorButton btn_show_deposit_{this};

  CalculatorButton btn_1_{this};
  CalculatorButton btn_2_{this};
  CalculatorButton btn_3_{this};
  CalculatorButton btn_4_{this};
  CalculatorButton btn_5_{this};
  CalculatorButton btn_6_{this};
  CalculatorButton btn_7_{this};
  CalculatorButton btn_8_{this};
  CalculatorButton btn_9_{this};
  CalculatorButton btn_0_{this};
  CalculatorButton btn_point_{this};
  CalculatorButton btn_unar_{this};
  CalculatorButton btn_open_br_{this};
  CalculatorButton btn_closed_br_{this};

  CalculatorButton btn_plus_{this};
  CalculatorButton btn_minus_{this};
  CalculatorButton btn_mul_{this};
  CalculatorButton btn_div_{this};
  CalculatorButton btn_exp_{this};
  CalculatorButton btn_mod_{this};

  CalculatorButton btn_sin_{this};
  CalculatorButton btn_cos_{this};
  CalculatorButton btn_tan_{this};
  CalculatorButton btn_asin_{this};
  CalculatorButton btn_acos_{this};
  CalculatorButton btn_atan_{this};
  CalculatorButton btn_sqrt_{this};
  CalculatorButton btn_ln_{this};
  CalculatorButton btn_log_{this};

  CalculatorButton btn_ac_{this};
  CalculatorButton btn_mc_{this};
  CalculatorButton btn_x_{this};

  CalculatorButton btn_graph_{this};

  QGraphicsScene *scene_;
  QButtonGroup *x_group_;

  bool pointer_swap_ = false;
};
};  // namespace s21

#endif  // CPP3_SMARTCALC_V2_1_VIEWSMARTCALC_H
