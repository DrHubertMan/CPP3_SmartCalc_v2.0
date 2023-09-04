#include <gtest/gtest.h>

#include <list>
#include <iostream>

#include "../model/expressionConverter.h"
#include "../model/calculation.h"
    // std::list<std::string> input_line = {"25", "+", "(", "66", ")"};
    // s21::ExpressionConverter Convert(input_line);
    // s21::Calculation expr(Convert.GetOut());

TEST(ExpressionConverter, CorrectCase_1) {
    std::list<std::string> inial_case{"sin", "(", "45", ")"};
    s21::ExpressionConverter convert(inial_case);
    s21::Calculation calic(convert.GetOut());
    // std::list<std::string> right_answer{"45", "sin", "2", "3", "^", "sqrt", "*"};
    // EXPECT_EQ(right_answer, convert.GetOut());
}

TEST(ExpressionConverter, CorrectCase_2) {

}

TEST(ExpressionConverter, CorrectCase_3) {

}

TEST(ExpressionConverter, CorrectCase_4) {

}

TEST(ExpressionConverter, CorrectCase_5) {

}

TEST(ExpressionConverter, CorrectCase_6) {

}

TEST(ExpressionConverter, CorrectCase_7) {

}

TEST(ExpressionConverter, CorrectCase_8) {

}

TEST(ExpressionConverter, CorrectCase_9) {

}

TEST(ExpressionConverter, CorrectCase_10) {

}