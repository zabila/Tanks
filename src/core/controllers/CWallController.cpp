#include "CWallController.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"
#include "implementations/CWall.h"

CWallController::CWallController(std::shared_ptr<CGameEngine> engine, QObject *parent)
    : QObject(parent)
    , gameEngine(std::move(engine))
{}

void CWallController::initialize(QQmlApplicationEngine *engine)
{
    LogIfNullReturn(gameEngine, "Game engine is nullptr");

    auto context = engine->rootContext();
    LogIfNullReturn(context, "Context is nullptr");

    context->setContextProperty("wallController", this);
}
QList<CWall *> CWallController::getWalls()
{
    gameEngine->loadWalls();
    return gameEngine->walls();
}
