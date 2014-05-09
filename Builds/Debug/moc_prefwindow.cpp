/****************************************************************************
** Meta object code from reading C++ file 'prefwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/ViewController/prefwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prefwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PrefWindow_t {
    QByteArrayData data[16];
    char stringdata[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PrefWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PrefWindow_t qt_meta_stringdata_PrefWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 23),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 3),
QT_MOC_LITERAL(4, 40, 4),
QT_MOC_LITERAL(5, 45, 25),
QT_MOC_LITERAL(6, 71, 5),
QT_MOC_LITERAL(7, 77, 14),
QT_MOC_LITERAL(8, 92, 5),
QT_MOC_LITERAL(9, 98, 5),
QT_MOC_LITERAL(10, 104, 7),
QT_MOC_LITERAL(11, 112, 15),
QT_MOC_LITERAL(12, 128, 13),
QT_MOC_LITERAL(13, 142, 13),
QT_MOC_LITERAL(14, 156, 7),
QT_MOC_LITERAL(15, 164, 15)
    },
    "PrefWindow\0changedUseCacheSettings\0\0"
    "use\0path\0changedUseHotkeysSettings\0"
    "index\0setNewSettings\0media\0cache\0"
    "minTray\0setUseHotkeysUi\0setUseCacheUi\0"
    "setUseMinTray\0useTray\0sendNewSettings\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrefWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06,
       5,    2,   54,    2, 0x06,
       7,    4,   59,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    2,   68,    2, 0x0a,
      12,    2,   73,    2, 0x0a,
      13,    1,   78,    2, 0x0a,
      15,    0,   81,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    3,    6,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    3,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    3,    8,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

void PrefWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrefWindow *_t = static_cast<PrefWindow *>(_o);
        switch (_id) {
        case 0: _t->changedUseCacheSettings((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->changedUseHotkeysSettings((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setNewSettings((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 3: _t->setUseHotkeysUi((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->setUseCacheUi((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->setUseMinTray((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->sendNewSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PrefWindow::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrefWindow::changedUseCacheSettings)) {
                *result = 0;
            }
        }
        {
            typedef void (PrefWindow::*_t)(bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrefWindow::changedUseHotkeysSettings)) {
                *result = 1;
            }
        }
        {
            typedef void (PrefWindow::*_t)(bool , bool , bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrefWindow::setNewSettings)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject PrefWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PrefWindow.data,
      qt_meta_data_PrefWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *PrefWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrefWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrefWindow.stringdata))
        return static_cast<void*>(const_cast< PrefWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int PrefWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void PrefWindow::changedUseCacheSettings(bool _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PrefWindow::changedUseHotkeysSettings(bool _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PrefWindow::setNewSettings(bool _t1, bool _t2, bool _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
