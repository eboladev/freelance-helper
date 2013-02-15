#include "optionsdialog.h"
#include "ui_optionsdialog.h"

#include "currencyconverter.h"
#include "settings.h"
#ifdef QT_DEBUG
#include <QtCore/QDebug>
#endif

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);

    connect(ui->updateCurrency, SIGNAL(clicked()), this, SLOT(on_updateCurrency_clicked()));
    connect(CurrencyConverter::instance(), SIGNAL(exchangeRateUpdated(currency, currency, float)), this, SLOT(updateExchangeRate(currency, currency, float)));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onAcceptChanges()));

    ui->usdToRubLabel->setText(QString::number(CurrencyConverter::instance()->getUsdToRu()));
    ui->usdToByrLabel->setText(QString::number(CurrencyConverter::instance()->getUsdToBy()));
    ui->RubToByrLabel->setText(QString::number(CurrencyConverter::instance()->getRuToBy()));
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::on_updateCurrency_clicked()
{
    CurrencyConverter::instance()->update();
}

void OptionsDialog::updateExchangeRate(const currency &from, const currency &to, const float &rate)
{
    if(from == USD && to == RUB)
    {
        ui->usdToRubLabel->setText(QString::number(rate));
    }
    else if(from == USD && to == BYR)
    {
        ui->usdToByrLabel->setText(QString::number(rate));
    }
    else if(from == RUB && to == BYR)
    {
        ui->RubToByrLabel->setText(QString::number(rate));
    }
    else
    {
#ifdef QT_DEBUG
        qDebug() << "Unknown currency exchange rate: from: " + QString::number(from) + ", to: " + QString::number(to) + ", rate: " + rate;
#endif
    }
}

void OptionsDialog::onAcceptChanges()
{
    CurrencyConverter::instance()->setUsdToRu(ui->usdToRubLabel->text().toFloat());
    CurrencyConverter::instance()->setUsdToBy(ui->usdToByrLabel->text().toFloat());
    CurrencyConverter::instance()->setRuToBy(ui->RubToByrLabel->text().toFloat());
    CurrencyConverter::instance()->store();
}
