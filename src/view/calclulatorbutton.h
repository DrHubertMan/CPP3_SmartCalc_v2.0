#ifndef CPP3_SMARTCALC_V2_1_CALCLULATORBUTTON_H
#define CPP3_SMARTCALC_V2_1_CALCLULATORBUTTON_H

#include <QErrorMessage>
#include <QGraphicsItem>
#include <QPainter>

// #include "../model/anuitetcalc.h"
// #include "../model/deposit.h"
// #include "../model/diferentcalc.h"
#include "../model/calculation.h"
#include "../model/expressionConverter.h"

namespace s21 {
class ViewSmartCalc;
// class ViewCreditCalc;
// class ViewDepositCalc;

class CalculatorButton : public QObject, public QGraphicsItem {
  Q_OBJECT
 public:
  CalculatorButton(ViewSmartCalc *parent = nullptr);
  // CalculatorButton(ViewCreditCalc *parent = nullptr);
  // CalculatorButton(ViewDepositCalc *parent = nullptr);
  ~CalculatorButton();

  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

  void SetGeometry(int heigth, int width) noexcept;
  void setText(const QString &text) noexcept;

 signals:
  void KeyPressed(QString text);

 private:
  ExpressionConverter *converter_;
  Calculation *calculator_;
  ViewSmartCalc *parent_ = nullptr;
  // ViewCreditCalc *parent_cred_ = nullptr;
  // ViewDepositCalc *parent_deposit_ = nullptr;

  int width_{0};
  int heigth_{0};
  QString text_;
  QColor color_;
  QList<QString> *outline_;

 private:
  void hoverEnterEvent(QGraphicsSceneHoverEvent *) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;
  void mousePressEvent(QGraphicsSceneMouseEvent *) override;
};
};  // namespace s21

#endif  // CPP3_SMARTCALC_V2_1_CALCLULATORBUTTON_H
