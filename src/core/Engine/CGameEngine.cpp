#include "CGameEngine.h"

#include <memory>
#include <random>

#include "Logger.h"
#include "implementations/CTank.h"
#include "implementations/CTankFactory.h"
#include "implementations/CWallFactory.h"
#include "interfaces/IWall.h"

namespace {
int getRandomNumber(int min, int max)
{
    std::random_device rd;                            // Obtain a random number from hardware
    std::mt19937 gen(rd());                           // Seed the random number engine
    std::uniform_int_distribution<int> dis(min, max); // Define the distribution

    return dis(gen);                                  // Generate and return a random number within the specified range
}
} // namespace

CGameEngine::CGameEngine(QObject *parent)
    : QObject(parent)
    , levelManager_(nullptr)
    , wallFactory_(std::make_unique<CWallFactory>())
    , tankFactory_(std::make_unique<CTankFactory>())
{}

void CGameEngine::startGame()
{
    Log(INFO) << "Start game";
    gameTimer_ = std::make_unique<QTimer>();
    connect(gameTimer_.get(), &QTimer::timeout, this, &CGameEngine::updateGame);
    gameTimer_->start(1000 / 60);
}

void CGameEngine::endGame()
{
    Log(INFO) << "End game";
    if (gameTimer_) {
        gameTimer_->stop();
        gameTimer_.reset();
    }
}
void CGameEngine::updateGame()
{
    for (auto &tank : tanks_enemy_) {
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
        if (wall->isDestroyable()) {
            wall->draw();
        }
    }
}

void CGameEngine::create_and_load_enemy_tank(CTankFactory::ETankType type)
{
    if (!mapRange_.has_value()) {
        Log(WARNING) << "Map range is empty";
        return;
    }

    auto tank = tankFactory_->createTank(type, {getRandomNumber(1, 15), getRandomNumber(1, 15)}, mapRange_.value());
    if (tank == nullptr) {
        Log(WARNING) << "Tank is nullptr";
        return;
    }
    tanks_enemy_.push_back(std::dynamic_pointer_cast<CTank>(tank));
}

void CGameEngine::load_enemy_tanks()
{
    tanks_enemy_.clear();

    if (!mapRange_.has_value()) {
        Log(WARNING) << "Map range is empty";
        return;
    }

    create_and_load_enemy_tank(CTankFactory::ETankType::LIGHT);
    create_and_load_enemy_tank(CTankFactory::ETankType::MEDIUM);
    create_and_load_enemy_tank(CTankFactory::ETankType::HEAVY);
}

QList<CTank *> CGameEngine::enemy_tanks() const
{
    if (tanks_enemy_.empty()) {
        Log(WARNING) << "Tanks is empty";
        return {};
    }

    if (!mapRange_.has_value()) {
        Log(WARNING) << "Map range is empty";
        return {};
    }

    QList<CTank *> result;
    for (auto &tank : tanks_enemy_) {
        if (tank == nullptr) {
            Log(WARNING) << "Tank is nullptr";
            continue;
        }
        result.append(tank.get());
    }
    return result;
}

void CGameEngine::load_player_tank()
{
    playerTank_.reset();

    if (!mapRange_.has_value()) {
        Log(WARNING) << "Map range is empty";
        return;
    }

    auto tank = tankFactory_->createTank(CTankFactory::ETankType::PLAYER,
                                         {getRandomNumber(0, 30), getRandomNumber(0, 30)},
                                         mapRange_.value());
    if (tank == nullptr) {
        Log(WARNING) << "Tank is nullptr";
        return;
    }
    playerTank_ = std::dynamic_pointer_cast<CTank>(tank);
}

CTank *CGameEngine::player_tank() const
{
    if (!mapRange_.has_value()) {
        Log(WARNING) << "Map range is empty";
        return nullptr;
    }

    if (playerTank_ == nullptr) {
        Log(WARNING) << "Player tank is nullptr";
        return nullptr;
    }
    return playerTank_.get();
}

void CGameEngine::initMap(int width, int height)
{
    Log(INFO) << "Init map width: " << width << " height: " << height;
    mapRange_ = {width, height};
}
