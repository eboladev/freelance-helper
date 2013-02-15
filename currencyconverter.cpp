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

/*
    Update exchange rate
  */
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

  /*  request.setUrl(QUrl("http://rate-exchange.appspot.com/currency?from=USD&to=RUB"));

    *reply = manager.get(request);
    connect(reply, SIGNAL(finished()),
            this, SLOT(catchRequestReadyUsdToRub()));

    request.setUrl(QUrl("http://rate-exchange.appspot.com/currency?from=USD&to=RUB"));

    *reply = manager.get(request);
    connect(reply, SIGNAL(finished()),
            this, SLOT(catchRequestReadyUsdToRub()));*/
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
    usdToRu = Settings::instance()->value("usdToRu").toFloat();
    usdToBy = Settings::instance()->value("usdToBy").toFloat();
    ruToBy = Settings::instance()->value("ruToBy").toFloat();

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

void CurrencyConverter::setUsdToRu(const float &rate)
{
    usdToRu = rate;
    emit exchangeRateUpdated(USD, RUB, usdToRu);
}

void CurrencyConverter::setUsdToBy(const float &rate)
{
    usdToBy = rate;
    emit exchangeRateUpdated(USD, BYR, usdToBy);
}

void CurrencyConverter::setRuToBy(const float &rate)
{
    ruToBy = rate;
    emit exchangeRateUpdated(RUB, BYR, ruToBy);
}

float CurrencyConverter::parseCurrency(const QByteArray &data)
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

    return result["rate"].toFloat();
}


