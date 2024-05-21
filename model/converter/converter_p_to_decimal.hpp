#ifndef CONVERTER_P_TO_DECIMAL_HPP
#define CONVERTER_P_TO_DECIMAL_HPP

#include <string>

class ConverterP2Decimal final
{
public:
    ConverterP2Decimal() = delete;
    ~ConverterP2Decimal() = delete;

public:
    static double pToFloat(const std::string& value, int p);
    static int pToInt(const std::string& value, int p);
    static int evaluatePrecision(const std::string& value);

private:
    static int charToInt(char symbol);
    static std::pair<char, char> evaluateLetters(int base);
};

#endif // CONVERTER_P_TO_DECIMAL_HPP
