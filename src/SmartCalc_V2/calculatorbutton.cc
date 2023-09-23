#include "calclulatorbutton.h"
#include "viewsmartcalc.h"
#include "viewcreditcalc.h"

s21::CalculatorButton::CalculatorButton(ViewSmartCalc *parent)
    : parent_(parent) {
  color_.setRgb(58, 120, 101);
  setAcceptHoverEvents(true);
};

s21::CalculatorButton::CalculatorButton(ViewCreditCalc *parent)
    : parent_cred_(parent) {
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
  if (parent_ != nullptr) {
    Element token(text_.toStdString());
    if (token.IsEq()) {
      EqCase();
    } else if (token.IsNumber() && CheckForAdd()) {
      parent_->oper_->clear();
      parent_->display_up_->setText(
          parent_->display_up_->text() + text_);
    } else if (token.IsX()) {
      if (CheckForAdd()) {
          parent_->display_up_->setText(text_);
          parent_->x_var_->setStyleSheet("background: #008080; color: red; font: 12pt");
      }
    } else if (token.IsOperator() && CheckDisplaysStatus()) {
      parent_->oper_->setText(text_);
      Adder();
    } else if (token.IsFunciotn() &&
               parent_->display_up_->text().isEmpty()) {
      parent_->oper_->clear();
      parent_->output_line_.push_back(text_);
      parent_->output_line_.push_back("(");
      parent_->display_down_->setText(
          parent_->display_down_->text() + text_ + " (");
    } else if (token.IsClosedBracket()) {
      Adder();
    } else if (token.IsPoint()) {
      if (parent_->display_up_->text().isEmpty()) {
        parent_->display_up_->setText("0.");
      } else if (!parent_->display_up_->text().contains('.')) {
        parent_->display_up_->setText(
            parent_->display_up_->text() + ".");
      }
    } else if (token.IsOpenBracket()) {
      QChar last_char;
      bool digit_end_input_line = false;
      bool display_down_is_empty =
          parent_->display_down_->text().isEmpty();
      if (!display_down_is_empty) {
        last_char = parent_->display_down_->text().at(
            parent_->display_down_->text().length() - 1);
        if (last_char.isDigit()) {
          digit_end_input_line = true;
        }
      }
      if ((display_down_is_empty || !digit_end_input_line) && last_char != ')') {
        parent_->display_down_->setText(
            parent_->display_down_->text() + text_);
        parent_->output_line_.push_back(text_);
      }
    } else if (text_ == "AC") {
      parent_->display_down_->clear();
      parent_->display_up_->clear();
      parent_->oper_->clear();
      parent_->x_var_->setStyleSheet(
          "background: #008080; color: white; font: 12pt");
      parent_->x_var_->update();
    } else if (text_ == "MC") {
      parent_->display_hystory_->clear();
    } else if (text_.at(0) == QChar(0x000000B1)) {
      if (!parent_->display_up_->text().isEmpty()) {
        QChar first_char = parent_->display_up_->text().at(0);
        if (first_char.isDigit()) {
          parent_->display_up_->setText(
              "-" + parent_->display_up_->text());
        } else {
          parent_->display_up_->setText(
              parent_->display_up_->text().remove(0, 1));
        }
      }
    } else if (text_ == "Credit_Calc") {
        parent_->credit_calc_.show();
    }
  } else if (parent_cred_ != nullptr) {
    if (text_ == "Clear") {
        parent_cred_->SetEveryMonthPay(0);
        parent_cred_->SetOverpay(0);
        parent_cred_->SetOverpaySum(0);
        parent_cred_->SetZeroSpin();
    } else if (parent_cred_->GetChecked()) {
        AnuitetCalc *credit = new AnuitetCalc(parent_cred_->GetAllSum(), parent_cred_->GetPercent(), parent_cred_->GetTerm());
        parent_cred_->SetEveryMonthPay(credit->GetMountlyPay());
        parent_cred_->SetOverpaySum(credit->GetAllPay());
        parent_cred_->SetOverpay(credit->GetOverPay());
        delete credit;
    } else {
        DiferenttCalc *credit = new DiferenttCalc(parent_cred_->GetAllSum(), parent_cred_->GetPercent(), parent_cred_->GetTerm());
        parent_cred_->SetDiferentEveryMountPayGraph();
        parent_cred_->SetOverpaySum(credit->GetAllPay());
        parent_cred_->SetOverpay(credit->GetOverPay());
        for (int i = 0; i < parent_cred_->GetTerm(); ++i) {
            parent_cred_->SetDifMounthPay(i + 1, credit->GetMountlyPay(i));
        }
        delete credit;
    }
  }
};

void s21::CalculatorButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
  color_.setRgb(58, 120, 101);
  update();
}

void s21::CalculatorButton::EqCase() noexcept {
  if (parent_->display_up_ == parent_->display_x_var_){
    parent_->display_down_->setText(parent_->display_down_->text() + "=");
  } else {
    Adder();
  }
  if (parent_->default_mode_->isChecked() || parent_->x_var_->isChecked()) {
      DefaultMode();
  } else {
      FunctionMode();
  }
  parent_->output_line_.clear();
  parent_->default_mode_->setChecked(true);
  parent_->display_up_->clear();
  if (parent_->display_up_ == parent_->display_x_var_) {
    parent_->display_up_ = parent_->fake_display;
  }
  parent_->x_var_->setStyleSheet("background: #008080; color: white; font: 12pt");
};

void s21::CalculatorButton::DefaultMode() noexcept {
    bool check_conversion = true;
    std::list<std::string> stdList;
    for (const QString &qString : parent_->output_line_) {
      if (qString == "x") {
          stdList.push_back(parent_->display_x_var_->text().toStdString());
      } else {
          stdList.push_back(qString.toStdString());
      }
    }
    try {
      converter_ = new ExpressionConverter(stdList);
    } catch (...) {
      check_conversion = false;
    }
    if (check_conversion) {
      calculator_ = new Calculation(converter_->GetOut());
      parent_->display_down_->setText(
          parent_->display_down_->text() +
          QString::number(calculator_->GetValue(), 'f', 7));
      parent_->display_hystory_->append(
          parent_->display_down_->text());
      parent_->display_down_->clear();
      delete calculator_;
      delete converter_;
    } else {
      parent_->display_hystory_->append(
          parent_->display_down_->text() + "(Wrong expression)");
      parent_->display_down_->clear();
      (new QErrorMessage())->showMessage("Wrong expression");
    }
};

void s21::CalculatorButton::FunctionMode() noexcept {
    double x_min_value = parent_->x_min_->value();
    double x_max_value = parent_->x_max_->value();

    QVector<double> x(8*(x_max_value - x_min_value));
    QVector<double> y(8*(x_max_value - x_min_value));
    bool check_conversion = true;
    for (int i = 0; x_min_value < x_max_value; x_min_value += 0.125, i++) {
        x[i] = x_min_value;
        std::list<std::string> stdList;
        for (const QString &qString : parent_->output_line_) {
          if (qString == "x") {
              stdList.push_back(std::to_string(x_min_value));
              std::cout << "lol";
          } else {
              stdList.push_back(qString.toStdString());
          }

        }
        try {
          converter_ = new ExpressionConverter(stdList);
        } catch (...) {
          check_conversion = false;
        }
        if (check_conversion) {
          calculator_ = new Calculation(converter_->GetOut());
          y[i] = calculator_->GetValue();
          delete calculator_;
          delete converter_;
        } else {
           (new QErrorMessage())->showMessage("Wrong expression");
            break;
        }
    }
    if (check_conversion) parent_->GraphShow(x, y);
};

void s21::CalculatorButton::Adder() const noexcept {
  if (parent_->display_up_) {
    PointAdder();
  }
  if (!parent_->display_up_->text().isEmpty()) {
    parent_->output_line_.push_back(
        parent_->display_up_->text());
  }
  parent_->output_line_.push_back(text_);
  if (!parent_->display_up_->text().isEmpty() && parent_->display_up_->text().at(0) == '-') {
    parent_->display_down_->setText(
        parent_->display_down_->text() + "(" +
        parent_->display_up_->text() + ")" + text_);
  } else {
    parent_->display_down_->setText(
        parent_->display_down_->text() +
        parent_->display_up_->text() + text_);
  }
  parent_->display_up_->clear();
  //  if (parent_->display_up_ != parent_->display_x_var_) parent_->display_up_->clear();
};

void s21::CalculatorButton::PointAdder() const noexcept {
    if (!parent_->display_up_->text().isEmpty()) {
      QChar last_char = parent_->display_up_->text().at(
          parent_->display_up_->text().length() - 1);
      if (last_char == '.') {
        parent_->display_up_->setText(
            parent_->display_up_->text() + "0");
      }
    }
};

bool s21::CalculatorButton::CheckDisplaysStatus() const noexcept {
  bool check_one = false;
  if (!parent_->display_up_->text().isEmpty()) {
    QChar last_char_one = parent_->display_up_->text().at(
        parent_->display_up_->text().length() - 1);
    if (last_char_one.isDigit() || last_char_one == '.' || last_char_one == 'x')
      check_one = true;
  }
  if (!parent_->display_down_->text().isEmpty()) {
    QChar last_char_two = parent_->display_down_->text().at(
        parent_->display_down_->text().length() - 1);
    if (last_char_two.isDigit() || last_char_two == ')' || last_char_two == '(')
      check_one = true;
  }
  return (check_one);
};

bool s21::CalculatorButton::CheckForAdd() const noexcept {
    bool check_one = false;
    bool check_two = false;
    if (parent_->display_up_->text().isEmpty()) {
        check_one = true;
    }
    if (!parent_->display_up_->text().isEmpty()) {
        if (parent_->display_up_->text().at(0) != 'x') {
            check_two = true;
        }
    }
    return (check_one || check_two);
};

