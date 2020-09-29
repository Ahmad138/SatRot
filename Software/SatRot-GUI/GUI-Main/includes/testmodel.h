#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QAbstractTableModel>

/**
 * @brief
 *
 */
class TestModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    TestModel(QObject* parent = 0);

    /**
     * @brief
     *
     * @param contactName
     * @param contactPhone
     */
    void populateData(const QList<QString>& contactName, const QList<QString>& contactPhone);

    /**
     * @brief
     *
     * @param parent
     * @return int
     */
    int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
    /**
     * @brief
     *
     * @param parent
     * @return int
     */
    int columnCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;

    /**
     * @brief
     *
     * @param index
     * @param role
     * @return QVariant
     */
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    /**
     * @brief
     *
     * @param section
     * @param orientation
     * @param role
     * @return QVariant
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> tm_contact_name; /**< TODO: describe */
    QList<QString> tm_contact_phone; /**< TODO: describe */

};

#endif // TESTMODEL_H
