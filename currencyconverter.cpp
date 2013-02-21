#include "currencyconverter.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include "json.h"
#include "settings.h"

#ifdef QT_DEBUG
#include <QtCore/QDebug>
#endif


CurrencyConverter::CurrencyConverter()
{
    load();
}

CurrencyConverter *CurrencyConverter::instance()
{
    static CurrencyConverter instance_;
    return &instance_;
}

long CurrencyConverter::convert(const long &value, const currency &from, const currency &to) const
{
    if(from == USD && to == RUB)
    {
        return value * usdToRu;
    }
    if(from == USD && to == BYR)
    {
        return value * usdToBy;
    }
    if(from == RUB && to == BYR)
    {
        return value * ruToBy;
    }
    if(from == RUB && to == USD)
    {
        return value / usdToRu;
    }
    if(from == BYR && to == USD)
    {
        return value / usdToBy;
    }
    if(from == BYR && to == RUB)
    {
        return value / ruToBy;
    }

    return 0;
}

void CurrencyConverter::update()
{
#ifdef QT_DEBUG
    qDebug() << "Update exchange rate...";
#endif

    QNetworkRequest request;
    request.setUrl(QUrl("http://rate-exchange.appspot.com/currency?from=USD&to=RUB"));

    static QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);
    connect(reply, SIGNAL(finished()),
            this, SLOT(catchRequestReadyUsdToRub()));
}

void CurrencyConverter::catchRequestReadyUsdToRub()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply) {
        setUsdToRu(parseCurrency(reply->readAll()));
#ifdef QT_DEBUG
    qDebug() << "usdToRu:" << QString::number(usdToRu);
#endif
        store();
        reply->deleteLater();
    }
}

void CurrencyConverter::store() const
{
    Settings::instance()->setValue("usdToRu", usdToRu);
    Settings::instance()->setValue("usdToBy", usdToBy);
    Settings::instance()->setValue("ruToBy", ruToBy);
    Settings::instance()->sync();
}

void CurrencyConverter::load()
{
    const int USD_TO_RUB_DEFAULT  = 30;
    const int USD_TO_BYR_DEFAULT  = 8710;
    const int RUB_TO_BYR_DEFAULT  = 288;

    usdToRu = Settings::instance()->value("usdToRu").toInt();
    usdToBy = Settings::instance()->value("usdToBy").toInt();
    ruToBy = Settings::instance()->value("ruToBy").toInt();

    if(usdToRu == 0)
    {
        usdToRu = USD_TO_RUB_DEFAULT;
    }

    if(usdToBy == 0)
    {
        usdToBy = USD_TO_BYR_DEFAULT;
    }

    if(ruToBy == 0)
    {
        ruToBy = RUB_TO_BYR_DEFAULT;
    }
}

void CurrencyConverter::setUsdToRu(const int &rate)
{
    usdToRu = rate;
    emit exchangeRateUpdated(USD, RUB, usdToRu);
}

void CurrencyConverter::setUsdToBy(const int &rate)
{
    usdToBy = rate;
    emit exchangeRateUpdated(USD, BYR, usdToBy);
}

void CurrencyConverter::setRuToBy(const int &rate)
{
    ruToBy = rate;
    emit exchangeRateUpdated(RUB, BYR, ruToBy);
}

int CurrencyConverter::parseCurrency(const QByteArray &data)
{
#ifdef QT_DEBUG
    qDebug() << data;
#endif
    bool ok;
    QVariantMap result = QtJson::parse(data, ok).toMap();

    if(!ok) {
#ifdef QT_DEBUG
        qDebug() << "Parse error!";
#endif
        return 0;
    }

    return result["rate"].toInt();
}


