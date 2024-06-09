#include "complex_number_controller.hpp"

#include <QDebug>

#include <iostream>

std::complex<double> parseComplex(const std::string& str)
{
    double real = 0.0, imag = 0.0;
    char op;
    std::stringstream ss(str);
    ss >> real >> op;

    if (op == '+' || op == '-') {
        ss.unget();
    } else {
        ss >> imag;
        imag = 0.0;
    }

    ss >> imag >> op;
    if (op == '-') imag = -imag;

    return std::complex<double>(real, imag);
}

QString ComplexNumberController::calculate()
{
    auto expression = m_editor.getExpression();
    if (expression.empty())
    {
        return "";
    }

    auto pos1 = expression.find('(');
    auto pos2 = expression.find(')', pos1);
    auto firstNumberStr = expression.substr(pos1 + 1, pos2 - pos1 - 1);

    auto op = expression[pos2 + 1];

    auto pos3 = expression.find('(', pos2);
    auto pos4 = expression.find(')', pos3);
    auto secondNumberStr = expression.substr(pos3 + 1, pos4 - pos3 - 1);

    try
    {
        m_processor.setLhs(ComplexNumber(parseComplex(firstNumberStr)));
        m_processor.setOperator(std::string{op});

        auto pos3 = expression.find('(', pos2);
        if (pos3 != std::string::npos)
        {
            auto pos4 = expression.find(')', pos3);
            auto secondNumberStr = expression.substr(pos3 + 1, pos4 - pos3 - 1);

            m_processor.setRhs(ComplexNumber(parseComplex(secondNumberStr)));
        }
    }
    catch (const std::exception& ex)
    {
        qWarning() << ex.what();
    }

    auto result = m_processor.execute();
    m_editor.resetExpression(result->value());
    m_processor.setLhs(dynamic_cast<ComplexNumber&>(*result));

    return QString::fromStdString(result->value());
}

void ComplexNumberController::addExpression(const QString& text)
{
    try
    {
        m_editor.addExpression(text.toStdString());
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void ComplexNumberController::setExpression(const QString& text)
{
    m_editor.resetExpression(text.toStdString());
}

void ComplexNumberController::clearEntry()
{
    m_editor.clearEntry();
}

void ComplexNumberController::clearAll()
{
    m_editor.clearAll();
}

void ComplexNumberController::memoryAdd(const QString& value)
{
    if (!m_memory.isActive())
    {
        return;
    }

    try
    {
        auto expression = value.toStdString();
        auto pos1 = expression.find('(');
        auto pos2 = expression.find(')', pos1);
        auto numberStr = expression.substr(pos1 + 1, pos2 - pos1 - 1);

        auto oldPointer = m_memory.getValue();
        auto oldValue = dynamic_cast<ComplexNumber&>(*oldPointer);
        auto result = oldValue + ComplexNumber(parseComplex(numberStr));

        m_memory.setValue(dynamic_cast<ComplexNumber&>(*result));
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void ComplexNumberController::memorySave(const QString& value)
{
    m_memory.on();

    try
    {
        auto expression = value.toStdString();
        auto pos1 = expression.find('(');
        auto pos2 = expression.find(')', pos1);
        auto numberStr = expression.substr(pos1 + 1, pos2 - pos1 - 1);

        m_memory.setValue(parseComplex(numberStr));
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

}

void ComplexNumberController::memoryClear()
{
    m_memory.clear();
    m_memory.off();
}

QString ComplexNumberController::memoryRead()
{
    if (!m_memory.isActive())
    {
        return "";
    }

    try
    {
        return QString::fromStdString(m_memory.getValue()->value());
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return "";
    }
}
