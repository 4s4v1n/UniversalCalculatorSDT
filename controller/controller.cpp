#include "controller.hpp"

#include <array>
#include <iostream>
#include <regex>

#include "model/converter/converter_p_to_decimal.hpp"
#include "model/converter/converter_decimal_to_p.hpp"

#include "model/processor/processor.hpp"

#include "model/memory/memory.hpp"

#include "model/number/real_number.hpp"

Controller* Controller::getInstance()
{
    static Controller instance {};
    return &instance;
}

// ~ is reverse
// ^ is square

QString Controller::calculate()
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
            auto lhs {expression.substr(0, pos)};

            Processor::getInstance()->setLhs({lhs, m_editor.getBase(), m_editor.getAccuracy()});
            Processor::getInstance()->setOperator(delimeter);

            if (pos + delimeter.size() < expression.size())
            {
                auto rhs {expression.substr(pos + delimeter.size(), expression.size())};
                Processor::getInstance()->setRhs({rhs, m_editor.getBase(), m_editor.getAccuracy()});
            }
        }
        catch (const std::exception& ex)
        {
            qWarning() << ex.what();
        }
        break;
    }

    auto result {Processor::getInstance()->execute()};

    m_editor.resetExpression(result.string());
    Processor::getInstance()->setLhs(result);

    return QString::fromStdString(result.string());
}

void Controller::setBase(const int base)
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

void Controller::setAccuracy(const int accuracy)
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


void Controller::addExpression(const QString& text)
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

void Controller::setExpression(const QString& text)
{
    m_editor.resetExpression(text.toStdString());
}

void Controller::clearEntry()
{
    m_editor.clearEntry();
}

void Controller::clearAll()
{
    m_editor.clearAll();
}


void Controller::memoryAdd(const QString& value)
{
    if (!Memory::getInstance()->isActive())
    {
        return;
    }

    try
    {
        auto currentValue {Memory::getInstance()->getValue()};
        auto newValue     {RealNumber{value.toStdString(), m_editor.getBase(),
                                 m_editor.getAccuracy()}};
        Memory::getInstance()->setValue(currentValue + newValue);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Controller::memorySave(const QString& value)
{
    Memory::getInstance()->on();

    try
    {
        Memory::getInstance()->setValue(RealNumber{value.toStdString(),
                                                   m_editor.getBase(), m_editor.getAccuracy()});
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

}

void Controller::memoryClear()
{
    Memory::getInstance()->clear();
    Memory::getInstance()->off();
}

QString Controller::memoryRead()
{
    if (!Memory::getInstance()->isActive())
    {
        return "";
    }

    try
    {
        return QString::fromStdString(Memory::getInstance()->getValue().string());
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return "";
    }
}
