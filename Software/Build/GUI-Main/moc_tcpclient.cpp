/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SatRot-GUI/GUI-Main/includes/tcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPClient_t {
    QByteArrayData data[29];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPClient_t qt_meta_stringdata_TCPClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPClient"
QT_MOC_LITERAL(1, 10, 9), // "connected"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "loggedIn"
QT_MOC_LITERAL(4, 30, 10), // "loginError"
QT_MOC_LITERAL(5, 41, 6), // "reason"
QT_MOC_LITERAL(6, 48, 12), // "disconnected"
QT_MOC_LITERAL(7, 61, 15), // "messageReceived"
QT_MOC_LITERAL(8, 77, 6), // "sender"
QT_MOC_LITERAL(9, 84, 4), // "text"
QT_MOC_LITERAL(10, 89, 5), // "error"
QT_MOC_LITERAL(11, 95, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(12, 124, 11), // "socketError"
QT_MOC_LITERAL(13, 136, 10), // "userJoined"
QT_MOC_LITERAL(14, 147, 8), // "username"
QT_MOC_LITERAL(15, 156, 8), // "userLeft"
QT_MOC_LITERAL(16, 165, 15), // "connectToServer"
QT_MOC_LITERAL(17, 181, 12), // "QHostAddress"
QT_MOC_LITERAL(18, 194, 7), // "address"
QT_MOC_LITERAL(19, 202, 4), // "port"
QT_MOC_LITERAL(20, 207, 5), // "login"
QT_MOC_LITERAL(21, 213, 8), // "userName"
QT_MOC_LITERAL(22, 222, 11), // "sendMessage"
QT_MOC_LITERAL(23, 234, 18), // "disconnectFromHost"
QT_MOC_LITERAL(24, 253, 19), // "sendTrackingDetails"
QT_MOC_LITERAL(25, 273, 12), // "QJsonObject&"
QT_MOC_LITERAL(26, 286, 11), // "satDataType"
QT_MOC_LITERAL(27, 298, 4), // "mode"
QT_MOC_LITERAL(28, 303, 11) // "onReadyRead"

    },
    "TCPClient\0connected\0\0loggedIn\0loginError\0"
    "reason\0disconnected\0messageReceived\0"
    "sender\0text\0error\0QAbstractSocket::SocketError\0"
    "socketError\0userJoined\0username\0"
    "userLeft\0connectToServer\0QHostAddress\0"
    "address\0port\0login\0userName\0sendMessage\0"
    "disconnectFromHost\0sendTrackingDetails\0"
    "QJsonObject&\0satDataType\0mode\0onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    1,   91,    2, 0x06 /* Public */,
       6,    0,   94,    2, 0x06 /* Public */,
       7,    2,   95,    2, 0x06 /* Public */,
      10,    1,  100,    2, 0x06 /* Public */,
      13,    1,  103,    2, 0x06 /* Public */,
      15,    1,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    2,  109,    2, 0x0a /* Public */,
      20,    1,  114,    2, 0x0a /* Public */,
      22,    1,  117,    2, 0x0a /* Public */,
      23,    0,  120,    2, 0x0a /* Public */,
      24,    3,  121,    2, 0x0a /* Public */,
      24,    2,  128,    2, 0x2a /* Public | MethodCloned */,
      28,    0,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 17, QMetaType::UShort,   18,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25, QMetaType::QString, QMetaType::Bool,    9,   26,   27,
    QMetaType::Void, 0x80000000 | 25, QMetaType::QString,    9,   26,
    QMetaType::Void,

       0        // eod
};

void TCPClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCPClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->loggedIn(); break;
        case 2: _t->loginError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->disconnected(); break;
        case 4: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->userJoined((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->userLeft((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->connectToServer((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 9: _t->login((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->disconnectFromHost(); break;
        case 12: _t->sendTrackingDetails((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 13: _t->sendTrackingDetails((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
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
            using _t = void (TCPClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPClient::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TCPClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPClient::loggedIn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TCPClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPClient::loginError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TCPClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPClient::disconnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TCPClient::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPClient::messageReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TCPClient::*)(QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPClient::error)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TCPClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPClient::userJoined)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TCPClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPClient::userLeft)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TCPClient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TCPClient.data,
    qt_meta_data_TCPClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TCPClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TCPClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TCPClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TCPClient::loggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TCPClient::loginError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TCPClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TCPClient::messageReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TCPClient::error(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TCPClient::userJoined(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TCPClient::userLeft(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
