#ifndef VIEWSMARTCALC_H
#define VIEWSMARTCALC_H

#include <QGraphicsScene>
#include <QGraphicsView>
//#include <QCheckBox>
#include <QButtonGroup>
#include <QColor>
#include <QDebug>
#include <QErrorMessage>
#include <QGraphicsItem>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QRadioButton>
#include <QTextEdit>
#include <QWidget>
#include <QSpinBox>

#include "calclulatorbutton.h"
#include "qcustomplot.h"

namespace s21 {
class ViewSmartCalc : public QGraphicsView {
public:
  ViewSmartCalc(QWidget *parent = nullptr);
  ~ViewSmartCalc();

  QLineEdit *display_up_;
  QLineEdit *display_down_;
  QLineEdit *display_x_var_;
  QLineEdit *fake_display;

  QTextEdit *display_hystory_;

  QLabel *oper_;
  QLabel *nickname_;

  QRadioButton *x_var_;
  QRadioButton *x_func_;
  QRadioButton *default_mode_;

  QList<QString> output_line_;

  QSpinBox *x_min_;
  QSpinBox *x_max_;
  QSpinBox *y_min_;
  QSpinBox *y_max_;

private:
  void InitViewElement();
  void InitNumberButtton();
  void InitOperatorButton();
  void InitFunctionButton();
  void InitTextElement();
  void InitQCheckBox();
  void InitSpinBox();

  void AddWidgetAtScene();
  void AddLineAtScene();
  void DisplayChange();

private:
  //    QGraphicsProxyWidget *x_var_proxy_widget_;
  CalculatorButton btn_eq_{this};

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

  QGraphicsScene scene_;
  QButtonGroup *x_group_;

public slots:
  void RadioClicked();
};
}; // namespace s21

#endif // VIEWSMARTCALC_H
