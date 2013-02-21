#ifndef FEE_H
#define FEE_H

#include "QtCore"
#include "currencyconverter.h"

class Fee
{
public:
    Fee(const QString &value);
    int getAmount() const;
    currency getCurrency() const;
    QString getString() const;
    float getAmountAsUsd() const;

private:
    void parseString();
    QString stringValue;
    currency currencyValue;
    int amount;
};

#endif // FEE_H
