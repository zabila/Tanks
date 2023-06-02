#pragma once

#include <memory>

#include <QObject>
#include <QTimer>

#include "implementations/CEnemyTank.h"
#include "interfaces/ITank.h"
#include "interfaces/ITankFactory.h"
#include "interfaces/IWallFactory.h"

#include "implementations/CPlayerTank.h"
#include "managers/CLevelManager.h"

class CGameEngine : public QObject
{
    Q_OBJECT
public:
    explicit CGameEngine(QObject *parent = nullptr);

    void startGame();
    void endGame();

    void load_ememy_tanks();
    QList<CEnemyTank *> ememy_tanks() const;

    void load_player_tank();
    CPlayerTank *player_tank() const;

private slots:
    void updateGame();

private:
    void create_and_load_enemy_tank(ITankFactory::ETankType type);

    std::unique_ptr<QTimer> gameTimer_{};
    std::unique_ptr<CLevelManager> levelManager_{};
    std::unique_ptr<IWallFactory> wallFactory_{};
    std::unique_ptr<ITankFactory> tankFactory_{};
    std::shared_ptr<CPlayerTank> playerTank_{};
    std::vector<std::shared_ptr<CEnemyTank>> tanks_ememy_{};
    std::vector<std::unique_ptr<IWall>> walls_{};
};
