/****************************************************************************
** Meta object code from reading C++ file 'master-controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/controllers/master-controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'master-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__controllers__MasterController_t {
    const uint offsetsAndSize[20];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cm__controllers__MasterController_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cm__controllers__MasterController_t qt_meta_stringdata_cm__controllers__MasterController = {
    {
QT_MOC_LITERAL(0, 33), // "cm::controllers::MasterContro..."
QT_MOC_LITERAL(34, 17), // "ui_welcomeMessage"
QT_MOC_LITERAL(52, 23), // "ui_navigationController"
QT_MOC_LITERAL(76, 38), // "cm::controllers::NavigationCo..."
QT_MOC_LITERAL(115, 20), // "ui_commandController"
QT_MOC_LITERAL(136, 35), // "cm::controllers::CommandContr..."
QT_MOC_LITERAL(172, 12), // "ui_newClient"
QT_MOC_LITERAL(185, 19), // "cm::models::Client*"
QT_MOC_LITERAL(205, 15), // "ui_basicStorage"
QT_MOC_LITERAL(221, 20) // "cm::models::Storage*"

    },
    "cm::controllers::MasterController\0"
    "ui_welcomeMessage\0ui_navigationController\0"
    "cm::controllers::NavigationController*\0"
    "ui_commandController\0"
    "cm::controllers::CommandController*\0"
    "ui_newClient\0cm::models::Client*\0"
    "ui_basicStorage\0cm::models::Storage*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__controllers__MasterController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015401, uint(-1), 0,
       2, 0x80000000 | 3, 0x00015409, uint(-1), 0,
       4, 0x80000000 | 5, 0x00015409, uint(-1), 0,
       6, 0x80000000 | 7, 0x00015409, uint(-1), 0,
       8, 0x80000000 | 9, 0x00015409, uint(-1), 0,

       0        // eod
};

void cm::controllers::MasterController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::controllers::CommandController* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::controllers::NavigationController* >(); break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::Client* >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::Storage* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MasterController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->welcomeMessage(); break;
        case 1: *reinterpret_cast< cm::controllers::NavigationController**>(_v) = _t->navigationController(); break;
        case 2: *reinterpret_cast< cm::controllers::CommandController**>(_v) = _t->commandController(); break;
        case 3: *reinterpret_cast< cm::models::Client**>(_v) = _t->newClient(); break;
        case 4: *reinterpret_cast< cm::models::Storage**>(_v) = _t->basicStorage(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
}

const QMetaObject cm::controllers::MasterController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cm__controllers__MasterController.offsetsAndSize,
    qt_meta_data_cm__controllers__MasterController,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cm__controllers__MasterController_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<cm::controllers::NavigationController*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::controllers::CommandController*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::models::Client*, std::true_type>, QtPrivate::TypeAndForceComplete<cm::models::Storage*, std::true_type>, QtPrivate::TypeAndForceComplete<MasterController, std::true_type>



>,
    nullptr
} };


const QMetaObject *cm::controllers::MasterController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::controllers::MasterController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__controllers__MasterController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cm::controllers::MasterController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
