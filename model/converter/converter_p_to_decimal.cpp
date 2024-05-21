#include "converter_p_to_decimal.hpp"

#include <cmath>

#include "../exception/conversion_exception.hpp"

double ConverterP2Decimal::pToFloat(const std::string& value, int p)
{
    auto dot_position{static_cast<int>(value.find('.'))};
    auto integer_part {pToInt(value.substr(0, dot_position), p)};
    auto fractional_part{0.};

    auto degree {-1};
    for (auto it {value.begin() + dot_position + 1}; it != value.end(); ++it, --degree)
    {
        fractional_part += charToInt(*it) * std::pow(p, degree);
    }
    return value.front() == '-' ? integer_part - fractional_part : integer_part + fractional_part;
}

int ConverterP2Decimal::pToInt(const std::string& value, int p)
{
    auto result {0};
    auto degree {0};

    for (auto it {value.rbegin()}; it != value.rend() && *it != '-'; ++it, ++degree)
    {
        result += charToInt(*it) * static_cast<int>(std::pow(p, degree));
    }
    return value.starts_with('-') ? result * -1 : result;
}

int ConverterP2Decimal::charToInt(const char symbol)
{
    if (symbol >= '0' && symbol <= '9')
    {
        return static_cast<int>(symbol) - 48;
    }
    if (symbol >= 'A' && symbol <= 'F')
    {
        return static_cast<int>(symbol) - 55;
    }
    if (symbol >= 'a' && symbol <= 'f')
    {
        return static_cast<int>(symbol) - 87;
    }

    std::string exception_message {"got invalid symbol " + std::to_string(symbol)};
    throw ConversionException{exception_message.c_str()};
}

int ConverterP2Decimal::evaluatePrecision(const std::string &value)
{
    auto dot_position {value.find('.')};
    return static_cast<int>(value.size() - dot_position);
}

std::pair<char, char> ConverterP2Decimal::evaluateLetters(const int base)
{
    if (base < 11 || base > 16)
    {
        std::string exception_message {"got invalid base " + std::to_string(base)};
        throw ConversionException{exception_message.c_str()};
    }
    return std::make_pair(static_cast<char>(base + 54), static_cast<char>(base + 86));
}
