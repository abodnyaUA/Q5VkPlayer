/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/ViewController/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[29];
    char stringdata[337];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 15),
QT_MOC_LITERAL(4, 38, 11),
QT_MOC_LITERAL(5, 50, 23),
QT_MOC_LITERAL(6, 74, 3),
QT_MOC_LITERAL(7, 78, 5),
QT_MOC_LITERAL(8, 84, 12),
QT_MOC_LITERAL(9, 97, 3),
QT_MOC_LITERAL(10, 101, 16),
QT_MOC_LITERAL(11, 118, 9),
QT_MOC_LITERAL(12, 128, 12),
QT_MOC_LITERAL(13, 141, 11),
QT_MOC_LITERAL(14, 153, 15),
QT_MOC_LITERAL(15, 169, 8),
QT_MOC_LITERAL(16, 178, 15),
QT_MOC_LITERAL(17, 194, 8),
QT_MOC_LITERAL(18, 203, 20),
QT_MOC_LITERAL(19, 224, 14),
QT_MOC_LITERAL(20, 239, 5),
QT_MOC_LITERAL(21, 245, 4),
QT_MOC_LITERAL(22, 250, 7),
QT_MOC_LITERAL(23, 258, 13),
QT_MOC_LITERAL(24, 272, 4),
QT_MOC_LITERAL(25, 277, 5),
QT_MOC_LITERAL(26, 283, 11),
QT_MOC_LITERAL(27, 295, 33),
QT_MOC_LITERAL(28, 329, 6)
    },
    "MainWindow\0loadToken\0\0setPlayingOrder\0"
    "QList<QUrl>\0setPrefWindowsHotkeysUi\0"
    "use\0media\0setMinToTray\0min\0updateMusicTable\0"
    "setSongUi\0setPlayingUi\0setPausedUi\0"
    "positionChanged\0position\0durationChanged\0"
    "duration\0offlineDebugFunction\0"
    "setNewSettings\0cache\0path\0minTray\0"
    "currentSearch\0text\0about\0trayHandler\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06,
       3,    1,   94,    2, 0x06,
       5,    2,   97,    2, 0x06,
       8,    1,  102,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      10,    0,  105,    2, 0x0a,
      11,    2,  106,    2, 0x0a,
      12,    0,  111,    2, 0x0a,
      13,    0,  112,    2, 0x0a,
      14,    1,  113,    2, 0x0a,
      16,    1,  116,    2, 0x0a,
      18,    0,  119,    2, 0x0a,
      19,    5,  120,    2, 0x0a,
      23,    1,  131,    2, 0x08,
      25,    0,  134,    2, 0x08,
      26,    1,  135,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    6,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   15,
    QMetaType::Void, QMetaType::LongLong,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::Bool,    6,    7,   20,   21,   22,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->loadToken((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->setPlayingOrder((*reinterpret_cast< QList<QUrl>(*)>(_a[1]))); break;
        case 2: _t->setPrefWindowsHotkeysUi((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->setMinToTray((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->updateMusicTable(); break;
        case 5: _t->setSongUi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->setPlayingUi(); break;
        case 7: _t->setPausedUi(); break;
        case 8: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->offlineDebugFunction(); break;
        case 11: _t->setNewSettings((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 12: _t->currentSearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->about(); break;
        case 14: _t->trayHandler((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QUrl> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::loadToken)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(QList<QUrl> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::setPlayingOrder)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::setPrefWindowsHotkeysUi)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::setMinToTray)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::loadToken(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::setPlayingOrder(QList<QUrl> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::setPrefWindowsHotkeysUi(bool _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::setMinToTray(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
