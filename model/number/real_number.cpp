#include "real_number.hpp"

#include "../exception/calculation_exception.hpp"

#include "../converter/converter_decimal_to_p.hpp"
#include "../converter/converter_p_to_decimal.hpp"

void RealNumber::checkAreDifferentBases(const RealNumber& lhs, const RealNumber& rhs) const
{
    if (lhs.base() != rhs.base())
    {
        throw CalculationException("operands got different base");
    }
}

void RealNumber::checkIsZero(const RealNumber& lhs) const
{
    if (lhs.m_value == 0.)
    {
        throw CalculationException("operand is equals zero");
    }
}

RealNumber::RealNumber(const std::string& value, int base, int accuracy):
    m_value(value.find(".") == std::string::npos ?
              ConverterP2Decimal::pToInt(value, base) :
              ConverterP2Decimal::pToFloat(value, base)),
    m_base(base),
    m_accuracy(accuracy)
{}

RealNumber::RealNumber(double value, int base, int accuracy):
    m_value{value},
    m_base{base},
    m_accuracy{accuracy}
{}

int RealNumber::accuracy() const
{
    return m_accuracy;
}

int RealNumber::base() const
{
    return m_base;
}

std::string RealNumber::value() const
{
    return ConverterDecimal2P::floatToP(m_value, m_base, m_accuracy);
}

std::string RealNumber::string() const
{
    return ConverterDecimal2P::floatToP(m_value, m_base, m_accuracy);
}

const RealNumber& RealNumber::operator+(const INumber& rhs) const
{
    auto rn_rhs = dynamic_cast<const RealNumber&>(rhs);
    checkAreDifferentBases(*this, rn_rhs);
    return RealNumber(m_value + rn_rhs.m_value, m_base , m_accuracy);
}

const RealNumber& RealNumber::operator-(const INumber& rhs) const
{
    auto rn_rhs = dynamic_cast<const RealNumber&>(rhs);
    checkAreDifferentBases(*this, rn_rhs);
    return RealNumber(m_value - rn_rhs.m_value, m_base, m_accuracy);
}

const RealNumber& RealNumber::operator*(const INumber& rhs) const
{
    auto rn_rhs = dynamic_cast<const RealNumber&>(rhs);
    checkAreDifferentBases(*this, rn_rhs);
    return RealNumber(m_value * rn_rhs.m_value, m_base, m_accuracy);
}

const RealNumber& RealNumber::operator/(const INumber& rhs) const
{
    auto rn_rhs = dynamic_cast<const RealNumber&>(rhs);
    checkAreDifferentBases(*this, rn_rhs);
    checkIsZero(rn_rhs);
    return RealNumber(m_value / rn_rhs.m_value, m_base, m_accuracy);
}

const RealNumber& RealNumber::operator~() const
{
    checkIsZero(*this);
    return RealNumber(1. / m_value, m_base, m_accuracy);
}
