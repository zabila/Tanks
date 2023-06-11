#include "CEnemyTanksController.h"

#include <utility>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"

CEnemyTanksController::CEnemyTanksController(std::shared_ptr<CGameEngine> engine, QObject* parent)
    : QObject(parent)
    , gameEngine(std::move(engine))
{}

void CEnemyTanksController::initialize(QQmlApplicationEngine* engine)
{
    LogIfNullReturn(gameEngine, "Game engine is nullptr");

    auto context = engine->rootContext();
    LogIfNullReturn(context, "Context is nullptr");

    context->setContextProperty("enemyTanksController", this);

    gameEngine->loadEnemyTanks();
}
QList<CTank*> CEnemyTanksController::getEnemyTanks()
{
    return gameEngine->enemyTanks();
}

void CEnemyTanksController::onEnemyTanksChanged()
{
    emit enemyTanksChanged();
}
