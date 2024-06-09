#include "processor.hpp"

template <typename T>
void Processor<T>::setOperator(const Operator op)
{
    m_operator = op;
}

template <typename T>
void Processor<T>::setOperator(const std::string& op)
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

template <typename T>
void Processor<T>::setLhs(const T& lhs)
{
    m_lhs = std::make_unique<T>(lhs);
}

template <typename T>
void Processor<T>::setRhs(const T& rhs)
{
    m_rhs = std::make_unique<T>(rhs);
}

template <typename T>
std::unique_ptr<INumber> Processor<T>::execute()
{
    switch (m_operator)
    {
        case Operator::None:     return std::unique_ptr<INumber>(nullptr);
        case Operator::Plus:     return *m_lhs + *m_rhs;
        case Operator::Minus:    return *m_lhs - *m_rhs;
        case Operator::Multiply: return *m_lhs * *m_rhs;
        case Operator::Division: return *m_lhs / *m_rhs;
        case Operator::Square:   return *m_lhs * *m_lhs;
        case Operator::Reverse:  return ~(*m_lhs);
    }
}
