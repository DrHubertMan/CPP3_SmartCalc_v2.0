#ifndef CALCLULATORBUTTON_H
#define CALCLULATORBUTTON_H

#include <QErrorMessage>
#include <QGraphicsItem>
#include <QPainter>

#include "../model/calculation.h"
#include "../model/expressionConverter.h"

namespace s21 {
class ViewSmartCalc;

class CalculatorButton : public QGraphicsItem {
public:
  CalculatorButton(ViewSmartCalc *calculation_view = nullptr);
  ~CalculatorButton();

  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

  void SetGeometry(int heigth, int width) noexcept;
  void setText(const QString &text) noexcept;

private:
  ExpressionConverter *converter_;
  Calculation *calculator_;
  ViewSmartCalc *calculation_view_;

  int width_{0};
  int heigth_{0};
  QString text_;
  QColor color_;
  QList<QString> *outline_;

private:
  void hoverEnterEvent(QGraphicsSceneHoverEvent *) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *) override;

  void mousePressEvent(QGraphicsSceneMouseEvent *) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;

  void EqCase() noexcept;
  void DefaultMode() noexcept;
  void Adder() const noexcept;
  void PointAdder() const noexcept;
  bool CheckCloseBracketEvent() const noexcept;
  bool CheckDisplaysStatus() const noexcept;
  bool CheckForAdd() const noexcept;
};
}; // namespace s21

#endif // CALCLULATORBUTTON_H
