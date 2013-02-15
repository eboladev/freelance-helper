#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include "currencyconverter.h"

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();
    
private:
    float exchangeRate;
    Ui::OptionsDialog *ui;

private slots:
    void on_updateCurrency_clicked();
    void updateExchangeRate(const currency &from, const currency &to, const float &rate);
    void onAcceptChanges();
};

#endif // OPTIONSDIALOG_H
