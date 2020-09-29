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

class CustomDialog : public QDialog
{
public:
    CustomDialog(const QStringList& items);

    QComboBox* comboBox() { return box; }

private:
    QComboBox* box;
};

#endif // CUSTOMDIALOG_H
