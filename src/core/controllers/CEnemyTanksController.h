#pragma once

#include <memory>

#include <QObject>

#include "implementations/CPlayerTank.h"
#include "interfaces/IController.h"
#include "managers/CGameManager.h"

class CEnemyTanksController : public QObject, public IController
{
    Q_OBJECT
    Q_PROPERTY(QList<CEmemyTank *> ememyTanks READ getEmemyTanks CONSTANT)
public:
    explicit CEnemyTanksController(std::shared_ptr<CGameManager> gameManager, QObject *parent = nullptr);
    ~CEnemyTanksController() override = default;

    void initialize(QQmlApplicationEngine *engine) override;

    QList<CEmemyTank *> getEmemyTanks();

private:
    std::shared_ptr<CGameManager> gameManager_;
};
