#include <QtGui/QApplication>
#include "mainwindow.h"
#include "settings.h"
#include "uniqueapp.h"
#ifdef QT_DEBUG
#include <QtCore/QDebug>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // set app attributes
    a.setApplicationName("FreelanceHelper");
    a.setOrganizationName("ncuxer");


    if (!UniqueApplication::checkUniqueuness()) {
#ifdef QT_DEBUG
        qDebug() << "Another application instance is already running";
#endif
        return EXIT_FAILURE;
    }

    MainWindow w;
    w.show();
    
    return a.exec();
}
