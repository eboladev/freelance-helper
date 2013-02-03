#include "employee.h"

Employee::Employee()
{
    sum = 0;
}

bool Employee::containsFee(const QDate &date, const int &column)  const
{
    if(dayMap.contains(date))
    {
        QSharedPointer<QList<Fee> > list = dayMap.value(date);
        if(false == list.isNull() && column < list->size())
        {
            return true;
        }
    }
    return false;
}

void Employee::setFee(const QDate &date, const int &column, const QString &feeString)
{
    Fee fee(feeString);
    if(containsFee(date, column))
    {
        QSharedPointer<QList<Fee> > list = dayMap.value(date);
        if(false == fee.getString().isEmpty())
        {
            sum = sum - list->at(column).getAmountAsUsd();
            list->replace(column, fee);
            sum = sum + fee.getAmountAsUsd();
        } else
        {
            //calc sum
            sum = sum - list->at(column).getAmountAsUsd();

            list->removeAt(column);
        }
        emit updateDay(date);
    }
    else
    {
        QSharedPointer<QList<Fee> > list = dayMap.value(date);
        if(list.isNull())
        {
           list = QSharedPointer<QList<Fee> >(new QList<Fee>);
           dayMap.insert(date, list);
        }
        list->append(fee);
        sum = sum + fee.getAmountAsUsd();

        emit updateDay(date);
    }

}

QSharedPointer<QList<Fee> > Employee::getFeesForDay(const QDate &date)  const
{
        return dayMap.value(date);
}

