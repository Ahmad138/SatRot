#include "../includes/customlistmodel.h"

CustomListModel::CustomListModel(QObject* parent):
    QStringListModel(parent)
{
}

Qt::ItemFlags CustomListModel::flags(const QModelIndex& index) const
{
    Qt::ItemFlags defaultFlags = QStringListModel::flags(index);
    if (index.isValid())
    {
        return defaultFlags | Qt::ItemIsUserCheckable;
    }
    return defaultFlags;
}

QVariant CustomListModel::data(const QModelIndex& index,
                               int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::CheckStateRole)
        return checkedItems.contains(index) ?
               Qt::Checked : Qt::Unchecked;

    else if (role == Qt::BackgroundColorRole)
        return checkedItems.contains(index) ?
               QColor("#ffffb2") : QColor("#ffffff");

    return QStringListModel::data(index, role);
}

bool CustomListModel::setData(const QModelIndex& index,
                              const QVariant& value, int role)
{

    if (!index.isValid() || role != Qt::CheckStateRole)
        return false;

    if (value == Qt::Checked)
        checkedItems.insert(index);
    else
        checkedItems.remove(index);

    emit dataChanged(index, index);
    return true;
}

QVariant CustomListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section == 0)
        {
            return QString("NORAD ID");
        }
        else if (section == 1)
        {
            return QString("Satellite Name");
        }
    }
    return QVariant();
}

void CustomListModel::save()
{
    QFile file("Satellites.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "Satellite Lists:" << "\n";
    foreach (QPersistentModelIndex index, checkedItems)
    {
        QString s = index.data().toString();
        const std::string z = s.toStdString();

        unsigned first = z.find("[");
        unsigned last = z.find("]");
        const std::string str = z.substr(first + 1, (last - 1) - first);

        QString strNew = QString::fromStdString(str);
        out << strNew << "\n";

    }

}

QString CustomListModel::getNORAD()
{

    QString all = "";

    foreach (QPersistentModelIndex index, checkedItems)
    {
        QString s = index.data().toString();
        if (s != "Satellite Name - NORAD Id" && s != "------------------------------------")
        {
            const std::string z = s.toStdString();

            unsigned first = z.find("[");
            unsigned last = z.find("]");
            const std::string str = z.substr(first + 1, (last - 1) - first);

            QString strNew = QString::fromStdString(str);
            all += strNew + ",";
        }
    }

    //remove last ',' in the QString
    const std::string y = all.toStdString();
    if (y.back() == ',')
    {
        const std::string w = y.substr(0, y.size() - 1);
        all = QString::fromStdString(w);
    }

    return all;
}

QList<QString> CustomListModel::getNORADObj()
{

    QList<QString> all;

    foreach (QPersistentModelIndex index, checkedItems)
    {
        QString s = index.data().toString();
        if (s != "Satellite Name - NORAD Id" && s != "------------------------------------")
        {
            const std::string z = s.toStdString();

            unsigned first = z.find("[");
            unsigned last = z.find("]");
            const std::string str = z.substr(first + 1, (last - 1) - first);

            QString strNew = QString::fromStdString(str);
            all.append(strNew);
        }
    }

    return all;
}
