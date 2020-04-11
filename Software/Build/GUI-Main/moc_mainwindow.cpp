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
    QByteArrayData data[62];
    char stringdata0[750];
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
QT_MOC_LITERAL(3, 25, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 47, 21), // "on_getSatData_clicked"
QT_MOC_LITERAL(5, 69, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(6, 89, 7), // "checked"
QT_MOC_LITERAL(7, 97, 8), // "showTime"
QT_MOC_LITERAL(8, 106, 7), // "webView"
QT_MOC_LITERAL(9, 114, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(10, 138, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(11, 162, 7), // "getCZML"
QT_MOC_LITERAL(12, 170, 8), // "endpoint"
QT_MOC_LITERAL(13, 179, 13), // "getSatDetails"
QT_MOC_LITERAL(14, 193, 14), // "QList<QString>"
QT_MOC_LITERAL(15, 208, 9), // "getSatPos"
QT_MOC_LITERAL(16, 218, 13), // "getSatVisPass"
QT_MOC_LITERAL(17, 232, 13), // "getSatRadPass"
QT_MOC_LITERAL(18, 246, 9), // "getSatTLE"
QT_MOC_LITERAL(19, 256, 6), // "tables"
QT_MOC_LITERAL(20, 263, 11), // "updateTable"
QT_MOC_LITERAL(21, 275, 10), // "clearTable"
QT_MOC_LITERAL(22, 286, 8), // "setValue"
QT_MOC_LITERAL(23, 295, 5), // "value"
QT_MOC_LITERAL(24, 301, 10), // "tableTimer"
QT_MOC_LITERAL(25, 312, 17), // "toggleStartServer"
QT_MOC_LITERAL(26, 330, 10), // "logMessage"
QT_MOC_LITERAL(27, 341, 3), // "msg"
QT_MOC_LITERAL(28, 345, 11), // "resizeEvent"
QT_MOC_LITERAL(29, 357, 13), // "QResizeEvent*"
QT_MOC_LITERAL(30, 371, 5), // "event"
QT_MOC_LITERAL(31, 377, 26), // "on_sat_currentIndexChanged"
QT_MOC_LITERAL(32, 404, 4), // "arg1"
QT_MOC_LITERAL(33, 409, 10), // "clientInit"
QT_MOC_LITERAL(34, 420, 17), // "attemptConnection"
QT_MOC_LITERAL(35, 438, 17), // "connectedToServer"
QT_MOC_LITERAL(36, 456, 12), // "attemptLogin"
QT_MOC_LITERAL(37, 469, 8), // "userName"
QT_MOC_LITERAL(38, 478, 8), // "loggedIn"
QT_MOC_LITERAL(39, 487, 11), // "loginFailed"
QT_MOC_LITERAL(40, 499, 6), // "reason"
QT_MOC_LITERAL(41, 506, 15), // "messageReceived"
QT_MOC_LITERAL(42, 522, 6), // "sender"
QT_MOC_LITERAL(43, 529, 4), // "text"
QT_MOC_LITERAL(44, 534, 11), // "sendMessage"
QT_MOC_LITERAL(45, 546, 22), // "disconnectedFromServer"
QT_MOC_LITERAL(46, 569, 10), // "userJoined"
QT_MOC_LITERAL(47, 580, 8), // "username"
QT_MOC_LITERAL(48, 589, 8), // "userLeft"
QT_MOC_LITERAL(49, 598, 5), // "error"
QT_MOC_LITERAL(50, 604, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(51, 633, 11), // "socketError"
QT_MOC_LITERAL(52, 645, 20), // "on_sendTrack_clicked"
QT_MOC_LITERAL(53, 666, 4), // "open"
QT_MOC_LITERAL(54, 671, 4), // "save"
QT_MOC_LITERAL(55, 676, 8), // "penColor"
QT_MOC_LITERAL(56, 685, 8), // "penWidth"
QT_MOC_LITERAL(57, 694, 5), // "about"
QT_MOC_LITERAL(58, 700, 10), // "clearRadar"
QT_MOC_LITERAL(59, 711, 9), // "logAngles"
QT_MOC_LITERAL(60, 721, 21), // "QMap<QString,double>&"
QT_MOC_LITERAL(61, 743, 6) // "angles"

    },
    "MainWindow\0valueChanged\0\0on_pushButton_clicked\0"
    "on_getSatData_clicked\0on_checkBox_toggled\0"
    "checked\0showTime\0webView\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked\0"
    "getCZML\0endpoint\0getSatDetails\0"
    "QList<QString>\0getSatPos\0getSatVisPass\0"
    "getSatRadPass\0getSatTLE\0tables\0"
    "updateTable\0clearTable\0setValue\0value\0"
    "tableTimer\0toggleStartServer\0logMessage\0"
    "msg\0resizeEvent\0QResizeEvent*\0event\0"
    "on_sat_currentIndexChanged\0arg1\0"
    "clientInit\0attemptConnection\0"
    "connectedToServer\0attemptLogin\0userName\0"
    "loggedIn\0loginFailed\0reason\0messageReceived\0"
    "sender\0text\0sendMessage\0disconnectedFromServer\0"
    "userJoined\0username\0userLeft\0error\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "on_sendTrack_clicked\0open\0save\0penColor\0"
    "penWidth\0about\0clearRadar\0logAngles\0"
    "QMap<QString,double>&\0angles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  229,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  230,    2, 0x08 /* Private */,
       4,    0,  231,    2, 0x08 /* Private */,
       5,    1,  232,    2, 0x08 /* Private */,
       7,    0,  235,    2, 0x08 /* Private */,
       8,    0,  236,    2, 0x08 /* Private */,
       9,    0,  237,    2, 0x08 /* Private */,
      10,    0,  238,    2, 0x08 /* Private */,
      11,    1,  239,    2, 0x08 /* Private */,
      13,    1,  242,    2, 0x08 /* Private */,
      15,    1,  245,    2, 0x08 /* Private */,
      16,    1,  248,    2, 0x08 /* Private */,
      17,    1,  251,    2, 0x08 /* Private */,
      18,    1,  254,    2, 0x08 /* Private */,
      19,    0,  257,    2, 0x08 /* Private */,
      20,    0,  258,    2, 0x08 /* Private */,
      21,    0,  259,    2, 0x08 /* Private */,
      22,    1,  260,    2, 0x08 /* Private */,
      24,    0,  263,    2, 0x08 /* Private */,
      25,    0,  264,    2, 0x08 /* Private */,
      26,    1,  265,    2, 0x08 /* Private */,
      28,    1,  268,    2, 0x08 /* Private */,
      31,    1,  271,    2, 0x08 /* Private */,
      33,    0,  274,    2, 0x08 /* Private */,
      34,    0,  275,    2, 0x08 /* Private */,
      35,    0,  276,    2, 0x08 /* Private */,
      36,    1,  277,    2, 0x08 /* Private */,
      38,    0,  280,    2, 0x08 /* Private */,
      39,    1,  281,    2, 0x08 /* Private */,
      41,    2,  284,    2, 0x08 /* Private */,
      44,    0,  289,    2, 0x08 /* Private */,
      45,    0,  290,    2, 0x08 /* Private */,
      46,    1,  291,    2, 0x08 /* Private */,
      48,    1,  294,    2, 0x08 /* Private */,
      49,    1,  297,    2, 0x08 /* Private */,
      52,    0,  300,    2, 0x08 /* Private */,
      53,    0,  301,    2, 0x08 /* Private */,
      54,    0,  302,    2, 0x08 /* Private */,
      55,    0,  303,    2, 0x08 /* Private */,
      56,    0,  304,    2, 0x08 /* Private */,
      57,    0,  305,    2, 0x08 /* Private */,
      58,    0,  306,    2, 0x08 /* Private */,
      59,    1,  307,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   42,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, 0x80000000 | 50,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 60,   61,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_getSatData_clicked(); break;
        case 3: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->showTime(); break;
        case 5: _t->webView(); break;
        case 6: _t->on_pushButton_5_clicked(); break;
        case 7: _t->on_pushButton_6_clicked(); break;
        case 8: _t->getCZML((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->getSatDetails((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 10: _t->getSatPos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->getSatVisPass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->getSatRadPass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->getSatTLE((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->tables(); break;
        case 15: _t->updateTable(); break;
        case 16: _t->clearTable(); break;
        case 17: _t->setValue((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 18: _t->tableTimer(); break;
        case 19: _t->toggleStartServer(); break;
        case 20: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 22: _t->on_sat_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->clientInit(); break;
        case 24: _t->attemptConnection(); break;
        case 25: _t->connectedToServer(); break;
        case 26: _t->attemptLogin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->loggedIn(); break;
        case 28: _t->loginFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 30: _t->sendMessage(); break;
        case 31: _t->disconnectedFromServer(); break;
        case 32: _t->userJoined((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->userLeft((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 35: _t->on_sendTrack_clicked(); break;
        case 36: _t->open(); break;
        case 37: _t->save(); break;
        case 38: _t->penColor(); break;
        case 39: _t->penWidth(); break;
        case 40: _t->about(); break;
        case 41: _t->clearRadar(); break;
        case 42: _t->logAngles((*reinterpret_cast< QMap<QString,double>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 34:
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
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
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
