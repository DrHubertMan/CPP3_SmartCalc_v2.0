#ifndef VIEWSMARTCALC_H
#define VIEWSMARTCALC_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QCheckBox>
#include <QLineEdit>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QList>
#include <QLabel>

#include "../model/expressionConverter.h"
#include "../model/calculation.h"

namespace s21 {
class ViewSmartCalc : public QGraphicsView {
public:
    ViewSmartCalc(QWidget* parent = nullptr);
    ~ViewSmartCalc();
private:
    void InitViewElement();
    void InitNumberButtton();
    void InitOperatorButton();
    void InitFunctionButton();
    void InitLineEdit();
    void InitQCheckBox();

    void AddBtnAtScene();
    void AddLineAtScene();
private:
    class CalculatorButton : public QGraphicsItem {
    public:
        CalculatorButton(ViewSmartCalc *calculation_view = nullptr);
        ~CalculatorButton();

        QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

        void SetGeometry(int heigth, int width) noexcept;
        void setText(const QString &text) noexcept;

        void hoverEnterEvent(QGraphicsSceneHoverEvent *) override;
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *) override;

        void mousePressEvent(QGraphicsSceneMouseEvent*) override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
    private:
        int width_{0};
        int heigth_{0};
        QString text_;
        QColor color_;
        QList<QString> *outline_;

        void EqCase() const noexcept;
        void Adder() const noexcept;
        bool CheckDisplaysStatus() const noexcept;

        s21::ViewSmartCalc *calculation_view_;

};
private:

    ExpressionConverter *converter_;
    Calculation *calculator_;

    QGraphicsScene scene_;

    QLineEdit *display_up_;
    QLineEdit *display_down_;

    QLabel *oper_;

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

    QCheckBox x_var_;
    QCheckBox x_func_;

    QList<QString> output_line_;

};
};

#endif // VIEWSMARTCALC_H
