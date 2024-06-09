#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP

#include <complex>

#include "i_number.hpp"

class ComplexNumber : public INumber
{
public:
    ComplexNumber();
    ComplexNumber(const std::string& str);
    ComplexNumber(double real, double imaginary);
    ComplexNumber(std::complex<double> value);

public:
    std::unique_ptr<INumber> operator+(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator-(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator*(const INumber& rhs) const override;
    std::unique_ptr<INumber> operator/(const INumber& rhs) const override;

    std::unique_ptr<INumber> operator~() const override;

    std::string value() const override;
private:
    std::complex<double> m_value = {0., 0.};
};

#endif // COMPLEX_NUMBER_HPP
