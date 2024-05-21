#include "memory.hpp"

Memory* Memory::getInstance()
{
    static Memory instance {};
    return &instance;
}

void Memory::setValue(const RealNumber& value)
{
    m_value = value;
}

RealNumber Memory::getValue() const
{
    return m_value;
}

void Memory::on()
{
    m_state = State::On;
}

void Memory::off()
{
    m_state = State::Off;
}

void Memory::clear()
{
    m_state = State::Off;
    m_value = RealNumber{0., 0, 0};
}

bool Memory::isActive() const
{
    return m_state == State::On;
}
