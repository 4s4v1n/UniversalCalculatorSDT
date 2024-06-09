#include "fraction_number_controller.hpp"

#include <QDebug>

#include <iostream>
#include <utility>

std::pair<int, int> parseFraction(const std::string& str)
{
    auto pos = str.find('/');

    auto numerator = std::stoi(str.substr(0, pos));
    auto denominator = std::stoi(str.substr(pos + 1));

    return { numerator, denominator };
}

QString FractionNumberController::calculate()
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

    try
    {
        m_processor.setLhs(FractionNumber(parseFraction(firstNumberStr)));
        m_processor.setOperator(std::string{op});

        auto pos3 = expression.find('(', pos2);
        if (pos3 != std::string::npos)
        {
            auto pos4 = expression.find(')', pos3);
            auto secondNumberStr = expression.substr(pos3 + 1, pos4 - pos3 - 1);

            m_processor.setRhs(FractionNumber(parseFraction(secondNumberStr)));
        }
    }
    catch (const std::exception& ex)
    {
        qWarning() << ex.what();
    }

    auto result = m_processor.execute();
    m_editor.resetExpression(result->value());
    m_processor.setLhs(dynamic_cast<FractionNumber&>(*result));

    return QString::fromStdString(result->value());
}

void FractionNumberController::addExpression(const QString& text)
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

void FractionNumberController::setExpression(const QString& text)
{
    m_editor.resetExpression(text.toStdString());
}

void FractionNumberController::clearEntry()
{
    m_editor.clearEntry();
}

void FractionNumberController::clearAll()
{
    m_editor.clearAll();
}

