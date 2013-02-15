#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "optionsdialog.h"
#include "currencyconverter.h"
#include "QDate"
#include "QStandardItemModel"
#include "QAbstractItemView"
#include "employee.h"


#ifdef QT_DEBUG
#include <QtCore/QDebug>
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

void MainWindow::init()
{
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionPreferences, SIGNAL(triggered()), this, SLOT(openPreferencesDialog()));
    connect(CurrencyConverter::instance(), SIGNAL(exchangeRateUpdated(currency, currency, float)), this, SLOT(setExchangeRate(currency, currency, float)));
    connect(&employee, SIGNAL(updateDay(QDate)), this, SLOT(updateDay(QDate)));

    // set exchange rate
    ui->usdToRubLabel->setText(QString::number(CurrencyConverter::instance()->getUsdToRu()));
    ui->usdToByrLabel->setText(QString::number(CurrencyConverter::instance()->getUsdToBy()));
    ui->rubToByrLabel->setText(QString::number(CurrencyConverter::instance()->getRuToBy()));

    // set model
    showingDate = QDate::currentDate();
    // TODO add maxColumnSizeFor each
    QStandardItemModel *model = new QStandardItemModel(showingDate.daysInMonth(), 30, this);
    ui->mainTable->setModel(model);

    // signal to model
    connect(ui->mainTable->model(), SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(addFee(QModelIndex,QModelIndex)));

    // set selection index
    QModelIndex index = ui->mainTable->model()->index(QDate::currentDate().day() - 1, 0);
    ui->mainTable->setFocus();
    ui->mainTable->setCurrentIndex(index);
    ui->mainTable->scrollTo(index,  QAbstractItemView::PositionAtCenter);
}


void MainWindow::openPreferencesDialog()
{
    OptionsDialog optionsDialog;
    optionsDialog.exec();
}

void MainWindow::updateDay(const QDate &date)
{
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(ui->mainTable->model());

    // get list
    QSharedPointer<QList<Fee> > list = employee.getFeesForDay(date);
    if(list.isNull())
    {
        return;
    }

    // fill row
    Fee fee("");
    int column = 0;
    foreach(fee, *list )
    {
        QModelIndex index = model->index(date.day() - 1, column++);
        bool oldState = model->blockSignals(true);
        model->setData(index, fee.getString() );
        model->blockSignals(oldState);
    }

    // clear last
    QModelIndex index = model->index(date.day() - 1, column);

    bool oldState = model->blockSignals(true);
    model->setData(index, "" );
    model->blockSignals(oldState);

    // update sum
    ui->sumLabel->setText(QString::number(employee.getSum(), 'f', 2));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setExchangeRate(const currency &from, const currency &to, const float rate)
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
        ui->rubToByrLabel->setText(QString::number(rate));
    }
    else
    {
#ifdef QT_DEBUG
        qDebug() << "Unknown currency exchange rate: from: " + QString::number(from) + ", to: " + QString::number(to) + ", rate: " + rate;
#endif
    }
}

void MainWindow::addFee(const QModelIndex &feeIndex, const QModelIndex)
{
    QModelIndex targetIndex = skipEmptyColumns(feeIndex);
    QDate targetDay(showingDate.year(), showingDate.month(), feeIndex.row() + 1);
    employee.setFee(targetDay, targetIndex.column(), targetIndex.data().toString());
}

QModelIndex MainWindow::skipEmptyColumns(const QModelIndex &index)
{
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(ui->mainTable->model());

    for(int loopColumn = 0; loopColumn < index.column(); loopColumn++)
    {
        QModelIndex loopIndex= model->index(index.row(), loopColumn);
        if(model->data(loopIndex).isNull() || model->data(loopIndex).toString().trimmed().isEmpty())
        {
            QModelIndex loopCell = model->index(index.row(), loopColumn);
            bool oldState = model->blockSignals(true);
            model->setData(loopCell, model->data(index));
            model->setData(index, "");
            model->blockSignals(oldState);
            return loopCell;
        }
    }

    return index;
}

void MainWindow::on_previousMonthBtn_clicked()
{
    showingDate = showingDate.addMonths(-1);
    updateTable();
}

void MainWindow::on_nextMonthBtn_clicked()
{
    showingDate = showingDate.addMonths(1);
    updateTable();
}

void MainWindow::updateTable()
{
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(ui->mainTable->model());
    // set month name
    ui->changeMonthBtn->setText(QLocale::system().monthName(showingDate.month()) + " " + QString::number(showingDate.year()));
    // reload table structure
    int daysInMonth = showingDate.daysInMonth();
    model->removeRows(0, model->rowCount());
    model->setRowCount(daysInMonth);
    // TODO add maxColumnSizeFor each
    model->setColumnCount(30);

    // reload table data from employee
    for(int i = 0; i < model->rowCount(); i++)
    {
        QDate dateForRow(showingDate.year(), showingDate.month(), i + 1);
        updateDay(dateForRow);
    }
}



