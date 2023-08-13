#ifndef CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H
#define CPP3_SMARTCALC_V2_1_MODEL_ECPRESSION_CONVERTER_H

#include <iostream>
#include <list>

namespace s21 {
class expressionConverter {
    public:

    expressionConverter() = default;
    ~expressionConverter() = default;

    explicit expressionConverter(std::list<char> input) : input_string_(input) {};
    
    expressionConverter(const expressionConverter &e) : input_string_(e.input_string_) , output_string_(e.output_string_) {};
    
    expressionConverter& operator=(const expressionConverter &e) {
      if (this != &e) {
        expressionConverter copy{e};
        swap(copy);
      }
      return *this;
    };

		expressionConverter(expressionConverter &&e) : expressionConverter() {swap(e)};

		expressionConverter& operator=(expressionConverter &&e) {
			if (this != &e) {
				expressionConverter moved{std::move(e)};
				swap(moved);
			}
			return *this;
		}

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