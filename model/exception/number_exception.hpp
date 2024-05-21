#ifndef NUMBER_BASE_EXCEPTION_HPP
#define NUMBER_BASE_EXCEPTION_HPP

#include <exception>
#include <string>

class NumberException : public std::exception
{
public:
    NumberException(const char* message);
    const char* what() const noexcept override;

private:
    std::string m_message;
};

#endif // NUMBER_BASE_EXCEPTION_HPP
