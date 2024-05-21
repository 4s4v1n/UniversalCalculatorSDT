#include "processor.hpp"

Processor* Processor::getInstance()
{
    static Processor instance {};
    return &instance;
}

void Processor::setOperator(const Operator op)
{
    m_operator = op;
}

void Processor::setOperator(const std::string& op)
{
    if (op == "+")
    {
        m_operator = Operator::Plus;
    }
    else if (op == "-")
    {
        m_operator = Operator::Minus;
    }
    else if (op == "*")
    {
        m_operator = Operator::Multiply;
    }
    else if (op == "/")
    {
        m_operator = Operator::Division;
    }
    else if (op == "^")
    {
        m_operator = Operator::Square;
    }
    else if (op == "~")
    {
        m_operator = Operator::Reverse;
    }
    else
    {
        m_operator = Operator::None;
    }
}

void Processor::setLhs(const RealNumber& lhs)
{
    m_lhs = lhs;
}

void Processor::setRhs(const RealNumber& rhs)
{
    m_rhs = rhs;
}

RealNumber Processor::execute()
{
    switch (m_operator)
    {
        case Operator::None:     return RealNumber{0., 0, 0};
        case Operator::Plus:     return m_lhs + m_rhs;
        case Operator::Minus:    return m_lhs - m_rhs;
        case Operator::Multiply: return m_lhs * m_rhs;
        case Operator::Division: return m_lhs / m_rhs;
        case Operator::Square:   return m_lhs * m_lhs;
        case Operator::Reverse:  return 1. / m_lhs;
    }
}
