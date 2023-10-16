#ifndef CPP3_SMARTCALC_V2_1_MODEL_GRAPH_MODEL_H
#define CPP3_SMARTCALC_V2_1_MODEL_GRAPH_MODEL_H

#include <list>
#include <string>
#include <vector>

#include "calculation.h"

namespace s21 {
class GraphModel {
 public:
  GraphModel(double min, double max, std::list<std::string> input_line);
  std::vector<double> GetX() const noexcept;
  std::vector<double> GetY() const noexcept;

 private:
  void Calculate() noexcept;

 private:
  double x_min_;
  double x_max_;
  std::list<std::string> postfix_expression_;
  std::vector<double> x_coordinate_;
  std::vector<double> y_coordinate;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_1_MODEL_GRAPH_MODEL_H