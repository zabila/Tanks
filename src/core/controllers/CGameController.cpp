#include "CGameController.h"

#include <QQmlContext>

#include "Logger.h"
#include "implementations/CEnemyTank.h"
#include "implementations/CPlayerTank.h"

CGameController::CGameController(QObject *parent)
    : QObject(parent)
    , gameManager_(std::make_unique<CGameManager>())
{}

void CGameController::initialize(QQmlApplicationEngine *engine)
{
    if (!engine) {
        Log(FATAL) << "Engine is nullptr";
        return;
    }

    auto context = engine->rootContext();
    if (!context) {
        Log(FATAL) << "Context is nullptr";
        return;
    }

    qRegisterMetaType<ITank *>("ITank");
    qRegisterMetaType<CPlayerTank *>("CPlayerTank");

    context->setContextProperty("gameController", this);
}

void CGameController::startGame()
{
    gameManager_->startGame();
}
void CGameController::endGame()
{
    gameManager_->endGame();
}

QList<CEmemyTank *> CGameController::getEmemyTanks()
{
    gameManager_->load_ememy_tanks();
    auto tanks = gameManager_->ememy_tanks();

    auto tank = dynamic_cast<CPlayerTank *>(tanks[0]);

    return tanks;
}

CPlayerTank *CGameController::getPlayerTank()
{
    return nullptr;
}
