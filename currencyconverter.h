#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H

#include <QtCore/QObject>
#include "qglobal.h"
#include "QSharedPointer"


enum currency {
    USD, RUB, BYR
};

class CurrencyConverter : public QObject
{
    CurrencyConverter();
    Q_OBJECT
public:
    static CurrencyConverter *instance();
    long convert(const long &value, const currency &from, const currency &to) const;
    void store() const;
    void load();
    void setUsdToRu(const int &rate);
    int getUsdToRu() const { return usdToRu; }

    void setUsdToBy(const int &rate);
    int getUsdToBy() const { return usdToBy; }

    void setRuToBy(const int &rate);
    int getRuToBy() const { return ruToBy; }

private:
    int parseCurrency(const QByteArray &data);

    int usdToRu;
    int usdToBy;
    int ruToBy;

signals:
    void exchangeRateUpdated(const currency &from,  const currency &to, const int &rate);

public slots:
    void update();

private slots:
    void catchRequestReadyUsdToRub();
};

#endif // CURRENCYCONVERTER_H
