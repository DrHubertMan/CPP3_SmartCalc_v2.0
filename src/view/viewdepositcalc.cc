#include "viewdepositcalc.h"

s21::ViewDepositCalc::ViewDepositCalc() {
  setAttribute(Qt::WA_QuitOnClose, false);
  setRenderHint(QPainter::Antialiasing);
  setCacheMode(QGraphicsView::CacheNone);
  setWindowTitle("Credit_Calc_V2.0");
  setFrameStyle(0);
  setSceneRect(0, 0, 500, 1000);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setFixedSize(500, 1000);
  scene_ = new QGraphicsScene();
  scene_->setItemIndexMethod(QGraphicsScene::NoIndex);
  setScene(scene_);
  setBackgroundBrush(QBrush(Qt::darkCyan));

  InitElement();
}

void s21::ViewDepositCalc::SetUpoloadList() noexcept {
  upload_list_->append(QString::number(upload_mounth_->value()) +
                       ". Month: sum - " +
                       QString::number(upload_sum_->value(), 'f', 2));
  upload_mounth_->setValue(0);
  upload_sum_->setValue(0);
}

void s21::ViewDepositCalc::SetDropedList() noexcept {
  drop_list_->append(QString::number(droped_mounth_->value()) +
                     ". Month: sum - " +
                     QString::number(droped_sum_->value(), 'f', 2));
  droped_mounth_->setValue(0);
  droped_sum_->setValue(0);
}

void s21::ViewDepositCalc::AddDeposit() noexcept {
  deposit_calc.AddDeposit(upload_mounth_->value(), upload_sum_->value());
}

void s21::ViewDepositCalc::AddWithdrawal() noexcept {
  deposit_calc.AddWithdrawal(droped_mounth_->value(), droped_sum_->value());
}

void s21::ViewDepositCalc::AllClear() noexcept {
  sum_deposit_->setValue(0);
  term_->setValue(0);
  percent_rate_->setValue(0);
  tax_rate_->setValue(0);
  capitalization_->setCheckState(Qt::Unchecked);

  upload_mounth_->setValue(0);
  upload_sum_->setValue(0);
  upload_list_->clear();

  droped_mounth_->setValue(0);
  droped_sum_->setValue(0);
  drop_list_->clear();

  output_->clear();
}

void s21::ViewDepositCalc::Calculate() noexcept {
  deposit_calc.SetPrincipal(sum_deposit_->value());
  deposit_calc.SetTerm(term_->value());
  deposit_calc.SetPercentRate(percent_rate_->value());
  deposit_calc.SetCaptalization(capitalization_->checkState());
  deposit_calc.SetPeriodicity(payment_frequency_->currentIndex());
}

int s21::ViewDepositCalc::GetAddMonth() noexcept {
  return upload_mounth_->value();
}

int s21::ViewDepositCalc::GetDropMonth() noexcept {
  return droped_mounth_->value();
}

double s21::ViewDepositCalc::GetAddSum() noexcept {
  return upload_sum_->value();
}

double s21::ViewDepositCalc::GetDropSum() noexcept {
  return droped_sum_->value();
}

void s21::ViewDepositCalc::InitElement() {
  InitTextElement();
  InitSpinBox();
  InitButton();
  AddAtScene();
}

void s21::ViewDepositCalc::InitButton() {
  add_upload_.setPos(10, 400);
  add_upload_.SetGeometry(20, 480);
  add_upload_.setText("add upload");

  add_drop_.setPos(10, 620);
  add_drop_.SetGeometry(20, 480);
  add_drop_.setText("add drop");

  btn_calc_.setPos(10, 760);
  btn_calc_.SetGeometry(50, 480);
  btn_calc_.setText("Calculate");

  btn_clear_.setPos(10, 975);
  btn_clear_.SetGeometry(20, 480);
  btn_clear_.setText("clear");
}

void s21::ViewDepositCalc::InitTextElement() {
  sum_deposit_label_ = new QLabel();
  sum_deposit_label_->setGeometry(10, 10, 235, 30);
  sum_deposit_label_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  sum_deposit_label_->setText("Deposit sum:");

  term_label_ = new QLabel();
  term_label_->setGeometry(10, 50, 235, 30);
  term_label_->setStyleSheet("background: #008080; color: white; font: 18pt");
  term_label_->setText("Deposit term:");

  percent_rate_label_ = new QLabel();
  percent_rate_label_->setGeometry(10, 90, 235, 30);
  percent_rate_label_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  percent_rate_label_->setText("Percent rate:");

  tax_rate_label_ = new QLabel();
  tax_rate_label_->setGeometry(10, 130, 235, 30);
  tax_rate_label_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  tax_rate_label_->setText("Tax rate:");

  payment_frequency_label_ = new QLabel();
  payment_frequency_label_->setGeometry(10, 220, 235, 30);
  payment_frequency_label_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  payment_frequency_label_->setText("Payment frequency:");

  payment_frequency_ = new QComboBox();
  payment_frequency_->setGeometry(250, 220, 235, 30);
  payment_frequency_->setStyleSheet(
      "background: #326759; color: white; font: 14pt");
  payment_frequency_->addItem("Month");
  payment_frequency_->addItem("Quarter");
  payment_frequency_->addItem("Year");
  payment_frequency_->raise();
  payment_frequency_->showPopup();

  capitalization_ = new QCheckBox();
  capitalization_->setGeometry(10, 180, 235, 30);
  capitalization_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  capitalization_->setText("Capitalization");

  upload_mounth_label_ = new QLabel();
  upload_mounth_label_->setGeometry(10, 320, 235, 30);
  upload_mounth_label_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  upload_mounth_label_->setText("Upload month:");

  upload_sum_label_ = new QLabel();
  upload_sum_label_->setGeometry(10, 360, 235, 30);
  upload_sum_label_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  upload_sum_label_->setText("Upload sum:");

  upload_list_ = new QTextEdit();
  upload_list_->setGeometry(10, 430, 480, 100);
  upload_list_->setStyleSheet("background: #326759; color: white; font: 10pt");
  upload_list_->setReadOnly(true);

  droped_mounth_label_ = new QLabel();
  droped_mounth_label_->setGeometry(10, 540, 235, 30);
  droped_mounth_label_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  droped_mounth_label_->setText("Droped month:");

  droped_sum_label = new QLabel();
  droped_sum_label->setGeometry(10, 580, 235, 30);
  droped_sum_label->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  droped_sum_label->setText("Droped sum:");

  drop_list_ = new QTextEdit();
  drop_list_->setGeometry(10, 650, 480, 100);
  drop_list_->setStyleSheet("background: #326759; color: white; font: 10pt");
  drop_list_->setReadOnly(true);

  output_ = new QTextEdit();
  output_->setGeometry(10, 820, 480, 150);
  output_->setStyleSheet("background: #326759; color: white; font: 10pt");
  output_->setReadOnly(true);
}

void s21::ViewDepositCalc::InitSpinBox() {
  sum_deposit_ = new QDoubleSpinBox();
  sum_deposit_->setGeometry(255, 10, 235, 30);
  sum_deposit_->setRange(0, 999999999);
  sum_deposit_->setValue(0);
  sum_deposit_->setStyleSheet("background: #326759; color: white; font: 14pt");

  term_ = new QSpinBox();
  term_->setGeometry(255, 50, 235, 30);
  term_->setRange(0, 9999);
  term_->setValue(0);
  term_->setStyleSheet("background: #326759; color: white; font: 14pt");

  percent_rate_ = new QDoubleSpinBox();
  percent_rate_->setGeometry(255, 90, 235, 30);
  percent_rate_->setRange(0, 999);
  percent_rate_->setValue(0);
  percent_rate_->setStyleSheet("background: #326759; color: white; font: 14pt");

  tax_rate_ = new QDoubleSpinBox();
  tax_rate_->setGeometry(255, 130, 235, 30);
  tax_rate_->setRange(0, 999);
  tax_rate_->setValue(0);
  tax_rate_->setStyleSheet("background: #326759; color: white; font: 14pt");

  upload_mounth_ = new QSpinBox();
  upload_mounth_->setGeometry(255, 320, 235, 30);
  upload_mounth_->setRange(0, 999);
  upload_mounth_->setValue(0);
  upload_mounth_->setStyleSheet(
      "background: #326759; color: white; font: 14pt");

  upload_sum_ = new QDoubleSpinBox();
  upload_sum_->setGeometry(255, 360, 235, 30);
  upload_sum_->setRange(0, 999999999);
  upload_sum_->setValue(0);
  upload_sum_->setStyleSheet("background: #326759; color: white; font: 14pt");

  droped_mounth_ = new QSpinBox();
  droped_mounth_->setGeometry(255, 540, 235, 30);
  droped_mounth_->setRange(0, 999);
  droped_mounth_->setValue(0);
  droped_mounth_->setStyleSheet(
      "background: #326759; color: white; font: 14pt");

  droped_sum_ = new QDoubleSpinBox();
  droped_sum_->setGeometry(255, 580, 235, 30);
  droped_sum_->setRange(0, 9999999999);
  droped_sum_->setValue(0);
  droped_sum_->setStyleSheet("background: #326759; color: white; font: 14pt");
}

void s21::ViewDepositCalc::AddAtScene() {
  scene_->addWidget(sum_deposit_label_);
  scene_->addWidget(term_label_);
  scene_->addWidget(percent_rate_label_);
  scene_->addWidget(tax_rate_label_);
  scene_->addWidget(payment_frequency_label_);
  scene_->addWidget(payment_frequency_);
  scene_->addWidget(capitalization_);
  scene_->addWidget(upload_mounth_label_);
  scene_->addWidget(upload_sum_label_);
  scene_->addWidget(upload_list_);
  scene_->addWidget(droped_mounth_label_);
  scene_->addWidget(droped_sum_label);
  scene_->addWidget(drop_list_);
  scene_->addWidget(output_);

  scene_->addWidget(sum_deposit_);
  scene_->addWidget(term_);
  scene_->addWidget(percent_rate_);
  scene_->addWidget(tax_rate_);
  scene_->addWidget(upload_mounth_);
  scene_->addWidget(upload_sum_);
  scene_->addWidget(droped_mounth_);
  scene_->addWidget(droped_sum_);

  scene_->addItem(&add_upload_);
  scene_->addItem(&add_drop_);
  scene_->addItem(&btn_calc_);
  scene_->addItem(&btn_clear_);
}
