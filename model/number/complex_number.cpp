#include "complex_number.hpp"

#include "../exception/calculation_exception.hpp"

ComplexNumber::ComplexNumber(double real, double imaginary) :
    m_value(real, imaginary)
{}

const ComplexNumber& ComplexNumber::operator+(const INumber& rhs) const
{
    auto cn_rhs = dynamic_cast<const ComplexNumber&>(rhs);
    auto result     = m_value + cn_rhs.m_value;
    return ComplexNumber(result.real(), result.imag());
}

const ComplexNumber& ComplexNumber::operator-(const INumber& rhs) const
{
    auto cn_rhs = dynamic_cast<const ComplexNumber&>(rhs);
    auto result     = m_value - cn_rhs.m_value;
    return ComplexNumber(result.real(), result.imag());
}

const ComplexNumber& ComplexNumber::operator*(const INumber& rhs) const
{
    auto cn_rhs = dynamic_cast<const ComplexNumber&>(rhs);
    auto result     = m_value * cn_rhs.m_value;
    return ComplexNumber(result.real(), result.imag());
}

const ComplexNumber& ComplexNumber::operator/(const INumber& rhs) const
{
    auto cn_rhs = dynamic_cast<const ComplexNumber&>(rhs);
    auto result     = m_value / cn_rhs.m_value;
    return ComplexNumber(result.real(), result.imag());
}

const ComplexNumber& ComplexNumber::operator~() const
{
    auto result = 1. / m_value;
    return ComplexNumber(result.real(), result.imag());
}

std::string ComplexNumber::value() const
{
    return std::to_string(m_value.real()) + "i" + std::to_string(m_value.imag());
}
