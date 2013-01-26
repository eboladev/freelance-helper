#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include "employee.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    void init();

    Ui::MainWindow *ui;
    Employee employee;

public slots:
    void openPreferencesDialog();

private slots:
    void setExchangeRate(const float rate);
    void addFee(const QModelIndex feeIndex, const QModelIndex feeIndex1);
    void setColumnNumber(const quint32 number);
};

#endif // MAINWINDOW_H
