#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "QList"
#include <QtCore>
#include <QDate>
#include <QString>
#include <QMap>
#include "fee.h"
#include "QSharedPointer"

class Employee : public QObject
{
    Q_OBJECT
public:
    Employee();
    bool containsFee(const QDate &date, const int &column) const;
    void setFee(const QDate &date, const int &column, const QString &fee);
    QSharedPointer<QList<Fee> > getFeesForDay(const QDate &date)  const;
    float getSum() { return sum; }

signals:
    void updateDay(QDate day);

private:
    QMap<QDate, QSharedPointer<QList<Fee> > > dayMap;
    float sum;
};

#endif // EMPLOYEE_H
