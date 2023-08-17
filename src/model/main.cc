#include <iostream>
#include "expressionConverter.h"

int main() {
    std::list<std::string> input_line = {"sin", "(", "2", "^", "3", "^", "4", ")"};
    s21::ExpressionConverter Convert(input_line);
    s21::ExpressionConverter lola(Convert);
    std::list<std::string> output = lola.GetOut();
    for (auto &item: output) {
        std::cout << item;
    }
    std::cout << std::endl;
    return 0;
}