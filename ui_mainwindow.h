/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Feb 21 17:10:20 2013
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
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLabel *usdToRubLabel;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLabel *rubToByrLabel;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QLabel *usdToByrLabel;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
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
        horizontalLayout->setSpacing(0);
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


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        usdToRubLabel = new QLabel(verticalLayoutWidget);
        usdToRubLabel->setObjectName(QString::fromUtf8("usdToRubLabel"));
        usdToRubLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(usdToRubLabel);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_9->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        rubToByrLabel = new QLabel(verticalLayoutWidget);
        rubToByrLabel->setObjectName(QString::fromUtf8("rubToByrLabel"));
        rubToByrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(rubToByrLabel);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 0, -1, -1);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        usdToByrLabel = new QLabel(verticalLayoutWidget);
        usdToByrLabel->setObjectName(QString::fromUtf8("usdToByrLabel"));
        usdToByrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(usdToByrLabel);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
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
        changeMonthBtn->setText(QString());
        nextMonthBtn->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Sum:", 0, QApplication::UnicodeUTF8));
        sumLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "USD to RUB", 0, QApplication::UnicodeUTF8));
        usdToRubLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "RUB", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "RUB to BYR", 0, QApplication::UnicodeUTF8));
        rubToByrLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "BYR", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "USD to BYR", 0, QApplication::UnicodeUTF8));
        usdToByrLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "BYR", 0, QApplication::UnicodeUTF8));
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
