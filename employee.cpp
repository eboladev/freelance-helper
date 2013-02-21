#include "employee.h"

Employee::Employee()
{
}

bool Employee::containsFee(const QDate &date, const int &column)  const
{
    if(dayMap.contains(date))
    {
        QList<Money>* list = dayMap.value(date);
        if(column < list->size())
        {
            return true;
        }
    }
    return false;
}

void Employee::setFee(const QDate &date, const int &column, const QString &feeString)
{
    Money fee(feeString);
    if(containsFee(date, column))
    {
        QList<Money>* list = dayMap.value(date);
        if(false == fee.getString().isEmpty())
        {
             sum.sub(list->at(column)).add(fee);
            list->replace(column, fee);
        } else
        {
            sum.sub(list->at(column));
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

        QList<Money>* list = dayMap.value(date);
        if(list == 0)
        {
            list = new QList<Money>;
            dayMap.insert(date, list);
        }
        list->append(fee);
        sum.add(fee);

        emit updateDay(date);
    }

}

QList<Money>* Employee::getFeesForDay(const QDate &date)  const
{
    return dayMap.value(date);
}

void Employee::store()
{

}

void Employee::load()
{
}

