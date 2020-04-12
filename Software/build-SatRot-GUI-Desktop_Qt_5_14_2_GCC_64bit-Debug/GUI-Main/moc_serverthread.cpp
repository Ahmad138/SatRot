/****************************************************************************
** Meta object code from reading C++ file 'serverthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SatRot-GUI/GUI-Main/includes/serverthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerThread_t {
    QByteArrayData data[10];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerThread_t qt_meta_stringdata_ServerThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ServerThread"
QT_MOC_LITERAL(1, 13, 12), // "jsonReceived"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "jsonDoc"
QT_MOC_LITERAL(4, 35, 22), // "disconnectedFromClient"
QT_MOC_LITERAL(5, 58, 5), // "error"
QT_MOC_LITERAL(6, 64, 10), // "logMessage"
QT_MOC_LITERAL(7, 75, 3), // "msg"
QT_MOC_LITERAL(8, 79, 20), // "disconnectFromClient"
QT_MOC_LITERAL(9, 100, 11) // "receiveJson"

    },
    "ServerThread\0jsonReceived\0\0jsonDoc\0"
    "disconnectedFromClient\0error\0logMessage\0"
    "msg\0disconnectFromClient\0receiveJson"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   52,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ServerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->jsonReceived((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 1: _t->disconnectedFromClient(); break;
        case 2: _t->error(); break;
        case 3: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->disconnectFromClient(); break;
        case 5: _t->receiveJson(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerThread::*)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerThread::jsonReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerThread::disconnectedFromClient)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ServerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerThread::error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ServerThread::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerThread::logMessage)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ServerThread.data,
    qt_meta_data_ServerThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ServerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ServerThread::jsonReceived(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerThread::disconnectedFromClient()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ServerThread::error()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ServerThread::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
