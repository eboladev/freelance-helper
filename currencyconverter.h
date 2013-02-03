#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H

#include <QtCore/QObject>
#include "qglobal.h"
#include "QSharedPointer"

class CurrencyConverter : public QObject
{
    CurrencyConverter();
    Q_OBJECT
public:
    static CurrencyConverter *instance();
    int convertUsdToRub(const int &value) const { return value * usdToRu; }
    int convertRubToUsd(const int &value) const { return value / usdToRu; }
    void store() const;
    void load();
    void setUsdToRu(const float &rate);
    float getUsdToRu() const { return usdToRu; }

private:
    float parseCurrency(const QByteArray &data);

    float usdToRu;
signals:
    void exchangeRateUpdated(const float &rate);

public slots:
    void update();

private slots:
    void catchRequestReady();
};

#endif // CURRENCYCONVERTER_H
