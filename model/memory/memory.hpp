#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "../number/i_number.hpp"

#include <memory>

template <typename T>
class Memory
{
public:
    void setValue(const T& value);
    std::shared_ptr<INumber> getValue() const;
    void on();
    void off();
    void clear();
    bool isActive() const;

private:
    enum State
    {
        On  = 0,
        Off = 1
    };

private:
    State m_state = State::Off;
    std::shared_ptr<INumber> m_value;
};

#include "memory.inl"

#endif // MEMORY_HPP
