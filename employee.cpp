#include "employee.h"

Employee::Employee()
{
    maxLength = 0;
}

bool Employee::containsFee(const QDate &date, const int &column)
{
    if(dayMap.contains(date))
    {
        QList<Fee> *list = dayMap.value(date);
        if( column < list->size())
        {
            return true;
        }
    }
    return false;
}

void Employee::setFee(const QDate &date, const int &column, const QString &feeString)
{
    Fee fee(feeString);
    if(dayMap.contains(date))
    {
        QList<Fee> *list = dayMap.value(date);
        // TODO if fee is empty
        // if <  than delete one list item and change maxsize!! else nothing to do
        if(column < list->size())
        {
            if(feeString.trimmed() == "")
            {
                // while changing maxlength we must check all other ddays for maxsize in this month
                // if there is row with same columns - just reload list for row
                list->removeAt(column);
                emit feeListReload();
                return;
            }
            else
            {

            }

            list->replace(column, fee);
        }
        else
        {
            // while changing maxlength we must check all other ddays for maxsize in this month

            list->append(fee);
            if(list->size() > maxLength)
            {
                maxLength = list->size();
                emit maxLengthChanged(maxLength);
            }
        }
    }
    else
    {
        // TODO if fee is empty return
        QList<Fee> *list = new QList<Fee>();
        list->append(fee);
        if(list->size() > maxLength)
        {
            maxLength = list->size();
            emit maxLengthChanged(maxLength);
        }
        dayMap.insert(date, list);
    }
}

QList<Fee>* Employee::getFeesForDay(const QDate &date)
{
    if(dayMap.contains(date))
    {
        return dayMap.value(date);
    }
    else
    {
        QList<Fee> *list = new QList<Fee>();
        return list;
        if(maxLength == 0)
        {
            maxLength++;
        }
    }
}

qint32 Employee::getMaxLength()
{
    return maxLength;
}
