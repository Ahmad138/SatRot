#include "../includes/tlemodel.h"

TLEModel::TLEModel(QObject* parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void TLEModel::populateData(const QList<QString>& satid,
                            const QList<QString>& satname,
                            const QList<QString>& tle)
{
    tm_satid.clear();
    tm_satname.clear();
    tm_tle.clear();

    tm_satid = satid;
    tm_satname = satname;
    tm_tle = tle;

    return;
}

int TLEModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return tm_satid.length();
}

int TLEModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant TLEModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if (index.column() == 0)
    {
        return tm_satid[index.row()];
    }
    else if (index.column() == 1)
    {
        return tm_satname[index.row()];
    }
    else if (index.column() == 2)
    {
        return tm_tle[index.row()];
    }
    return QVariant();
}

QVariant TLEModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section == 0)
        {
            return QString("NORAD No");
        }
        else if (section == 1)
        {
            return QString("Satellite");
        }
        else if (section == 2)
        {
            return QString("TLE");
        }
    }
    return QVariant();
}

void TLEModel::addItem(QString a, QString b, QString c)
{
    int rw = tm_satid.length();
    QModelIndex ndx = QAbstractTableModel::createIndex(rw, 0);
    //cerr << "addItem" << ", exclVec.size "<< exclVec.size() << endl;
    if (insertRows(rw, 3, ndx))
    {
        setData(QAbstractTableModel::index(rw - 1, 0), QVariant(a));
        setData(QAbstractTableModel::index(rw - 1, 1), QVariant(b));
        setData(QAbstractTableModel::index(rw - 1, 2), QVariant(c));
    }
}

bool TLEModel::insertRows(int row, int count, const QModelIndex& parent)
{
    bool bRet = false;
    if (parent.isValid())
    {
        // we always insert at the end...
        //cerr << "insertRows" << ", exclVec.size "<< exclVec.size() << endl;
        emit layoutAboutToBeChanged();
        beginInsertRows(parent, row, row + count - 1);
        int i;
        for (i = 0; i < count; i++)
        {
//            tm_satid.push_back("");
//            tm_satname.push_back("");
//            tm_tle.push_back("");
        }
        //cerr << "end insertRows" << ", exclVec.size "<< exclVec.size() << endl;
        endInsertRows();
        emit layoutChanged();
        bRet = true;
    }
    return bRet;
}

void TLEModel::clearTable()
{
    int rw = tm_satid.length();
    QModelIndex ndx = QAbstractTableModel::createIndex(rw, 0);
    removeRows(rw, 3, ndx);
}

bool TLEModel::removeRows(int row, int count, const QModelIndex& parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    //remove rows from underlying data
    for (int i = 0; i < count; ++i)
    {
        tm_satid.clear();
        tm_satname.clear();
        tm_tle.clear();
    }
    endRemoveRows();
    return true;
}
