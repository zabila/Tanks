#pragma once

#include <memory>
#include <tuple>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QTimer>

#include "interfaces/IDrawable.h"
#include "interfaces/IMovable.h"

#include "Engine/CGameEngine.h"
#include "implementations/CTank.h"
#include "implementations/CWall.h"
#include "managers/CLevelManager.h"
#include "pod/MapData.h"
#include "pod/TankData.h"

class CGameEngine : public QObject
{
    Q_OBJECT

    using CollisionResult = std::tuple<IDrawable*, bool>;

public:
    explicit CGameEngine(QQmlApplicationEngine* engine);
    ~CGameEngine() override = default;

    void startGame();
    void endGame();

    MapData mapData() const;
    TankData tankData() const;

    bool inRangOfMap(const Point& point) const;

    void loadEnemyTanks();
    QList<CTank*> enemyTanks() const;

    void loadPlayerTank();
    CTank* playerTank() const;

    void loadWalls();
    QList<CWall*> walls() const;

    void detroitObject(IDrawable* object);

    CollisionResult checkingCollisions(IMovable* movable_object) const;

signals:
    void onWallChanged();
    void onEnemyTanksChanged();

private slots:
    void updateGame();

private:
    void createAndLoadEnemyTank();

    QQmlApplicationEngine* qmlEngine_;

    std::unique_ptr<QTimer> gameTimer_{};
    std::unique_ptr<CLevelManager> levelManager_{};
    std::shared_ptr<CTank> playerTank_{};
    std::vector<std::shared_ptr<CTank>> tanks_enemy_{};

    bool isShouldUpdateWalls_ = false;
    std::vector<std::shared_ptr<CWall>> walls_{};

    MapDataOpt mapRange_ = std::nullopt;
    TankDataOpt tankDataDefault_ = std::nullopt;
};
