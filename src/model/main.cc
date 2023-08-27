#include <iostream>
#include "expressionConverter.h"
#include "calculation.h"

int main() {
    std::list<std::string> input_line = {"10.5", "-", "5", "*" , "(", "15", "-", "(", "15", "-", "5", ")", ")"};
    s21::ExpressionConverter Convert(input_line);
    s21::Calculation expr(Convert.GetOut());
    std::cout << expr.GetValue() << std::endl;
    return 0;
}