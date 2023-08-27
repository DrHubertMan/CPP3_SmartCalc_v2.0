#ifndef VIEWSMARTCALC_H
#define VIEWSMARTCALC_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "button.h"

namespace s21 {
class viewSmartCalc : public QGraphicsView {
public:
    viewSmartCalc();
private:
    void InitViewElement();
    void InitNumberButtton();
    void InitOperatorButton();
    void AddBtnAtScene();

private:
    QGraphicsScene scene_;

    button btn_eq_;

    button btn_1_;
    button btn_2_;
    button btn_3_;
    button btn_4_;
    button btn_5_;
    button btn_6_;
    button btn_7_;
    button btn_8_;
    button btn_9_;
    button btn_0_;
    button btn_point_;
    button btn_sep_;
    button btn_open_br_;
    button btn_closed_br_;

    button btn_plus_;
    button btn_minus_;
    button btn_mul_;
    button btn_div_;
    button btn_exp_;
    button btn_mod_;

    button btn_sin_;
    button btn_cos_;
    button btn_tan_;
    button btn_asin_;
    button btn_acos_;
    button btn_atan_;
    button btn_sqrt_;
    button btn_ln_;
    button btn_log_;
};
};

#endif // VIEWSMARTCALC_H
