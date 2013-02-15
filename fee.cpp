#include "fee.h"
#include "currencyconverter.h"

Fee::Fee(const QString &value)
{
    stringValue = value;
    currencyValue = USD;
    amount = 0;
    parseString();
}

void Fee::parseString()
{
    // parse currency
    bool forceCurrency = false;
    if(stringValue.contains("$"))
    {
        currencyValue = USD;
        forceCurrency = true;
    }
    else if(stringValue.contains("r"))
    {
        currencyValue = RUB;
        forceCurrency = true;
    }

    // parse digits
    QRegExp regExp("\\D");
    QString number = stringValue.replace(regExp, "");
    amount = number.toInt();

    // auto mode
    if(!forceCurrency && amount > 100)
    {
        currencyValue = RUB;
    }
    else if(!forceCurrency && amount > 0)
    {
        currencyValue = USD;
    }

    // generate string value
    const char* const str_currency[]={"$", "r"};
    if(amount > 0)
    {
        stringValue = QString::number(amount) + " " + str_currency[currencyValue];
    }
    else
    {
        stringValue = "";
    }
}

int Fee::getAmount()  const
{
    return amount;
}

currency Fee::getCurrency()  const
{
    return currencyValue;
}

QString Fee::getString() const
{
    return stringValue;
}

float Fee::getAmountAsUsd() const
{
    if(currencyValue == USD)
    {
        return amount;
    }
    else if(currencyValue == RUB)
    {
        return CurrencyConverter::instance()->convertRubToUsd(amount);
    }
}
