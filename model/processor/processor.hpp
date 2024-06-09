#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "../number/i_number.hpp"

template <typename T>
class Processor
{
public:
    enum class Operator
    {
        None,
        Plus,
        Minus,
        Multiply,
        Division,
        Square,
        Reverse
    };

public:
    void setOperator(Operator op);
    void setOperator(const std::string& op);
    void setLhs(const T& lhs);
    void setRhs(const T& rhs);
    std::unique_ptr<INumber> execute();

private:
    Operator m_operator {Operator::None};
    std::unique_ptr<T> m_lhs;
    std::unique_ptr<T> m_rhs;
};

#include "processor.inl"

#endif // PROCESSOR_HPP
