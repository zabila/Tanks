#include "CGameController.h"

#include <QQmlContext>

#include "Logger.h"
#include "implementations/CEnemyTank.h"
#include "implementations/CPlayerTank.h"

CGameController::CGameController(std::shared_ptr<CGameManager> gameManager, QObject *parent)
    : QObject(parent)
    , gameManager_(gameManager)
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