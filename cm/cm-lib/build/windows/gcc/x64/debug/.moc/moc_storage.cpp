/****************************************************************************
** Meta object code from reading C++ file 'storage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/models/storage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'storage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__models__Storage_t {
    const uint offsetsAndSize[30];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cm__models__Storage_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cm__models__Storage_t qt_meta_stringdata_cm__models__Storage = {
    {
QT_MOC_LITERAL(0, 19), // "cm::models::Storage"
QT_MOC_LITERAL(20, 13), // "coffeeChanged"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 7), // "ui_name"
QT_MOC_LITERAL(43, 26), // "cm::data::StringDecorator*"
QT_MOC_LITERAL(70, 9), // "ui_coffee"
QT_MOC_LITERAL(80, 23), // "cm::data::MapDecorator*"
QT_MOC_LITERAL(104, 9), // "ui_change"
QT_MOC_LITERAL(114, 7), // "ui_milk"
QT_MOC_LITERAL(122, 8), // "ui_water"
QT_MOC_LITERAL(131, 9), // "ui_status"
QT_MOC_LITERAL(141, 8), // "ui_users"
QT_MOC_LITERAL(150, 19), // "ui_users_privileges"
QT_MOC_LITERAL(170, 12), // "ui_max_water"
QT_MOC_LITERAL(183, 11) // "ui_max_milk"

    },
    "cm::models::Storage\0coffeeChanged\0\0"
    "ui_name\0cm::data::StringDecorator*\0"
    "ui_coffee\0cm::data::MapDecorator*\0"
    "ui_change\0ui_milk\0ui_water\0ui_status\0"
    "ui_users\0ui_users_privileges\0ui_max_water\0"
    "ui_max_milk"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__models__Storage[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
      10,   21, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, 0x80000000 | 4, 0x00015409, uint(-1), 0,
       5, 0x80000000 | 6, 0x00015409, uint(-1), 0,
       7, 0x80000000 | 6, 0x00015409, uint(-1), 0,
       8, 0x80000000 | 6, 0x00015409, uint(-1), 0,
       9, 0x80000000 | 6, 0x00015409, uint(-1), 0,
      10, 0x80000000 | 6, 0x00015409, uint(-1), 0,
      11, 0x80000000 | 6, 0x00015409, uint(-1), 0,
      12, 0x80000000 | 6, 0x00015409, uint(-1), 0,
      13, QMetaType::Int, 0x00015401, uint(-1), 0,
      14, QMetaType::Int, 0x00015401, uint(-1), 0,

       0        // eod
};

void cm::models::Storage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Storage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->coffeeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Storage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Storage::coffeeChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
        case 6:
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::data::MapDecorator* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::data::StringDecorator* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Storage *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< cm::data::StringDecorator**>(_v) = _t->name; break;
        case 1: *reinterpret_cast< cm::data::MapDecorator**>(_v) = _t->coffee; break;
        case 2: *reinterpret_cast< cm::data::MapDecorator**>(_v) = _t->change; break;
        case 3: *reinterpret_cast< cm::data::MapDecorator**>(_v) = _t->milk; break;
        case 4: *reinterpret_cast< cm::data::MapDecorator**>(_v) = _t->water; break;
        case 5: *reinterpret_cast< cm::data::MapDecorator**>(_v) = _t->status; break;
        case 6: *reinterpret_cast< cm::data::MapDecorator**>(_v) = _t->users; break;
        case 7: *reinterpret_cast< cm::data::MapDecorator**>(_v) = _t->usersPrivileges; break;
        case 8: *reinterpret_cast< int*>(_v) = _t->maxWater; break;
        case 9: *reinterpret_cast< int*>(_v) = _t->maxMilk; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject cm::models::Storage::staticMetaObject = { {
    QMetaObject::SuperData::link<data::Entity::staticMetaObject>(),
    qt_meta_stringdata_cm__models__Storage.offsetsAndSize,
    qt_meta_data_cm__models__Storage,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cm__models__Storage_t
, QtPrivate::TypeAndForceComplete<cm::data::StringDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::MapDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::MapDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::MapDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::MapDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::MapDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::MapDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::MapDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<Storage, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *cm::models::Storage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::models::Storage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__models__Storage.stringdata0))
        return static_cast<void*>(this);
    return data::Entity::qt_metacast(_clname);
}

int cm::models::Storage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = data::Entity::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void cm::models::Storage::coffeeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
