#include "fraction_number.hpp"

#include "../exception/calculation_exception.hpp"

FractionNumber::FractionNumber(double numerator, double denominator):
    m_numerator(denominator < 0 ? -numerator : numerator),
    m_denominator(denominator < 0 ? -denominator : denominator)
{}

void FractionNumber::checkIsZero(const FractionNumber& lhs) const
{
    if (lhs.m_numerator == 0. || lhs.m_denominator == 0.)
    {
        throw CalculationException("operand is equals zero");
    }
}

const FractionNumber& FractionNumber::operator+(const INumber& rhs) const
{
    auto fn_rhs = dynamic_cast<const FractionNumber&>(rhs);
    return FractionNumber(m_numerator * fn_rhs.m_denominator + fn_rhs.m_numerator * m_denominator,
                          m_denominator * fn_rhs.m_denominator);
}

const FractionNumber& FractionNumber::operator-(const INumber& rhs) const
{
    auto fn_rhs = dynamic_cast<const FractionNumber&>(rhs);
    return FractionNumber(m_numerator * fn_rhs.m_denominator - fn_rhs.m_numerator * m_denominator,
                          m_denominator * fn_rhs.m_denominator);
}

const FractionNumber& FractionNumber::operator*(const INumber& rhs) const
{
    auto fn_rhs = dynamic_cast<const FractionNumber&>(rhs);
    return FractionNumber(m_numerator * fn_rhs.m_numerator, m_denominator * fn_rhs.m_denominator);
}

const FractionNumber& FractionNumber::operator/(const INumber& rhs) const
{
    auto fn_rhs = dynamic_cast<const FractionNumber&>(rhs);
    checkIsZero(fn_rhs);
    return FractionNumber(m_numerator * fn_rhs.m_denominator, m_denominator * fn_rhs.m_numerator);
}

const FractionNumber& FractionNumber::operator~() const
{
    return FractionNumber(m_denominator, m_numerator);
}

std::string FractionNumber::value() const
{
    return std::to_string(m_numerator) + "/" + std::to_string(m_denominator);
}
