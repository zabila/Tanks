#include "CPlayerTankController.h"

#include <utility>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"

CPlayerTankController::CPlayerTankController(std::shared_ptr<CGameEngine> engine, QObject *parent)
    : QObject(parent)
    , gameEngine(std::move(engine))
{}

void CPlayerTankController::initialize(QQmlApplicationEngine *engine)
{
    LogIfNullReturn(engine, "Game engine is nullptr");

    auto context = engine->rootContext();
    LogIfNullReturn(context, "Context is nullptr");

    context->setContextProperty("playerTankController", this);
}

CTank *CPlayerTankController::getPlayerTank()
{
    gameEngine->loadPlayerTank();
    return gameEngine->playerTank();
}