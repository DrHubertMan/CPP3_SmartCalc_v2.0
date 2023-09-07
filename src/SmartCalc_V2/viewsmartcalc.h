#ifndef VIEWSMARTCALC_H
#define VIEWSMARTCALC_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QCheckBox>
#include <QLineEdit>
#include <QWidget>
#include <QGraphicsItem>
#include <QColor>
#include <QDebug>
#include <QList>
#include <QLabel>
#include <QErrorMessage>
#include <QTextEdit>

#include "calclulatorbutton.h"

namespace s21 {
class ViewSmartCalc : public QGraphicsView {
public:
    ViewSmartCalc(QWidget* parent = nullptr);
    ~ViewSmartCalc();
    QGraphicsScene scene_;

    QLineEdit *display_up_;
    QLineEdit *display_down_;

    QTextEdit *display_hystory_;

    QLabel *oper_;
    QList<QString> output_line_;

private:
    void InitViewElement();
    void InitNumberButtton();
    void InitOperatorButton();
    void InitFunctionButton();
    void InitTextElement();
    void InitQCheckBox();

    void AddWidgetAtScene();
    void AddLineAtScene();
    
private:
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
    CalculatorButton btn_sep_{this};
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

    QCheckBox *x_var_;
    QCheckBox x_func_;
};
};

#endif // VIEWSMARTCALC_H
