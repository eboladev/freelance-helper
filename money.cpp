#include "money.h"
#include "currencyconverter.h"

Money::Money()
{
    amountUsCents = 0;
    amountRuCopeck = 0;
    amountByr = 0;
    currencyValue = USD;
    stringValue = "";
}

Money::Money(const QString &value)
{
    amountUsCents = 0;
    amountRuCopeck = 0;
    amountByr = 0;
    currencyValue = USD;
    stringValue = value;
    parseString();
}

void Money::parseString()
{
    determineCurrency();

    // parse digits
    QRegExp regExp("(?!\\d)");
    QString number = stringValue.replace(regExp, "");
    float amount = number.toFloat();

    // generate string value
    if(amount > 0)
    {
        formatAsReadable(amount);
    }
    else
    {
        stringValue = "";
    }
}

currency Money::getCurrency()  const
{
    return currencyValue;
}

QString Money::getString() const
{
    return stringValue;
}

Money& Money::add(const Money &money)
{
    amountUsCents += money.amountUsCents;
    amountRuCopeck += money.amountRuCopeck;
    amountByr += money.amountByr;
    regenerateStringValue();
    return *this;
}

Money& Money::sub(const Money &money)
{
    amountUsCents -= money.amountUsCents;
    amountRuCopeck -= money.amountRuCopeck;
    amountByr -= money.amountByr;
    regenerateStringValue();
    return *this;
}

long Money::getAmountAsUsd() const
{
    if(currencyValue == USD)
    {
        return amountUsCents;
    }
    else if(currencyValue == RUB)
    {
        return CurrencyConverter::instance()->convert(amountRuCopeck, RUB, USD);
    }
    else if(currencyValue == BYR)
    {
        return CurrencyConverter::instance()->convert(amountByr, BYR, USD);
    }

    return 0;
}

void Money::formatAsReadable(const float &amount)
{
    // prepare data
    if(currencyValue == USD)
    {
        amountUsCents = amount * 100;
        amountRuCopeck = CurrencyConverter::instance()->convert(amountUsCents, USD, RUB);
        amountByr = CurrencyConverter::instance()->convert(amountUsCents, USD, BYR);
    } else if (currencyValue == RUB)
    {
        amountRuCopeck = amount * 100;
        amountUsCents = CurrencyConverter::instance()->convert(amountRuCopeck, RUB, USD);
        amountByr = CurrencyConverter::instance()->convert(amountRuCopeck, RUB, BYR);
    }else if(currencyValue == BYR)
    {
        amountByr = amount;
        amountRuCopeck = CurrencyConverter::instance()->convert(amountByr, BYR, RUB);
        amountUsCents = CurrencyConverter::instance()->convert(amountByr, BYR, USD);
    }

    regenerateStringValue();
}

void Money::regenerateStringValue()
{
    // create string value
    if(currencyValue == USD)
    {
        if(amountUsCents > 0)
        {
            stringValue = QString::number(amountUsCents / 100);
            long cent = amountUsCents % 100;
            if(cent > 0)
            {
                stringValue += "." + QString::number(cent);
            }
            stringValue += " $";
        }
        else
        {
            stringValue = "";
        }
    } else if (currencyValue == RUB)
    {
        if(amountRuCopeck > 0)
        {
            stringValue = QString::number(amountRuCopeck / 100);
            long cent = amountRuCopeck % 100;
            if(cent > 0)
            {
                stringValue += "." + QString::number(cent);
            }
            stringValue += " r";
        }
        else
        {
            stringValue = "";
        }
    }else if(currencyValue == BYR)
    {
        if(amountByr > 0)
        {
            stringValue = QString::number(amountByr) + " br";
        }
        else
        {
            stringValue = "";
        }
    }
}

void Money::determineCurrency()
{
    // parse currency if it exists in the string
    bool forceCurrency = false;
    if(stringValue.contains("$"))
    {
        currencyValue = USD;
        forceCurrency = true;
    }
    else if (stringValue.contains("br"))
    {
        currencyValue = BYR;
        forceCurrency = true;
    }
    else if(stringValue.contains("r"))
    {
        currencyValue = RUB;
        forceCurrency = true;
    }

    QRegExp regExp("?!\\d|.|,");
    float amount  = stringValue.replace(regExp, "").toFloat();

    // auto currency detection if there is no string value
    if(!forceCurrency)
    {
        if(amount > 10000)
        {
            currencyValue = BYR;
        }
        else if(amount > 100)
        {
            currencyValue = RUB;
        }
        else
        {
            currencyValue = USD;
        }
    }

}
