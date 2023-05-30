#pragma once

#include <memory>

#include <QObject>
#include <QTimer>

#include "interfaces/ITank.h"
#include "interfaces/ITankFactory.h"
#include "interfaces/IWallFactory.h"

#include "CLevelManager.h"

class CGameManager : public QObject
{
    Q_OBJECT
public:
    explicit CGameManager(QObject *parent = nullptr);

    void startGame();
    void endGame();
    void setLevel(int level);

private slots:
    void updateGame();

private:
    std::unique_ptr<QTimer> gameTimer_{};
    std::unique_ptr<CLevelManager> levelManager_{};
    std::unique_ptr<IWallFactory> wallFactory_{};
    std::unique_ptr<ITankFactory> tankFactory_{};
    std::vector<std::unique_ptr<ITank>> tanks_{};
    std::vector<std::unique_ptr<IWall>> walls_{};
};