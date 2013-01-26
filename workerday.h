#ifndef WORKERDAY_H
#define WORKERDAY_H

#include "QtCore"
#include "QDate"
#include "QList"

class WorkerDay
{
public:
    WorkerDay(const QDate &date);
    quint32 getNumberOfDays();
    void addFee(const QString &fee);
    QList<QString> getFeeList();

private:
    QDate date;
    QList<QString> feesList;
};

#endif // WORKERDAY_H
