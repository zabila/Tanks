#pragma once

#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>

#include "Engine/CGameEngine.h"
#include "implementations/CTank.h"
#include "interfaces/IController.h"
#include "pod/Point.h"

class CGameController : public QObject, public IController
{
    Q_OBJECT
    Q_PROPERTY(int mapWidth READ mapWidth CONSTANT)
    Q_PROPERTY(int mapHeight READ mapHeight CONSTANT)
public:
    explicit CGameController(std::shared_ptr<CGameEngine> engine, QObject* parent = nullptr);
    ~CGameController() override = default;

    void initialize(QQmlApplicationEngine* engine) override;

    Q_INVOKABLE void startGame();
    Q_INVOKABLE void endGame();

    int mapWidth() const;
    int mapHeight() const;

private:
    std::shared_ptr<CGameEngine> gameEngine;
};
