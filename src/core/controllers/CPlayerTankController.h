#pragma once

#include <memory>

#include <QObject>

#include "Engine/CGameEngine.h"
#include "implementations/CTank.h"
#include "interfaces/IController.h"

class CPlayerTankController : public QObject, public IController
{
    Q_OBJECT
    Q_PROPERTY(CTank *playerTank READ getPlayerTank CONSTANT)
public:
    explicit CPlayerTankController(std::shared_ptr<CGameEngine> engine, QObject *parent = nullptr);
    ~CPlayerTankController() override = default;

    void initialize(QQmlApplicationEngine *engine) override;

    CTank *getPlayerTank();

private:
    std::shared_ptr<CGameEngine> gameEngine;
};