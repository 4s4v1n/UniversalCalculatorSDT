#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "../number/real_number.hpp"

class Memory
{
public:
    static Memory* getInstance();

public:
    void setValue(const RealNumber& value);
    RealNumber getValue() const;
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
    Memory() = default;
    ~Memory() = default;

private:
    RealNumber m_value {0., 0, 0};
    State      m_state {State::Off};
};

#endif // MEMORY_HPP
