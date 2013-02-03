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
            this, SLOT(catchRequestReady()));
}

/*
    Catch reply and handle it
  */
void CurrencyConverter::catchRequestReady()
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

/*
    Store data to settings
  */
void CurrencyConverter::store() const
{
    Settings::instance()->setValue("rate", usdToRu);
    Settings::instance()->sync();
}

/*
    Store data to settings
  */
void CurrencyConverter::load()
{
    usdToRu = Settings::instance()->value("rate").toFloat();
}

void CurrencyConverter::setUsdToRu(const float &rate)
{
    usdToRu = rate;
    emit exchangeRateUpdated(usdToRu);
}

/*
    Parse Json data
    Return exchange rate
  */
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


