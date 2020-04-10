/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SatRot-GUI/GUI-Main/includes/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[54];
    char stringdata0[714];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "valueChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(4, 58, 5), // "value"
QT_MOC_LITERAL(5, 64, 30), // "on_verticalSlider_valueChanged"
QT_MOC_LITERAL(6, 95, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 117, 21), // "on_getSatData_clicked"
QT_MOC_LITERAL(8, 139, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(9, 159, 7), // "checked"
QT_MOC_LITERAL(10, 167, 8), // "showTime"
QT_MOC_LITERAL(11, 176, 7), // "webView"
QT_MOC_LITERAL(12, 184, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(13, 208, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(14, 232, 7), // "getCZML"
QT_MOC_LITERAL(15, 240, 8), // "endpoint"
QT_MOC_LITERAL(16, 249, 13), // "getSatDetails"
QT_MOC_LITERAL(17, 263, 14), // "QList<QString>"
QT_MOC_LITERAL(18, 278, 9), // "getSatPos"
QT_MOC_LITERAL(19, 288, 13), // "getSatVisPass"
QT_MOC_LITERAL(20, 302, 13), // "getSatRadPass"
QT_MOC_LITERAL(21, 316, 9), // "getSatTLE"
QT_MOC_LITERAL(22, 326, 6), // "tables"
QT_MOC_LITERAL(23, 333, 11), // "updateTable"
QT_MOC_LITERAL(24, 345, 10), // "clearTable"
QT_MOC_LITERAL(25, 356, 8), // "setValue"
QT_MOC_LITERAL(26, 365, 10), // "tableTimer"
QT_MOC_LITERAL(27, 376, 17), // "toggleStartServer"
QT_MOC_LITERAL(28, 394, 10), // "logMessage"
QT_MOC_LITERAL(29, 405, 3), // "msg"
QT_MOC_LITERAL(30, 409, 11), // "resizeEvent"
QT_MOC_LITERAL(31, 421, 13), // "QResizeEvent*"
QT_MOC_LITERAL(32, 435, 5), // "event"
QT_MOC_LITERAL(33, 441, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(34, 473, 4), // "arg1"
QT_MOC_LITERAL(35, 478, 10), // "clientInit"
QT_MOC_LITERAL(36, 489, 17), // "attemptConnection"
QT_MOC_LITERAL(37, 507, 17), // "connectedToServer"
QT_MOC_LITERAL(38, 525, 12), // "attemptLogin"
QT_MOC_LITERAL(39, 538, 8), // "userName"
QT_MOC_LITERAL(40, 547, 8), // "loggedIn"
QT_MOC_LITERAL(41, 556, 11), // "loginFailed"
QT_MOC_LITERAL(42, 568, 6), // "reason"
QT_MOC_LITERAL(43, 575, 15), // "messageReceived"
QT_MOC_LITERAL(44, 591, 6), // "sender"
QT_MOC_LITERAL(45, 598, 4), // "text"
QT_MOC_LITERAL(46, 603, 11), // "sendMessage"
QT_MOC_LITERAL(47, 615, 22), // "disconnectedFromServer"
QT_MOC_LITERAL(48, 638, 10), // "userJoined"
QT_MOC_LITERAL(49, 649, 8), // "username"
QT_MOC_LITERAL(50, 658, 8), // "userLeft"
QT_MOC_LITERAL(51, 667, 5), // "error"
QT_MOC_LITERAL(52, 673, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(53, 702, 11) // "socketError"

    },
    "MainWindow\0valueChanged\0\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_verticalSlider_valueChanged\0"
    "on_pushButton_clicked\0on_getSatData_clicked\0"
    "on_checkBox_toggled\0checked\0showTime\0"
    "webView\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked\0getCZML\0"
    "endpoint\0getSatDetails\0QList<QString>\0"
    "getSatPos\0getSatVisPass\0getSatRadPass\0"
    "getSatTLE\0tables\0updateTable\0clearTable\0"
    "setValue\0tableTimer\0toggleStartServer\0"
    "logMessage\0msg\0resizeEvent\0QResizeEvent*\0"
    "event\0on_comboBox_currentIndexChanged\0"
    "arg1\0clientInit\0attemptConnection\0"
    "connectedToServer\0attemptLogin\0userName\0"
    "loggedIn\0loginFailed\0reason\0messageReceived\0"
    "sender\0text\0sendMessage\0disconnectedFromServer\0"
    "userJoined\0username\0userLeft\0error\0"
    "QAbstractSocket::SocketError\0socketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  199,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  200,    2, 0x08 /* Private */,
       5,    1,  203,    2, 0x08 /* Private */,
       6,    0,  206,    2, 0x08 /* Private */,
       7,    0,  207,    2, 0x08 /* Private */,
       8,    1,  208,    2, 0x08 /* Private */,
      10,    0,  211,    2, 0x08 /* Private */,
      11,    0,  212,    2, 0x08 /* Private */,
      12,    0,  213,    2, 0x08 /* Private */,
      13,    0,  214,    2, 0x08 /* Private */,
      14,    1,  215,    2, 0x08 /* Private */,
      16,    1,  218,    2, 0x08 /* Private */,
      18,    1,  221,    2, 0x08 /* Private */,
      19,    1,  224,    2, 0x08 /* Private */,
      20,    1,  227,    2, 0x08 /* Private */,
      21,    1,  230,    2, 0x08 /* Private */,
      22,    0,  233,    2, 0x08 /* Private */,
      23,    0,  234,    2, 0x08 /* Private */,
      24,    0,  235,    2, 0x08 /* Private */,
      25,    1,  236,    2, 0x08 /* Private */,
      26,    0,  239,    2, 0x08 /* Private */,
      27,    0,  240,    2, 0x08 /* Private */,
      28,    1,  241,    2, 0x08 /* Private */,
      30,    1,  244,    2, 0x08 /* Private */,
      33,    1,  247,    2, 0x08 /* Private */,
      35,    0,  250,    2, 0x08 /* Private */,
      36,    0,  251,    2, 0x08 /* Private */,
      37,    0,  252,    2, 0x08 /* Private */,
      38,    1,  253,    2, 0x08 /* Private */,
      40,    0,  256,    2, 0x08 /* Private */,
      41,    1,  257,    2, 0x08 /* Private */,
      43,    2,  260,    2, 0x08 /* Private */,
      46,    0,  265,    2, 0x08 /* Private */,
      47,    0,  266,    2, 0x08 /* Private */,
      48,    1,  267,    2, 0x08 /* Private */,
      50,    1,  270,    2, 0x08 /* Private */,
      51,    1,  273,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 17,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   44,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, 0x80000000 | 52,   53,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged(); break;
        case 1: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_verticalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_getSatData_clicked(); break;
        case 5: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->showTime(); break;
        case 7: _t->webView(); break;
        case 8: _t->on_pushButton_5_clicked(); break;
        case 9: _t->on_pushButton_6_clicked(); break;
        case 10: _t->getCZML((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->getSatDetails((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 12: _t->getSatPos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->getSatVisPass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->getSatRadPass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->getSatTLE((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->tables(); break;
        case 17: _t->updateTable(); break;
        case 18: _t->clearTable(); break;
        case 19: _t->setValue((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 20: _t->tableTimer(); break;
        case 21: _t->toggleStartServer(); break;
        case 22: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 24: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->clientInit(); break;
        case 26: _t->attemptConnection(); break;
        case 27: _t->connectedToServer(); break;
        case 28: _t->attemptLogin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->loggedIn(); break;
        case 30: _t->loginFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 32: _t->sendMessage(); break;
        case 33: _t->disconnectedFromServer(); break;
        case 34: _t->userJoined((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->userLeft((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
