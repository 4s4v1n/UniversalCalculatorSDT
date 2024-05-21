#include "number_exception.hpp"

NumberException::NumberException(const char* message):
    m_message{message}
{}

const char* NumberException::what() const noexcept
{
    return m_message.c_str();
}