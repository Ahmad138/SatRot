#include "../includes/testmodel.h"

TestModel::TestModel(QObject* parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void TestModel::populateData(const QList<QString>& contactName, const QList<QString>& contactPhone)
{
    tm_contact_name.clear();
    tm_contact_name = contactName;
    tm_contact_phone.clear();
    tm_contact_phone = contactPhone;
    return;
}

int TestModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return tm_contact_name.length();
}

int TestModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant TestModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if (index.column() == 0)
    {
        return tm_contact_name[index.row()];
    }
    else if (index.column() == 1)
    {
        return tm_contact_phone[index.row()];
    }
    return QVariant();
}

QVariant TestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section == 0)
        {
            return QString("View");
        }
        else if (section == 1)
        {
            return QString("Id");
        }
        else if (section == 2)
        {
            return QString("Satellite Name");
        }
    }
    return QVariant();
}
