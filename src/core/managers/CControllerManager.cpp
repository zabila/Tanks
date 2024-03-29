#include "CControllerManager.h"
#include "Engine/CGameEngine.h"
#include "controllers/CEnemyTanksController.h"
#include "controllers/CGameController.h"
#include "controllers/CPlayerTankController.h"
#include "controllers/CWallController.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <qobject.h>

void CControllerManager::init(QQmlApplicationEngine* engine)
{
    gameEngine = std::make_shared<CGameEngine>(engine);

    auto gameController = std::make_unique<CGameController>(gameEngine);
    controllers_.push_back(std::move(gameController));

    auto playerTankController = std::make_unique<CPlayerTankController>(gameEngine);
    controllers_.push_back(std::move(playerTankController));

    auto enemyTanksController = std::make_unique<CEnemyTanksController>(gameEngine);
    QObject::connect(gameEngine.get(),
                     &CGameEngine::onEnemyTanksChanged,
                     enemyTanksController.get(),
                     &CEnemyTanksController::onEnemyTanksChanged);
    controllers_.push_back(std::move(enemyTanksController));

    auto wallController = std::make_unique<CWallController>(gameEngine);
    QObject::connect(gameEngine.get(),
                     &CGameEngine::onWallChanged,
                     wallController.get(),
                     &CWallController::onWallsChanged);
    controllers_.push_back(std::move(wallController));
}

void CControllerManager::initializeAll(QQmlApplicationEngine* engine)
{
    for (auto& controller : controllers_) {
        controller->initialize(engine);
    }
}

void CControllerManager::RegisterMetaTypes()
{
    qRegisterMetaType<ITank*>("ITank");
    qRegisterMetaType<CTank*>("CTank");
    qRegisterMetaType<PointWrapper>("PointWrapper");
    qRegisterMetaType<EDirection>("EDirection");
    qmlRegisterUncreatableType<MyEnum>("MyEnums",
                                       1,
                                       0,
                                       "EDirection",
                                       QStringLiteral("Cannot create objects of type MyEnum"));
}

CControllerManager::CControllerManager(QQmlApplicationEngine* engine)
{
    init(engine);
}
