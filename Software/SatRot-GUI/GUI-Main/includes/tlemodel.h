#ifndef TLEMODEL_H
#define TLEMODEL_H

#include <QAbstractTableModel>

class TLEModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TLEModel(QObject *parent = 0);

    void populateData(const QList<QString> &satid,
                      const QList<QString> &satname,
                      const QList<QString> &tle);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void addItem(QString a, QString b, QString c);
    void clearTable();
    bool insertRows(int row, int count, const QModelIndex & parent);
    bool removeRows(int row, int count, const QModelIndex &parent);

private:
    QList<QString> tm_satid;
    QList<QString> tm_satname;
    QList<QString> tm_tle;

};


#endif // TLEMODEL_H
