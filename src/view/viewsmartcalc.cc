#include "viewsmartcalc.h"

#include <QGraphicsProxyWidget>

s21::ViewSmartCalc::ViewSmartCalc(CalcControl *control, QWidget *parent)
    : QGraphicsView(parent), control_(control) {
  setRenderHint(QPainter::Antialiasing);
  setCacheMode(QGraphicsView::CacheNone);
  setWindowTitle("SmartCalc v2.0");
  setFrameStyle(0);
  setSceneRect(0, 0, 650, 800);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setFixedSize(650, 800);
  scene_ = new QGraphicsScene();
  scene_->setItemIndexMethod(QGraphicsScene::NoIndex);
  setScene(scene_);
  InitViewElement();
  graph_ = new QCustomPlot;
  GraphShow();
  AddWidgetAtScene();
  setBackgroundBrush(QBrush(Qt::darkCyan));
};

void s21::ViewSmartCalc::GraphShow() noexcept {
  graph_->addGraph();
  graph_->xAxis->setLabel("x");
  graph_->yAxis->setLabel("y");
  graph_->xAxis->setLabelColor(Qt::white);
  graph_->yAxis->setLabelColor(Qt::white);
  graph_->xAxis->setRange(x_min_->value(), x_max_->value());
  graph_->yAxis->setRange(y_min_->value(), y_max_->value());
  graph_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  graph_->setBackground(QBrush(Qt::darkCyan));
  graph_->setGeometry(300, 450, 350, 350);
}

void s21::ViewSmartCalc::SetNumOnDisplay(QString text) noexcept {
  bool check = true;
  if (!display_up_->text().contains('x')) {
    if (display_up_->text().contains('e')) {
      if ((display_up_->text().length() - display_up_->text().indexOf('e')) >
          2) {
        check = false;
      }
    }
    if (check) {
      display_up_->setText(display_up_->text() + text);
      oper_->clear();
    }
  }
}

void s21::ViewSmartCalc::SetXVarOnDisplay(QString text) noexcept {
  if (display_up_->text().isEmpty()) {
    display_up_->setText(text);
    oper_->clear();
  }
}

void s21::ViewSmartCalc::DisplayInputClear() noexcept {
  display_up_->clear();
  display_down_->clear();
  oper_->clear();
  x_var_->setStyleSheet("background: #008080; color: white; font: 12pt");
  control_->ClearModel();
}

void s21::ViewSmartCalc::SetDotOnDisplay() noexcept {
  if (display_up_->text().isEmpty()) {
    display_up_->setText("0.");
  } else if (!display_up_->text().contains('.') &&
             !display_up_->text().contains('x') &&
             !display_up_->text().contains('e')) {
    display_up_->setText(display_up_->text() + ".");
  }
}

void s21::ViewSmartCalc::SetUnarSign() noexcept {
  if (!display_up_->text().isEmpty()) {
    QChar first_char = display_up_->text().at(0);
    if (first_char.isDigit() || first_char == 'x') {
      display_up_->setText("-" + display_up_->text());
    } else {
      display_up_->setText(display_up_->text().remove(0, 1));
    }
  }
}

void s21::ViewSmartCalc::SetFunction(QString text) noexcept {
  if (display_up_->text().isEmpty()) {
    oper_->clear();
    display_down_->setText(display_down_->text() + text + "(");
    control_->AddValueInModel(text);
    control_->AddValueInModel("(");
  }
}

void s21::ViewSmartCalc::SetOper(QString text) noexcept {
  AddNumber();
  bool check_oper = CheckState();
  if (!check_oper) {
    oper_->setText(text);
    display_down_->setText(display_down_->text() + text);
    display_up_->clear();
    control_->AddValueInModel(text);
  }
}

void s21::ViewSmartCalc::SetOpenBracket(QString text) noexcept {
  if (display_down_->text().at(display_down_->text().length() - 1) != ')') {
    display_down_->setText(display_down_->text() + text);
    AddNumber();
    control_->AddValueInModel(text);
  }
}

void s21::ViewSmartCalc::SetClosedBracket(QString text) noexcept {
  AddNumber();
  bool check_oper = CheckState();
  if (!check_oper) {
    display_down_->setText(display_down_->text() + text);
    control_->AddValueInModel(text);
  }
}

void s21::ViewSmartCalc::ClearHystoryDisplay() noexcept {
  display_hystory_->clear();
}

void s21::ViewSmartCalc::CalculateCase() noexcept {
  if (!x_var_->isChecked()) {
    AddNumber();
  }
}

void s21::ViewSmartCalc::ScientificCase() noexcept {
  QChar last_char;
  if (!display_up_->text().isEmpty()) {
    last_char = display_up_->text().at(display_up_->text().length() - 1);
  }
  if (!display_up_->text().contains('e')) {
    display_up_->setText(display_up_->text() + "e");
  } else if (last_char == 'e' || last_char == '-') {
    if (last_char == '-') {
      display_up_->setText(
          display_up_->text().remove(display_up_->text().length() - 1, 1) +
          "+");
    } else {
      display_up_->setText(display_up_->text() + "+");
    }
  } else if (display_up_->text().at(display_up_->text().length() - 1) == '+') {
    display_up_->setText(
        display_up_->text().remove(display_up_->text().length() - 1, 1) + "-");
  }
}

void s21::ViewSmartCalc::SetAnswer(QString value) noexcept {
  display_hystory_->append(display_down_->text() + "=" + value);
  display_down_->clear();
}

void s21::ViewSmartCalc::AddNumber() noexcept {
  if (!display_up_->text().isEmpty()) {
    if (display_up_->text().at(0) == '-') {
      display_down_->setText(display_down_->text() + "(" + display_up_->text() +
                             ")");
      control_->AddValueInModel("(");
      control_->AddValueInModel(display_up_->text());
      control_->AddValueInModel(")");
    } else {
      display_down_->setText(display_down_->text() + display_up_->text());
      control_->AddValueInModel(display_up_->text());
    }
    display_up_->clear();
  }
}

// void s21::ViewSmartCalc::ECase() noexcept {}

// void s21::ViewSmartCalc::SetController(CalcControl &control) {
//   control_ = control;
// };

void s21::ViewSmartCalc::UpdateGraph(std::vector<double> x,
                                     std::vector<double> y) noexcept {
  graph_->clearGraphs();
  graph_->addGraph();
  graph_->xAxis->setRange(x_min_->value(), x_max_->value());
  graph_->yAxis->setRange(y_min_->value(), y_max_->value());
  QVector<double> q_x(x.begin(), x.end());
  QVector<double> q_y(y.begin(), y.end());
  graph_->graph(0)->setData(q_x, q_y);
  graph_->graph(0)->setLineStyle(QCPGraph::lsNone);
  QCPScatterStyle scatter_style =
      QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::white, 3.0);
  graph_->graph(0)->setScatterStyle(scatter_style);
  graph_->replot();
}

void s21::ViewSmartCalc::InitViewElement() {
  InitNumberButtton();
  InitOperatorButton();
  InitFunctionButton();
  InitTextElement();
  InitSpinBox();
};

void s21::ViewSmartCalc::InitNumberButtton() {
  btn_7_.setPos(10, 70);
  btn_7_.SetGeometry(50, 50);
  btn_7_.setText("7");
  connect(&btn_7_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_8_.setPos(70, 70);
  btn_8_.SetGeometry(50, 50);
  btn_8_.setText("8");
  connect(&btn_8_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_9_.setPos(130, 70);
  btn_9_.SetGeometry(50, 50);
  btn_9_.setText("9");
  connect(&btn_9_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_4_.setPos(10, 130);
  btn_4_.SetGeometry(50, 50);
  btn_4_.setText("4");
  connect(&btn_4_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_5_.setPos(70, 130);
  btn_5_.SetGeometry(50, 50);
  btn_5_.setText("5");
  connect(&btn_5_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_6_.setPos(130, 130);
  btn_6_.SetGeometry(50, 50);
  btn_6_.setText("6");
  connect(&btn_6_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_1_.setPos(10, 190);
  btn_1_.SetGeometry(50, 50);
  btn_1_.setText("1");
  connect(&btn_1_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_2_.setPos(70, 190);
  btn_2_.SetGeometry(50, 50);
  btn_2_.setText("2");
  connect(&btn_2_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_3_.setPos(130, 190);
  btn_3_.SetGeometry(50, 50);
  btn_3_.setText("3");
  connect(&btn_3_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_0_.setPos(70, 250);
  btn_0_.SetGeometry(50, 50);
  btn_0_.setText("0");
  connect(&btn_0_, &CalculatorButton::KeyPressed, control_, &CalcControl::Num);

  btn_point_.setPos(130, 250);
  btn_point_.SetGeometry(50, 50);
  btn_point_.setText(".");
  connect(&btn_point_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Dot);
};

void s21::ViewSmartCalc::InitOperatorButton() {
  btn_mod_.setPos(10, 10);
  btn_mod_.SetGeometry(50, 50);
  btn_mod_.setText("%");
  connect(&btn_mod_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::OperPressed);

  btn_div_.setPos(70, 10);
  btn_div_.SetGeometry(50, 50);
  btn_div_.setText("/");
  connect(&btn_div_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::OperPressed);

  btn_mul_.setPos(130, 10);
  btn_mul_.SetGeometry(50, 50);
  btn_mul_.setText("*");
  connect(&btn_mul_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::OperPressed);

  btn_minus_.setPos(190, 10);
  btn_minus_.SetGeometry(50, 50);
  btn_minus_.setText("-");
  connect(&btn_minus_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::OperPressed);

  btn_plus_.setPos(190, 70);
  btn_plus_.SetGeometry(50, 50);
  btn_plus_.setText("+");
  connect(&btn_plus_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::OperPressed);

  btn_open_br_.setPos(190, 130);
  btn_open_br_.SetGeometry(50, 50);
  btn_open_br_.setText("(");
  connect(&btn_open_br_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::OpenBraketPressed);

  btn_closed_br_.setPos(190, 190);
  btn_closed_br_.SetGeometry(50, 50);
  btn_closed_br_.setText(")");
  connect(&btn_closed_br_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::ClosedBraketPressed);

  btn_eq_.setPos(190, 250);
  btn_eq_.SetGeometry(50, 50);
  btn_eq_.setText("=");
  connect(&btn_eq_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::EqualPressed);

  btn_e_.setPos(250, 250);
  btn_e_.SetGeometry(50, 50);
  btn_e_.setText("e");
  connect(&btn_e_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::ScientificNotation);

  btn_exp_.setPos(250, 130);
  btn_exp_.SetGeometry(50, 50);
  btn_exp_.setText("^");
  connect(&btn_exp_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::OperPressed);

  btn_unar_.setPos(250, 190);
  btn_unar_.SetGeometry(50, 50);
  btn_unar_.setText(QChar(0x000000B1));
  connect(&btn_unar_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::UnarClicked);
};

void s21::ViewSmartCalc::InitFunctionButton() {
  btn_sin_.setPos(330, 10);
  btn_sin_.SetGeometry(50, 150);
  btn_sin_.setText("sin");
  connect(&btn_sin_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_cos_.setPos(330, 70);
  btn_cos_.SetGeometry(50, 150);
  btn_cos_.setText("cos");
  connect(&btn_cos_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_tan_.setPos(330, 130);
  btn_tan_.SetGeometry(50, 150);
  btn_tan_.setText("tan");
  connect(&btn_tan_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_asin_.setPos(490, 10);
  btn_asin_.SetGeometry(50, 150);
  btn_asin_.setText("asin");
  connect(&btn_asin_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_acos_.setPos(490, 70);
  btn_acos_.SetGeometry(50, 150);
  btn_acos_.setText("acos");
  connect(&btn_acos_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_atan_.setPos(490, 130);
  btn_atan_.SetGeometry(50, 150);
  btn_atan_.setText("atan");
  connect(&btn_atan_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_ln_.setPos(330, 190);
  btn_ln_.SetGeometry(50, 150);
  btn_ln_.setText("ln");
  connect(&btn_ln_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_log_.setPos(490, 190);
  btn_log_.SetGeometry(50, 150);
  btn_log_.setText("log");
  connect(&btn_log_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_sqrt_.setPos(490, 250);
  btn_sqrt_.SetGeometry(50, 150);
  btn_sqrt_.setText("sqrt");
  connect(&btn_sqrt_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Function);

  btn_ac_.setPos(250, 10);
  btn_ac_.SetGeometry(50, 50);
  btn_ac_.setText("AC");
  connect(&btn_ac_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::Clear);

  btn_mc_.setPos(250, 70);
  btn_mc_.SetGeometry(50, 50);
  btn_mc_.setText("MC");
  connect(&btn_mc_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::MemoryClear);

  btn_x_.setPos(10, 250);
  btn_x_.SetGeometry(50, 50);
  btn_x_.setText("x");
  connect(&btn_x_, &CalculatorButton::KeyPressed, control_, &CalcControl::XVar);

  btn_graph_.setPos(330, 250);
  btn_graph_.SetGeometry(50, 150);
  btn_graph_.setText("Graph");
  connect(&btn_graph_, &CalculatorButton::KeyPressed, control_,
          &CalcControl::GraphPressed);

  btn_show_credit_.setPos(490, 310);
  btn_show_credit_.SetGeometry(25, 150);
  btn_show_credit_.setText("Credit_Calc");
  // connect(&btn_show_credit_, &CalculatorButton::KeyPressed, &control_,
  //         &CalcControl::StartCredit);

  btn_show_deposit_.setPos(490, 340);
  btn_show_deposit_.SetGeometry(25, 150);
  btn_show_deposit_.setText("Deposit_calc");
};

void s21::ViewSmartCalc::InitTextElement() {
  display_up_ = new QLineEdit();
  display_up_->setGeometry(10, 400, 290, 30);
  display_up_->setReadOnly(true);
  display_up_->setStyleSheet("background: #326759; color: white; font: 15pt");

  display_down_ = new QLineEdit();
  display_down_->setGeometry(10, 310, 290, 30);
  display_down_->setReadOnly(true);
  display_down_->setStyleSheet("background: #326759; color: white; font: 15pt");

  display_x_var_ = new QLineEdit();
  display_x_var_->setGeometry(400, 310, 80, 30);
  display_x_var_->setReadOnly(true);
  display_x_var_->setStyleSheet(
      "background: #326759; color: white; font: 15pt");

  display_hystory_ = new QTextEdit();
  display_hystory_->setGeometry(10, 440, 290, 290);
  display_hystory_->setReadOnly(true);
  display_hystory_->setStyleSheet(
      "background: #326759; color: white; font: 15pt");

  oper_ = new QLabel();
  oper_->setGeometry(10, 350, 30, 30);
  oper_->setStyleSheet("background: #008080; color: white; font: 15pt");

  nickname_ = new QLabel();
  nickname_->setGeometry(10, 750, 200, 70);
  nickname_->setStyleSheet("background: #008080; color: #4400cc; font: 22pt");
  nickname_->setText("@mammiemi");

  x_min_label_ = new QLabel();
  x_min_label_->setGeometry(330, 380, 45, 20);
  x_min_label_->setStyleSheet("background: #008080; color: white; font: 12pt");
  x_min_label_->setText("x.min:");

  x_max_label_ = new QLabel();
  x_max_label_->setGeometry(470, 380, 45, 20);
  x_max_label_->setStyleSheet("background: #008080; color: white; font: 12pt");
  x_max_label_->setText("x.max:");

  y_min_label_ = new QLabel();
  y_min_label_->setGeometry(330, 410, 45, 20);
  y_min_label_->setStyleSheet("background: #008080; color: white; font: 12pt");
  y_min_label_->setText("y.min:");

  y_max_label_ = new QLabel();
  y_max_label_->setGeometry(470, 410, 45, 20);
  y_max_label_->setStyleSheet("background: #008080; color: white; font: 12pt");
  y_max_label_->setText("y.max:");

  x_var_ = new QRadioButton();
  x_var_->setGeometry(330, 310, 80, 20);
  x_var_->setText("x-var");
  x_var_->setStyleSheet("background: #008080; color: white; font: 12pt");
  connect(x_var_, &QRadioButton::clicked, control_, &CalcControl::ModeSelect);

  // x_func_ = new QRadioButton();
  // x_func_->setGeometry(330, 330, 80, 20);
  // x_func_->setText("x-func");
  // x_func_->setStyleSheet("background: #008080; color: white; font: 12pt");
  // connect(x_func_, &QRadioButton::clicked, &control_,
  // &CalcControl::ModeSelect);

  default_mode_ = new QRadioButton();
  default_mode_->setGeometry(330, 330, 80, 20);
  default_mode_->setText("default");
  default_mode_->setChecked(true);
  default_mode_->setStyleSheet("background: #008080; color: white; font: 12pt");
  connect(default_mode_, &QRadioButton::clicked, control_,
          &CalcControl::ModeSelect);

  x_group_ = new QButtonGroup();
  x_group_->addButton(x_var_);
  // x_group_->addButton(x_func_);
  x_group_->addButton(default_mode_);
};

void s21::ViewSmartCalc::InitSpinBox() {
  x_min_ = new QSpinBox();
  x_min_->setGeometry(380, 380, 80, 20);
  x_min_->setRange(-1000000, 1000000);
  x_min_->setValue(-10);
  x_min_->setStyleSheet("background: #326759; color: white; font: 10pt");

  x_max_ = new QSpinBox();
  x_max_->setGeometry(520, 380, 80, 20);
  x_max_->setRange(-1000000, 1000000);
  x_max_->setValue(10);
  x_max_->setStyleSheet("background: #326759; color: white; font: 10pt");

  y_min_ = new QSpinBox();
  y_min_->setGeometry(380, 410, 80, 20);
  y_min_->setRange(-1000000, 1000000);
  y_min_->setValue(-3);
  y_min_->setStyleSheet("background: #326759; color: white; font: 10pt");

  y_max_ = new QSpinBox();
  y_max_->setGeometry(520, 410, 80, 20);
  y_max_->setRange(-1000000, 1000000);
  y_max_->setValue(3);
  y_max_->setStyleSheet("background: #326759; color: white; font: 10pt");
};

void s21::ViewSmartCalc::AddWidgetAtScene() {
  scene_->addItem(&btn_7_);
  scene_->addItem(&btn_8_);
  scene_->addItem(&btn_9_);
  scene_->addItem(&btn_4_);
  scene_->addItem(&btn_5_);
  scene_->addItem(&btn_6_);
  scene_->addItem(&btn_1_);
  scene_->addItem(&btn_2_);
  scene_->addItem(&btn_3_);
  scene_->addItem(&btn_0_);
  scene_->addItem(&btn_mod_);
  scene_->addItem(&btn_div_);
  scene_->addItem(&btn_mul_);
  scene_->addItem(&btn_minus_);
  scene_->addItem(&btn_plus_);
  scene_->addItem(&btn_point_);
  scene_->addItem(&btn_open_br_);
  scene_->addItem(&btn_closed_br_);
  scene_->addItem(&btn_eq_);
  scene_->addItem(&btn_e_);
  scene_->addItem(&btn_unar_);
  scene_->addItem(&btn_exp_);
  scene_->addItem(&btn_sin_);
  scene_->addItem(&btn_cos_);
  scene_->addItem(&btn_tan_);
  scene_->addItem(&btn_asin_);
  scene_->addItem(&btn_acos_);
  scene_->addItem(&btn_atan_);
  scene_->addItem(&btn_sqrt_);
  scene_->addItem(&btn_ln_);
  scene_->addItem(&btn_log_);
  scene_->addItem(&btn_ac_);
  scene_->addItem(&btn_mc_);
  scene_->addItem(&btn_x_);
  scene_->addItem(&btn_show_credit_);
  scene_->addItem(&btn_show_deposit_);
  scene_->addItem(&btn_graph_);

  scene_->addWidget(x_var_);
  // scene_->addWidget(x_func_);
  scene_->addWidget(default_mode_);
  scene_->addWidget(oper_);
  scene_->addWidget(display_hystory_);
  scene_->addWidget(display_up_);
  scene_->addWidget(display_down_);
  scene_->addWidget(display_x_var_);
  scene_->addWidget(nickname_);

  scene_->addWidget(x_min_);
  scene_->addWidget(x_max_);
  scene_->addWidget(y_min_);
  scene_->addWidget(y_max_);

  scene_->addWidget(x_min_label_);
  scene_->addWidget(x_max_label_);
  scene_->addWidget(y_min_label_);
  scene_->addWidget(y_max_label_);

  scene_->addWidget(graph_);
};

void s21::ViewSmartCalc::DisplayChange() {
  display_up_->clear();
  if (display_up_ == display_x_var_) {
    display_up_ = fake_display;
    fake_display = nullptr;
  }
};

void s21::ViewSmartCalc::RadioClicked() {
  if (x_var_->isChecked()) {
    AddNumber();
    if (!pointer_swap_) {
      fake_display = display_up_;
      display_up_ = display_x_var_;
      pointer_swap_ = true;
    }
  } else if (pointer_swap_) {
    DisplayChange();
    pointer_swap_ = false;
  }
};

bool s21::ViewSmartCalc::CheckState() const noexcept {
  bool result = false;
  if (!display_down_->text().isEmpty()) {
    QChar last_char =
        display_down_->text().at(display_down_->text().length() - 1);
    result = (last_char == '-' || last_char == '+' || last_char == '/' ||
              last_char == '*' || last_char == '%' || last_char == '^');
  }
  return result;
}

double s21::ViewSmartCalc::GetXMin() { return x_min_->value(); }
double s21::ViewSmartCalc::GetXmax() { return x_max_->value(); }

bool s21::ViewSmartCalc::XvarIsChecked() const noexcept {
  return x_var_->isChecked();
}

double s21::ViewSmartCalc::GetDisplayXvarValue() const noexcept {
  return std::stod(display_x_var_->text().toStdString());
}

// void s21::ViewSmartCalc::CreditCaclStart() noexcept {
//   std::cout << &credit_calc_ << " kek" << std::endl;
//   control_.SetCreditView(&credit_calc_);
//   credit_calc_.SetControl(control_);
//   credit_calc_.show();
// }