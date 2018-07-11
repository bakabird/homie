/****************************************************************************
** Meta object code from reading C++ file 'GlobalDrawProperties.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../app/GlobalDrawProperties.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlobalDrawProperties.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GlobalDrawProperties_t {
    QByteArrayData data[9];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GlobalDrawProperties_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GlobalDrawProperties_t qt_meta_stringdata_GlobalDrawProperties = {
    {
QT_MOC_LITERAL(0, 0, 20), // "GlobalDrawProperties"
QT_MOC_LITERAL(1, 21, 16), // "onClickFillColor"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "onSelectFillColor"
QT_MOC_LITERAL(4, 57, 5), // "color"
QT_MOC_LITERAL(5, 63, 17), // "onRejectFillColor"
QT_MOC_LITERAL(6, 81, 16), // "onClickLineColor"
QT_MOC_LITERAL(7, 98, 17), // "onSelectLineColor"
QT_MOC_LITERAL(8, 116, 17) // "onRejectLineColor"

    },
    "GlobalDrawProperties\0onClickFillColor\0"
    "\0onSelectFillColor\0color\0onRejectFillColor\0"
    "onClickLineColor\0onSelectLineColor\0"
    "onRejectLineColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GlobalDrawProperties[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    4,
    QMetaType::Void,

       0        // eod
};

void GlobalDrawProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GlobalDrawProperties *_t = static_cast<GlobalDrawProperties *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClickFillColor(); break;
        case 1: _t->onSelectFillColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->onRejectFillColor(); break;
        case 3: _t->onClickLineColor(); break;
        case 4: _t->onSelectLineColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 5: _t->onRejectLineColor(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GlobalDrawProperties::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GlobalDrawProperties.data,
      qt_meta_data_GlobalDrawProperties,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GlobalDrawProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GlobalDrawProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GlobalDrawProperties.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GlobalDrawProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
