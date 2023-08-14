#include <iostream>
#include "expressionConverter.h"

int main() {
    std::list<std::string> input_line = {"5","*", "6", "+", "2", "-", "9"};
    s21::expressionConverter Convert(input_line);
    int a = 1;
    int b = 2;
    int c = 3;
    Convert.Conversion();
    std::vector<std::string> output = Convert.GetOut();
    for (auto &item: output) {
        std::cout << item;
    }
    std::cout << std::endl;
    return 0;
}