#ifndef RADIOPASSMODEL_H
#define RADIOPASSMODEL_H

#include <QAbstractTableModel>

/**
 * @brief
 *
 */
class RadioPassModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    RadioPassModel(QObject* parent = 0);

    /**
     * @brief
     *
     * @param satid
     * @param satname
     * @param passescount
     * @param startUTC
     * @param startAz
     * @param maxUTC
     * @param maxAz
     * @param maxEl
     * @param endAz
     * @param endUTC
     * @param startAzCompass
     * @param maxAzCompass
     * @param endAzCompass
     */
    void populateData(
        const QList<QString>& satid,
        const QList<QString>& satname,
        const QList<QString>& passescount,
        const QList<QString>& startUTC,
        const QList<QString>& startAz,
        const QList<QString>& maxUTC,
        const QList<QString>& maxAz,
        const QList<QString>& maxEl,
        const QList<QString>& endAz,
        const QList<QString>& endUTC,
        const QList<QString>& startAzCompass,
        const QList<QString>& maxAzCompass,
        const QList<QString>& endAzCompass
    );

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
     * @param d
     * @param e
     * @param f
     * @param g
     * @param h
     * @param i
     * @param j
     * @param k
     * @param l
     * @param m
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
                 QString j,
                 QString k,
                 QString l,
                 QString m);
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
    QList<QString> tm_passescount; /**< TODO: describe */
    QList<QString> tm_startUTC; /**< TODO: describe */
    QList<QString> tm_startAz; /**< TODO: describe */
    QList<QString> tm_maxUTC; /**< TODO: describe */
    QList<QString> tm_maxAz; /**< TODO: describe */
    QList<QString> tm_maxEl; /**< TODO: describe */
    QList<QString> tm_endAz; /**< TODO: describe */
    QList<QString> tm_endUTC; /**< TODO: describe */
    QList<QString> tm_startAzCompass; /**< TODO: describe */
    QList<QString> tm_maxAzCompass; /**< TODO: describe */
    QList<QString> tm_endAzCompass; /**< TODO: describe */

};


#endif // RADIOPASSMODEL_H
