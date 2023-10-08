#include "expressionConverter.h"

std::list<std::string> s21::ExpressionConverter::GetOut() {
  return output_string_;
}

s21::ExpressionConverter::ExpressionConverter(std::list<std::string> input)
    : input_string_(input){};

s21::ExpressionConverter::ExpressionConverter(const ExpressionConverter &e)
    : input_string_(e.input_string_), output_string_(e.output_string_){};

s21::ExpressionConverter &s21::ExpressionConverter::operator=(
    const ExpressionConverter &e) {
  if (this != &e) {
    ExpressionConverter copy{e};
    swap(copy);
  }
  return *this;
};

s21::ExpressionConverter::ExpressionConverter(ExpressionConverter &&e)
    : ExpressionConverter() {
  swap(e);
};

s21::ExpressionConverter &s21::ExpressionConverter::operator=(
    ExpressionConverter &&e) {
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

void s21::ExpressionConverter::AddTokenInModel(std::string token) noexcept {
  input_string_.push_back(token);
}

void s21::ExpressionConverter::Clear() noexcept {
  input_string_.clear();
  output_string_.clear();
}

void s21::ExpressionConverter::Conversion() {
  std::stack<std::string> transformator;
  if (input_string_.size() == 1) {
    Check();
  }
  while (!input_string_.empty()) {
    Element token(input_string_.front());
    input_string_.pop_front();

    if (token.IsNumber() || token.IsX()) {
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

void s21::ExpressionConverter::Check() {
  Element token(input_string_.front());
  if (token.IsOperator()) {
    throw std::invalid_argument("\nInvalid expression_0\n");
  }
}

void s21::ExpressionConverter::PullOverStack(
    std::stack<std::string> &transformator) {
  Element top(transformator.top());
  while (!top.IsOpenBracket()) {
    output_string_.push_back(top.GetData());
    transformator.pop();
    if (transformator.empty()) {
      throw std::invalid_argument("\nInvalid expression_1\n");
    }
    top.SetData(transformator.top());
  }
}

void s21::ExpressionConverter::EmptyTheStack(
    std::stack<std::string> &transformator) {
  while (!transformator.empty()) {
    if (transformator.top() == "(") {
      throw std::invalid_argument("\nInvalid expression_2\n");
    }
    output_string_.push_back(transformator.top());
    transformator.pop();
  }
}

void s21::ExpressionConverter::AddInOut(
    std::stack<std::string> &transformator) {
  if (transformator.empty()) {
    throw std::invalid_argument("\nInvalid expression_3\n");
  }
  Element top(transformator.top());
  while (!top.IsOpenBracket()) {
    output_string_.push_back(top.GetData());
    transformator.pop();
    if (transformator.empty()) {
      throw std::invalid_argument("\nInvalid expression_4\n");
    }
    top.SetData(transformator.top());
  }
  transformator.pop();
  if (!transformator.empty()) {
    top.SetData(transformator.top());
    if (top.IsFunciotn()) {
      output_string_.push_back(top.GetData());
      transformator.pop();
      if (!transformator.empty()) {
        top.SetData(transformator.top());
      }
    }
  }
};

void s21::ExpressionConverter::AddOperatorInStack(
    std::stack<std::string> &transformator, Element &op_one) noexcept {
  if (!transformator.empty()) {
    Element op_two(transformator.top());
    while (!transformator.empty() && op_two.IsOperator() &&
           op_two.OperatorCheck(op_one)) {
      output_string_.push_back(op_two.GetData());
      transformator.pop();
      if (!transformator.empty()) {
        op_two.SetData(transformator.top());
      }
    }
  }
};
