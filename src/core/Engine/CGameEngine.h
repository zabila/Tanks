#pragma once

#include <memory>

#include <QObject>
#include <QTimer>

#include "interfaces/ITank.h"
#include "interfaces/ITankFactory.h"
#include "interfaces/IWallFactory.h"

#include "implementations/CTank.h"
#include "implementations/CWall.h"
#include "managers/CLevelManager.h"
#include "pod/MapRange.h"

class CGameEngine : public QObject
{
    Q_OBJECT
public:
    explicit CGameEngine(QObject *parent = nullptr);
    ~CGameEngine() override = default;

    void startGame();
    void endGame();
    void initMap(int width, int height);

    void load_enemy_tanks();
    QList<CTank *> enemy_tanks() const;

    void load_player_tank();
    CTank *player_tank() const;

    void load_walls();
    QList<CWall *> walls() const;

private slots:
    void updateGame();

private:
    void create_and_load_enemy_tank(ITankFactory::ETankType type);
    void checkingCollisions();

    std::unique_ptr<QTimer> gameTimer_{};
    std::unique_ptr<CLevelManager> levelManager_{};
    std::unique_ptr<IWallFactory> wallFactory_{};
    std::unique_ptr<ITankFactory> tankFactory_{};
    std::shared_ptr<CTank> playerTank_{};
    std::vector<std::shared_ptr<CTank>> tanks_enemy_{};
    std::vector<std::shared_ptr<CWall>> walls_{};
    MapRangeOpt mapRange_ = std::nullopt;
};
