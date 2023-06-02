#include "CEnemyTanksController.h"

#include <utility>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"

CEnemyTanksController::CEnemyTanksController(std::shared_ptr<CGameEngine> engine, QObject *parent)
    : QObject(parent)
    , gameEngine(std::move(engine))
{}

void CEnemyTanksController::initialize(QQmlApplicationEngine *engine)
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

    context->setContextProperty("enemyTanksController", this);
}
QList<CTank *> CEnemyTanksController::getEmemyTanks()
{
    gameEngine->load_enemy_tanks();
    return gameEngine->enemy_tanks();
}
