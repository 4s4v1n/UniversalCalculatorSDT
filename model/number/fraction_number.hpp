#ifndef FRACTION_NUMBER_HPP
#define FRACTION_NUMBER_HPP

#include "i_number.hpp"

class FractionNumber : public INumber
{
public:
    FractionNumber(double numerator, double denominator);

    const FractionNumber& operator+(const INumber& rhs) const override;
    const FractionNumber& operator-(const INumber& rhs) const override;
    const FractionNumber& operator*(const INumber& rhs) const override;
    const FractionNumber& operator/(const INumber& rhs) const override;

    const FractionNumber& operator~() const override;

    std::string value() const override;

    void checkIsZero(const FractionNumber& lhs) const;

private:
    double m_numerator   = 0.;
    double m_denominator = 0.;
};

#endif // FRACTION_NUMBER_HPP
