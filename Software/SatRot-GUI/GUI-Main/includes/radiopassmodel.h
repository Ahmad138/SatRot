#ifndef RADIOPASSMODEL_H
#define RADIOPASSMODEL_H

#include <QAbstractTableModel>

class RadioPassModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    RadioPassModel(QObject *parent = 0);

    void populateData(
            const QList<QString> &satid,
            const QList<QString> &satname,
            const QList<QString> &passescount,
            const QList<QString> &startUTC,
            const QList<QString> &startAz,
            const QList<QString> &maxUTC,
            const QList<QString> &maxAz,
            const QList<QString> &maxEl,
            const QList<QString> &endAz,
            const QList<QString> &endUTC,
            const QList<QString> &startAzCompass,
            const QList<QString> &maxAzCompass,
            const QList<QString> &endAzCompass
            );

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
                 QString j,
                 QString k,
                 QString l,
                 QString m);
    void clearTable();
    bool insertRows(int row, int count, const QModelIndex & parent);
    bool removeRows(int row, int count, const QModelIndex &parent);

private:
    QList<QString> tm_satid;
    QList<QString> tm_satname;
    QList<QString> tm_passescount;
    QList<QString> tm_startUTC;
    QList<QString> tm_startAz;
    QList<QString> tm_maxUTC;
    QList<QString> tm_maxAz;
    QList<QString> tm_maxEl;
    QList<QString> tm_endAz;
    QList<QString> tm_endUTC;
    QList<QString> tm_startAzCompass;
    QList<QString> tm_maxAzCompass;
    QList<QString> tm_endAzCompass;

};


#endif // RADIOPASSMODEL_H
