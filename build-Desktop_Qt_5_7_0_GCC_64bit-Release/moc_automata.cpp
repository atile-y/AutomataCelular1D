/****************************************************************************
** Meta object code from reading C++ file 'automata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../automata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'automata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Automata_t {
    QByteArrayData data[8];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Automata_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Automata_t qt_meta_stringdata_Automata = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Automata"
QT_MOC_LITERAL(1, 9, 7), // "newStep"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 6), // "evolve"
QT_MOC_LITERAL(4, 25, 5), // "bool*"
QT_MOC_LITERAL(5, 31, 7), // "endTime"
QT_MOC_LITERAL(6, 39, 4), // "Idle"
QT_MOC_LITERAL(7, 44, 8) // "addState"

    },
    "Automata\0newStep\0\0evolve\0bool*\0endTime\0"
    "Idle\0addState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Automata[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    2,   42,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::UInt,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void Automata::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Automata *_t = static_cast<Automata *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newStep((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->evolve((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->endTime(); break;
        case 3: _t->Idle(); break;
        case 4: _t->addState((*reinterpret_cast< bool*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Automata::*_t)(uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automata::newStep)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Automata::*_t)(bool * , uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automata::evolve)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Automata::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automata::endTime)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Automata::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_Automata.data,
      qt_meta_data_Automata,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Automata::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Automata::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Automata.stringdata0))
        return static_cast<void*>(const_cast< Automata*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int Automata::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Automata::newStep(uint _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Automata::evolve(bool * _t1, uint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Automata::endTime()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
