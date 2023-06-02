#include "CControllerManager.h"
#include "CGameManager.h"
#include "controllers/CEnemyTanksController.h"
#include "controllers/CGameController.h"
#include "controllers/CPlayerTankController.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

CControllerManager::CControllerManager()
{
    init();
}

void CControllerManager::init()
{
    gameManager_ = std::make_shared<CGameManager>();

    auto gameController = std::make_unique<CGameController>(gameManager_);
    controllers_.push_back(std::move(gameController));

    auto playerTankController = std::make_unique<CPlayerTankController>(gameManager_);
    controllers_.push_back(std::move(playerTankController));

    auto enemyTanksController = std::make_unique<CEnemyTanksController>(gameManager_);
    controllers_.push_back(std::move(enemyTanksController));
}

void CControllerManager::initializeAll(QQmlApplicationEngine *engine)
{
    for (auto &controller : controllers_) {
        controller->initialize(engine);
    }
}

void CControllerManager::RegisterMetaTypes()
{
    qRegisterMetaType<ITank *>("ITank");
    qRegisterMetaType<CPlayerTank *>("CPlayerTank");
    qRegisterMetaType<PointWrapper>("PointWrapper");
    qRegisterMetaType<EDirection>("EDirection");
    qmlRegisterType<CPlayerTank>("CustomTypes", 1, 0, "CPlayerTank");
    qmlRegisterUncreatableType<MyEnum>("MyEnums",
                                       1,
                                       0,
                                       "EDirection",
                                       QStringLiteral("Cannot create objects of type MyEnum"));
}
