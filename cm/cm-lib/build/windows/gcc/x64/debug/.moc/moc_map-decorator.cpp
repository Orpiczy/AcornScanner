/****************************************************************************
** Meta object code from reading C++ file 'map-decorator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/data/map-decorator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map-decorator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__data__MapDecorator_t {
    const uint offsetsAndSize[42];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cm__data__MapDecorator_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cm__data__MapDecorator_t qt_meta_stringdata_cm__data__MapDecorator = {
    {
QT_MOC_LITERAL(0, 22), // "cm::data::MapDecorator"
QT_MOC_LITERAL(23, 12), // "valueChanged"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 3), // "key"
QT_MOC_LITERAL(41, 9), // "valueRead"
QT_MOC_LITERAL(51, 9), // "ui_value0"
QT_MOC_LITERAL(61, 7), // "ui_key0"
QT_MOC_LITERAL(69, 9), // "ui_value1"
QT_MOC_LITERAL(79, 7), // "ui_key1"
QT_MOC_LITERAL(87, 9), // "ui_value2"
QT_MOC_LITERAL(97, 7), // "ui_key2"
QT_MOC_LITERAL(105, 9), // "ui_value3"
QT_MOC_LITERAL(115, 7), // "ui_key3"
QT_MOC_LITERAL(123, 9), // "ui_value4"
QT_MOC_LITERAL(133, 7), // "ui_key4"
QT_MOC_LITERAL(141, 9), // "ui_value5"
QT_MOC_LITERAL(151, 7), // "ui_key5"
QT_MOC_LITERAL(159, 9), // "ui_value6"
QT_MOC_LITERAL(169, 7), // "ui_key6"
QT_MOC_LITERAL(177, 9), // "ui_value7"
QT_MOC_LITERAL(187, 7) // "ui_key7"

    },
    "cm::data::MapDecorator\0valueChanged\0"
    "\0key\0valueRead\0ui_value0\0ui_key0\0"
    "ui_value1\0ui_key1\0ui_value2\0ui_key2\0"
    "ui_value3\0ui_key3\0ui_value4\0ui_key4\0"
    "ui_value5\0ui_key5\0ui_value6\0ui_key6\0"
    "ui_value7\0ui_key7"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__data__MapDecorator[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
      16,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,   17 /* Public */,
       4,    1,   29,    2, 0x06,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
       5, QMetaType::Int, 0x00015001, uint(0), 0,
       6, QMetaType::QString, 0x00015001, uint(1), 0,
       7, QMetaType::Int, 0x00015001, uint(0), 0,
       8, QMetaType::QString, 0x00015001, uint(1), 0,
       9, QMetaType::Int, 0x00015001, uint(0), 0,
      10, QMetaType::QString, 0x00015001, uint(1), 0,
      11, QMetaType::Int, 0x00015001, uint(0), 0,
      12, QMetaType::QString, 0x00015001, uint(1), 0,
      13, QMetaType::Int, 0x00015001, uint(0), 0,
      14, QMetaType::QString, 0x00015001, uint(1), 0,
      15, QMetaType::Int, 0x00015001, uint(0), 0,
      16, QMetaType::QString, 0x00015001, uint(1), 0,
      17, QMetaType::Int, 0x00015001, uint(0), 0,
      18, QMetaType::QString, 0x00015001, uint(1), 0,
      19, QMetaType::Int, 0x00015001, uint(0), 0,
      20, QMetaType::QString, 0x00015001, uint(1), 0,

       0        // eod
};

void cm::data::MapDecorator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MapDecorator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->valueRead((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MapDecorator::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapDecorator::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MapDecorator::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapDecorator::valueRead)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MapDecorator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->valueFromInd0(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->keyFromInd0(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->valueFromInd1(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->keyFromInd1(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->valueFromInd2(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->keyFromInd2(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->valueFromInd3(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->keyFromInd3(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->valueFromInd4(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->keyFromInd4(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->valueFromInd5(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->keyFromInd5(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->valueFromInd6(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->keyFromInd6(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->valueFromInd6(); break;
        case 15: *reinterpret_cast< QString*>(_v) = _t->keyFromInd6(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject cm::data::MapDecorator::staticMetaObject = { {
    QMetaObject::SuperData::link<DataDecorator::staticMetaObject>(),
    qt_meta_stringdata_cm__data__MapDecorator.offsetsAndSize,
    qt_meta_data_cm__data__MapDecorator,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cm__data__MapDecorator_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<MapDecorator, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>



>,
    nullptr
} };


const QMetaObject *cm::data::MapDecorator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::data::MapDecorator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__data__MapDecorator.stringdata0))
        return static_cast<void*>(this);
    return DataDecorator::qt_metacast(_clname);
}

int cm::data::MapDecorator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataDecorator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void cm::data::MapDecorator::valueChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cm::data::MapDecorator::valueRead(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
