#pragma once

#include <memory>

#include <QObject>

#include "Engine/CGameEngine.h"
#include "implementations/CWall.h"
#include "interfaces/IController.h"

class CWallController : public QObject, public IController
{
    Q_OBJECT
    Q_PROPERTY(QList<CWall*> walls READ getWalls NOTIFY wallsChanged)
public:
    explicit CWallController(std::shared_ptr<CGameEngine> engine, QObject* parent = nullptr);
    ~CWallController() override = default;

    void initialize(QQmlApplicationEngine* engine) override;

    QList<CWall*> getWalls();

public slots:
    void onEnemyTanksChanged();

signals:
    void wallsChanged();

private:
    std::shared_ptr<CGameEngine> gameEngine;
};