#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "workerday.h"
#include "QList"
#include <QtCore>
#include <QDate>
#include <QString>
#include <QMap>
#include "fee.h"

class Employee : public QObject
{
    Q_OBJECT
public:
    Employee();
    bool containsFee(const QDate &date, const int &column);
    void setFee(const QDate &date, const int &column, const QString &fee);
    QList<Fee>* getFeesForDay(const QDate &date);
    qint32 getMaxLength();

signals:
    void feeListReload();
    void maxLengthChanged(quint32);

private:
    QMap<QDate, QList<Fee>* > dayMap;
    int maxLength;
};

#endif // EMPLOYEE_H
