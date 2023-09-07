#include <iostream>
#include "expressionConverter.h"
#include "calculation.h"

int main() {
    std::list<std::string> inial_case{"(","(","25","+",")",")",")"};
    s21::ExpressionConverter Convert(inial_case);
    // s21::Calculation expr(Convert.GetOut());
    // std::cout << expr.GetValue() << std::endl;
    return 0;
}