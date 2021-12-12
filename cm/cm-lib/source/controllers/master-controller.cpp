#include "master-controller.h"

namespace cm {
namespace controllers {

class MasterController::Implementation
{ public:
    Implementation(MasterController* _masterController)
        : masterController(_masterController)
    {
        navigationController = new NavigationController(masterController);
        commandController = new CommandController(masterController);
        newClient = new Client(masterController);
        basicStorage = new Storage(masterController);
        recentlyScannedData = new ScannedData(masterController);
    }
    MasterController* masterController{nullptr};
    NavigationController* navigationController{nullptr};
    CommandController* commandController{nullptr};
    QString welcomeMessage = "This is MasterController to Major Tom";
    Client* newClient{nullptr};
    Storage* basicStorage{nullptr};
    ScannedData* recentlyScannedData{nullptr};
};
MasterController::MasterController(QObject* parent)
    : QObject(parent)
{
    implementation.reset(new Implementation(this));
}
MasterController::~MasterController()
{}
NavigationController* MasterController::navigationController()
{
    return implementation->navigationController;
}

CommandController *MasterController::commandController()
{
    return implementation->commandController;
}
const QString& MasterController::welcomeMessage() const
{
    return implementation->welcomeMessage;
}

Client* MasterController::newClient()
{
    return implementation->newClient;
}

Storage *MasterController::basicStorage()
{
    return implementation->basicStorage;
}

ScannedData *MasterController::recentlyScannedData()
{
    return implementation->recentlyScannedData;
}
}}
