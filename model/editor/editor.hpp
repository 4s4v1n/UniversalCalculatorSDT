#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <set>
#include <string>

class Editor
{
public:
    void setBase(int base);
    void setAccuracy(int accuracy);
    std::string getExpression() const;
    int getBase() const;
    int getAccuracy() const;
    void addExpression(const std::string &expression);
    void clearEntry();
    void clearAll();
    void resetExpression(const std::string& expression);

private:
    std::string m_expression {};
    int         m_base       {2};
    int         m_accruracy  {0};
};

#endif // EDITOR_HPP
