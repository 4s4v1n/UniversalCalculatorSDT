#include "conversion_exception.hpp"

ConversionException::ConversionException(const char* message):
        m_message{message}
{}

const char* ConversionException::what() const noexcept
{
    return m_message.c_str();
}