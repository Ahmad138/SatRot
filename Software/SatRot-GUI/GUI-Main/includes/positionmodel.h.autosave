#ifndef POSITIONMODEL_H
#define POSITIONMODEL_H

#include <QAbstractTableModel>

/**
 * @brief
 *
 */
class PositionModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    PositionModel(QObject* parent = 0);

    /**
     * @brief
     *
     * @param satid
     * @param satname
     * @param satlatitude
     * @param satlongitude
     * @param sataltitude
     * @param azimuth
     * @param elevation
     * @param ra
     * @param dec
     * @param timestamp
     */
    void populateData(
        const QList<QString>& satid,
        const QList<QString>& satname,
        const QList<QString>& satlatitude,
        const QList<QString>& satlongitude,
        const QList<QString>& sataltitude,
        const QList<QString>& azimuth,
        const QList<QString>& elevation,
        const QList<QString>& ra,
        const QList<QString>& dec,
        const QList<QString>& timestamp);

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
     *Each parameter is a section of the table to be filled
     * @param a
     * @param b
     * @param c
     * @param d
     * @param e
     * @param f
     * @param g
     * @param h
     * @param i
     * @param j
     */
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
    QList<QString> tm_satlatitude; /**< TODO: describe */
    QList<QString> tm_satlongitude;     /**< TODO: describe */
    QList<QString> tm_sataltitude; /**< TODO: describe */
    QList<QString> tm_azimuth; /**< TODO: describe */
    QList<QString> tm_elevation; /**< TODO: describe */
    QList<QString> tm_ra; /**< TODO: describe */
    QList<QString> tm_dec; /**< TODO: describe */
    QList<QString> tm_timestamp; /**< TODO: describe */

};


#endif // POSITIONMODEL_H
