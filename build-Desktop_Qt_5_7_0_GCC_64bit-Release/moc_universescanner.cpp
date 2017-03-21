/****************************************************************************
** Meta object code from reading C++ file 'universescanner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../universescanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'universescanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UniverseScanner_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UniverseScanner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UniverseScanner_t qt_meta_stringdata_UniverseScanner = {
    {
QT_MOC_LITERAL(0, 0, 15), // "UniverseScanner"
QT_MOC_LITERAL(1, 16, 9), // "startRule"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "endScanning"
QT_MOC_LITERAL(4, 39, 4) // "scan"

    },
    "UniverseScanner\0startRule\0\0endScanning\0"
    "scan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UniverseScanner[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void UniverseScanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UniverseScanner *_t = static_cast<UniverseScanner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startRule((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->endScanning(); break;
        case 2: _t->scan((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UniverseScanner::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UniverseScanner::startRule)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UniverseScanner::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UniverseScanner::endScanning)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject UniverseScanner::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UniverseScanner.data,
      qt_meta_data_UniverseScanner,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UniverseScanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UniverseScanner::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UniverseScanner.stringdata0))
        return static_cast<void*>(const_cast< UniverseScanner*>(this));
    return QObject::qt_metacast(_clname);
}

int UniverseScanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UniverseScanner::startRule(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UniverseScanner::endScanning()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
