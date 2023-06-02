#include "CPlayerTankController.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"

CPlayerTankController::CPlayerTankController(std::shared_ptr<CGameManager> gameManager, QObject *parent)
    : QObject(parent)
    , gameManager_(gameManager)
{}

void CPlayerTankController::initialize(QQmlApplicationEngine *engine)
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

    context->setContextProperty("playerTankController", this);
}

CPlayerTank *CPlayerTankController::getPlayerTank()
{
    gameManager_->load_player_tank();
    return gameManager_->player_tank();
}