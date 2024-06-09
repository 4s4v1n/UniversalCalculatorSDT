#include "memory.hpp"

template <typename T>
void Memory<T>::setValue(const T& value)
{
    m_value = std::make_shared<T>(value);
}

template <typename T>
std::shared_ptr<INumber> Memory<T>::getValue() const
{
    return m_value;
}

template <typename T>
void Memory<T>::on()
{
    m_state = State::On;
}

template <typename T>
void Memory<T>::off()
{
    m_state = State::Off;
}

template <typename T>
void Memory<T>::clear()
{
    m_state = State::Off;
    m_value.reset();
}

template <typename T>
bool Memory<T>::isActive() const
{
    return m_state == State::On;
}
