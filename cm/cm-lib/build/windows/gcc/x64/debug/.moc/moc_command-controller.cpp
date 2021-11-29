/****************************************************************************
** Meta object code from reading C++ file 'command-controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/controllers/command-controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'command-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__controllers__CommandController_t {
    const uint offsetsAndSize[10];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cm__controllers__CommandController_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cm__controllers__CommandController_t qt_meta_stringdata_cm__controllers__CommandController = {
    {
QT_MOC_LITERAL(0, 34), // "cm::controllers::CommandContr..."
QT_MOC_LITERAL(35, 26), // "onCreateClientSaveExecuted"
QT_MOC_LITERAL(62, 0), // ""
QT_MOC_LITERAL(63, 34), // "ui_createClientViewContextCom..."
QT_MOC_LITERAL(98, 40) // "QQmlListProperty<cm::framewor..."

    },
    "cm::controllers::CommandController\0"
    "onCreateClientSaveExecuted\0\0"
    "ui_createClientViewContextCommands\0"
    "QQmlListProperty<cm::framework::Command>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__controllers__CommandController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   21, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x0a,    2 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, 0x80000000 | 4, 0x00015409, uint(-1), 0,

       0        // eod
};

void cm::controllers::CommandController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCreateClientSaveExecuted(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CommandController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_createClientViewContextCommands(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
}

const QMetaObject cm::controllers::CommandController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cm__controllers__CommandController.offsetsAndSize,
    qt_meta_data_cm__controllers__CommandController,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cm__controllers__CommandController_t
, QtPrivate::TypeAndForceComplete<QQmlListProperty<cm::framework::Command>, std::true_type>, QtPrivate::TypeAndForceComplete<CommandController, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *cm::controllers::CommandController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::controllers::CommandController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__controllers__CommandController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cm::controllers::CommandController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
