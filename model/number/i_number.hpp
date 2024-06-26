#ifndef I_NUMBER_HPP
#define I_NUMBER_HPP

#include <memory>
#include <string>

class INumber
{
public:
    // бинарные операторы <lhs> <operator> <rhs>, где <lhs> - this
    virtual std::unique_ptr<INumber> operator+(const INumber& rhs) const = 0;
    virtual std::unique_ptr<INumber> operator-(const INumber& rhs) const = 0;
    virtual std::unique_ptr<INumber> operator*(const INumber& rhs) const = 0;
    virtual std::unique_ptr<INumber> operator/(const INumber& rhs) const = 0;

    // унарные операторы <operator> <rhs>, где <rhs> - this
    virtual std::unique_ptr<INumber> operator~() const = 0;

    // строковое представление числа
    virtual std::string value() const = 0;
};

#endif // I_NUMBER_HPP
