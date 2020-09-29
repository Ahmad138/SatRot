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
 * This class creates a custom list that has checkboxes on each list item.
 * This permits the selection/deselection of items from the list view. This is used to select
 * satellites to track all at once
 *
 * @author: Ahmad Muhammad (https://github.com/Ahmad138)
 */
class CustomListModel : public QStringListModel
{
public:
    /**
     * @brief
     *The constructor class that takes in the parent from the main window class
     * @param parent -> takes the main class QObject
     */
    CustomListModel(QObject* parent = 0);

    /**
     * @brief
     *This class overrides the default method for flags. it converts it into a user
     * checkable flag.
     *
     * @param index -> takes in the index of the model that requires the changes.
     * @return Qt::ItemFlags -> returns the newly changes flags
     */
    Qt::ItemFlags flags(const QModelIndex& index) const Q_DECL_OVERRIDE;

    /**
     * @brief
     *This method also overrides the default data method.
     * It toggles the check state of the list items, changes the colors based on the check state.
     *
     * @param index -> takes in the model index as an input parameter
     * @param role -> this is the role of the item
     * @return QVariant -> returns the QVariant
     */
    QVariant data(const QModelIndex& index, int role) const Q_DECL_OVERRIDE;

    /**
     * @brief
     * This method sets the data of the item to checked or unchecked
     *
     * @param index -> takes in the model index as an input parameter
     * @param value -> current value of the item
     * @param role -> the role of the item
     * @return bool -> returns false if inavlid and true if valid after changing the states of the item
     */
    bool setData(const QModelIndex& index, const QVariant& value,
                 int role) Q_DECL_OVERRIDE;
    /**
     * @brief
     *This sets the header information of the table model.
     *
     * @param section -> section of the table, that is, columns
     * @param orientation -> the orientation, either horizontal or vertical (in our case, horizontal)
     * @param role -> the role of the item
     * @return QVariant -> returns a QVariant type.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    /**
     * @brief
     *You have the option of saving the list to a file Satellites.txt and save for later use.
     */
    void save();

    /**
     * @brief
     *This method strips the items selected and gets the NORAD numbers only to be used to construct the enpoint
     * for the api request.
     *
     * @return QString -> returns the NORAD numbers appended together by "," e.g 1233,34535,5363
     */
    QString getNORAD();

    /**
     * @brief
     *This gets the checked items (satellites) from the list and returns it as a QList
     * @return QList<QString>
     */
    QList<QString> getNORADObj();
private:
    QSet<QPersistentModelIndex> checkedItems; /**< TODO: describe */
};

#endif // CUSTOMLISTMODEL_H
