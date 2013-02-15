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
    float convertUsdToRub(const int &value) const { return (float) value * (float) usdToRu; }
    float convertRubToUsd(const int &value) const { return (float) value / (float) usdToRu; }
    float convertUsdToBy(const int &value) const { return (float) value * (float) usdToBy; }
    float convertByToUsd(const int &value) const { return (float) value / (float) usdToBy; }
    float convertRubToBy(const int &value) const { return (float) value * (float) ruToBy; }
    float convertByToRub(const int &value) const { return (float) value / (float) ruToBy; }
    void store() const;
    void load();
    void setUsdToRu(const float &rate);
    float getUsdToRu() const { return usdToRu; }

    void setUsdToBy(const float &rate);
    float getUsdToBy() const { return usdToBy; }

    void setRuToBy(const float &rate);
    float getRuToBy() const { return ruToBy; }

private:
    float parseCurrency(const QByteArray &data);

    float usdToRu;
    float usdToBy;
    float ruToBy;
    static const int USD_TO_RUB_DEFAULT  = 30;
    static const int USD_TO_BYR_DEFAULT  = 8710;
    static const int RUB_TO_BYR_DEFAULT  = 288;

signals:
    void exchangeRateUpdated(const currency &from,  const currency &to, const float &rate);

public slots:
    void update();

private slots:
    void catchRequestReadyUsdToRub();
/*    void catchRequestReadyUsdToBy();
    void catchRequestReadyRuToBy();*/
};

#endif // CURRENCYCONVERTER_H
