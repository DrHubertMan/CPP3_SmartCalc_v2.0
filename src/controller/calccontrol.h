#ifndef CPP3_SMARTCALC_V2_1_CONTROLLER_CALCCONTROL_H
#define CPP3_SMARTCALC_V2_1_CONTROLLER_CALCCONTROL_H

#include <QObject>
#include <iostream>

#include "../model/calculation.h"
#include "../model/expressionConverter.h"
#include "../model/graph_model.h"

namespace s21 {
class ViewSmartCalc;
// class ViewCreditCalc;
class CalcControl : public QObject {
  Q_OBJECT
 public:
  CalcControl() = default;
  explicit CalcControl(ExpressionConverter *converter_model);

  CalcControl(const CalcControl &c);
  CalcControl &operator=(const CalcControl &c);

  CalcControl(CalcControl &&c);
  CalcControl &operator=(CalcControl &&c);
  ~CalcControl();

 public:
  void AddValueInModel(QString text) noexcept;
  // void SetModel(ExpressionConverter &e) noexcept;
  void ClearModel() noexcept;
  void SetView(ViewSmartCalc *e) noexcept;

 public slots:
  void Num(QString text) const noexcept;
  void Dot() const noexcept;
  void Clear() const noexcept;
  void XVar(QString text) const noexcept;
  void UnarClicked() const noexcept;
  void Function(QString text) const noexcept;
  void OperPressed(QString text) const noexcept;
  void OpenBraketPressed(QString text) const noexcept;
  void ClosedBraketPressed(QString text) const noexcept;
  void EqualPressed();
  void MemoryClear() const noexcept;
  void ModeSelect() noexcept;
  void GraphPressed();
  void ScientificNotation() noexcept;
  // void StartCredit() noexcept;
  // void ClearCredit() noexcept;

 private:
  ViewSmartCalc *calculator_ = nullptr;
  ExpressionConverter *converter_model_ = nullptr;
  // ViewCreditCalc *credit_calc_ = nullptr;
  // Qlist<Qstring> ouput_line_;

 private:
  void swap(CalcControl &other);
  bool CheckConversion();
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_1_CONTROLLER_CALCCONTROL_H