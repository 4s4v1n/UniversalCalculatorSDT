#include "p_number.hpp"

#include "../exception/calculation_exception.hpp"

#include "../converter/converter_decimal_to_p.hpp"
#include "../converter/converter_p_to_decimal.hpp"

void PNumber::checkAreDifferentBases(const PNumber& lhs, const PNumber& rhs) const
{
    if (lhs.base() != rhs.base())
    {
        throw CalculationException("operands got different base");
    }
}

void PNumber::checkIsZero(const PNumber& lhs) const
{
    if (lhs.m_value == 0.)
    {
        throw CalculationException("operand is equals zero");
    }
}

PNumber::PNumber():
    m_value(0),
    m_base(0),
    m_accuracy(0)
{}

PNumber::PNumber(const std::string& value, int base, int accuracy):
    m_value(value.find(".") == std::string::npos ?
              ConverterP2Decimal::pToInt(value, base) :
              ConverterP2Decimal::pToFloat(value, base)),
    m_base(base),
    m_accuracy(accuracy)
{}

PNumber::PNumber(double value, int base, int accuracy):
    m_value{value},
    m_base{base},
    m_accuracy{accuracy}
{}

int PNumber::accuracy() const
{
    return m_accuracy;
}

int PNumber::base() const
{
    return m_base;
}

std::string PNumber::value() const
{
    return ConverterDecimal2P::floatToP(m_value, m_base, m_accuracy);
}

std::string PNumber::string() const
{
    return ConverterDecimal2P::floatToP(m_value, m_base, m_accuracy);
}

std::unique_ptr<INumber> PNumber::operator+(const INumber& rhs) const
{
    auto rn_rhs = dynamic_cast<const PNumber&>(rhs);
    checkAreDifferentBases(*this, rn_rhs);
    return std::make_unique<PNumber>(m_value + rn_rhs.m_value, m_base , m_accuracy);
}

std::unique_ptr<INumber> PNumber::operator-(const INumber& rhs) const
{
    auto rn_rhs = dynamic_cast<const PNumber&>(rhs);
    checkAreDifferentBases(*this, rn_rhs);
    return std::make_unique<PNumber>(m_value - rn_rhs.m_value, m_base , m_accuracy);
}

std::unique_ptr<INumber> PNumber::operator*(const INumber& rhs) const
{
    auto rn_rhs = dynamic_cast<const PNumber&>(rhs);
    checkAreDifferentBases(*this, rn_rhs);
    return std::make_unique<PNumber>(m_value * rn_rhs.m_value, m_base , m_accuracy);
}

std::unique_ptr<INumber> PNumber::operator/(const INumber& rhs) const
{
    auto rn_rhs = dynamic_cast<const PNumber&>(rhs);
    checkAreDifferentBases(*this, rn_rhs);
    checkIsZero(rn_rhs);
    return std::make_unique<PNumber>(m_value / rn_rhs.m_value, m_base , m_accuracy);
}

std::unique_ptr<INumber> PNumber::operator~() const
{
    checkIsZero(*this);
    return std::make_unique<PNumber>(1. / m_value, m_base, m_accuracy);
}
