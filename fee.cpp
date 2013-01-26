#include "fee.h"


Fee::Fee(const QString &value)
{
    enteredFee = value;
    usedCurrency = USD;
    amount = 0;
    parseString();
}

void Fee::parseString()
{

}

quint32 Fee::getAmount()
{
    return amount;
}

Fee::currency Fee::getCurrency()
{
    return usedCurrency;
}
