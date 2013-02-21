#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "QList"
#include <QtCore>
#include <QDate>
#include <QString>
#include <QMap>
#include "money.h"

class Employee : public QObject
{
    Q_OBJECT
public:
    Employee();
    void setFee(const QDate &date, const int &column, const QString &fee);
    QList<Money>* getFeesForDay(const QDate &date)  const;
    Money getSum() { return sum; }
    void store();
    void load();

signals:
    void updateDay(QDate day);

private:
    bool containsFee(const QDate &date, const int &column) const;
    QMap<QDate, QList<Money>* > dayMap;
    Money sum;
};

#endif // EMPLOYEE_H
