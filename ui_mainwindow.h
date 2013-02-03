/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jan 29 16:48:20 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionPreferences;
    QAction *actionAbout;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *yearCombobox;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *previousMonthBtn;
    QPushButton *changeMonthBtn;
    QPushButton *nextMonthBtn;
    QTableView *mainTable;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLabel *sumLabel;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *exchangeRateLabel;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(605, 608);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 591, 551));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        yearCombobox = new QComboBox(verticalLayoutWidget);
        yearCombobox->setObjectName(QString::fromUtf8("yearCombobox"));
        yearCombobox->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(yearCombobox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        previousMonthBtn = new QPushButton(verticalLayoutWidget);
        previousMonthBtn->setObjectName(QString::fromUtf8("previousMonthBtn"));
        previousMonthBtn->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(previousMonthBtn);

        changeMonthBtn = new QPushButton(verticalLayoutWidget);
        changeMonthBtn->setObjectName(QString::fromUtf8("changeMonthBtn"));
        changeMonthBtn->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(changeMonthBtn);

        nextMonthBtn = new QPushButton(verticalLayoutWidget);
        nextMonthBtn->setObjectName(QString::fromUtf8("nextMonthBtn"));
        nextMonthBtn->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(nextMonthBtn);


        verticalLayout->addLayout(horizontalLayout);

        mainTable = new QTableView(verticalLayoutWidget);
        mainTable->setObjectName(QString::fromUtf8("mainTable"));
        mainTable->setMaximumSize(QSize(700, 400));
        mainTable->setGridStyle(Qt::SolidLine);

        verticalLayout->addWidget(mainTable);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 10, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(16);
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        sumLabel = new QLabel(verticalLayoutWidget);
        sumLabel->setObjectName(QString::fromUtf8("sumLabel"));
        sumLabel->setMinimumSize(QSize(30, 0));
        sumLabel->setFont(font);

        horizontalLayout_4->addWidget(sumLabel);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        exchangeRateLabel = new QLabel(verticalLayoutWidget);
        exchangeRateLabel->setObjectName(QString::fromUtf8("exchangeRateLabel"));
        exchangeRateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(exchangeRateLabel);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        verticalLayoutWidget->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 605, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuAbout->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionExit);
        menuOptions->addAction(actionPreferences);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FreelanceHelper", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        yearCombobox->clear();
        yearCombobox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Month view", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Statistics view", 0, QApplication::UnicodeUTF8)
        );
        previousMonthBtn->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        changeMonthBtn->setText(QApplication::translate("MainWindow", "January 2013", 0, QApplication::UnicodeUTF8));
        nextMonthBtn->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Sum:", 0, QApplication::UnicodeUTF8));
        sumLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Exchange rate:", 0, QApplication::UnicodeUTF8));
        exchangeRateLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", " RUB", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
