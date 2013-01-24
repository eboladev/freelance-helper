#include "workermonth.h"

WorkerMonth::WorkerMonth(const QDate &date)
{
    this->date = date;
}

quint32 WorkerMonth::getNumberOfDays()
{
   return date.daysInMonth();
}

