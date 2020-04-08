#ifndef POSITIONMODEL_H
#define POSITIONMODEL_H

#include <QAbstractTableModel>

class PositionModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    PositionModel(QObject *parent = 0);

    void populateData(
            const QList<QString> &satid,
            const QList<QString> &satname,
            const QList<QString> &satlatitude,
            const QList<QString> &satlongitude,
            const QList<QString> &sataltitude,
            const QList<QString> &azimuth,
            const QList<QString> &elevation,
            const QList<QString> &ra,
            const QList<QString> &dec,
            const QList<QString> &timestamp);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void addItem(QString a,
                 QString b,
                 QString c,
                 QString d,
                 QString e,
                 QString f,
                 QString g,
                 QString h,
                 QString i,
                 QString j);
    void clearTable();
    bool insertRows(int row, int count, const QModelIndex & parent);
    bool removeRows(int row, int count, const QModelIndex &parent);

private:
    QList<QString> tm_satid;
    QList<QString> tm_satname;
    QList<QString> tm_satlatitude;
    QList<QString> tm_satlongitude;    
    QList<QString> tm_sataltitude;
    QList<QString> tm_azimuth;
    QList<QString> tm_elevation;
    QList<QString> tm_ra;
    QList<QString> tm_dec;
    QList<QString> tm_timestamp;

};


#endif // POSITIONMODEL_H
