/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SatRot-GUI/GUI-Main/includes/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPServer_t {
    QByteArrayData data[16];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPServer_t qt_meta_stringdata_TCPServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPServer"
QT_MOC_LITERAL(1, 10, 10), // "logMessage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "msg"
QT_MOC_LITERAL(4, 26, 14), // "stopAllClients"
QT_MOC_LITERAL(5, 41, 9), // "broadcast"
QT_MOC_LITERAL(6, 51, 7), // "message"
QT_MOC_LITERAL(7, 59, 13), // "ServerThread*"
QT_MOC_LITERAL(8, 73, 7), // "exclude"
QT_MOC_LITERAL(9, 81, 12), // "jsonReceived"
QT_MOC_LITERAL(10, 94, 6), // "sender"
QT_MOC_LITERAL(11, 101, 3), // "doc"
QT_MOC_LITERAL(12, 105, 16), // "userDisconnected"
QT_MOC_LITERAL(13, 122, 9), // "threadIdx"
QT_MOC_LITERAL(14, 132, 9), // "userError"
QT_MOC_LITERAL(15, 142, 10) // "stopServer"

    },
    "TCPServer\0logMessage\0\0msg\0stopAllClients\0"
    "broadcast\0message\0ServerThread*\0exclude\0"
    "jsonReceived\0sender\0doc\0userDisconnected\0"
    "threadIdx\0userError\0stopServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   53,    2, 0x08 /* Private */,
       9,    2,   58,    2, 0x08 /* Private */,
      12,    2,   63,    2, 0x08 /* Private */,
      14,    1,   68,    2, 0x08 /* Private */,
      15,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QJsonObject,   10,   11,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,   10,   13,
    QMetaType::Void, 0x80000000 | 7,   10,
    QMetaType::Void,

       0        // eod
};

void TCPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCPServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->stopAllClients(); break;
        case 2: _t->broadcast((*reinterpret_cast< const QJsonObject(*)>(_a[1])),(*reinterpret_cast< ServerThread*(*)>(_a[2]))); break;
        case 3: _t->jsonReceived((*reinterpret_cast< ServerThread*(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 4: _t->userDisconnected((*reinterpret_cast< ServerThread*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->userError((*reinterpret_cast< ServerThread*(*)>(_a[1]))); break;
        case 6: _t->stopServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TCPServer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPServer::logMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TCPServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPServer::stopAllClients)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TCPServer::staticMetaObject = { {
    &QTcpServer::staticMetaObject,
    qt_meta_stringdata_TCPServer.data,
    qt_meta_data_TCPServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int TCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TCPServer::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TCPServer::stopAllClients()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
