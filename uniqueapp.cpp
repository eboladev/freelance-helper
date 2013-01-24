#include "uniqueapp.h"

#include <QCoreApplication>
#include <QSharedMemory>


bool UniqueApplication::checkUniqueuness()
{
    bool isSingle = false;
    static QSharedMemory lock("SingleAppLock" + qApp->applicationName());
    if (lock.attach(QSharedMemory::ReadOnly)) {
        lock.detach();
    }
    if (lock.create(1))
        isSingle = true;
    return isSingle;
}
