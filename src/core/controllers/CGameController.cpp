#include "CGameController.h"

#include <QQmlContext>

#include "Logger.h"
#include "implementations/CTank.h"

CGameController::CGameController(std::shared_ptr<CGameEngine> engine, QObject* parent)
    : QObject(parent)
    , gameEngine(engine)
{}

void CGameController::initialize(QQmlApplicationEngine* engine)
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

    qRegisterMetaType<ITank*>("ITank");
    qRegisterMetaType<CTank*>("CTank");

    context->setContextProperty("gameController", this);
}

void CGameController::startGame()
{
    gameEngine->startGame();
}
void CGameController::endGame()
{
    gameEngine->endGame();
}
int CGameController::mapWidth() const
{
    const auto& data = gameEngine->mapData();
    return data.width;
}
int CGameController::mapHeight() const
{
    const auto& data = gameEngine->mapData();
    return data.height;
}