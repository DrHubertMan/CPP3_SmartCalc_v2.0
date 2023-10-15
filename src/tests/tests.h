#include <gtest/gtest.h>

#include <iostream>
#include <list>

#include "../model/element.h"
#include "../model/expressionConverter.h"
#include "../model/calculation.h"

using s21::ExpressionConverter;
// using s21::Calculation;
// std::list<std::string> input_line = {"25", "+", "(", "66", ")"};
// s21::ExpressionConverter Convert(input_line);
// s21::Calculation expr(Convert.GetOut());

// TEST(ExpressionConverter, CorrectCase_1) {
//   std::list<std::string> inial_case{"sin", "(", "(", "45", ")"};
//   EXPECT_THROW(ExpressionConverter convert(inial_case),
//                std::invalid_argument);
//   // s21::Calculation calic(convert.GetOut());
//   // std::cout << calic.GetValue() << std::endl;
//   // std::list<std::string> right_answer{"45", "sin", "2", "3", "^", "sqrt",
//   // "*"}; EXPECT_EQ(right_answer, convert.GetOut());
// }

TEST(ExpressionConverter, CorrectCase_2) {
  ExpressionConverter *convert;
  bool check = true;
  std::list<std::string> inial_case{"(", "(","(", "25","+",")",")",")"};
  try {
    convert = new ExpressionConverter(inial_case);
    // std::list<std::string> inial_case{"sin", "(", "(", "45", ")"};
  } catch (...) {
    std::cout << "poimal" << std::endl;
    check = false;
  }
  if (check) {
    delete convert;
  }
}
