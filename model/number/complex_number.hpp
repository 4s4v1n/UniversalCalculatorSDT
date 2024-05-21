#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP

#include <complex>

#include "i_number.hpp"

class ComplexNumber : public INumber
{
public:
    ComplexNumber(double real, double imaginary);

public:
    const ComplexNumber& operator+(const INumber& rhs) const override;
    const ComplexNumber& operator-(const INumber& rhs) const override;
    const ComplexNumber& operator*(const INumber& rhs) const override;
    const ComplexNumber& operator/(const INumber& rhs) const override;

    const ComplexNumber& operator~() const override;

    std::string value() const override;
private:
    std::complex<double> m_value = {0., 0.};
};

#endif // COMPLEX_NUMBER_HPP
