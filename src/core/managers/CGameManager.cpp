#include "CGameManager.h"

#include <memory>
#include <random>

#include "Logger.h"
#include "implementations/CEnemyTank.h"
#include "implementations/CPlayerTank.h"
#include "implementations/CTankFactory.h"
#include "implementations/CWallFactory.h"
#include "interfaces/IWall.h"

namespace {
int getRandomNumber(int min, int max)
{
    std::random_device rd;                            // Obtain a random number from hardware
    std::mt19937 gen(rd());                           // Seed the random number engine
    std::uniform_int_distribution<int> dis(min, max); // Define the distribution

    return dis(gen); // Generate and return a random number within the specified range
}
} // namespace

CGameManager::CGameManager(QObject *parent)
    : QObject(parent)
    , levelManager_(nullptr)
    , wallFactory_(std::make_unique<CWallFactory>())
    , tankFactory_(std::make_unique<CTankFactory>())
{}

void CGameManager::startGame()
{
    gameTimer_ = std::make_unique<QTimer>();
    connect(gameTimer_.get(), &QTimer::timeout, this, &CGameManager::updateGame);
    gameTimer_->start(1000 / 60);
}

void CGameManager::endGame()
{
    if (gameTimer_) {
        gameTimer_->stop();
        gameTimer_.reset();
    }
}
void CGameManager::updateGame()
{
    for (auto &tank : tanks_ememy_) {
        if (tank == nullptr) {
            Log(WARNING) << "Tank is nullptr";
            continue;
        }
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

void CGameManager::create_and_load_enemy_tank(CTankFactory::ETankType type)
{
    auto tank = tankFactory_->createTank(type, {getRandomNumber(0, 30), getRandomNumber(0, 30)});
    if (tank == nullptr) {
        Log(WARNING) << "Tank is nullptr";
        return;
    }
    tanks_ememy_.push_back(std::dynamic_pointer_cast<CEmemyTank>(tank));
}

void CGameManager::load_ememy_tanks()
{
    create_and_load_enemy_tank(CTankFactory::ETankType::LIGHT);
    create_and_load_enemy_tank(CTankFactory::ETankType::MEDIUM);
    create_and_load_enemy_tank(CTankFactory::ETankType::HEAVY);
}

QList<CEmemyTank *> CGameManager::ememy_tanks() const
{
    if (tanks_ememy_.empty()) {
        Log(WARNING) << "Tanks is empty";
    }

    QList<CEmemyTank *> result;
    for (auto &tank : tanks_ememy_) {
        if (tank == nullptr) {
            Log(WARNING) << "Tank is nullptr";
            continue;
        }
        result.append(tank.get());
    }
    return result;
}

void CGameManager::load_walls() {}
