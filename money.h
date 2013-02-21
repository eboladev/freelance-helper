#ifndef MONEY_H
#define MONEY_H

#include "QtCore"
#include "currencyconverter.h"

class Money
{
public:
    Money();
    Money(const QString &value);
    currency getCurrency() const;
    long getAmountAsUsd() const;
    QString getString() const;
    Money& add(const Money &money);
    Money& sub(const Money &money);

private:
    void parseString();
    void determineCurrency();
    void formatAsReadable(const float &amount);
    void regenerateStringValue();

    long amountUsCents;
    long amountRuCopeck;
    long amountByr;
    currency currencyValue;
    QString stringValue;
};
#endif // MONEY_H
