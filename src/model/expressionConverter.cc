#include "expressionConverter.h"

std::list<std::string> s21::ExpressionConverter::GetOut() {
  return output_string_;
}

s21::ExpressionConverter::ExpressionConverter(std::list<std::string> input)
    : input_string_(input) {
  Conversion();
};

s21::ExpressionConverter::ExpressionConverter(const ExpressionConverter &e)
    : input_string_(e.input_string_), output_string_(e.output_string_) {
  Conversion();
};

s21::ExpressionConverter &
s21::ExpressionConverter::operator=(const ExpressionConverter &e) {
  if (this != &e) {
    ExpressionConverter copy{e};
    swap(copy);
  }
  return *this;
};

s21::ExpressionConverter::ExpressionConverter(ExpressionConverter &&e)
    : ExpressionConverter() {
  swap(e);
  Conversion();
};

s21::ExpressionConverter &s21::ExpressionConverter::operator=(ExpressionConverter &&e) {
  if (this != &e) {
    ExpressionConverter moved{std::move(e)};
    swap(moved);
  }
  return *this;
};

void s21::ExpressionConverter::swap(ExpressionConverter &other) noexcept {
  std::swap(input_string_, other.input_string_);
  std::swap(output_string_, other.output_string_);
};

void s21::ExpressionConverter::Conversion() noexcept {
  std::stack<std::string> transformator;
  while (!input_string_.empty()) {
    Element token(input_string_.front());
    for (auto &item : output_string_) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
    input_string_.pop_front();
    if (token.IsNumber()) {
      output_string_.push_back(token.GetData());
    } else if (token.IsFunciotn()) {
      transformator.push(token.GetData());
    } else if (token.IsSeparator()) {
      PullOverStack(transformator);
    } else if (token.IsOperator()) {
      AddOperatorInStack(transformator, token);
      transformator.push(token.GetData());
    } else if (token.IsOpenBracket()) {
      transformator.push(token.GetData());
    } else if (token.IsClosedBracket()) {
      AddInOut(transformator);
    }
  }
  EmptyTheStack(transformator);
};

void s21::ExpressionConverter::PullOverStack(
    std::stack<std::string> &transformator) noexcept {
  Element top(transformator.top());
  while (!top.IsOpenBracket()) {
    output_string_.push_back(top.GetData());
    transformator.pop();
    top.SetData(transformator.top());
  }
}

void s21::ExpressionConverter::EmptyTheStack(
    std::stack<std::string> &transformator) noexcept {
  while (!transformator.empty()) {
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
}

void s21::ExpressionConverter::AddInOut(
    std::stack<std::string> &transformator) noexcept {
  Element top(transformator.top());
  while (!top.IsOpenBracket()) {
    output_string_.push_back(top.GetData());
    transformator.pop();
    top.SetData(transformator.top());
  }
  transformator.pop();
  top.SetData(transformator.top());
  if (top.IsFunciotn()) {
    output_string_.push_back(top.GetData());
    transformator.pop();
    top.SetData(transformator.top());
  }
};

void s21::ExpressionConverter::AddOperatorInStack(
    std::stack<std::string> &transformator,
    Element &op_one) noexcept {
  Element op_two(transformator.top());
  while (!transformator.empty() && op_two.IsOperator() &&
         op_two.OperatorCheck(op_one)) {
    output_string_.push_back(op_two.GetData());
    transformator.pop();
    op_two.SetData(transformator.top());
  }
};