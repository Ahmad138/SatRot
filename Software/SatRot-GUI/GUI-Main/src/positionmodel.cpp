#include "includes/positionmodel.h"

PositionModel::PositionModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void PositionModel::populateData(const QList<QString> &satid,
                                 const QList<QString> &satname,
                                 const QList<QString> &satlatitude,
                                 const QList<QString> &satlongitude,
                                 const QList<QString> &sataltitude,
                                 const QList<QString> &azimuth,
                                 const QList<QString> &elevation,
                                 const QList<QString> &ra,
                                 const QList<QString> &dec,
                                 const QList<QString> &timestamp)
{
    tm_satid.clear();
    tm_satname.clear();
    tm_satlatitude.clear();
    tm_satlongitude.clear();
    tm_sataltitude.clear();
    tm_azimuth.clear();
    tm_elevation.clear();
    tm_ra.clear();
    tm_dec.clear();
    tm_timestamp.clear();

    tm_satid = satid;
    tm_satname = satname;
    tm_satlatitude = satlatitude;
    tm_satlongitude = satlongitude;
    tm_sataltitude = sataltitude;
    tm_azimuth = azimuth;
    tm_elevation = elevation;
    tm_ra = ra;
    tm_dec = dec;
    tm_timestamp = timestamp;

    return;
}

int PositionModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_satid.length();
}

int PositionModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 10;
}

QVariant PositionModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_satid[index.row()];
    } else if (index.column() == 1) {
        return tm_satname[index.row()];
    } else if (index.column() == 2) {
        return tm_satlatitude[index.row()];
    } else if (index.column() == 3) {
        return tm_satlongitude[index.row()];
    } else if (index.column() == 4) {
        return tm_sataltitude[index.row()];
    } else if (index.column() == 5) {
        return tm_azimuth[index.row()];
    } else if (index.column() == 6) {
        return tm_elevation[index.row()];
    } else if (index.column() == 7) {
        return tm_ra[index.row()];
    } else if (index.column() == 8) {
        return tm_dec[index.row()];
    } else if (index.column() == 9) {
        return tm_timestamp[index.row()];
    }
    return QVariant();
}

QVariant PositionModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("NORAD No");
        } else if (section == 1) {
            return QString("Satellite");
        }else if (section == 2) {
            return QString("Satellite Lat");
        }else if (section == 3) {
            return QString("Satellite Long");
        }else if (section == 4) {
            return QString("Satellite Altitude");
        }else if (section == 5) {
            return QString("Satellite Az");
        }else if (section == 6) {
            return QString("Satellite El");
        }else if (section == 7) {
            return QString("Satellite Right Ascension");
        }else if (section == 8) {
            return QString("Satellite Declination");
        }else if (section == 9) {
            return QString("Time Stamp");
        }
    }
    return QVariant();
}


void PositionModel::addItem(QString a,
                            QString b,
                            QString c,
                            QString d,
                            QString e,
                            QString f,
                            QString g,
                            QString h,
                            QString i,
                            QString j)
{
    int rw = tm_satid.length();
    QModelIndex ndx = QAbstractTableModel::createIndex(rw,0);
    //cerr << "addItem" << ", exclVec.size "<< exclVec.size() << endl;
    if (insertRows(rw,10,ndx))
    {
        setData(QAbstractTableModel::index(rw-1,0),QVariant(a));
        setData(QAbstractTableModel::index(rw-1,1),QVariant(b));
        setData(QAbstractTableModel::index(rw-1,2),QVariant(c));
        setData(QAbstractTableModel::index(rw-1,3),QVariant(d));
        setData(QAbstractTableModel::index(rw-1,4),QVariant(e));
        setData(QAbstractTableModel::index(rw-1,5),QVariant(f));
        setData(QAbstractTableModel::index(rw-1,6),QVariant(g));
        setData(QAbstractTableModel::index(rw-1,7),QVariant(h));
        setData(QAbstractTableModel::index(rw-1,8),QVariant(i));
        setData(QAbstractTableModel::index(rw-1,9),QVariant(j));
    }
}

bool PositionModel::insertRows(int row, int count, const QModelIndex & parent)
{
    bool bRet=false;
    if (parent.isValid())
    {
        // we always insert at the end...
        //cerr << "insertRows" << ", exclVec.size "<< exclVec.size() << endl;
        emit layoutAboutToBeChanged();
        beginInsertRows(parent,row,row+count-1);
        int i;
        for (i=0;i<count;i++)
        {
            //            tm_satid.push_back("");
            //            tm_satname.push_back("");
            //            tm_tle.push_back("");
        }
        //cerr << "end insertRows" << ", exclVec.size "<< exclVec.size() << endl;
        endInsertRows();
        emit layoutChanged();
        bRet=true;
    }
    return bRet;
}

void PositionModel::clearTable(){
    int rw = tm_satid.length();
    QModelIndex ndx = QAbstractTableModel::createIndex(rw,0);
    removeRows(rw, 10, ndx);
}

bool PositionModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row+count-1);
    //remove rows from underlying data
    for (int i = 0; i < count; ++i) {
        tm_satid.clear();
        tm_satname.clear();
        tm_satlatitude.clear();
        tm_satlongitude.clear();
        tm_sataltitude.clear();
        tm_azimuth.clear();
        tm_elevation.clear();
        tm_ra.clear();
        tm_dec.clear();
        tm_timestamp.clear();
    }
    endRemoveRows();
    return true;
}
