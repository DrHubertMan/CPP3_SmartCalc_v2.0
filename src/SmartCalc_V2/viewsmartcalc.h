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
    class Button : public QGraphicsItem {
    public:
        Button(ViewSmartCalc *parent = nullptr);
        ~Button();

        QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

        void SetGeometry(int heigth, int width) noexcept;
        void setText(const QString &text) noexcept;

        void hoverEnterEvent(QGraphicsSceneHoverEvent*) override;
        void hoverLeaveEvent(QGraphicsSceneHoverEvent*) override;
        void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    private:
        int width_{0};
        int heigth_{0};
        QString text_;
        QColor color_;
        QList<QString> *outline_;

        s21::ViewSmartCalc *parent_;

};
private:

    ExpressionConverter *converter;
    Calculation *calic;

    QGraphicsScene scene_;

    QLineEdit *display_up_;

    Button btn_eq_{this};

    Button btn_1_{this};
    Button btn_2_{this};
    Button btn_3_{this};
    Button btn_4_{this};
    Button btn_5_{this};
    Button btn_6_{this};
    Button btn_7_{this};
    Button btn_8_{this};
    Button btn_9_{this};
    Button btn_0_{this};
    Button btn_point_{this};
    Button btn_sep_{this};
    Button btn_open_br_{this};
    Button btn_closed_br_{this};

    Button btn_plus_{this};
    Button btn_minus_{this};
    Button btn_mul_{this};
    Button btn_div_{this};
    Button btn_exp_{this};
    Button btn_mod_{this};

    Button btn_sin_{this};
    Button btn_cos_{this};
    Button btn_tan_{this};
    Button btn_asin_{this};
    Button btn_acos_{this};
    Button btn_atan_{this};
    Button btn_sqrt_{this};
    Button btn_ln_{this};
    Button btn_log_{this};

    QCheckBox x_var_;
    QCheckBox x_func_;

    QList<QString> output_line_;

};
};

#endif // VIEWSMARTCALC_H
