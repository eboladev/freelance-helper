#include "workerday.h"

WorkerDay::WorkerDay(const QDate &date)
{
    this->date = date;
}

quint32 WorkerDay::getNumberOfDays()
{
    return date.daysInMonth();
}

void WorkerDay::addFee(const QString &fee)
{
    feesList.append(fee);
}

QList<QString> WorkerDay::getFeeList()
{
    return feesList;
}

