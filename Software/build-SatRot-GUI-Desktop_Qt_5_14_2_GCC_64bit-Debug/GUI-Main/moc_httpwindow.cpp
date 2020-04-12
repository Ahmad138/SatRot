/****************************************************************************
** Meta object code from reading C++ file 'httpwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SatRot-GUI/GUI-Main/includes/httpwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpWindow_t {
    QByteArrayData data[15];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpWindow_t qt_meta_stringdata_HttpWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HttpWindow"
QT_MOC_LITERAL(1, 11, 12), // "startRequest"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "requestedUrl"
QT_MOC_LITERAL(4, 38, 14), // "cancelDownload"
QT_MOC_LITERAL(5, 53, 12), // "httpFinished"
QT_MOC_LITERAL(6, 66, 13), // "httpReadyRead"
QT_MOC_LITERAL(7, 80, 20), // "enableDownloadButton"
QT_MOC_LITERAL(8, 101, 26), // "slotAuthenticationRequired"
QT_MOC_LITERAL(9, 128, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 143, 15), // "QAuthenticator*"
QT_MOC_LITERAL(11, 159, 13), // "authenticator"
QT_MOC_LITERAL(12, 173, 9), // "sslErrors"
QT_MOC_LITERAL(13, 183, 16), // "QList<QSslError>"
QT_MOC_LITERAL(14, 200, 6) // "errors"

    },
    "HttpWindow\0startRequest\0\0requestedUrl\0"
    "cancelDownload\0httpFinished\0httpReadyRead\0"
    "enableDownloadButton\0slotAuthenticationRequired\0"
    "QNetworkReply*\0QAuthenticator*\0"
    "authenticator\0sslErrors\0QList<QSslError>\0"
    "errors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    2,   56,    2, 0x08 /* Private */,
      12,    2,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 10,    2,   11,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 13,    2,   14,

       0        // eod
};

void HttpWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startRequest((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: _t->cancelDownload(); break;
        case 2: _t->httpFinished(); break;
        case 3: _t->httpReadyRead(); break;
        case 4: _t->enableDownloadButton(); break;
        case 5: _t->slotAuthenticationRequired((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 6: _t->sslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_HttpWindow.data,
    qt_meta_data_HttpWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
