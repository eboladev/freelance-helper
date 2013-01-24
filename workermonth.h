#ifndef WORKERMONTH_H
#define WORKERMONTH_H

#include "QtCore"
#include "QDate"

class WorkerMonth
{
public:
    WorkerMonth(const QDate &date);
    quint32 getNumberOfDays();

private:
    QDate date;
};

#endif // WORKERMONTH_H
