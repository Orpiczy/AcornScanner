/****************************************************************************
** Meta object code from reading C++ file 'contact.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/models/contact.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contact.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__models__Contact_t {
    const uint offsetsAndSize[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cm__models__Contact_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cm__models__Contact_t qt_meta_stringdata_cm__models__Contact = {
    {
QT_MOC_LITERAL(0, 19), // "cm::models::Contact"
QT_MOC_LITERAL(20, 14), // "ui_contactType"
QT_MOC_LITERAL(35, 30), // "cm::data::EnumeratorDecorator*"
QT_MOC_LITERAL(66, 10), // "ui_address"
QT_MOC_LITERAL(77, 26) // "cm::data::StringDecorator*"

    },
    "cm::models::Contact\0ui_contactType\0"
    "cm::data::EnumeratorDecorator*\0"
    "ui_address\0cm::data::StringDecorator*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__models__Contact[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x00015409, uint(-1), 0,
       3, 0x80000000 | 4, 0x00015409, uint(-1), 0,

       0        // eod
};

void cm::models::Contact::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::data::EnumeratorDecorator* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::data::StringDecorator* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Contact *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< cm::data::EnumeratorDecorator**>(_v) = _t->contactType; break;
        case 1: *reinterpret_cast< cm::data::StringDecorator**>(_v) = _t->address; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
}

const QMetaObject cm::models::Contact::staticMetaObject = { {
    QMetaObject::SuperData::link<data::Entity::staticMetaObject>(),
    qt_meta_stringdata_cm__models__Contact.offsetsAndSize,
    qt_meta_data_cm__models__Contact,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cm__models__Contact_t
, QtPrivate::TypeAndForceComplete<cm::data::EnumeratorDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::StringDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<Contact, std::true_type>



>,
    nullptr
} };


const QMetaObject *cm::models::Contact::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::models::Contact::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__models__Contact.stringdata0))
        return static_cast<void*>(this);
    return data::Entity::qt_metacast(_clname);
}

int cm::models::Contact::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = data::Entity::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
