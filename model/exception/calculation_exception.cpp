#include "calculation_exception.hpp"

CalculationException::CalculationException(const char* message):
    m_message{message}
{}

const char* CalculationException::what() const noexcept
{
    return m_message.c_str();
}