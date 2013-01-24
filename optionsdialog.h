#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

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
private slots:
    void on_updateCurrency_clicked();
    void exchangeRateUpdate(const float rate);
    void onAcceptChanges();

private:
    Ui::OptionsDialog *ui;
};

#endif // OPTIONSDIALOG_H
