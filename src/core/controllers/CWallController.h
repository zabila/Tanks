#pragma once

#include <memory>

#include <QObject>

#include "Engine/CGameEngine.h"
#include "implementations/CWall.h"
#include "interfaces/IController.h"

class CWallController : public QObject, public IController
{
    Q_OBJECT
    Q_PROPERTY(QList<CWall *> walls READ getWalls CONSTANT)
public:
    explicit CWallController(std::shared_ptr<CGameEngine> engine, QObject *parent = nullptr);
    ~CWallController() override = default;

    void initialize(QQmlApplicationEngine *engine) override;

    QList<CWall *> getWalls();

private:
    std::shared_ptr<CGameEngine> gameEngine;
};