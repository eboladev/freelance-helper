#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "optionsdialog.h"
#include "currencyconverter.h"
#include "maintablemodel.h"
#include "QDate"
#include "workermonth.h"
#include "QStandardItemModel"
#include "QAbstractItemView"

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
    connect(CurrencyConverter::instance(), SIGNAL(exchangeRateUpdated(float)), this, SLOT(exchangeRateUpdate(float)));

    ui->exchangeRateLabel->setText(QString::number(CurrencyConverter::instance()->getUsdToRu()));

 //   MainTableModel  model(0);
  ////  model.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  //  model.setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
 //   model.setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
   // qDebug() << model.columnCount();
 //   ui->mainTable->setRowCount(3);
   // ui->mainTable->set
    WorkerMonth workerMonth(QDate::currentDate());
    quint32 daysInMonth = workerMonth.getNumberOfDays();
    QStandardItemModel *model = new QStandardItemModel(daysInMonth, 2, this);
    model->setHeaderData(0, Qt::Horizontal, tr("Label"));
    model->setHeaderData(1, Qt::Horizontal, tr("Quantity"));

     ui->mainTable->setModel(model);
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

void MainWindow::exchangeRateUpdate(const float rate)
{
    ui->exchangeRateLabel->setText(QString::number(rate));
}
