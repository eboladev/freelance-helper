#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H

#include <QtCore/QObject>
#include "qglobal.h"

class CurrencyConverter : public QObject
{
    CurrencyConverter();
    Q_OBJECT
public:
    static CurrencyConverter *instance();
    quint32 convertUsdToRub(const quint32 &value);
    quint32 convertRubToUsd(const quint32 &value);
    void store();
    void load();
    void setUsdToRu(const float &rate);
    float getUsdToRu();

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
