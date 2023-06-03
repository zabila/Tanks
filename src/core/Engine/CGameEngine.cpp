#include "CGameEngine.h"

#include <memory>
#include <random>

#include "Logger.h"
#include "implementations/CTank.h"
#include "implementations/CTankFactory.h"
#include "implementations/CWall.h"
#include "implementations/CWallFactory.h"
#include "interfaces/IWall.h"

namespace {

static std::mt19937 engine(std::random_device{}());
int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(engine);
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
    checkingCollisions();

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

    auto tank = tankFactory_->createTank(type,
                                         {getRandomNumber(0, mapRange_->height), getRandomNumber(0, mapRange_->height)},
                                         mapRange_.value());
    tanks_enemy_.push_back(std::dynamic_pointer_cast<CTank>(tank));
}

void CGameEngine::load_enemy_tanks()
{
    tanks_enemy_.clear();

    LogIfFalseReturn(mapRange_.has_value(), "Map range is empty");

    create_and_load_enemy_tank(CTankFactory::ETankType::LIGHT);
    create_and_load_enemy_tank(CTankFactory::ETankType::MEDIUM);
    create_and_load_enemy_tank(CTankFactory::ETankType::HEAVY);
}

QList<CTank *> CGameEngine::enemy_tanks() const
{
    LogIfFalseReturnValue(!tanks_enemy_.empty(), "Enemy tanks is empty", {});
    LogIfFalseReturnValue(mapRange_.has_value(), "Map range is empty", {});

    QList<CTank *> result;
    for (auto &tank : tanks_enemy_) {
        result.append(tank.get());
    }
    return result;
}

void CGameEngine::load_player_tank()
{
    playerTank_.reset();
    LogIfFalseReturn(mapRange_.has_value(), "Map range is empty");

    auto tank = tankFactory_->createTank(CTankFactory::ETankType::PLAYER,
                                         {getRandomNumber(0, 30), getRandomNumber(0, 30)},
                                         mapRange_.value());
    playerTank_ = std::dynamic_pointer_cast<CTank>(tank);
}

CTank *CGameEngine::player_tank() const
{
    LogIfFalseReturnValue(mapRange_.has_value(), "Map range is empty", nullptr);
    LogIfNullReturnValue(playerTank_.get(), "Player tank is nullptr", nullptr);
    return playerTank_.get();
}

void CGameEngine::initMap(int width, int height)
{
    Log(INFO) << "Init map width: " << width << " height: " << height;
    mapRange_ = {width, height};
}
void CGameEngine::checkingCollisions()
{
    for (const auto &enemyTank : tanks_enemy_) {
        checkCollisionAndDoAction(playerTank_.get(), enemyTank.get(), []() {
            Log(INFO) << "Player tank collide with enemy tank";
        });

        for (const auto &wall : walls_) {
            checkCollisionAndDoAction(enemyTank.get(), wall.get(), []() {
                Log(INFO) << "Enemy tank collide with wall";
            });
        }
    }

    for (size_t i = 0; i < tanks_enemy_.size(); ++i) {
        for (size_t j = i + 1; j < tanks_enemy_.size(); ++j) {
            checkCollisionAndDoAction(tanks_enemy_[i].get(), tanks_enemy_[j].get(), []() {
                Log(INFO) << "Enemy tank collide with enemy tank";
            });
        }
    }

    for (const auto &wall : walls_) {
        checkCollisionAndDoAction(playerTank_.get(), wall.get(), []() { Log(INFO) << "Player tank collide with wall"; });
    }
}
void CGameEngine::load_walls()
{
    walls_.clear();

    LogIfFalseReturn(mapRange_.has_value(), "Map range is empty");

    for (int i = 0; i < 10; ++i) {
        auto wall = wallFactory_->createWall(IWallFactory::EWallsType::BRICK,
                                             {getRandomNumber(0, mapRange_->height),
                                              getRandomNumber(0, mapRange_->height)},
                                             mapRange_.value());
        walls_.push_back(std::dynamic_pointer_cast<CWall>(wall));
    }
}
QList<CWall *> CGameEngine::walls() const
{
    LogIfFalseReturnValue(!walls_.empty(), "Tanks is empty", {});
    LogIfFalseReturnValue(mapRange_.has_value(), "Map range is empty", {});

    QList<CWall *> result;
    for (auto &wall : walls_) {
        result.append(wall.get());
    }
    return result;
}
