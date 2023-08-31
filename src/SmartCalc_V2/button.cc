#include "viewsmartcalc.h"

s21::ViewSmartCalc::Button::Button(ViewSmartCalc *parent) : parent_(parent)  {
    color_.setRgb(107, 91, 149);
    setAcceptHoverEvents(true);
}

s21::ViewSmartCalc::Button::~Button() {
    if (parent_) {
        delete parent_;
    }
}

QRectF s21::ViewSmartCalc::Button::boundingRect() const {
  return QRectF(0, 0, width_, heigth_);
};

void s21::ViewSmartCalc::Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  painter->setBrush(color_);
  painter->drawRoundedRect(0, 0, width_, heigth_, 5, 5);
  if (!text_.isEmpty()) {
    painter->setFont(QFont("Arial", 12));
    painter->drawText(QRectF(0, 0, width_, heigth_), Qt::AlignCenter, text_);
  }
}

void s21::ViewSmartCalc::Button::SetGeometry(int heigth, int width) noexcept {
  heigth_ = heigth;
  width_ = width;
}

void s21::ViewSmartCalc::Button::setText(const QString &text) noexcept {
  text_ = text;
  update();
}

void s21::ViewSmartCalc::Button::hoverEnterEvent(QGraphicsSceneHoverEvent *) {
    color_.setRgb(57, 48, 79);
    update();
}

void s21::ViewSmartCalc::Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
    color_.setRgb(107, 91, 149);
    update();
}

void s21::ViewSmartCalc::Button::mousePressEvent(QGraphicsSceneMouseEvent *) {
    if(parent_ != nullptr) {
        if (text_ == "=") {
            std::list<std::string> stdList;
            for (const QString& qString : parent_->output_line_) {
                stdList.push_back(qString.toStdString());
            }
            parent_->converter = new ExpressionConverter(stdList);
            parent_->calic = new Calculation(parent_->converter->GetOut());
            qWarning() << parent_->calic->GetValue();
            parent_->output_line_.clear();
        }
        parent_->output_line_.push_back(text_);
    }
//    qWarning() << text_;
};


