#ifndef FEE_H
#define FEE_H

#include "QtCore"


class Fee
{

    enum currency {
        USD, RUB
    };

public:
    Fee(const QString &value);
    quint32 getAmount();
    currency getCurrency();


private:
    void parseString();
    QString enteredFee;
    currency usedCurrency;
    quint32 amount;
};

#endif // FEE_H
