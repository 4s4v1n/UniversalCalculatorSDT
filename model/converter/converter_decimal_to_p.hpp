#ifndef CONVERTER_DECIMAL_TO_P_HPP
#define CONVERTER_DECIMAL_TO_P_HPP

#include <string>

class ConverterDecimal2P
{
public:
    ConverterDecimal2P() = delete;
    ~ConverterDecimal2P() = delete;

public:
    static std::string floatToP(double value, int notation, int accuracy);
    static std::string intToP(int value, int notation);

private:
    static char intToChar(int value);
};

#endif // CONVERTER_DECIMAL_TO_P_HPP
