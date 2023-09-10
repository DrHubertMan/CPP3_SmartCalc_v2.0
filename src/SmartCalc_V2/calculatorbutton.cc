#include "calclulatorbutton.h"
#include "viewsmartcalc.h"

s21::CalculatorButton::CalculatorButton(ViewSmartCalc *calculation_view)
    : calculation_view_(calculation_view) {
  color_.setRgb(58, 120, 101);
  setAcceptHoverEvents(true);
}

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
}

void s21::CalculatorButton::SetGeometry(int heigth, int width) noexcept {
  heigth_ = heigth;
  width_ = width;
}

void s21::CalculatorButton::setText(const QString &text) noexcept {
  text_ = text;
  update();
}

void s21::CalculatorButton::hoverEnterEvent(QGraphicsSceneHoverEvent *) {
  color_.setRgb(83, 172, 147);
  update();
}

void s21::CalculatorButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
  color_.setRgb(58, 120, 101);
  update();
}

void s21::CalculatorButton::mousePressEvent(QGraphicsSceneMouseEvent *) {
  color_.setRgb(33, 69, 59);
  update();
  if (calculation_view_ != nullptr) {
    Element token(text_.toStdString());
    if (token.IsEq()) {
      EqCase();
    } else if (token.IsNumber() && CheckForAdd()) {
      calculation_view_->oper_->clear();
      calculation_view_->display_up_->setText(
          calculation_view_->display_up_->text() + text_);
    } else if (token.IsX()) {
      if (CheckForAdd()) {
          calculation_view_->display_up_->setText(text_);
          calculation_view_->x_var_->setStyleSheet("background: #008080; color: red; font: 12pt");
      }
    } else if (token.IsOperator() && CheckDisplaysStatus()) {
      calculation_view_->oper_->setText(text_);
      Adder();
    } else if (token.IsFunciotn() &&
               calculation_view_->display_up_->text().isEmpty()) {
      calculation_view_->oper_->clear();
      calculation_view_->output_line_.push_back(text_);
      calculation_view_->output_line_.push_back("(");
      calculation_view_->display_down_->setText(
          calculation_view_->display_down_->text() + text_ + " (");
    } else if (token.IsClosedBracket()) {
      Adder();
    } else if (token.IsPoint()) {
      if (calculation_view_->display_up_->text().isEmpty()) {
        calculation_view_->display_up_->setText("0.");
      } else if (!calculation_view_->display_up_->text().contains('.')) {
        calculation_view_->display_up_->setText(
            calculation_view_->display_up_->text() + ".");
      }
    } else if (token.IsOpenBracket()) {
      QChar last_char;
      bool digit_end_input_line = false;
      bool display_down_is_empty =
          calculation_view_->display_down_->text().isEmpty();
      if (!display_down_is_empty) {
        last_char = calculation_view_->display_down_->text().at(
            calculation_view_->display_down_->text().length() - 1);
        if (last_char.isDigit()) {
          digit_end_input_line = true;
        }
      }
      if ((display_down_is_empty || !digit_end_input_line) && last_char != ')') {
        calculation_view_->display_down_->setText(
            calculation_view_->display_down_->text() + text_);
        calculation_view_->output_line_.push_back(text_);
      }
    } else if (text_ == "AC") {
      calculation_view_->display_down_->clear();
      calculation_view_->display_up_->clear();
      calculation_view_->oper_->clear();
      calculation_view_->x_var_->setStyleSheet(
          "background: #008080; color: white; font: 12pt");
      calculation_view_->x_var_->update();
    } else if (text_ == "MC") {
      calculation_view_->display_hystory_->clear();
    } else if (text_.at(0) == QChar(0x000000B1)) {
      if (!calculation_view_->display_up_->text().isEmpty()) {
        QChar first_char = calculation_view_->display_up_->text().at(0);
        if (first_char.isDigit()) {
          calculation_view_->display_up_->setText(
              "-" + calculation_view_->display_up_->text());
        } else {
          calculation_view_->display_up_->setText(
              calculation_view_->display_up_->text().remove(0, 1));
        }
      }
    }
  }
}

void s21::CalculatorButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
  color_.setRgb(58, 120, 101);
  update();
}

void s21::CalculatorButton::EqCase() noexcept {
  if (calculation_view_->display_up_ == calculation_view_->display_x_var_){
    calculation_view_->display_down_->setText(calculation_view_->display_down_->text() + "=");
  } else {
    Adder();
  }
  if (calculation_view_->default_mode_->isChecked() || calculation_view_->x_var_->isChecked()) {
      DefaultMode();
  } else {
      FunctionMode();
  }
  calculation_view_->output_line_.clear();
  calculation_view_->default_mode_->setChecked(true);
  calculation_view_->display_up_->clear();
  if (calculation_view_->display_up_ == calculation_view_->display_x_var_) {
    calculation_view_->display_up_ = calculation_view_->fake_display;
  }
  calculation_view_->x_var_->setStyleSheet("background: #008080; color: white; font: 12pt");
}

void s21::CalculatorButton::DefaultMode() noexcept {
    bool check_conversion = true;
    std::list<std::string> stdList;
    for (const QString &qString : calculation_view_->output_line_) {
      if (qString == "x") {
          stdList.push_back(calculation_view_->display_x_var_->text().toStdString());
  //        qWarning() << calculation_view_->display_x_var_->text();
      } else {
          stdList.push_back(qString.toStdString());
  //        qWarning() << qString;
      }
    }
    try {
      converter_ = new ExpressionConverter(stdList);
    } catch (...) {
      check_conversion = false;
    }
    if (check_conversion) {
      calculator_ = new Calculation(converter_->GetOut());
      calculation_view_->display_down_->setText(
          calculation_view_->display_down_->text() +
          QString::number(calculator_->GetValue()));
      calculation_view_->display_hystory_->append(
          calculation_view_->display_down_->text());
      calculation_view_->display_down_->clear();
      delete calculator_;
      delete converter_;
    } else {
      calculation_view_->display_hystory_->append(
          calculation_view_->display_down_->text() + "(Wrong expression)");
      calculation_view_->display_down_->clear();
      (new QErrorMessage())->showMessage("Wrong expression");
    }
}

void s21::CalculatorButton::FunctionMode() noexcept {

}

void s21::CalculatorButton::Adder() const noexcept {
  PointAdder();
  if (!calculation_view_->display_up_->text().isEmpty()) {
    calculation_view_->output_line_.push_back(
        calculation_view_->display_up_->text());
  }
  calculation_view_->output_line_.push_back(text_);
  if (!calculation_view_->display_up_->text().isEmpty() && calculation_view_->display_up_->text().at(0) == '-') {
    calculation_view_->display_down_->setText(
        calculation_view_->display_down_->text() + "(" +
        calculation_view_->display_up_->text() + ")" + text_);
  } else {
    calculation_view_->display_down_->setText(
        calculation_view_->display_down_->text() +
        calculation_view_->display_up_->text() + text_);
  }
  calculation_view_->display_up_->clear();
  //  if (calculation_view_->display_up_ != calculation_view_->display_x_var_) calculation_view_->display_up_->clear();
}

void s21::CalculatorButton::PointAdder() const noexcept {
    if (!calculation_view_->display_up_->text().isEmpty()) {
      QChar last_char = calculation_view_->display_up_->text().at(
          calculation_view_->display_up_->text().length() - 1);
      if (last_char == '.') {
        calculation_view_->display_up_->setText(
            calculation_view_->display_up_->text() + "0");
      }
    }
}

bool s21::CalculatorButton::CheckDisplaysStatus() const noexcept {
  bool check_one = false;
  if (!calculation_view_->display_up_->text().isEmpty()) {
    QChar last_char_one = calculation_view_->display_up_->text().at(
        calculation_view_->display_up_->text().length() - 1);
    if (last_char_one.isDigit() || last_char_one == '.' || last_char_one == 'x')
      check_one = true;
  }
  if (!calculation_view_->display_down_->text().isEmpty()) {
    QChar last_char_two = calculation_view_->display_down_->text().at(
        calculation_view_->display_down_->text().length() - 1);
    if (last_char_two.isDigit() || last_char_two == ')' || last_char_two == '(')
      check_one = true;
  }
  return (check_one);
}

bool s21::CalculatorButton::CheckForAdd() const noexcept {
    bool check_one = false;
    bool check_two = false;
    if (calculation_view_->display_up_->text().isEmpty()) {
//        qWarning() << "olo";
        check_one = true;
    }
    if (!calculation_view_->display_up_->text().isEmpty()) {
        if (calculation_view_->display_up_->text().at(0) != 'x') {
            check_two = true;
        }
    }
    return (check_one || check_two);
};

