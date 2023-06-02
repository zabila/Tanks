#pragma once

#include <memory>

#include <QObject>

#include "Engine/CGameEngine.h"
#include "implementations/CPlayerTank.h"
#include "interfaces/IController.h"

class CEnemyTanksController : public QObject, public IController
{
    Q_OBJECT
    Q_PROPERTY(QList<CEnemyTank *> ememyTanks READ getEmemyTanks CONSTANT)
public:
    explicit CEnemyTanksController(std::shared_ptr<CGameEngine> engine, QObject *parent = nullptr);
    ~CEnemyTanksController() override = default;

    void initialize(QQmlApplicationEngine *engine) override;

    QList<CEnemyTank *> getEmemyTanks();

private:
    std::shared_ptr<CGameEngine> gameEngine;
};
