/****************************************************************************
** Meta object code from reading C++ file 'networker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/Controller/Network/networker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetWorker_t {
    QByteArrayData data[13];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NetWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NetWorker_t qt_meta_stringdata_NetWorker = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 15),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 12),
QT_MOC_LITERAL(4, 40, 15),
QT_MOC_LITERAL(5, 56, 5),
QT_MOC_LITERAL(6, 62, 8),
QT_MOC_LITERAL(7, 71, 9),
QT_MOC_LITERAL(8, 81, 12),
QT_MOC_LITERAL(9, 94, 13),
QT_MOC_LITERAL(10, 108, 14),
QT_MOC_LITERAL(11, 123, 5),
QT_MOC_LITERAL(12, 129, 17)
    },
    "NetWorker\0didRecieveSongs\0\0QList<Song*>\0"
    "didDownloadSong\0Song*\0setToken\0loginSlot\0"
    "getAudioList\0replyFinished\0QNetworkReply*\0"
    "reply\0songDidDownloaded\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       4,    1,   52,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    2,   55,    2, 0x0a,
       7,    0,   60,    2, 0x0a,
       8,    0,   61,    2, 0x0a,
       9,    1,   62,    2, 0x08,
      12,    1,   65,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void NetWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetWorker *_t = static_cast<NetWorker *>(_o);
        switch (_id) {
        case 0: _t->didRecieveSongs((*reinterpret_cast< QList<Song*>(*)>(_a[1]))); break;
        case 1: _t->didDownloadSong((*reinterpret_cast< Song*(*)>(_a[1]))); break;
        case 2: _t->setToken((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->loginSlot(); break;
        case 4: _t->getAudioList(); break;
        case 5: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->songDidDownloaded((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Song*> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Song* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetWorker::*_t)(QList<Song*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetWorker::didRecieveSongs)) {
                *result = 0;
            }
        }
        {
            typedef void (NetWorker::*_t)(Song * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetWorker::didDownloadSong)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject NetWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetWorker.data,
      qt_meta_data_NetWorker,  qt_static_metacall, 0, 0}
};


const QMetaObject *NetWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetWorker.stringdata))
        return static_cast<void*>(const_cast< NetWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int NetWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void NetWorker::didRecieveSongs(QList<Song*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetWorker::didDownloadSong(Song * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
