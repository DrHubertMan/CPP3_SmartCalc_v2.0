#include "viewsmartcalc.h"

s21::ViewSmartCalc::CalculatorButton::CalculatorButton(ViewSmartCalc *calculation_view) : calculation_view_(calculation_view) {
  color_.setRgb(107, 91, 149);
  setAcceptHoverEvents(true);
}

s21::ViewSmartCalc::CalculatorButton::~CalculatorButton() {
  if (calculation_view_) {
    delete calculation_view_;
  }
}

QRectF s21::ViewSmartCalc::CalculatorButton::boundingRect() const {
  return QRectF(0, 0, width_, heigth_);
};

void s21::ViewSmartCalc::CalculatorButton::paint(QPainter *painter,
                                       const QStyleOptionGraphicsItem *option,
                                       QWidget *widget) {
  painter->setBrush(color_);
  painter->drawRoundedRect(0, 0, width_, heigth_, 5, 5);
  if (!text_.isEmpty()) {
    painter->setFont(QFont("Arial", 12));
    painter->drawText(QRectF(0, 0, width_, heigth_), Qt::AlignCenter, text_);
  }
}

void s21::ViewSmartCalc::CalculatorButton::SetGeometry(int heigth, int width) noexcept {
  heigth_ = heigth;
  width_ = width;
}

void s21::ViewSmartCalc::CalculatorButton::setText(const QString &text) noexcept {
  text_ = text;
  update();
}

void s21::ViewSmartCalc::CalculatorButton::mousePressEvent(QGraphicsSceneMouseEvent *) {
    color_.setRgb(57, 48, 79);
    update();
  if (calculation_view_ != nullptr) {
    Element token(text_.toStdString());
    if (token.IsEq() && calculation_view_->oper_->text().isEmpty()) {
        EqCase();
    } else if (token.IsNumber()) {
      calculation_view_->oper_->clear();
      calculation_view_->display_up_->setText(calculation_view_->display_up_->text() + text_);
    } else if (token.IsOperator() && CheckDisplaysStatus() ) {
      calculation_view_->oper_->setText(text_);
      Adder();
    } else if (token.IsFunciotn() && calculation_view_->display_up_->text().isEmpty()) {
      calculation_view_->oper_->clear();
      calculation_view_->output_line_.push_back(text_);
      calculation_view_->output_line_.push_back("(");
      calculation_view_->display_down_->setText(calculation_view_->display_down_->text() + text_ +
                                      " (");
    } else if (token.IsClosedBracket() && !calculation_view_->display_up_->text().isEmpty()) {
      Adder();
    } else if (token.IsPoint()) {
      if (calculation_view_->display_up_->text().isEmpty()) {
        calculation_view_->display_up_->setText("0.");
      } else if (!calculation_view_->display_up_->text().contains('.')) {
        calculation_view_->display_up_->setText(calculation_view_->display_up_->text() + ".");
      }
    } else if (token.IsOpenBracket()) {
        bool digit_end_input_line = false;
        bool display_down_is_empty = calculation_view_->display_down_->text().isEmpty();
        if (!display_down_is_empty) {
            QChar last_char = calculation_view_->display_down_->text().at(calculation_view_->display_down_->text().length() - 1);
            if (last_char.isDigit()) {
                digit_end_input_line = true;
            }
        }
        if (display_down_is_empty || !digit_end_input_line) {
            calculation_view_->display_down_->setText(calculation_view_->display_down_->text() + text_);
        }
    } else if (text_ == "AC") {
        calculation_view_->display_down_->clear();
        calculation_view_->display_up_->clear();
        calculation_view_->oper_->clear();
    }
  }
  //    qWarning() << text_;
}

void s21::ViewSmartCalc::CalculatorButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
    color_.setRgb(107, 91, 149);
    update();
}

void s21::ViewSmartCalc::CalculatorButton::EqCase() const noexcept {
    Adder();
    std::list<std::string> stdList;
    for (const QString &qString : calculation_view_->output_line_) {
      stdList.push_back(qString.toStdString());
//      qWarning() << qString;
    }

    calculation_view_->converter_ = new ExpressionConverter(stdList);
    calculation_view_->calculator_ = new Calculation(calculation_view_->converter_->GetOut());
    qWarning() << calculation_view_->calculator_->GetValue();
    calculation_view_->display_down_->setText(calculation_view_->display_down_->text() + QString::number(calculation_view_->calculator_->GetValue()));
    delete calculation_view_->converter_;
    delete calculation_view_->calculator_;
    calculation_view_->output_line_.clear();
}

void s21::ViewSmartCalc::CalculatorButton::Adder() const noexcept {
  if (!calculation_view_->display_up_->text().isEmpty()) {
    QChar last_char = calculation_view_->display_up_->text().at(
        calculation_view_->display_up_->text().length() - 1);
    if (last_char == '.') {
      calculation_view_->display_up_->setText(calculation_view_->display_up_->text() + "0");
    }
  }
  calculation_view_->output_line_.push_back(calculation_view_->display_up_->text());
  calculation_view_->output_line_.push_back(text_);
  calculation_view_->display_down_->setText(calculation_view_->display_down_->text() +
                                  calculation_view_->display_up_->text() + text_);
  calculation_view_->display_up_->clear();
}

bool s21::ViewSmartCalc::CalculatorButton::CheckDisplaysStatus() const noexcept{
    bool check_one = false;
    bool check_two = false;
    if (!calculation_view_->display_up_->text().isEmpty()) {
        QChar last_char_one = calculation_view_->display_up_->text().at(calculation_view_->display_up_->text().length() - 1);
        if (last_char_one.isDigit() || last_char_one == '.') check_one = true;
    } else if (!calculation_view_->display_down_->text().isEmpty()) {
        QChar last_char_two = calculation_view_->display_down_->text().at(calculation_view_->display_down_->text().length() - 1);
        if (last_char_two.isDigit()) check_two = true;
    }
    return (check_one || check_two);
};
