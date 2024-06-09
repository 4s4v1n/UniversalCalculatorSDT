#include "p_number_controller.hpp"

#include "model/processor/processor.hpp"
#include "model/memory/memory.hpp"
#include "model/number/p_number.hpp"

#include <QDebug>

#include <array>
#include <iostream>

// ~ is reverse
// ^ is square

QString PNumberController::calculate()
{
    static const std::array<std::string, 6> delimeters {"+", "-", "*", "/",
                                                       "^", "~"};
    auto expression {m_editor.getExpression()};
    if (expression.empty())
    {
        return "";
    }

    for (const auto& delimeter : delimeters)
    {
        auto pos {expression.find(delimeter)};
        if (pos == std::string::npos)
        {
            // TODO make something
        }

        if (pos == std::string::npos || pos == 0 && delimeter == "-")
        {
            continue;
        }

        try
        {
            auto lhs = expression.substr(0, pos);

            m_processor.setLhs(PNumber(lhs, m_editor.getBase(), m_editor.getAccuracy()));
            m_processor.setOperator(delimeter);

            if (pos + delimeter.size() < expression.size())
            {
                auto rhs = expression.substr(pos + delimeter.size(), expression.size());
                m_processor.setRhs(PNumber(rhs, m_editor.getBase(), m_editor.getAccuracy()));
            }
        }
        catch (const std::exception& ex)
        {
            qWarning() << ex.what();
        }
        break;
    }

    auto result = m_processor.execute();

    m_editor.resetExpression(result->value());
    m_processor.setLhs(dynamic_cast<PNumber&>(*result));

    return QString::fromStdString(result->value());
}

void PNumberController::setBase(const int base)
{
    try
    {
        m_editor.setBase(base);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void PNumberController::setAccuracy(const int accuracy)
{
    try
    {
        m_editor.setAccuracy(accuracy);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void PNumberController::addExpression(const QString& text)
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

void PNumberController::setExpression(const QString& text)
{
    m_editor.resetExpression(text.toStdString());
}

void PNumberController::clearEntry()
{
    m_editor.clearEntry();
}

void PNumberController::clearAll()
{
    m_editor.clearAll();
}

void PNumberController::memoryAdd(const QString& value)
{
    if (!m_memory.isActive())
    {
        return;
    }

    try
    {
        auto oldPointer = m_memory.getValue();
        auto oldValue = dynamic_cast<PNumber&>(*oldPointer);
        auto result = oldValue + PNumber(value.toStdString(), m_editor.getBase(), m_editor.getAccuracy());

        m_memory.setValue(dynamic_cast<PNumber&>(*result));
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void PNumberController::memorySave(const QString& value)
{
    m_memory.on();

    try
    {
        m_memory.setValue(PNumber(value.toStdString(),m_editor.getBase(), m_editor.getAccuracy()));
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

}

void PNumberController::memoryClear()
{
    m_memory.clear();
    m_memory.off();
}

QString PNumberController::memoryRead()
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
