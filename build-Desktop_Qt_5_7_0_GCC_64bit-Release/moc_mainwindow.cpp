/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[445];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "startScan"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 33), // "on_actionAbrir_Automata_trigg..."
QT_MOC_LITERAL(4, 56, 35), // "on_actionGuardar_Automata_tri..."
QT_MOC_LITERAL(5, 92, 24), // "on_actionTodas_triggered"
QT_MOC_LITERAL(6, 117, 31), // "on_actionEquivalentes_triggered"
QT_MOC_LITERAL(7, 149, 33), // "on_lengthLineEdit_editingFini..."
QT_MOC_LITERAL(8, 183, 31), // "on_ruleLineEdit_editingFinished"
QT_MOC_LITERAL(9, 215, 31), // "on_timeLineEdit_editingFinished"
QT_MOC_LITERAL(10, 247, 25), // "on_playPushButton_clicked"
QT_MOC_LITERAL(11, 273, 26), // "on_pausePushButton_clicked"
QT_MOC_LITERAL(12, 300, 25), // "on_stopPushButton_clicked"
QT_MOC_LITERAL(13, 326, 34), // "on_percentLineEdit_editingFin..."
QT_MOC_LITERAL(14, 361, 39), // "on_percentHorizontalSlider_va..."
QT_MOC_LITERAL(15, 401, 14), // "takeScreenshot"
QT_MOC_LITERAL(16, 416, 17), // "statusRunningRule"
QT_MOC_LITERAL(17, 434, 10) // "finishScan"

    },
    "MainWindow\0startScan\0\0"
    "on_actionAbrir_Automata_triggered\0"
    "on_actionGuardar_Automata_triggered\0"
    "on_actionTodas_triggered\0"
    "on_actionEquivalentes_triggered\0"
    "on_lengthLineEdit_editingFinished\0"
    "on_ruleLineEdit_editingFinished\0"
    "on_timeLineEdit_editingFinished\0"
    "on_playPushButton_clicked\0"
    "on_pausePushButton_clicked\0"
    "on_stopPushButton_clicked\0"
    "on_percentLineEdit_editingFinished\0"
    "on_percentHorizontalSlider_valueChanged\0"
    "takeScreenshot\0statusRunningRule\0"
    "finishScan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  102,    2, 0x08 /* Private */,
       4,    0,  103,    2, 0x08 /* Private */,
       5,    0,  104,    2, 0x08 /* Private */,
       6,    0,  105,    2, 0x08 /* Private */,
       7,    0,  106,    2, 0x08 /* Private */,
       8,    0,  107,    2, 0x08 /* Private */,
       9,    0,  108,    2, 0x08 /* Private */,
      10,    0,  109,    2, 0x08 /* Private */,
      11,    0,  110,    2, 0x08 /* Private */,
      12,    0,  111,    2, 0x08 /* Private */,
      13,    0,  112,    2, 0x08 /* Private */,
      14,    1,  113,    2, 0x08 /* Private */,
      15,    1,  116,    2, 0x08 /* Private */,
      15,    0,  119,    2, 0x28 /* Private | MethodCloned */,
      16,    1,  120,    2, 0x08 /* Private */,
      17,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startScan((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_actionAbrir_Automata_triggered(); break;
        case 2: _t->on_actionGuardar_Automata_triggered(); break;
        case 3: _t->on_actionTodas_triggered(); break;
        case 4: _t->on_actionEquivalentes_triggered(); break;
        case 5: _t->on_lengthLineEdit_editingFinished(); break;
        case 6: _t->on_ruleLineEdit_editingFinished(); break;
        case 7: _t->on_timeLineEdit_editingFinished(); break;
        case 8: _t->on_playPushButton_clicked(); break;
        case 9: _t->on_pausePushButton_clicked(); break;
        case 10: _t->on_stopPushButton_clicked(); break;
        case 11: _t->on_percentLineEdit_editingFinished(); break;
        case 12: _t->on_percentHorizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->takeScreenshot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->takeScreenshot(); break;
        case 15: _t->statusRunningRule((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->finishScan(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startScan)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startScan(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
