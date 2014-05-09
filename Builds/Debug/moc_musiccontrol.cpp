/****************************************************************************
** Meta object code from reading C++ file 'musiccontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/Controller/musiccontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musiccontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MusicControl_t {
    QByteArrayData data[22];
    char stringdata[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MusicControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MusicControl_t qt_meta_stringdata_MusicControl = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 12),
QT_MOC_LITERAL(4, 40, 11),
QT_MOC_LITERAL(5, 52, 8),
QT_MOC_LITERAL(6, 61, 11),
QT_MOC_LITERAL(7, 73, 14),
QT_MOC_LITERAL(8, 88, 12),
QT_MOC_LITERAL(9, 101, 11),
QT_MOC_LITERAL(10, 113, 14),
QT_MOC_LITERAL(11, 128, 13),
QT_MOC_LITERAL(12, 142, 12),
QT_MOC_LITERAL(13, 155, 12),
QT_MOC_LITERAL(14, 168, 11),
QT_MOC_LITERAL(15, 180, 16),
QT_MOC_LITERAL(16, 197, 11),
QT_MOC_LITERAL(17, 209, 8),
QT_MOC_LITERAL(18, 218, 12),
QT_MOC_LITERAL(19, 231, 25),
QT_MOC_LITERAL(20, 257, 15),
QT_MOC_LITERAL(21, 273, 10)
    },
    "MusicControl\0setIndexToUi\0\0setPlayingUi\0"
    "setPausedUi\0newRange\0newPosition\0"
    "updatePlayList\0playThatSong\0shuffleMode\0"
    "songDidChanged\0QMediaContent\0playNextSong\0"
    "playPrevSong\0changeState\0volumeSliderSlot\0"
    "setPosition\0position\0stateHandler\0"
    "QMediaPlayer::MediaStatus\0setSelectedSong\0"
    "repeatMode\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06,
       3,    0,  104,    2, 0x06,
       4,    0,  105,    2, 0x06,
       5,    1,  106,    2, 0x06,
       6,    1,  109,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,  112,    2, 0x0a,
       8,    2,  113,    2, 0x0a,
       9,    1,  118,    2, 0x0a,
      10,    1,  121,    2, 0x0a,
      12,    0,  124,    2, 0x0a,
      13,    0,  125,    2, 0x0a,
      14,    0,  126,    2, 0x0a,
      15,    1,  127,    2, 0x0a,
      16,    1,  130,    2, 0x0a,
      18,    1,  133,    2, 0x0a,
      20,    2,  136,    2, 0x0a,
      21,    1,  141,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MusicControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicControl *_t = static_cast<MusicControl *>(_o);
        switch (_id) {
        case 0: _t->setIndexToUi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setPlayingUi(); break;
        case 2: _t->setPausedUi(); break;
        case 3: _t->newRange((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->newPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->updatePlayList(); break;
        case 6: _t->playThatSong((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->shuffleMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->songDidChanged((*reinterpret_cast< QMediaContent(*)>(_a[1]))); break;
        case 9: _t->playNextSong(); break;
        case 10: _t->playPrevSong(); break;
        case 11: _t->changeState(); break;
        case 12: _t->volumeSliderSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->stateHandler((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 15: _t->setSelectedSong((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->repeatMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaContent >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MusicControl::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicControl::setIndexToUi)) {
                *result = 0;
            }
        }
        {
            typedef void (MusicControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicControl::setPlayingUi)) {
                *result = 1;
            }
        }
        {
            typedef void (MusicControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicControl::setPausedUi)) {
                *result = 2;
            }
        }
        {
            typedef void (MusicControl::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicControl::newRange)) {
                *result = 3;
            }
        }
        {
            typedef void (MusicControl::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicControl::newPosition)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject MusicControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MusicControl.data,
      qt_meta_data_MusicControl,  qt_static_metacall, 0, 0}
};


const QMetaObject *MusicControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MusicControl.stringdata))
        return static_cast<void*>(const_cast< MusicControl*>(this));
    return QObject::qt_metacast(_clname);
}

int MusicControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MusicControl::setIndexToUi(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MusicControl::setPlayingUi()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MusicControl::setPausedUi()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MusicControl::newRange(qint64 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MusicControl::newPosition(qint64 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
