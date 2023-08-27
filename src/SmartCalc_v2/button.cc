#include "button.h"

s21::button::button() {
    color_.setRgb(107, 91, 149);
    setAcceptHoverEvents(true);
}

QRectF s21::button::boundingRect() const {
  return QRectF(0, 0, width_, heigth_);
};

void s21::button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  painter->setBrush(color_);
  painter->drawRoundedRect(0, 0, width_, heigth_, 5, 5);
  if (!text_.isEmpty()) {
    painter->setFont(QFont("Arial", 12));
    painter->drawText(QRectF(0, 0, width_, heigth_), Qt::AlignCenter, text_);
  }
}

void s21::button::SetGeometry(int heigth, int width) noexcept {
  heigth_ = heigth;
  width_ = width;
}

void s21::button::setText(const QString &text) noexcept {
  text_ = text;
  update();
}

void s21::button::hoverEnterEvent(QGraphicsSceneHoverEvent *) {
    color_.setRgb(57, 48, 79);
    update();
}

void s21::button::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
    color_.setRgb(107, 91, 149);
    update();
}

void s21::button::mousePressEvent(QGraphicsSceneMouseEvent *) {
   qWarning() << text_;
};


