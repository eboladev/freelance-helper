#include "optionsdialog.h"
#include "ui_optionsdialog.h"

#include "currencyconverter.h"
#include "settings.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);

    connect(ui->updateCurrency, SIGNAL(clicked()), this, SLOT(on_updateCurrency_clicked()));
    connect(CurrencyConverter::instance(), SIGNAL(exchangeRateUpdated(float)), this, SLOT(updateExchangeRate(float)));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onAcceptChanges()));

    ui->rateLabel->setText(QString::number(CurrencyConverter::instance()->getUsdToRu()));
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::on_updateCurrency_clicked()
{
    CurrencyConverter::instance()->update();
}

void OptionsDialog::updateExchangeRate(const float rate)
{
    ui->rateLabel->setText(QString::number(rate));
}

void OptionsDialog::onAcceptChanges()
{
    CurrencyConverter::instance()->setUsdToRu(ui->rateLabel->text().toFloat());
    CurrencyConverter::instance()->store();
}
