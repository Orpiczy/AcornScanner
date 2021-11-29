/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/models/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__models__Client_t {
    const uint offsetsAndSize[30];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cm__models__Client_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cm__models__Client_t qt_meta_stringdata_cm__models__Client = {
    {
QT_MOC_LITERAL(0, 18), // "cm::models::Client"
QT_MOC_LITERAL(19, 19), // "appointmentsChanged"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 15), // "contactsChanged"
QT_MOC_LITERAL(56, 10), // "addContact"
QT_MOC_LITERAL(67, 12), // "ui_reference"
QT_MOC_LITERAL(80, 26), // "cm::data::StringDecorator*"
QT_MOC_LITERAL(107, 7), // "ui_name"
QT_MOC_LITERAL(115, 16), // "ui_supplyAddress"
QT_MOC_LITERAL(132, 20), // "cm::models::Address*"
QT_MOC_LITERAL(153, 17), // "ui_billingAddress"
QT_MOC_LITERAL(171, 15), // "ui_appointments"
QT_MOC_LITERAL(187, 41), // "QQmlListProperty<cm::models::..."
QT_MOC_LITERAL(229, 11), // "ui_contacts"
QT_MOC_LITERAL(241, 37) // "QQmlListProperty<cm::models::..."

    },
    "cm::models::Client\0appointmentsChanged\0"
    "\0contactsChanged\0addContact\0ui_reference\0"
    "cm::data::StringDecorator*\0ui_name\0"
    "ui_supplyAddress\0cm::models::Address*\0"
    "ui_billingAddress\0ui_appointments\0"
    "QQmlListProperty<cm::models::Appointment>\0"
    "ui_contacts\0QQmlListProperty<cm::models::Contact>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__models__Client[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       6,   35, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    7 /* Public */,
       3,    0,   33,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   34,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x00015409, uint(-1), 0,
       7, 0x80000000 | 6, 0x00015409, uint(-1), 0,
       8, 0x80000000 | 9, 0x00015409, uint(-1), 0,
      10, 0x80000000 | 9, 0x00015409, uint(-1), 0,
      11, 0x80000000 | 12, 0x00015009, uint(0), 0,
      13, 0x80000000 | 14, 0x00015009, uint(1), 0,

       0        // eod
};

void cm::models::Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->appointmentsChanged(); break;
        case 1: _t->contactsChanged(); break;
        case 2: _t->addContact(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::appointmentsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::contactsChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::data::StringDecorator* >(); break;
        case 3:
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::Address* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Client *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< cm::data::StringDecorator**>(_v) = _t->reference; break;
        case 1: *reinterpret_cast< cm::data::StringDecorator**>(_v) = _t->name; break;
        case 2: *reinterpret_cast< cm::models::Address**>(_v) = _t->supplyAddress; break;
        case 3: *reinterpret_cast< cm::models::Address**>(_v) = _t->billingAddress; break;
        case 4: *reinterpret_cast< QQmlListProperty<cm::models::Appointment>*>(_v) = _t->ui_appointments(); break;
        case 5: *reinterpret_cast< QQmlListProperty<cm::models::Contact>*>(_v) = _t->ui_contacts(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject cm::models::Client::staticMetaObject = { {
    QMetaObject::SuperData::link<data::Entity::staticMetaObject>(),
    qt_meta_stringdata_cm__models__Client.offsetsAndSize,
    qt_meta_data_cm__models__Client,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cm__models__Client_t
, QtPrivate::TypeAndForceComplete<cm::data::StringDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::data::StringDecorator*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::models::Address*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::models::Address*, std::true_type>, QtPrivate::TypeAndForceComplete<QQmlListProperty<cm::models::Appointment>, std::true_type>, QtPrivate::TypeAndForceComplete<QQmlListProperty<cm::models::Contact>, std::true_type>, QtPrivate::TypeAndForceComplete<Client, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *cm::models::Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::models::Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__models__Client.stringdata0))
        return static_cast<void*>(this);
    return data::Entity::qt_metacast(_clname);
}

int cm::models::Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = data::Entity::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void cm::models::Client::appointmentsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cm::models::Client::contactsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
