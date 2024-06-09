#include "editor.hpp"

#include "../exception/number_exception.hpp"

void Editor::setBase(const int base)
{
    if (base < 2 || base > 16)
    {
        throw NumberException{"base is out of range"};
    }
    if (m_base != base)
    {
        m_base = base;
    }
}

void Editor::setAccuracy(const int accuracy)
{
    if (accuracy < 0)
    {
        throw NumberException{"accuracy is out of range"};
    }
    if (m_accruracy != accuracy)
    {
        m_accruracy = accuracy;
    }
}

std::string Editor::getExpression() const
{
    return m_expression;
}

int Editor::getBase() const
{
    return m_base;
}

int Editor::getAccuracy() const
{
    return m_accruracy;
}

void Editor::addExpression(const std::string &expression)
{
    m_expression += expression;
}

void Editor::clearEntry()
{
    if (m_expression.empty())
    {
        return;
    }
    m_expression.pop_back();
}

void Editor::clearAll()
{
    m_expression.clear();
}

void Editor::resetExpression(const std::string& expression)
{
    m_expression = expression;
}
