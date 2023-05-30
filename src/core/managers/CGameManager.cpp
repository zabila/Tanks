#include "CGameManager.h"

#include "Logger.h"
#include "implementations/CTankFactory.h"
#include "implementations/CWallFactory.h"

CGameManager::CGameManager(QObject *parent)
    : QObject(parent)
{}

void CGameManager::startGame()
{
    wallFactory_.reset();
    tankFactory_.reset();

    gameTimer_ = std::make_unique<QTimer>();
    connect(gameTimer_.get(), &QTimer::timeout, this, &CGameManager::updateGame);
    gameTimer_->start(1000 / 60);

    if (!tankFactory_) {
        tankFactory_ = std::make_unique<CTankFactory>();
    }
    tanks_.push_back(tankFactory_->createTank(CTankFactory::ETankType::PLAYER));
    tanks_.push_back(tankFactory_->createTank(CTankFactory::ETankType::LIGHT));
    tanks_.push_back(tankFactory_->createTank(CTankFactory::ETankType::MEDIUM));
    tanks_.push_back(tankFactory_->createTank(CTankFactory::ETankType::HEAVY));

    if (!wallFactory_) {
        wallFactory_ = std::make_unique<CWallFactory>();
    }
    walls_.push_back(wallFactory_->createWall(CWallFactory::EWallsType::BRICK));
    walls_.push_back(wallFactory_->createWall(CWallFactory::EWallsType::CONCRETE));
}
void CGameManager::endGame()
{
    if (gameTimer_) {
        gameTimer_->stop();
        gameTimer_.reset();
    }

    wallFactory_.reset();
    tankFactory_.reset();
}
void CGameManager::updateGame()
{
    for (auto &tank : tanks_) {
        if (tank == nullptr) {
            Log(WARNING) << "Tank is nullptr";
            continue;
        }
        tank->move();
        tank->draw();
    }

    for (auto &wall : walls_) {
        if (wall == nullptr) {
            Log(WARNING) << "Wall is nullptr";
            continue;
        }
        if (wall->isDestroyble()) {
            wall->draw();
        }
    }
}
void CGameManager::setLevel(int level)
{
    wallFactory_.reset();
    levelManager_ = std::make_unique<CLevelManager>();
    levelManager_->loadLevel(level);
}
