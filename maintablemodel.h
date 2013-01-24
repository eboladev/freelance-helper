#ifndef MAINTABLEMODEL_H
#define MAINTABLEMODEL_H

#include <QAbstractTableModel>

class MainTableModel : public QAbstractTableModel 
{
    Q_OBJECT
public:
    MainTableModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};
#endif // MAINTABLEMODEL_H
