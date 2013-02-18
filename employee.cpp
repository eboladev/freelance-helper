#include "employee.h"

Employee::Employee()
{
    sum = 0;
}

bool Employee::containsFee(const QDate &date, const int &column)  const
{
    if(dayMap.contains(date))
    {
        QList<Fee>* list = dayMap.value(date);
        if(column < list->size())
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
        QList<Fee>* list = dayMap.value(date);
        if(false == fee.getString().isEmpty())
        {
            sum = sum - list->at(column).getAmountAsUsd() + fee.getAmountAsUsd();
            list->replace(column, fee);
        } else
        {
            sum = sum - list->at(column).getAmountAsUsd();
            list->removeAt(column);
            if(list->isEmpty())
            {
                delete list;
                dayMap.remove(date);
            }
        }
        emit updateDay(date);
    }
    else
    {
        if(fee.getString().isEmpty())
        {
            emit updateDay(date);
            return;
        }

        QList<Fee>* list = dayMap.value(date);
        if(list == 0)
        {
            list = new QList<Fee>;
            dayMap.insert(date, list);
        }
        list->append(fee);
        sum = sum + fee.getAmountAsUsd();

        emit updateDay(date);
    }

}

QList<Fee>* Employee::getFeesForDay(const QDate &date)  const
{
    return dayMap.value(date);
}

void Employee::store()
{

}

void Employee::load()
{
}

