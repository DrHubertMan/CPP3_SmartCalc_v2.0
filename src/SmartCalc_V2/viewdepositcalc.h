#ifndef VIEWDEPOSITCALC_H
#define VIEWDEPOSITCALC_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QCheckBox>

#include "calclulatorbutton.h"

namespace s21 {
class ViewDepositCalc : public QGraphicsView {

public:
    ViewDepositCalc();

    int GetBoxIndex() const noexcept;
    bool GetCapitalizationCheck() const noexcept;

    void SetUploadList() noexcept;
    void SetDropedList() noexcept;
    void SetOuput() noexcept;

private:
    QLabel *sum_deposit_label_;
    QDoubleSpinBox *sum_deposit_;

    QLabel *term_label_;
    QSpinBox *term_;

    QLabel *percent_rate_label_;
    QDoubleSpinBox *percent_rate_;

    QLabel *tax_rate_label_;
    QDoubleSpinBox *tax_rate_;

    QLabel *payment_frequency_label_;
    QComboBox *payment_frequency_;

    QCheckBox *capitalization_;

    QLabel *upload_mounth_label;
    QSpinBox *upload_mounth_;

    QLabel *upload_sum_label_;
    QDoubleSpinBox *upload_sum_;

    CalculatorButton add_upload_{this};

    QTextEdit *upload_list_;
    std::map<int, double> upload_map_;

    QLabel *droped_mounth_label_;
    QSpinBox *droped_mounth_;

    QLabel *droped_sum_label;
    QDoubleSpinBox *droped_sum_;

    CalculatorButton add_drop_{this};

    QTextEdit *drop_list_;
    std::map<int, double> drop_map_;

    QTextEdit *output_;

    QGraphicsScene scene_;
private:
    void InitElement();
    void InitTextElement();
    void InitSpinBox();
    void AddAtScene();
};
};

#endif // VIEWDEPOSITCALC_H
