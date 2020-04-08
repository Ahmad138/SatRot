#include "includes/visualpassmodel.h"

VisualPassModel::VisualPassModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void VisualPassModel::populateData(const QList<QString> &satid,
                                   const QList<QString> &satname,
                                   const QList<QString> &passescount,
                                   const QList<QString> &startUTC,
                                   const QList<QString> &startAz,
                                   const QList<QString> &startEl,
                                   const QList<QString> &maxUTC,
                                   const QList<QString> &maxAz,
                                   const QList<QString> &maxEl,
                                   const QList<QString> &endUTC,
                                   const QList<QString> &endAz,
                                   const QList<QString> &endEl,
                                   const QList<QString> &startAzCompass,
                                   const QList<QString> &maxAzCompass,
                                   const QList<QString> &endAzCompass,
                                   const QList<QString> &mag,
                                   const QList<QString> &duration)
{
    tm_satid.clear();
    tm_satname.clear();
    tm_passescount.clear();
    tm_startUTC.clear();
    tm_startAz.clear();
    tm_startEl.clear();
    tm_maxUTC.clear();
    tm_maxAz.clear();
    tm_maxEl.clear();
    tm_endUTC.clear();
    tm_endAz.clear();
    tm_endEl.clear();
    tm_startAzCompass.clear();
    tm_maxAzCompass.clear();
    tm_endAzCompass.clear();
    tm_mag.clear();
    tm_duration.clear();

    tm_satid = satid;
    tm_satname = satname;
    tm_passescount = passescount;
    tm_startUTC = startUTC;
    tm_startAz = startAz;
    tm_startEl = startEl;
    tm_maxUTC = maxUTC;
    tm_maxAz = maxAz;
    tm_maxEl = maxEl;
    tm_endUTC = endUTC;
    tm_endAz = endAz;
    tm_endEl = endEl;
    tm_startAzCompass = startAzCompass;
    tm_maxAzCompass = maxAzCompass;
    tm_endAzCompass = endAzCompass;
    tm_mag = mag;
    tm_duration = duration;

    return;
}

int VisualPassModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_satid.length();
}

int VisualPassModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 17;
}

QVariant VisualPassModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_satid[index.row()];
    }else if (index.column() == 1) {
        return tm_satname[index.row()];
    }else if (index.column() == 2) {
        return tm_passescount[index.row()];
    }else if (index.column() == 3) {
        return tm_startUTC[index.row()];
    }else if (index.column() == 4) {
        return tm_startAz[index.row()];
    }else if (index.column() == 5) {
        return tm_startEl[index.row()];
    }else if (index.column() == 6) {
        return tm_maxUTC[index.row()];
    }else if (index.column() == 7) {
        return tm_maxAz[index.row()];
    }else if (index.column() == 8) {
        return tm_maxEl[index.row()];
    }else if (index.column() == 9) {
        return tm_endUTC[index.row()];
    }else if (index.column() == 10) {
        return tm_endAz[index.row()];
    }else if (index.column() == 11) {
        return tm_endEl[index.row()];
    }else if (index.column() == 12) {
        return tm_startAzCompass[index.row()];
    }else if (index.column() == 13) {
        return tm_maxAzCompass[index.row()];
    }else if (index.column() == 14) {
        return tm_endAzCompass[index.row()];
    }else if (index.column() == 15) {
        return tm_mag[index.row()];
    }else if (index.column() == 16) {
        return tm_duration[index.row()];
    }
    return QVariant();
}

QVariant VisualPassModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("NORAD");
        } else if (section == 1) {
            return QString("Satellite");
        }else if (section == 2) {
            return QString("Pass Count");
        }else if (section == 3) {
            return QString("Start UTC");
        }else if (section == 4) {
            return QString("Start Az");
        }else if (section == 5) {
            return QString("Start El");
        }else if (section == 6) {
            return QString("Max UTC");
        }else if (section == 7) {
            return QString("Max Az");
        }else if (section == 8) {
            return QString("Max El");
        }else if (section == 9) {
            return QString("End UTC");
        }else if (section == 10) {
            return QString("End Az");
        }else if (section == 11) {
            return QString("End El");
        }else if (section == 12) {
            return QString("Start Az Compass");
        }else if (section == 13) {
            return QString("Max Az Compass");
        }else if (section == 14) {
            return QString("End Az Compass");
        }else if (section == 15) {
            return QString("Max Visual Magnitude");
        }else if (section == 16) {
            return QString("Duration (seconds)");
        }
    }
    return QVariant();
}

void VisualPassModel::addItem(QString a,
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
                              QString m,
                              QString n,
                              QString p,
                              QString q,
                              QString r)
{
    int rw = tm_satid.length();
    QModelIndex ndx = QAbstractTableModel::createIndex(rw,0);
    //cerr << "addItem" << ", exclVec.size "<< exclVec.size() << endl;
    if (insertRows(rw,17,ndx))
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
        setData(QAbstractTableModel::index(rw-1,10),QVariant(k));
        setData(QAbstractTableModel::index(rw-1,11),QVariant(l));
        setData(QAbstractTableModel::index(rw-1,12),QVariant(m));
        setData(QAbstractTableModel::index(rw-1,13),QVariant(n));
        setData(QAbstractTableModel::index(rw-1,14),QVariant(p));
        setData(QAbstractTableModel::index(rw-1,15),QVariant(q));
        setData(QAbstractTableModel::index(rw-1,16),QVariant(r));
    }
}

bool VisualPassModel::insertRows(int row, int count, const QModelIndex & parent)
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

void VisualPassModel::clearTable(){
    int rw = tm_satid.length();
    QModelIndex ndx = QAbstractTableModel::createIndex(rw,0);
    removeRows(rw, 17, ndx);
}

bool VisualPassModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row+count-1);
    //remove rows from underlying data
    for (int i = 0; i < count; ++i) {
        tm_satid.clear();
        tm_satname.clear();
        tm_passescount.clear();
        tm_startUTC.clear();
        tm_startAz.clear();
        tm_startEl.clear();
        tm_maxUTC.clear();
        tm_maxAz.clear();
        tm_maxEl.clear();
        tm_endUTC.clear();
        tm_endAz.clear();
        tm_endEl.clear();
        tm_startAzCompass.clear();
        tm_maxAzCompass.clear();
        tm_endAzCompass.clear();
        tm_mag.clear();
        tm_duration.clear();
    }
    endRemoveRows();
    return true;
}
