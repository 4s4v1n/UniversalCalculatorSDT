#include "fraction_number.hpp"

#include "../exception/calculation_exception.hpp"

FractionNumber::FractionNumber() :
    m_numerator(0),
    m_denominator(0)
{}

FractionNumber::FractionNumber(const std::pair<int, int>& pair) :
    m_numerator(pair.first),
    m_denominator(pair.second)
{}

FractionNumber::FractionNumber(int numerator, int denominator) :
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

std::unique_ptr<INumber> FractionNumber::operator+(const INumber& rhs) const
{
    auto fn_rhs = dynamic_cast<const FractionNumber&>(rhs);
    return std::make_unique<FractionNumber>(m_numerator * fn_rhs.m_denominator + fn_rhs.m_numerator * m_denominator,
                          m_denominator * fn_rhs.m_denominator);
}

std::unique_ptr<INumber> FractionNumber::operator-(const INumber& rhs) const
{
    auto fn_rhs = dynamic_cast<const FractionNumber&>(rhs);
    return std::make_unique<FractionNumber>(m_numerator * fn_rhs.m_denominator - fn_rhs.m_numerator * m_denominator,
                          m_denominator * fn_rhs.m_denominator);
}

std::unique_ptr<INumber> FractionNumber::operator*(const INumber& rhs) const
{
    auto fn_rhs = dynamic_cast<const FractionNumber&>(rhs);
    return std::make_unique<FractionNumber>(m_numerator * fn_rhs.m_numerator, m_denominator * fn_rhs.m_denominator);
}

std::unique_ptr<INumber> FractionNumber::operator/(const INumber& rhs) const
{
    auto fn_rhs = dynamic_cast<const FractionNumber&>(rhs);
    checkIsZero(fn_rhs);
    return std::make_unique<FractionNumber>(m_numerator * fn_rhs.m_denominator, m_denominator * fn_rhs.m_numerator);
}

std::unique_ptr<INumber> FractionNumber::operator~() const
{
    return std::make_unique<FractionNumber>(m_denominator, m_numerator);
}

std::string FractionNumber::value() const
{
    return "(" + std::to_string(m_numerator) + "/" + std::to_string(m_denominator) + ")";
}
