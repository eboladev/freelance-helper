#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "optionsdialog.h"
#include "currencyconverter.h"
#include "maintablemodel.h"
#include "QDate"
#include "workerday.h"
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
    connect(CurrencyConverter::instance(), SIGNAL(exchangeRateUpdated(float)), this, SLOT(setExchangeRate(float)));


    ui->exchangeRateLabel->setText(QString::number(CurrencyConverter::instance()->getUsdToRu()));

 //   MainTableModel  model(0);
  ////  model.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  //  model.setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
 //   model.setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
   // qDebug() << model.columnCount();
 //   ui->mainTable->setRowCount(3);
   // ui->mainTable->set
    WorkerDay workerMonth(QDate::currentDate());
    quint32 daysInMonth = workerMonth.getNumberOfDays();
    QStandardItemModel *model = new QStandardItemModel(daysInMonth, employee.getMaxLength() + 1, this);
   // model->setHeaderData(0, Qt::Horizontal, tr("Label"));
  //  model->setHeaderData(1, Qt::Horizontal, tr("Quantity"));

     ui->mainTable->setModel(model);

     connect(ui->mainTable->model(), SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(addFee(QModelIndex,QModelIndex)));
     connect(&employee, SIGNAL(maxLengthChanged(quint32)), this, SLOT(setColumnNumber(quint32)));
     QModelIndex index = ui->mainTable->model()->index(QDate::currentDate().day(), 0);
    ui->mainTable->selectionModel()->select(index, QItemSelectionModel::Select);
    ui->mainTable->scrollTo(index,  QAbstractItemView::PositionAtTop);
}

void MainWindow::openPreferencesDialog()
{
    OptionsDialog optionsDialog;
    optionsDialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setExchangeRate(const float rate)
{
    ui->exchangeRateLabel->setText(QString::number(rate));
}

void MainWindow::addFee(const QModelIndex feeIndex, const QModelIndex feeIndex1)
{
    employee.setFee(QDate::currentDate(), feeIndex.column(), feeIndex.data().toString());
}

void MainWindow::setColumnNumber(const quint32 number)
{
    if(ui->mainTable->model()->columnCount() < number)
    {
        //move column
    }
    else
    {
        QList<QStandardItem*> items;
     //   for(int i = 0; i < ui->mainTable->model()->rowCount(); i++)
    //    {
    //        QStandardItem* item = new QStandardItem("");
     //       items.append(item);
     //   }
        ((QStandardItemModel*) ui->mainTable->model())->appendColumn(items);
    }
}
