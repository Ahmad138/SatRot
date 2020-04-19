#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QComboBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QGuiApplication>
#include <QGroupBox>

/**
 * @brief
 *This is a custom dialog box class that extends the QDialog class
 * used for the connection to server by a client socket.
 * just shows simple input field, and connect/cancel buttons. This creates a focused, interractive
 * user experience.
 *
 * @author: Ahmad Muhammad (https://github.com/Ahmad138)
 */
class CustomDialog : public QDialog
{
public:
    /**
     * @brief
     * The constructor takes in the the list of items to be put in the combo box
     * @param items -> a QStringList pointer to the list of items to put in the combo box
     */
    CustomDialog(const QStringList& items);

    /**
     * @brief
     *Creates a simple QComboBox instance to be used
     * @return QComboBox
     */
    QComboBox* comboBox() { return box; }

private:
    QComboBox* box; /**< TODO: describe */
};

#endif // CUSTOMDIALOG_H
