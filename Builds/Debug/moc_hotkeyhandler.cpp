/****************************************************************************
** Meta object code from reading C++ file 'hotkeyhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/Controller/hotkeyhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hotkeyhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HotkeyHandler_t {
    QByteArrayData data[5];
    char stringdata[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_HotkeyHandler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_HotkeyHandler_t qt_meta_stringdata_HotkeyHandler = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 16),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 16),
QT_MOC_LITERAL(4, 49, 21)
    },
    "HotkeyHandler\0didTapNextButton\0\0"
    "didTapPrevButton\0didTapPlayPauseButton\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HotkeyHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06,
       3,    0,   30,    2, 0x06,
       4,    0,   31,    2, 0x06,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HotkeyHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HotkeyHandler *_t = static_cast<HotkeyHandler *>(_o);
        switch (_id) {
        case 0: _t->didTapNextButton(); break;
        case 1: _t->didTapPrevButton(); break;
        case 2: _t->didTapPlayPauseButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HotkeyHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HotkeyHandler::didTapNextButton)) {
                *result = 0;
            }
        }
        {
            typedef void (HotkeyHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HotkeyHandler::didTapPrevButton)) {
                *result = 1;
            }
        }
        {
            typedef void (HotkeyHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HotkeyHandler::didTapPlayPauseButton)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HotkeyHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HotkeyHandler.data,
      qt_meta_data_HotkeyHandler,  qt_static_metacall, 0, 0}
};


const QMetaObject *HotkeyHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HotkeyHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HotkeyHandler.stringdata))
        return static_cast<void*>(const_cast< HotkeyHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int HotkeyHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HotkeyHandler::didTapNextButton()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void HotkeyHandler::didTapPrevButton()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void HotkeyHandler::didTapPlayPauseButton()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
