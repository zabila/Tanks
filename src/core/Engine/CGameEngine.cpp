#include "CGameEngine.h"

#include <memory>
#include <random>

#include "Logger.h"
#include "implementations/CTank.h"
#include "implementations/CWall.h"
#include "interfaces/IMovable.h"
#include "interfaces/IWall.h"
#include "pod/Point.h"

namespace {

static std::mt19937 engine(std::random_device{}());
int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(engine);
}
} // namespace

CGameEngine::CGameEngine(QObject* parent)
    : QObject(parent)
    , levelManager_(nullptr)
{
    tankDataDefault_ = {30, ""};
    mapRange_ = {500, 500};
}

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
    for (auto& tank : tanks_enemy_) {
        if (tank == nullptr) {
            Log(WARNING) << "Tank is nullptr";
            continue;
        }
        tank->draw();
    }

    for (auto& wall : walls_) {
        if (wall == nullptr) {
            Log(WARNING) << "Wall is nullptr";
            continue;
        }
        if (wall->isDestroyable()) {
            wall->draw();
        }
    }
}

void CGameEngine::createAndLoadEnemyTank()
{
    LogIfFalseReturn(mapRange_.has_value(), "Map range is empty");

    Point point = {getRandomNumber(0, mapRange_->height - tankDataDefault_->size),
                   getRandomNumber(0, mapRange_->height - tankDataDefault_->size)};

    LogIfFalseReturn(tankDataDefault_.has_value(), "Tanks data is empty");
    auto tank = std::make_shared<CTank>(this, point, tankDataDefault_.value());
    tanks_enemy_.push_back(std::move(tank));
}

void CGameEngine::loadEnemyTanks()
{
    tanks_enemy_.clear();

    LogIfFalseReturn(mapRange_.has_value(), "Map range is empty");

    createAndLoadEnemyTank();
    createAndLoadEnemyTank();
    createAndLoadEnemyTank();
}

QList<CTank*> CGameEngine::enemyTanks() const
{
    LogIfFalseReturnValue(!tanks_enemy_.empty(), "Enemy tanks is empty", {});
    LogIfFalseReturnValue(mapRange_.has_value(), "Map range is empty", {});

    QList<CTank*> result;
    for (auto& tank : tanks_enemy_) {
        result.append(tank.get());
    }
    return result;
}

void CGameEngine::loadPlayerTank()
{
    playerTank_.reset();
    LogIfFalseReturn(mapRange_.has_value(), "Map range is empty");

    Point point = {
        getRandomNumber(0, 30),
        getRandomNumber(0, 30),
    };
    LogIfFalseReturn(tankDataDefault_.has_value(), "Tanks data is empty");
    playerTank_ = std::make_shared<CTank>(this, point, tankDataDefault_.value());
}

CTank* CGameEngine::playerTank() const
{
    LogIfFalseReturnValue(mapRange_.has_value(), "Map range is empty", nullptr);
    LogIfNullReturnValue(playerTank_.get(), "Player tank is nullptr", nullptr);
    return playerTank_.get();
}

bool CGameEngine::inRangOfMap(const Point& point) const
{
    LogIfFalseReturnValue(mapRange_.has_value(), "Map range is empty", false);
    return mapRange_->contains(point);
}

CGameEngine::CollisionResult CGameEngine::checkingCollisions(IMovable* movable_object) const
{
    if (movable_object->id() != playerTank_->id() && movable_object->isCollide(playerTank_.get())) {
        return {playerTank_.get(), true};
    }

    auto collisionIt = std::find_if(tanks_enemy_.begin(), tanks_enemy_.end(), [movable_object](const auto& enemyTank) {
        if (movable_object->id() == enemyTank->id()) {
            return false;
        }
        return movable_object->isCollide(enemyTank.get());
    });

    if (collisionIt != tanks_enemy_.end()) {
        return {collisionIt->get(), true};
    }

    auto collisionWallIt = std::find_if(walls_.begin(), walls_.end(), [movable_object](const auto& wall) {
        return movable_object->isCollide(wall.get());
    });

    if (collisionWallIt != walls_.end()) {
        return {collisionWallIt->get(), true};
    }

    return {nullptr, false};
}

void CGameEngine::loadWalls()
{
    walls_.clear();

    LogIfFalseReturn(mapRange_.has_value(), "Map range is empty");

    for (int i = 0; i < 10; ++i) {
        Point point = {getRandomNumber(0, mapRange_->height - tankDataDefault_->size),
                       getRandomNumber(0, mapRange_->height - tankDataDefault_->size)};
        auto wall = std::make_shared<CWall>(this, point);
        walls_.push_back(std::move(wall));
    }
}
QList<CWall*> CGameEngine::walls() const
{
    LogIfFalseReturnValue(!walls_.empty(), "Tanks is empty", {});
    LogIfFalseReturnValue(mapRange_.has_value(), "Map range is empty", {});

    QList<CWall*> result;
    for (auto& wall : walls_) {
        result.append(wall.get());
    }
    return result;
}

MapData CGameEngine::mapData() const
{
    LogIfFalseReturnValue(mapRange_.has_value(), "Map range is empty", {});
    return mapRange_.value();
}

TankData CGameEngine::tankData() const
{
    LogIfFalseReturnValue(tankDataDefault_.has_value(), "Tank data is empty", {});
    return tankDataDefault_.value();
}
