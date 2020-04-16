#ifndef CUSTOMLISTMODEL_H
#define CUSTOMLISTMODEL_H

#include <regex>
#include <string>

#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QColor>
#include <QSet>

/**
 * @brief
 *
 */
class CustomListModel : public QStringListModel
{
public:
    /**
     * @brief
     *
     * @param parent
     */
    CustomListModel(QObject* parent = 0);
    /**
     * @brief
     *
     * @param strings
     * @param parent
     */
    CustomListModel(const QStringList& strings, QObject* parent = 0);
    /**
     * @brief
     *
     * @param index
     * @return Qt::ItemFlags
     */
    Qt::ItemFlags flags(const QModelIndex& index) const;
    /**
     * @brief
     *
     * @param index
     * @param role
     * @return QVariant
     */
    QVariant data(const QModelIndex& index, int role) const;
    /**
     * @brief
     *
     * @param index
     * @param value
     * @param role
     * @return bool
     */
    bool setData(const QModelIndex& index, const QVariant& value,
                 int role);
    /**
     * @brief
     *
     * @param section
     * @param orientation
     * @param role
     * @return QVariant
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    /**
     * @brief
     *
     */
    void save();
    /**
     * @brief
     *
     * @return QString
     */
    QString getNORAD();
    /**
     * @brief
     *
     * @return QList<QString>
     */
    QList<QString> getNORADObj();
private:
    QSet<QPersistentModelIndex> checkedItems; /**< TODO: describe */
};

#endif // CUSTOMLISTMODEL_H
