#include "viewsmartcalc.h"
#include <QGraphicsProxyWidget>

s21::ViewSmartCalc::ViewSmartCalc(QWidget *parent) : QGraphicsView(parent) {

  setRenderHint(QPainter::Antialiasing);
  setCacheMode(QGraphicsView::CacheNone);
  setWindowTitle("SmartCalc v2.0");
  setFrameStyle(0);
  setSceneRect(0, 0, 800, 800);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setFixedSize(800, 800);
  scene_.setItemIndexMethod(QGraphicsScene::NoIndex);
  setScene(&scene_);
  InitViewElement();
  setBackgroundBrush(QBrush(Qt::darkCyan));
};

s21::ViewSmartCalc::~ViewSmartCalc() {
  if (display_up_)
    delete display_up_;
  if (display_down_)
    delete display_down_;
  if (oper_)
    delete oper_;
};

void s21::ViewSmartCalc::InitViewElement() {
  InitNumberButtton();
  InitOperatorButton();
  InitFunctionButton();
  InitTextElement();
  AddWidgetAtScene();
};

void s21::ViewSmartCalc::InitNumberButtton() {
  btn_7_.setPos(10, 70);
  btn_7_.SetGeometry(50, 50);
  btn_7_.setText("7");

  btn_8_.setPos(70, 70);
  btn_8_.SetGeometry(50, 50);
  btn_8_.setText("8");

  btn_9_.setPos(130, 70);
  btn_9_.SetGeometry(50, 50);
  btn_9_.setText("9");

  btn_4_.setPos(10, 130);
  btn_4_.SetGeometry(50, 50);
  btn_4_.setText("4");

  btn_5_.setPos(70, 130);
  btn_5_.SetGeometry(50, 50);
  btn_5_.setText("5");

  btn_6_.setPos(130, 130);
  btn_6_.SetGeometry(50, 50);
  btn_6_.setText("6");

  btn_1_.setPos(10, 190);
  btn_1_.SetGeometry(50, 50);
  btn_1_.setText("1");

  btn_2_.setPos(70, 190);
  btn_2_.SetGeometry(50, 50);
  btn_2_.setText("2");

  btn_3_.setPos(130, 190);
  btn_3_.SetGeometry(50, 50);
  btn_3_.setText("3");

  btn_0_.setPos(10, 250);
  btn_0_.SetGeometry(50, 110);
  btn_0_.setText("0");

  btn_point_.setPos(130, 250);
  btn_point_.SetGeometry(50, 50);
  btn_point_.setText(".");
}

void s21::ViewSmartCalc::InitOperatorButton() {
  btn_mod_.setPos(10, 10);
  btn_mod_.SetGeometry(50, 50);
  btn_mod_.setText("%");

  btn_div_.setPos(70, 10);
  btn_div_.SetGeometry(50, 50);
  btn_div_.setText("/");

  btn_mul_.setPos(130, 10);
  btn_mul_.SetGeometry(50, 50);
  btn_mul_.setText("*");

  btn_minus_.setPos(190, 10);
  btn_minus_.SetGeometry(50, 50);
  btn_minus_.setText("-");

  btn_plus_.setPos(190, 70);
  btn_plus_.SetGeometry(50, 50);
  btn_plus_.setText("+");

  btn_open_br_.setPos(190, 130);
  btn_open_br_.SetGeometry(50, 50);
  btn_open_br_.setText("(");

  btn_closed_br_.setPos(190, 190);
  btn_closed_br_.SetGeometry(50, 50);
  btn_closed_br_.setText(")");

  btn_eq_.setPos(190, 250);
  btn_eq_.SetGeometry(50, 110);
  btn_eq_.setText("=");

  btn_exp_.setPos(250, 130);
  btn_exp_.SetGeometry(50, 50);
  btn_exp_.setText("^");

  btn_unar_.setPos(250, 190);
  btn_unar_.SetGeometry(50, 50);
  btn_unar_.setText(QChar(0x000000B1));
};

void s21::ViewSmartCalc::InitFunctionButton() {
  btn_sin_.setPos(330, 10);
  btn_sin_.SetGeometry(50, 150);
  btn_sin_.setText("sin");

  btn_cos_.setPos(330, 70);
  btn_cos_.SetGeometry(50, 150);
  btn_cos_.setText("cos");

  btn_tan_.setPos(330, 130);
  btn_tan_.SetGeometry(50, 150);
  btn_tan_.setText("tan");

  btn_asin_.setPos(490, 10);
  btn_asin_.SetGeometry(50, 150);
  btn_asin_.setText("asin");

  btn_acos_.setPos(490, 70);
  btn_acos_.SetGeometry(50, 150);
  btn_acos_.setText("acos");

  btn_atan_.setPos(490, 130);
  btn_atan_.SetGeometry(50, 150);
  btn_atan_.setText("atan");

  btn_ln_.setPos(330, 190);
  btn_ln_.SetGeometry(50, 150);
  btn_ln_.setText("ln");

  btn_log_.setPos(490, 190);
  btn_log_.SetGeometry(50, 150);
  btn_log_.setText("log");

  btn_sqrt_.setPos(330, 250);
  btn_sqrt_.SetGeometry(50, 310);
  btn_sqrt_.setText("sqrt");

  btn_ac_.setPos(250, 10);
  btn_ac_.SetGeometry(50, 50);
  btn_ac_.setText("AC");

  btn_mc_.setPos(250, 70);
  btn_mc_.SetGeometry(50, 50);
  btn_mc_.setText("MC");
};

void s21::ViewSmartCalc::InitTextElement() {
  display_up_ = new QLineEdit();
  display_up_->setGeometry(10, 310, 290, 30);
  display_up_->setReadOnly(true);
  display_up_->setStyleSheet("background: #326759; color: white; font: 15pt");

  display_down_ = new QLineEdit();
  display_down_->setGeometry(10, 400, 290, 30);
  display_down_->setReadOnly(true);
  display_down_->setStyleSheet("background: #326759; color: white; font: 15pt");

  display_x_var_ = new QLineEdit();
  display_x_var_->setGeometry(420, 310, 80, 30);
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

  x_var_ = new QRadioButton();
  x_var_->setGeometry(330, 310, 80, 20);
  x_var_->setText("x-var");
  x_var_->setStyleSheet("background: #008080; color: white; font: 12pt");
  connect(x_var_, &QRadioButton::clicked, this, [=]() { RadioClicked(); });

  x_func_ = new QRadioButton();
  x_func_->setGeometry(330, 330, 80, 20);
  x_func_->setText("x-func");
  x_func_->setStyleSheet("background: #008080; color: white; font: 12pt");
  connect(x_func_, &QRadioButton::clicked, this, [=]() { RadioClicked(); });

  default_mode_ = new QRadioButton();
  default_mode_->setGeometry(330, 350, 80, 20);
  default_mode_->setText("default");
  default_mode_->setChecked(true);
  default_mode_->setStyleSheet("background: #008080; color: white; font: 12pt");
  connect(default_mode_, &QRadioButton::clicked, this,
          [=]() { RadioClicked(); });

  x_group_ = new QButtonGroup();
  x_group_->addButton(x_var_);
  x_group_->addButton(x_func_);
  x_group_->addButton(default_mode_);
};

void s21::ViewSmartCalc::AddWidgetAtScene() {
  scene_.addItem(&btn_7_);
  scene_.addItem(&btn_8_);
  scene_.addItem(&btn_9_);
  scene_.addItem(&btn_4_);
  scene_.addItem(&btn_5_);
  scene_.addItem(&btn_6_);
  scene_.addItem(&btn_1_);
  scene_.addItem(&btn_2_);
  scene_.addItem(&btn_3_);
  scene_.addItem(&btn_0_);
  scene_.addItem(&btn_mod_);
  scene_.addItem(&btn_div_);
  scene_.addItem(&btn_mul_);
  scene_.addItem(&btn_minus_);
  scene_.addItem(&btn_plus_);
  scene_.addItem(&btn_point_);
  scene_.addItem(&btn_open_br_);
  scene_.addItem(&btn_closed_br_);
  scene_.addItem(&btn_eq_);
  scene_.addItem(&btn_unar_);
  scene_.addItem(&btn_exp_);
  scene_.addItem(&btn_sin_);
  scene_.addItem(&btn_cos_);
  scene_.addItem(&btn_tan_);
  scene_.addItem(&btn_asin_);
  scene_.addItem(&btn_acos_);
  scene_.addItem(&btn_atan_);
  scene_.addItem(&btn_sqrt_);
  scene_.addItem(&btn_ln_);
  scene_.addItem(&btn_log_);
  scene_.addItem(&btn_ac_);
  scene_.addItem(&btn_mc_);

  scene_.addWidget(x_var_);
  scene_.addWidget(x_func_);
  scene_.addWidget(default_mode_);
  scene_.addWidget(oper_);
  scene_.addWidget(display_hystory_);
  scene_.addWidget(display_up_);
  scene_.addWidget(display_down_);
  scene_.addWidget(display_x_var_);
}

void s21::ViewSmartCalc::DisplayChange() {
  display_up_->clear();
  display_up_ = fake_display;
}

void s21::ViewSmartCalc::RadioClicked() {
  if (x_var_->isChecked()) {
    fake_display = display_up_;
    display_up_ = display_x_var_;
  } else if (default_mode_->isChecked()) {
    DisplayChange();
  } else if (x_func_->isChecked()) {
    DisplayChange();
  }
};
