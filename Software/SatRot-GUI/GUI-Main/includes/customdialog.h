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
 *
 */
class CustomDialog : public QDialog
{
public:
    /**
     * @brief
     *
     * @param items
     */
    CustomDialog(const QStringList& items);

    /**
     * @brief
     *
     * @return QComboBox
     */
    QComboBox* comboBox() { return box; }

private:
    QComboBox* box; /**< TODO: describe */
};

#endif // CUSTOMDIALOG_H
