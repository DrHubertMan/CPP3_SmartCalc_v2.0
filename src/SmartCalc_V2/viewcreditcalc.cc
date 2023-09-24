#include "viewcreditcalc.h"

s21::ViewCreditCalc::ViewCreditCalc(QWidget *parent) {
  setAttribute(Qt::WA_QuitOnClose, false);
  setRenderHint(QPainter::Antialiasing);
  setCacheMode(QGraphicsView::CacheNone);
  setWindowTitle("Credit_Calc_V2.0");
  setFrameStyle(0);
  setSceneRect(0, 0, 300, 900);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setFixedSize(300, 900);
  scene_ = new QGraphicsScene();
  scene_->setItemIndexMethod(QGraphicsScene::NoIndex);
  setScene(scene_);
  setBackgroundBrush(QBrush(Qt::darkCyan));

  InitElement();
}

bool s21::ViewCreditCalc::GetChecked() const noexcept {
  return anuitet_->isChecked();
}

double s21::ViewCreditCalc::GetAllSum() const noexcept {
  return credit_sum_->value();
}

double s21::ViewCreditCalc::GetPercent() const noexcept {
  return double_percent_->value();
}

int s21::ViewCreditCalc::GetTerm() const noexcept { return mounth_->value(); }

void s21::ViewCreditCalc::SetEveryMonthPay(double mounthly_pay) noexcept {
  everymonth_pay_text_->setText(QString::number(mounthly_pay, 'f', 2));
}

void s21::ViewCreditCalc::SetOverpay(double overpay) noexcept {
  overpay_text_->setText(QString::number(overpay, 'f', 2));
  diferent_pay_->clear();
}

void s21::ViewCreditCalc::SetOverpaySum(double overpay_sum) noexcept {
  overpay_sum_text_->setText(QString::number(overpay_sum, 'f', 2));
}

void s21::ViewCreditCalc::SetDiferentEveryMountPayGraph() noexcept {
  everymonth_pay_text_->setText("Diferential Loan");
}

void s21::ViewCreditCalc::SetDifMounthPay(int mounth, double pay) noexcept {
  diferent_pay_->append(QString::number(mounth) + ". Mounth: pay - " +
                        QString::number(pay, 'f', 2));
}

void s21::ViewCreditCalc::SetZeroSpin() noexcept {
  credit_sum_->setValue(0);
  mounth_->setValue(0);
  double_percent_->setValue(0);
}

void s21::ViewCreditCalc::InitElement() {
  InitLabel();
  InitSpinBox();
  InitRadioButton();
  InitButton();
  AddAtScene();
}

void s21::ViewCreditCalc::InitRadioButton() {
  anuitet_ = new QRadioButton();
  anuitet_->setGeometry(10, 240, 280, 30);
  anuitet_->setText("Annuitet mode");
  anuitet_->setStyleSheet("background: #008080; color: white; font: 12pt");
  anuitet_->setChecked(true);

  diferent_ = new QRadioButton();
  diferent_->setGeometry(10, 270, 280, 30);
  diferent_->setText("Diferent mode");
  diferent_->setStyleSheet("background: #008080; color: white; font: 12pt");

  credit_mode_ = new QButtonGroup();
  credit_mode_->addButton(anuitet_);
  credit_mode_->addButton(diferent_);
}

void s21::ViewCreditCalc::InitLabel() {
  all_sum_ = new QLabel();
  all_sum_->setGeometry(10, 10, 280, 30);
  all_sum_->setStyleSheet("background: #008080; color: white; font: 18pt");
  all_sum_->setText("Sum of credit:");

  term_ = new QLabel();
  term_->setGeometry(10, 90, 280, 30);
  term_->setStyleSheet("background: #008080; color: white; font: 18pt");
  term_->setText("Loan term:");

  percent_ = new QLabel();
  percent_->setGeometry(10, 170, 280, 30);
  percent_->setStyleSheet("background: #008080; color: white; font: 18pt");
  percent_->setText("Annual percent:");

  everymonth_pay_ = new QLabel();
  everymonth_pay_->setGeometry(10, 320, 280, 30);
  everymonth_pay_->setStyleSheet(
      "background: #008080; color: white; font: 18pt");
  everymonth_pay_->setText("Everymonth pay:");

  everymonth_pay_text_ = new QLineEdit();
  everymonth_pay_text_->setGeometry(10, 350, 280, 30);
  everymonth_pay_text_->setReadOnly(true);
  everymonth_pay_text_->setStyleSheet(
      "background: #326759; color: white; font: 15pt");

  overpay_ = new QLabel();
  overpay_->setGeometry(10, 390, 280, 30);
  overpay_->setStyleSheet("background: #008080; color: white; font: 18pt");
  overpay_->setText("Overpay:");

  overpay_text_ = new QLineEdit();
  overpay_text_->setGeometry(10, 420, 280, 30);
  overpay_text_->setReadOnly(true);
  overpay_text_->setStyleSheet("background: #326759; color: white; font: 15pt");

  overpay_sum_ = new QLabel();
  overpay_sum_->setGeometry(10, 470, 280, 30);
  overpay_sum_->setStyleSheet("background: #008080; color: white; font: 18pt");
  overpay_sum_->setText("All sum pay:");

  overpay_sum_text_ = new QLineEdit();
  overpay_sum_text_->setGeometry(10, 500, 280, 30);
  overpay_sum_text_->setReadOnly(true);
  overpay_sum_text_->setStyleSheet(
      "background: #326759; color: white; font: 15pt");

  diferent_pay_ = new QTextEdit;
  diferent_pay_->setGeometry(10, 540, 280, 200);
  diferent_pay_->setReadOnly(true);
  diferent_pay_->setStyleSheet("background: #326759; color: white; font: 15pt");
}

void s21::ViewCreditCalc::InitSpinBox() {
  credit_sum_ = new QDoubleSpinBox();
  credit_sum_->setGeometry(10, 50, 250, 30);
  credit_sum_->setRange(0, 999999999);
  credit_sum_->setValue(0);
  credit_sum_->setStyleSheet("background: #326759; color: white; font: 14pt");

  mounth_ = new QSpinBox();
  mounth_->setGeometry(10, 130, 250, 30);
  mounth_->setRange(0, 999);
  mounth_->setValue(0);
  mounth_->setStyleSheet("background: #326759; color: white; font: 14pt");

  double_percent_ = new QDoubleSpinBox();
  double_percent_->setGeometry(10, 210, 250, 30);
  double_percent_->setRange(0, 999);
  double_percent_->setValue(0);
  double_percent_->setStyleSheet(
      "background: #326759; color: white; font: 14pt");
}

void s21::ViewCreditCalc::InitButton() {
  btn_ac_.setPos(10, 840);
  btn_ac_.SetGeometry(50, 280);
  btn_ac_.setText("Clear");

  btn_calculate_.setPos(10, 780);
  btn_calculate_.SetGeometry(50, 280);
  btn_calculate_.setText("Credit calculate");
}

void s21::ViewCreditCalc::AddAtScene() {
  scene_->addWidget(all_sum_);
  scene_->addWidget(term_);
  scene_->addWidget(percent_);
  scene_->addWidget(everymonth_pay_);
  scene_->addWidget(everymonth_pay_text_);
  scene_->addWidget(overpay_);
  scene_->addWidget(overpay_text_);
  scene_->addWidget(overpay_sum_);
  scene_->addWidget(overpay_sum_text_);
  scene_->addWidget(credit_sum_);
  scene_->addWidget(mounth_);
  scene_->addWidget(double_percent_);
  scene_->addWidget(anuitet_);
  scene_->addWidget(diferent_);
  scene_->addWidget(diferent_pay_);

  scene_->addItem(&btn_ac_);
  scene_->addItem(&btn_calculate_);
}
