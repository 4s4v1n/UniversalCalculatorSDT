#ifndef REAL_NUMBER_HPP
#define REAL_NUMBER_HPP

#include <string>

#include "i_number.hpp"

class RealNumber : public INumber
{
public:
    RealNumber(const std::string& value, int base, int accuracy);
    RealNumber(double value, int base, int accuracy);

public:
    const RealNumber& operator+(const INumber& rhs) const override;
    const RealNumber& operator-(const INumber& rhs) const override;
    const RealNumber& operator*(const INumber& rhs) const override;
    const RealNumber& operator/(const INumber& rhs) const override;

    const RealNumber& operator~() const override;

    std::string value() const override;

    // проверки числа перед вычислением значений
    void checkIsZero(const RealNumber& lhs) const;
    void checkAreDifferentBases(const RealNumber& lhs, const RealNumber& rhs) const;

    int accuracy() const;
    int base() const;
    std::string string() const;

private:
    double m_value    = 0.;
    int    m_base     = 0;
    int    m_accuracy = 0;
};

#endif // REAL_NUMBER_HPP
