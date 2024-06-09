#include "complex_number.hpp"

#include "../exception/calculation_exception.hpp"

ComplexNumber::ComplexNumber() :
    m_value()
{}

ComplexNumber::ComplexNumber(double real, double imaginary) :
    m_value(real, imaginary)
{}

ComplexNumber::ComplexNumber(std::complex<double> value) :
    m_value(value)
{}

std::unique_ptr<INumber> ComplexNumber::operator+(const INumber& rhs) const
{
    auto cn_rhs = dynamic_cast<const ComplexNumber&>(rhs);
    auto result = m_value + cn_rhs.m_value;
    return std::make_unique<ComplexNumber>(result.real(), result.imag());
}

std::unique_ptr<INumber> ComplexNumber::operator-(const INumber& rhs) const
{
    auto cn_rhs = dynamic_cast<const ComplexNumber&>(rhs);
    auto result = m_value - cn_rhs.m_value;
    return std::make_unique<ComplexNumber>(result.real(), result.imag());
}

std::unique_ptr<INumber> ComplexNumber::operator*(const INumber& rhs) const
{
    auto cn_rhs = dynamic_cast<const ComplexNumber&>(rhs);
    auto result = m_value * cn_rhs.m_value;
    return std::make_unique<ComplexNumber>(result.real(), result.imag());
}

std::unique_ptr<INumber> ComplexNumber::operator/(const INumber& rhs) const
{
    auto cn_rhs = dynamic_cast<const ComplexNumber&>(rhs);
    auto result = m_value / cn_rhs.m_value;
    return std::make_unique<ComplexNumber>(result.real(), result.imag());
}

std::unique_ptr<INumber> ComplexNumber::operator~() const
{
    auto result = 1. / m_value;
    return std::make_unique<ComplexNumber>(result.real(), result.imag());
}

std::string ComplexNumber::value() const
{
    return "(" + std::to_string(m_value.real()) + (m_value.imag() > 0 ? "+" : "")
           + std::to_string(m_value.imag()) + "i" + ")";
}
