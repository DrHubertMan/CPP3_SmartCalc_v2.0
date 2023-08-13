#ifndef CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H
#define CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H

#include <list>

namespace s21 {
class expressionConverter {
    public:

    expressionConverter() = default;
    ~expressionConverter() = default;

    explicit expressionConverter(std::list<char> input);
    
    expressionConverter(const expressionConverter &e);
    
    expressionConverter& operator=(const expressionConverter &e);

    expressionConverter(expressionConverter &&e);

    expressionConverter& operator=(expressionConverter &&e) {
      if (this != &e) {
        expressionConverter moved{std::move(e)};
        swap(moved);
      }
      return *this;
    };

    private:
    std::list<char> input_string_;
    std::string output_string_;

    void swap(expressionConverter &other) noexcept {
        std::swap(input_string_, other.input_string_);
        std::swap(output_string_, other.output_string_);
    };
};
};

#endif