#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "QList"
#include <QtCore>
#include <QDate>
#include <QString>
#include <QMap>
#include "fee.h"

class Employee : public QObject
{
    Q_OBJECT
public:
    Employee();
    void setFee(const QDate &date, const int &column, const QString &fee);
    QList<Fee>* getFeesForDay(const QDate &date)  const;
    float getSum() { return sum; }
    void store();
    void load();

signals:
    void updateDay(QDate day);

private:
    bool containsFee(const QDate &date, const int &column) const;
    QMap<QDate, QList<Fee>* > dayMap;
    float sum;
};

#endif // EMPLOYEE_H
