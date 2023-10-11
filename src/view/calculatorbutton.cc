#include "calclulatorbutton.h"
#include "viewcreditcalc.h"
#include "viewdepositcalc.h"
#include "viewsmartcalc.h"

s21::CalculatorButton::CalculatorButton(ViewSmartCalc *parent)
    : parent_(parent) {
  color_.setRgb(58, 120, 101);
  setAcceptHoverEvents(true);
};

s21::CalculatorButton::CalculatorButton(ViewCreditCalc *parent)
    : parent_cred_(parent) {
  color_.setRgb(58, 120, 101);
  setAcceptHoverEvents(true);
}

s21::CalculatorButton::CalculatorButton(ViewDepositCalc *parent)
    : parent_deposit_(parent) {
  color_.setRgb(58, 120, 101);
  setAcceptHoverEvents(true);
};

s21::CalculatorButton::~CalculatorButton() {}

QRectF s21::CalculatorButton::boundingRect() const {
  return QRectF(0, 0, width_, heigth_);
};

void s21::CalculatorButton::paint(QPainter *painter,
                                  const QStyleOptionGraphicsItem *option,
                                  QWidget *widget) {
  painter->setBrush(color_);
  painter->setPen(QColor(Qt::white));
  painter->drawRoundedRect(0, 0, width_, heigth_, 5, 5);
  if (!text_.isEmpty()) {
    painter->setFont(QFont("Monaco", 12));
    painter->drawText(QRectF(0, 0, width_, heigth_), Qt::AlignCenter, text_);
  }
  option = nullptr;
  widget = nullptr;
};

void s21::CalculatorButton::SetGeometry(int heigth, int width) noexcept {
  heigth_ = heigth;
  width_ = width;
};

void s21::CalculatorButton::setText(const QString &text) noexcept {
  text_ = text;
  update();
};

void s21::CalculatorButton::hoverEnterEvent(QGraphicsSceneHoverEvent *) {
  color_.setRgb(83, 172, 147);
  update();
};

void s21::CalculatorButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
  color_.setRgb(58, 120, 101);
  update();
};

void s21::CalculatorButton::mousePressEvent(QGraphicsSceneMouseEvent *) {
  color_.setRgb(33, 69, 59);
  update();
  emit KeyPressed(text_);
};

void s21::CalculatorButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
  color_.setRgb(58, 120, 101);
  update();
}