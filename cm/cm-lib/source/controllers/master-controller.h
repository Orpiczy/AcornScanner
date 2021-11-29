#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H



#include <QObject>
#include <QScopedPointer>
#include <QString>
#include <cm-lib_global.h>
#include <controllers/navigation-controller.h>
#include <controllers/command-controller.h>
#include <models/client.h>
#include <models/storage.h>

namespace cm {
namespace controllers {

using Client = cm::models::Client;
using Storage = cm::models::Storage;

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString                                ui_welcomeMessage       READ welcomeMessage       CONSTANT )
//    we are adding here namespace info because it is access from ui side
    Q_PROPERTY( cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY( cm::controllers::CommandController*    ui_commandController    READ commandController    CONSTANT )
    Q_PROPERTY( cm::models::Client*                    ui_newClient            READ newClient            CONSTANT )
    Q_PROPERTY( cm::models::Storage*                   ui_basicStorage         READ basicStorage         CONSTANT )
public:
    explicit MasterController(QObject* parent = nullptr);
    ~MasterController();
    NavigationController* navigationController();
    CommandController* commandController();
    const QString& welcomeMessage() const;
    Client *newClient();
    Storage *basicStorage();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};
}}
#endif
