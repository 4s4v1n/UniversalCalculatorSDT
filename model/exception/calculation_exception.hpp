#ifndef CALCULATION_EXCEPTION_HPP
#define CALCULATION_EXCEPTION_HPP

#include <exception>
#include <string>

class CalculationException : public std::exception
{
public:
    CalculationException(const char* message);
    const char* what() const noexcept override;

private:
    std::string m_message;
};


#endif // CALCULATION_EXCEPTION_HPP
