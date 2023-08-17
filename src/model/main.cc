#include <iostream>
#include "expressionConverter.h"

int main() {
    std::list<std::string> input_line = {"5","*", "6", "+", "2", "-", "9"};
    s21::expressionConverter Convert(input_line);
    Convert.Conversion();
    std::vector<std::string> output = Convert.GetOut();
    for (auto &item: output) {
        std::cout << item;
    }
    std::cout << std::endl;
    return 0;
}