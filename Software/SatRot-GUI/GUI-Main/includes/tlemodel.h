#ifndef TLEMODEL_H
#define TLEMODEL_H

#include <QAbstractTableModel>

/**
 * @brief
 *
 */
class TLEModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    TLEModel(QObject* parent = 0);

    /**
     * @brief
     *
     * @param satid
     * @param satname
     * @param tle
     */
    void populateData(const QList<QString>& satid,
                      const QList<QString>& satname,
                      const QList<QString>& tle);

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

    /**
     * @brief
     *
     * @param a
     * @param b
     * @param c
     */
    void addItem(QString a, QString b, QString c);
    /**
     * @brief
     *
     */
    void clearTable();
    /**
     * @brief
     *
     * @param row
     * @param count
     * @param parent
     * @return bool
     */
    bool insertRows(int row, int count, const QModelIndex& parent);
    /**
     * @brief
     *
     * @param row
     * @param count
     * @param parent
     * @return bool
     */
    bool removeRows(int row, int count, const QModelIndex& parent);

private:
    QList<QString> tm_satid; /**< TODO: describe */
    QList<QString> tm_satname; /**< TODO: describe */
    QList<QString> tm_tle; /**< TODO: describe */

};


#endif // TLEMODEL_H
