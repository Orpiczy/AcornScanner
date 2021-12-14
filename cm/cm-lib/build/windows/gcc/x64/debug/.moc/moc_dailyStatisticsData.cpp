/****************************************************************************
** Meta object code from reading C++ file 'dailyStatisticsData.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/models/dailyStatisticsData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dailyStatisticsData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ac__models__DailyStatisticsData_t {
    const uint offsetsAndSize[18];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ac__models__DailyStatisticsData_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ac__models__DailyStatisticsData_t qt_meta_stringdata_ac__models__DailyStatisticsData = {
    {
QT_MOC_LITERAL(0, 31), // "ac::models::DailyStatisticsData"
QT_MOC_LITERAL(32, 26), // "dailyStatisticsDataChanged"
QT_MOC_LITERAL(59, 0), // ""
QT_MOC_LITERAL(60, 23), // "onUpdateDailyStatistics"
QT_MOC_LITERAL(84, 15), // "ui_healthy_list"
QT_MOC_LITERAL(100, 10), // "QList<int>"
QT_MOC_LITERAL(111, 17), // "ui_unhealthy_list"
QT_MOC_LITERAL(129, 20), // "ui_unrecognized_list"
QT_MOC_LITERAL(150, 8) // "ui_dates"

    },
    "ac::models::DailyStatisticsData\0"
    "dailyStatisticsDataChanged\0\0"
    "onUpdateDailyStatistics\0ui_healthy_list\0"
    "QList<int>\0ui_unhealthy_list\0"
    "ui_unrecognized_list\0ui_dates"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ac__models__DailyStatisticsData[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       4,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   27,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       4, 0x80000000 | 5, 0x0001500b, uint(0), 0,
       6, 0x80000000 | 5, 0x0001500b, uint(0), 0,
       7, 0x80000000 | 5, 0x0001500b, uint(0), 0,
       8, QMetaType::QStringList, 0x00015003, uint(0), 0,

       0        // eod
};

void ac::models::DailyStatisticsData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DailyStatisticsData *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dailyStatisticsDataChanged(); break;
        case 1: _t->onUpdateDailyStatistics(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DailyStatisticsData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DailyStatisticsData::dailyStatisticsDataChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DailyStatisticsData *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<int>*>(_v) = _t->healthyList; break;
        case 1: *reinterpret_cast< QList<int>*>(_v) = _t->unhealthyList; break;
        case 2: *reinterpret_cast< QList<int>*>(_v) = _t->unrecognizedList; break;
        case 3: *reinterpret_cast< QList<QString>*>(_v) = _t->dates; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DailyStatisticsData *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->healthyList != *reinterpret_cast< QList<int>*>(_v)) {
                _t->healthyList = *reinterpret_cast< QList<int>*>(_v);
                Q_EMIT _t->dailyStatisticsDataChanged();
            }
            break;
        case 1:
            if (_t->unhealthyList != *reinterpret_cast< QList<int>*>(_v)) {
                _t->unhealthyList = *reinterpret_cast< QList<int>*>(_v);
                Q_EMIT _t->dailyStatisticsDataChanged();
            }
            break;
        case 2:
            if (_t->unrecognizedList != *reinterpret_cast< QList<int>*>(_v)) {
                _t->unrecognizedList = *reinterpret_cast< QList<int>*>(_v);
                Q_EMIT _t->dailyStatisticsDataChanged();
            }
            break;
        case 3:
            if (_t->dates != *reinterpret_cast< QList<QString>*>(_v)) {
                _t->dates = *reinterpret_cast< QList<QString>*>(_v);
                Q_EMIT _t->dailyStatisticsDataChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ac::models::DailyStatisticsData::staticMetaObject = { {
    QMetaObject::SuperData::link<cm::data::Entity::staticMetaObject>(),
    qt_meta_stringdata_ac__models__DailyStatisticsData.offsetsAndSize,
    qt_meta_data_ac__models__DailyStatisticsData,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ac__models__DailyStatisticsData_t
, QtPrivate::TypeAndForceComplete<QList<int>, std::true_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::true_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::true_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>, QtPrivate::TypeAndForceComplete<DailyStatisticsData, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ac::models::DailyStatisticsData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ac::models::DailyStatisticsData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ac__models__DailyStatisticsData.stringdata0))
        return static_cast<void*>(this);
    return cm::data::Entity::qt_metacast(_clname);
}

int ac::models::DailyStatisticsData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = cm::data::Entity::qt_metacall(_c, _id, _a);
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
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ac::models::DailyStatisticsData::dailyStatisticsDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
