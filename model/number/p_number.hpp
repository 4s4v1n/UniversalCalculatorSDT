#ifndef P_NUMBER_H
#define P_NUMBER_H

#include <memory>
#include <string>

#include "i_number.hpp"

class PNumber : public INumber
{
public:
    PNumber();
    PNumber(const std::string& value, int base, int accuracy);
    PNumber(double value, int base, int accuracy);

public:
    std::unique_ptr<INumber> operator+(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator-(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator*(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator/(const INumber& rhs) const override;

    std::unique_ptr<INumber> operator~() const override;

    std::string value() const override;

    // проверки числа перед вычислением значений
    void checkIsZero(const PNumber& lhs) const;
    void checkAreDifferentBases(const PNumber& lhs, const PNumber& rhs) const;

    int accuracy() const;
    int base() const;
    std::string string() const;

private:
    double m_value    = 0.;
    int    m_base     = 0;
    int    m_accuracy = 0;
};

#endif // P_NUMBER_H
