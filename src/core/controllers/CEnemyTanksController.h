#pragma once

#include <memory>

#include <QObject>

#include "Engine/CGameEngine.h"
#include "implementations/CTank.h"
#include "interfaces/IController.h"

class CEnemyTanksController : public QObject, public IController
{
    Q_OBJECT
    Q_PROPERTY(QList<CTank*> enemyTanks READ getEnemyTanks NOTIFY enemyTanksChanged)
public:
    explicit CEnemyTanksController(std::shared_ptr<CGameEngine> engine, QObject* parent = nullptr);
    ~CEnemyTanksController() override = default;

    void initialize(QQmlApplicationEngine* engine) override;
    QList<CTank*> getEnemyTanks();

public slots:
    void onEnemyTanksChanged();

signals:
    void enemyTanksChanged();

private:
    void emitEnemyTanksChanged();

    std::shared_ptr<CGameEngine> gameEngine;
};
