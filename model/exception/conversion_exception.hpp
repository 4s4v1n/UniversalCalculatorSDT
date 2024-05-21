#ifndef CONVERSION_EXCEPTION_HPP
#define CONVERSION_EXCEPTION_HPP

#include <exception>
#include <string>

class ConversionException : public std::exception
{
public:
    ConversionException(const char* message);
    const char* what() const noexcept override;

private:
    std::string m_message;
};


#endif // CONVERSION_EXCEPTION_HPP
