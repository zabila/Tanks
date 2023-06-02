#include "CPlayerTankController.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"

CPlayerTankController::CPlayerTankController(std::shared_ptr<CGameEngine> engine, QObject *parent)
    : QObject(parent)
    , gameEngine(engine)
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
    gameEngine->load_player_tank();
    return gameEngine->player_tank();
}