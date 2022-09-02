/****************************************************************************
** Meta object code from reading C++ file 'cave_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../view/cave_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cave_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaveWindow_t {
    const uint offsetsAndSize[20];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CaveWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CaveWindow_t qt_meta_stringdata_CaveWindow = {
    {
QT_MOC_LITERAL(0, 10), // "CaveWindow"
QT_MOC_LITERAL(11, 25), // "on_generateButton_clicked"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 21), // "on_stepButton_clicked"
QT_MOC_LITERAL(60, 21), // "on_autoButton_clicked"
QT_MOC_LITERAL(82, 10), // "closeEvent"
QT_MOC_LITERAL(93, 12), // "QCloseEvent*"
QT_MOC_LITERAL(106, 5), // "event"
QT_MOC_LITERAL(112, 25), // "on_saveButtonCave_clicked"
QT_MOC_LITERAL(138, 25) // "on_loadButtonCave_clicked"

    },
    "CaveWindow\0on_generateButton_clicked\0"
    "\0on_stepButton_clicked\0on_autoButton_clicked\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_saveButtonCave_clicked\0"
    "on_loadButtonCave_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaveWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    1,   53,    2, 0x08,    4 /* Private */,
       8,    0,   56,    2, 0x08,    6 /* Private */,
       9,    0,   57,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CaveWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaveWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_generateButton_clicked(); break;
        case 1: _t->on_stepButton_clicked(); break;
        case 2: _t->on_autoButton_clicked(); break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 4: _t->on_saveButtonCave_clicked(); break;
        case 5: _t->on_loadButtonCave_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject CaveWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CaveWindow.offsetsAndSize,
    qt_meta_data_CaveWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CaveWindow_t
, QtPrivate::TypeAndForceComplete<CaveWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CaveWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaveWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaveWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CaveWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
