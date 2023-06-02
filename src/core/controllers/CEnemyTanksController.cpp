#include "CEnemyTanksController.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"

CEnemyTanksController::CEnemyTanksController(std::shared_ptr<CGameEngine> engine, QObject *parent)
    : QObject(parent)
    , gameEngine(engine)
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
QList<CEnemyTank *> CEnemyTanksController::getEmemyTanks()
{
    gameEngine->load_ememy_tanks();
    return gameEngine->ememy_tanks();
}
