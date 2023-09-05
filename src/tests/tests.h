#include <gtest/gtest.h>

#include <iostream>
#include <list>

#include "../model/calculation.h"
#include "../model/expressionConverter.h"

using s21::ExpressionConverter;
using s21::Calculation;
// std::list<std::string> input_line = {"25", "+", "(", "66", ")"};
// s21::ExpressionConverter Convert(input_line);
// s21::Calculation expr(Convert.GetOut());

TEST(ExpressionConverter, CorrectCase_1) {
  std::list<std::string> inial_case{"sin", "(", "(", "45", ")"};
  EXPECT_THROW(ExpressionConverter convert(inial_case),
               std::invalid_argument);
  // s21::Calculation calic(convert.GetOut());
  // std::cout << calic.GetValue() << std::endl;
  // std::list<std::string> right_answer{"45", "sin", "2", "3", "^", "sqrt",
  // "*"}; EXPECT_EQ(right_answer, convert.GetOut());
}

TEST(ExpressionConverter, CorrectCase_2) {
  std::list<std::string> inial_case{"25", "+" , "(", "5", ")"};
  ExpressionConverter convert(inial_case);
  Calculation calic(convert.GetOut());
  std::cout << calic.GetValue() << std::endl;
}

TEST(ExpressionConverter, CorrectCase_3) {}

TEST(ExpressionConverter, CorrectCase_4) {}

TEST(ExpressionConverter, CorrectCase_5) {}

TEST(ExpressionConverter, CorrectCase_6) {}

TEST(ExpressionConverter, CorrectCase_7) {}

TEST(ExpressionConverter, CorrectCase_8) {}

TEST(ExpressionConverter, CorrectCase_9) {}

TEST(ExpressionConverter, CorrectCase_10) {}