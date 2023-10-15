#include <gtest/gtest.h>

#include <iostream>
#include <list>
#include <string>

#include "../model/element.h"
#include "../model/expressionConverter.h"
#include "../model/calculation.h"

#define S21EPS 1e-6

using namespace s21;
// ELEMENT NUMBER

TEST(Element, Constructor_1) {
  Element test("lol");
  std::string right_answer = "lol";
  EXPECT_EQ(right_answer, test.GetData()); 
};

TEST(Element, IsNumber_Correct_1) {
  Element test("0");
  EXPECT_EQ(true, test.IsNumber()); 
};

TEST(Element, IsNumber_Correct_2) {
  Element test("-1");
  EXPECT_EQ(true, test.IsNumber());  
};

TEST(Element, IsNumber_Correct_3) {
  Element test("1");
  EXPECT_EQ(true, test.IsNumber());
};

TEST(Element, IsNumber_UnCorrect_1) {
  Element test("=");
  EXPECT_EQ(false, test.IsNumber());
};

TEST(Element, IsNumber_UnCorrect_2) {
  Element test("lol");
  EXPECT_EQ(false, test.IsNumber()); 
};

TEST(Element, IsNumber_UnCorrect_3) {
  Element test("");
  EXPECT_EQ(false, test.IsNumber()); 
};

// ELEMENT OPERATOR

TEST(Element, IsOperator_Correct_1) {
  Element test("+");
  EXPECT_EQ(true, test.IsOperator()); 
};

TEST(Element, IsOperator_Correct_2) {
  Element test("-");
  EXPECT_EQ(true, test.IsOperator());  
};

TEST(Element, IsOperator_Correct_3) {
  Element test("*");
  EXPECT_EQ(true, test.IsOperator());
};

TEST(Element, IsOperator_Correct_4) {
  Element test("%");
  EXPECT_EQ(true, test.IsOperator()); 
};

TEST(Element, IsOperator_Correct_5) {
  Element test("/");
  EXPECT_EQ(true, test.IsOperator());  
};

TEST(Element, IsOperator_Correct_6) {
  Element test("^");
  EXPECT_EQ(true, test.IsOperator());
};

TEST(Element, IsOperator_UnCorrect_1) {
  Element test("=");
  EXPECT_EQ(false, test.IsOperator());
};

TEST(Element, IsOperator_UnCorrect_2) {
  Element test("");
  EXPECT_EQ(false, test.IsOperator()); 
};

TEST(Element, IsOperator_UnCorrect_3) {
  Element test("sin");
  EXPECT_EQ(false, test.IsOperator()); 
};

TEST(Element, IsOperator_UnCorrect_4) {
  Element test("(");
  EXPECT_EQ(false, test.IsOperator());
};

TEST(Element, IsOperator_UnCorrect_5) {
  Element test(")");
  EXPECT_EQ(false, test.IsOperator()); 
};

TEST(Element, IsOperator_UnCorrect_6) {
  Element test("23");
  EXPECT_EQ(false, test.IsOperator()); 
};

// ELEMENT IS FUNCTION

TEST(Element, IsFunction_Correct_1) {
  Element test("sin");
  EXPECT_EQ(true, test.IsFunciotn()); 
};

TEST(Element, IsFunction_Correct_2) {
  Element test("cos");
  EXPECT_EQ(true, test.IsFunciotn());  
};

TEST(Element, IsFunction_Correct_3) {
  Element test("tan");
  EXPECT_EQ(true, test.IsFunciotn());
};

TEST(Element, IsFunction_Correct_4) {
  Element test("asin");
  EXPECT_EQ(true, test.IsFunciotn()); 
};

TEST(Element, IsFunction_Correct_5) {
  Element test("acos");
  EXPECT_EQ(true, test.IsFunciotn());  
};

TEST(Element, IsFunction_Correct_6) {
  Element test("atan");
  EXPECT_EQ(true, test.IsFunciotn());
};

TEST(Element, IsFunction_Correct_7) {
  Element test("log");
  EXPECT_EQ(true, test.IsFunciotn()); 
};

TEST(Element, IsFunction_Correct_8) {
  Element test("ln");
  EXPECT_EQ(true, test.IsFunciotn());  
};

TEST(Element, IsFunction_Correct_9) {
  Element test("sqrt");
  EXPECT_EQ(true, test.IsFunciotn());
};

TEST(Element, IsFunction_UnCorrect_1) {
  Element test("");
  EXPECT_EQ(false, test.IsFunciotn());
};

TEST(Element, IsFunction_UnCorrect_2) {
  Element test("+");
  EXPECT_EQ(false, test.IsFunciotn()); 
};

TEST(Element, IsFunction_UnCorrect_3) {
  Element test("12");
  EXPECT_EQ(false, test.IsFunciotn()); 
};

TEST(Element, IsFunction_UnCorrect_4) {
  Element test("(");
  EXPECT_EQ(false, test.IsFunciotn());
};

TEST(Element, IsFunction_UnCorrect_5) {
  Element test(")");
  EXPECT_EQ(false, test.IsFunciotn()); 
};

TEST(Element, IsFunction_UnCorrect_6) {
  Element test("^");
  EXPECT_EQ(false, test.IsFunciotn()); 
};

TEST(Element, IsFunction_UnCorrect_7) {
  Element test("bebra");
  EXPECT_EQ(false, test.IsFunciotn());
};

TEST(Element, IsFunction_UnCorrect_8) {
  Element test("biba");
  EXPECT_EQ(false, test.IsFunciotn()); 
};

TEST(Element, IsFunction_UnCorrect_9) {
  Element test("boba");
  EXPECT_EQ(false, test.IsFunciotn()); 
};

// ELEMENT IS Separator

TEST(Element, IsSeparator_Correct_1) {
  Element test(",");
  EXPECT_EQ(true, test.IsSeparator()); 
};

TEST(Element, IsSeparator_UnCorrect_1) {
  Element test("23");
  EXPECT_EQ(false, test.IsSeparator()); 
};

// ELEMENT IS LEFT PRIORITY

TEST(Element, IsLeftPriority_Correct_1) {
  Element test("+");
  EXPECT_EQ(true, test.IsLeftPriority()); 
};

TEST(Element, IsLeftPriority_Correct_2) {
  Element test("-");
  EXPECT_EQ(true, test.IsLeftPriority()); 
};

TEST(Element, IsLeftPriority_Correct_3) {
  Element test("*");
  EXPECT_EQ(true, test.IsLeftPriority()); 
};

TEST(Element, IsLeftPriority_Correct_4) {
  Element test("/");
  EXPECT_EQ(true, test.IsLeftPriority()); 
};

TEST(Element, IsLeftPriority_Correct_5) {
  Element test("%");
  EXPECT_EQ(true, test.IsLeftPriority()); 
};

TEST(Element, IsLeftPriority_Correct_6) {
  Element test("=");
  EXPECT_EQ(true, test.IsLeftPriority()); 
};

TEST(Element, IsLeftPriority_Correct_7) {
  Element test("3");
  EXPECT_EQ(true, test.IsLeftPriority()); 
};

TEST(Element, IsLeftPriority_UnCorrect_1) {
  Element test("^");
  EXPECT_EQ(false, test.IsLeftPriority()); 
};

// ELEMENT SETDATA

TEST(Element, SetData_Correct_1) {
  Element test;
  std::string right_answer = "lol";
  test.SetData(right_answer);
  EXPECT_EQ(right_answer, test.GetData()); 
};

// ELEMENT ISOPENBRACKET

TEST(Element, IsOpenBracket_Correct_1) {
  Element test("(");
  EXPECT_EQ(true, test.IsOpenBracket());
}

TEST(Element, IsOpenBracket_UnCorrect_1) {
  Element test(")");
  EXPECT_EQ(false, test.IsOpenBracket());
}

TEST(Element, IsOpenBracket_UnCorrect_2) {
  Element test("a");
  EXPECT_EQ(false, test.IsOpenBracket());
}

TEST(Element, IsOpenBracket_UnCorrect_3) {
  Element test("");
  EXPECT_EQ(false, test.IsOpenBracket());
}

// ELEMENT ISCLOSEDBRACKET

TEST(Element, IsClosedBracket_Correct_1) {
  Element test(")");
  EXPECT_EQ(true, test.IsClosedBracket());
}

TEST(Element, IsClosedBracket_UnCorrect_1) {
  Element test("(");
  EXPECT_EQ(false, test.IsClosedBracket());
}

TEST(Element, IsClosedBracket_UnCorrect_2) {
  Element test("a");
  EXPECT_EQ(false, test.IsClosedBracket());
}

TEST(Element, IsClosedBracket_UnCorrect_3) {
  Element test("");
  EXPECT_EQ(false, test.IsClosedBracket());
}

// ELEMENT ISEQ

TEST(Element, IsEq_Correct_1) {
  Element test("=");
  EXPECT_EQ(true, test.IsEq());
}

TEST(Element, IsEq_UnCorrect_1) {
  Element test("(");
  EXPECT_EQ(false, test.IsEq());
}

TEST(Element, IsEq_UnCorrect_2) {
  Element test("a");
  EXPECT_EQ(false, test.IsEq());
}

TEST(Element, IsEq_UnCorrect_3) {
  Element test("");
  EXPECT_EQ(false, test.IsEq());
}

// ELEMENT ISPOINT

TEST(Element, IsPoint_Correct_1) {
  Element test(".");
  EXPECT_EQ(true, test.IsPoint());
}

TEST(Element, IsPoint_UnCorrect_1) {
  Element test("(");
  EXPECT_EQ(false, test.IsPoint());
}

TEST(Element, IsPoint_UnCorrect_2) {
  Element test("a");
  EXPECT_EQ(false, test.IsPoint());
}

TEST(Element, IsPoint_UnCorrect_3) {
  Element test("");
  EXPECT_EQ(false, test.IsPoint());
}

// ELEMENT ISX

TEST(Element, IsX_Correct_1) {
  Element test("x");
  EXPECT_EQ(true, test.IsX());
}

TEST(Element, IsX_UnCorrect_1) {
  Element test("(");
  EXPECT_EQ(false, test.IsX());
}

TEST(Element, IsX_UnCorrect_2) {
  Element test("a");
  EXPECT_EQ(false, test.IsX());
}

TEST(Element, IsX_UnCorrect_3) {
  Element test("");
  EXPECT_EQ(false, test.IsX());
}

// ELEMENT OPERATORCHECK

TEST(Element, OperatorCheck_Correct_1) {
  Element kek("+");
  Element lol("-");
  EXPECT_EQ(true, kek.OperatorCheck(lol));
}

TEST(Element, OperatorCheck_UnCorrect_1) {
  Element kek("*");
  Element lol("-");
  EXPECT_EQ(true, kek.OperatorCheck(lol));
}

TEST(Element, OperatorCheck_UnCorrect_2) {
  Element kek("-");
  Element lol("^");
  EXPECT_EQ(false, kek.OperatorCheck(lol));
}

// EXPRESSION CONVERTER

TEST(ExpressionConverter, Conctructor_1) {
  std::list<std::string> inital_list{"(" , "25", "+", "5", ")"};
  ExpressionConverter test(inital_list);
  std::list<std::string> right_answer{"25", "5", "+"};
  EXPECT_EQ(right_answer, test.GetOut());
}

TEST(ExpressionConverter, Conctructor_2) {
  std::list<std::string> inital_list{"(" , "25", "+", "5", ")" , "*", "(", "99", "/", "3", ")"};
  ExpressionConverter test(inital_list);
  std::list<std::string> right_answer{"25", "5", "+", "99", "3", "/", "*"};
  EXPECT_EQ(right_answer, test.GetOut());
}

TEST(ExpressionConverter, Conctructor_3) {
  std::list<std::string> inital_list{"sin", "(", "45", "+", "cos", "(", "34", ")", ")"};
  ExpressionConverter test(inital_list);
  std::list<std::string> right_answer{"45", "34", "cos", "+", "sin"};
  EXPECT_EQ(right_answer, test.GetOut());
}

TEST(ExpressionConverter, Conctructor_4) {
  std::list<std::string> inital_list{"sin", "(", "45", "+", "cos", "(", "34", ")", ")"};
  ExpressionConverter test;
  for (const auto& item: inital_list) {
    test.AddTokenInModel(item);
  }
  test.Conversion();
  std::list<std::string> right_answer{"45", "34", "cos", "+", "sin"};
  EXPECT_EQ(right_answer, test.GetOut());
}

TEST(ExpressionConverter, Conctructor_5) {
  std::list<std::string> inital_list{"23"};
  ExpressionConverter test;
  for (const auto& item: inital_list) {
    test.AddTokenInModel(item);
  }
  test.Conversion();
  std::list<std::string> right_answer{"23"};
  EXPECT_EQ(right_answer, test.GetOut());
}

TEST(ExpressionConverter, Conctructor_6) {
  std::list<std::string> inital_list{"sin", "(", "45", "+", "cos", "(", "34", ")", ")"};
  ExpressionConverter test;
  for (const auto& item: inital_list) {
    test.AddTokenInModel(item);
  }
  test.Clear();
  std::list<std::string> right_answer;
  EXPECT_EQ(right_answer, test.GetOut());
}

TEST(ExpressionConverter, Conctructor_7) {
  std::list<std::string> inital_list{"-", "2", "^", "3", "^", "5", "^", "6", "*", "8", "/", "4", "-", "4"};
  ExpressionConverter test;
  for (const auto& item: inital_list) {
    test.AddTokenInModel(item);
  }
  test.Conversion();
  std::list<std::string> right_answer{"2", "3", "5", "6", "^", "^", "^", "8", "*", "4", "/", "-", "4", "-"};
  EXPECT_EQ(right_answer, test.GetOut());
}

// CALCULATION 

TEST(Calculation, Test_1) {
  std::list<std::string> right_answer{"25", "5", "+", "99", "3", "/", "*"};
  Calculation test(right_answer);
  EXPECT_EQ(990, test.GetValue());
}

TEST(Calculation, Test_2) {
  std::list<std::string> right_answer{"25", "x", "+", "99", "3", "/", "*"};
  Calculation test(right_answer, 5);
  EXPECT_EQ(990, test.GetValue());
}

TEST(Calculation, Test_3) {
  std::list<std::string> right_answer{"25", "x", "-", "99", "3", "/", "*"};
  Calculation test(right_answer, 5);
  EXPECT_EQ(660, test.GetValue());
}

TEST(Calculation, Test_4) {
  std::list<std::string> right_answer{"2", "^", "3", "^", "cos", "45"};
  Calculation test(right_answer);
  EXPECT_EQ(45, test.GetValue());
}

TEST(Calculation, Test_5) {
  std::list<std::string> right_answer{"2", "^", "3", "^", "sin", "45"};
  Calculation test(right_answer);
  EXPECT_EQ(45, test.GetValue());
}

TEST(Calculation, Test_6) {
  std::list<std::string> right_answer{"2", "^", "3", "^", "atan", "45"};
  Calculation test(right_answer);
  EXPECT_EQ(45, test.GetValue());
}

TEST(Calculation, Test_7) {
  std::list<std::string> right_answer{"2", "^", "3", "^", "tan", "45"};
  Calculation test(right_answer);
  EXPECT_EQ(45, test.GetValue());
}

TEST(Calculation, Test_8) {
  std::list<std::string> right_answer{"2", "^", "3", "^", "asin", "45"};
  Calculation test(right_answer);
  EXPECT_EQ(45, test.GetValue());
}

TEST(Calculation, Test_9) {
  std::list<std::string> right_answer{"2", "^", "3", "^", "acos", "45", };
  Calculation test(right_answer);
  EXPECT_EQ(45, test.GetValue());
}

TEST(Calculation, Test_10) {
  std::list<std::string> right_answer{"1", "ln"};
  Calculation test(right_answer);
  EXPECT_EQ(0, test.GetValue());
}

TEST(Calculation, Test_11) {
  std::list<std::string> right_answer{"9", "sqrt"};
  Calculation test(right_answer);
  EXPECT_EQ(3, test.GetValue());
}

TEST(Calculation, Test_12) {
  std::list<std::string> right_answer{"1", "log"};
  Calculation test(right_answer);
  EXPECT_EQ(0, test.GetValue());
}

TEST(Calculation, Test_13) {
  std::list<std::string> right_answer{"4", "2", "%"};
  Calculation test(right_answer);
  EXPECT_EQ(0, test.GetValue());
}