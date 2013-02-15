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
    
public slots:
    void openPreferencesDialog();

private:
    void init();
    void updateTable();
    QModelIndex skipEmptyColumns(const QModelIndex &index);

    Ui::MainWindow *ui;

    Employee employee;
    QDate showingDate;


private slots:
    void updateDay(const QDate &date);
    void setExchangeRate(const currency &from, const currency &to, const float rate);
    void addFee(const QModelIndex &feeIndex, const QModelIndex);
    void on_nextMonthBtn_clicked();
    void on_previousMonthBtn_clicked();
};

#endif // MAINWINDOW_H
