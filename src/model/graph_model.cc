#include "graph_model.h"

s21::GraphModel::GraphModel(double min, double max,
                            std::list<std::string> input_line)
    : x_min_(min), x_max_(max), postfix_expression_(input_line){
      Calculate();
    };

void s21::GraphModel::Calculate() noexcept {
  for (; x_min_ < x_max_; x_min_ += 0.125) {
    std::list<std::string> expression;
    x_coordinate_.push_back(x_min_);
    for (auto &item : postfix_expression_) {
      if (item == "x") {
        expression.push_back(std::to_string(x_min_));
      } else {
        expression.push_back(item);
      }
    }
    Calculation y_value(expression);
    y_coordinate.push_back(y_value.GetValue());
  }
};

std::vector<double> s21::GraphModel::GetX() const noexcept {
  return x_coordinate_;
};

std::vector<double> s21::GraphModel::GetY() const noexcept {
  return y_coordinate;
}