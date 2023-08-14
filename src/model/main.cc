#include <iostream>
#include "expressionConverter.h"

int main() {
    std::list<char> input_line = {'(', '3','+','4', ')','*','2'};
    s21::expressionConverter Convert(input_line);
    Convert.Conversion();
    std::cout << Convert.GetOut() << std::endl;
    return 0;
}