#include "CEnemyTanksController.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"

CEnemyTanksController::CEnemyTanksController(std::shared_ptr<CGameManager> gameManager, QObject *parent)
    : QObject(parent)
    , gameManager_(gameManager)
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
QList<CEmemyTank *> CEnemyTanksController::getEmemyTanks()
{
    gameManager_->load_ememy_tanks();
    return gameManager_->ememy_tanks();
}
