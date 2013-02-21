/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created: Thu Feb 21 17:10:20 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *autoUpdate;
    QPushButton *updateCurrency;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *usdToByrLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *usdToRubLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *RubToByrLabel;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        autoUpdate = new QCheckBox(OptionsDialog);
        autoUpdate->setObjectName(QString::fromUtf8("autoUpdate"));
        autoUpdate->setGeometry(QRect(10, 120, 82, 17));
        updateCurrency = new QPushButton(OptionsDialog);
        updateCurrency->setObjectName(QString::fromUtf8("updateCurrency"));
        updateCurrency->setGeometry(QRect(250, 10, 75, 23));
        gridLayoutWidget = new QWidget(OptionsDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 222, 99));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        usdToByrLabel = new QLineEdit(gridLayoutWidget);
        usdToByrLabel->setObjectName(QString::fromUtf8("usdToByrLabel"));

        horizontalLayout->addWidget(usdToByrLabel);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        usdToRubLabel = new QLineEdit(gridLayoutWidget);
        usdToRubLabel->setObjectName(QString::fromUtf8("usdToRubLabel"));

        horizontalLayout_2->addWidget(usdToRubLabel);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        RubToByrLabel = new QLineEdit(gridLayoutWidget);
        RubToByrLabel->setObjectName(QString::fromUtf8("RubToByrLabel"));

        horizontalLayout_3->addWidget(RubToByrLabel);


        gridLayout->addLayout(horizontalLayout_3, 4, 1, 1, 1);

        buttonBox->raise();
        autoUpdate->raise();
        updateCurrency->raise();
        gridLayoutWidget->raise();
        gridLayoutWidget->raise();

        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        autoUpdate->setText(QApplication::translate("OptionsDialog", "auto update", 0, QApplication::UnicodeUTF8));
        updateCurrency->setText(QApplication::translate("OptionsDialog", "Update", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OptionsDialog", "USD to BYR", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionsDialog", "USD to RUB", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OptionsDialog", "RUB to BYR", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
