#ifndef P_NUMBER_CONTROLLER_H
#define P_NUMBER_CONTROLLER_H

#include "model/editor/editor.hpp"
#include "model/memory/memory.hpp"
#include "model/processor/processor.hpp"
#include "model/number/p_number.hpp"

#include <QObject>

class PNumberController : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE void setBase(int base);
    Q_INVOKABLE void setAccuracy(int accuracy);
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
    Memory<PNumber>    m_memory;
    Processor<PNumber> m_processor;
    Editor             m_editor;
};


#endif // P_NUMBER_CONTROLLER_H
