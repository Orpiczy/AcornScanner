#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>
#include <cm-lib_global.h>

namespace cm {
namespace controllers {

class CMLIB_EXPORT NavigationController : public QObject
{
    Q_OBJECT
public:
    explicit NavigationController(QObject* _parent = nullptr)
        : QObject(_parent)
    {}
signals:
    void goACMasterView();
    void goACSettingsView();
};
}}

#endif
