#ifndef COMPLEX_NUMBER_CONTROLLER_HPP
#define COMPLEX_NUMBER_CONTROLLER_HPP

#include "model/editor/editor.hpp"
#include "model/memory/memory.hpp"
#include "model/processor/processor.hpp"
#include "model/number/complex_number.hpp"

#include <QObject>

class ComplexNumberController : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE void addExpression(const QString& text);
    Q_INVOKABLE void setExpression(const QString& text);
    Q_INVOKABLE void clearEntry();
    Q_INVOKABLE void clearAll();
    Q_INVOKABLE QString calculate();
    Q_INVOKABLE void memoryAdd(const QString& value);
    Q_INVOKABLE void memorySave(const QString& value);
    Q_INVOKABLE void memoryClear();
    Q_INVOKABLE QString memoryRead();

private:
    Memory<ComplexNumber>    m_memory;
    Processor<ComplexNumber> m_processor;
    Editor                   m_editor;
};

#endif // COMPLEX_NUMBER_CONTROLLER_HPP
