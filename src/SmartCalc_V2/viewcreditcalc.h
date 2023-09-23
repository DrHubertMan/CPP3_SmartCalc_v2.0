#ifndef VIEWCREDITCALC_H
#define VIEWCREDITCALC_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLineEdit>
#include <QTextEdit>

#include "calclulatorbutton.h"

namespace s21 {

class ViewCreditCalc : public QGraphicsView {
public:
    ViewCreditCalc(QWidget *parent = nullptr);

    bool GetChecked() const noexcept;
    double GetAllSum() const noexcept;
    double GetPercent() const noexcept;
    int GetTerm() const noexcept;

    void SetEveryMonthPay(double mounthly_pay) noexcept;
    void SetOverpay(double overpay) noexcept;
    void SetOverpaySum(double overpay_sum) noexcept;

    void SetDiferentEveryMountPayGraph() noexcept;
    void SetDifMounthPay(int mounth, double pay) noexcept;

    void SetZeroSpin() noexcept;

private:
    QTextEdit *diferent_pay_;

    QLineEdit *everymonth_pay_text_;
    QLineEdit *overpay_text_;
    QLineEdit *overpay_sum_text_;

    QLabel *all_sum_;
    QLabel *term_;
    QLabel *percent_;

    QLabel *everymonth_pay_;
    QLabel *overpay_;
    QLabel *overpay_sum_;

    QDoubleSpinBox *credit_sum_;
    QSpinBox *mounth_;
    QDoubleSpinBox *double_percent_;


    QGraphicsScene *scene_;
    CalculatorButton btn_ac_{this};
    CalculatorButton btn_calculate_{this};

    QRadioButton *anuitet_;
    QRadioButton *diferent_;
    QButtonGroup *credit_mode_;
private:
    void InitElement();
    void InitRadioButton();
    void InitLabel();
    void InitSpinBox();
    void InitButton();
    void AddAtScene();
};
}

#endif // VIEWCREDITCALC_H
