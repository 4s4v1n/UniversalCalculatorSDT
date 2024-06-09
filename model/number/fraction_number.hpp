#ifndef FRACTION_NUMBER_HPP
#define FRACTION_NUMBER_HPP

#include "i_number.hpp"

class FractionNumber : public INumber
{
public:
    FractionNumber();
    FractionNumber(const std::pair<int, int>& pair);
    FractionNumber(int numerator, int denominator);

    std::unique_ptr<INumber> operator+(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator-(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator*(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator/(const INumber& rhs) const override;

    std::unique_ptr<INumber> operator~() const override;

    std::string value() const override;

    void checkIsZero(const FractionNumber& lhs) const;

private:
    int m_numerator   = 0.;
    int m_denominator = 0.;
};

#endif // FRACTION_NUMBER_HPP
