#pragma once

#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>

#include "implementations/CEnemyTank.h"
#include "implementations/CPlayerTank.h"
#include "managers/CGameManager.h"
#include "pod/Point.h"

// Register the types with the meta-object system
Q_DECLARE_METATYPE(CEmemyTank *)
Q_DECLARE_METATYPE(CPlayerTank *)
Q_DECLARE_METATYPE(PointWrapper *)
class CGameController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<CEmemyTank *> ememyTanks READ getEmemyTanks CONSTANT)
    Q_PROPERTY(CPlayerTank *playerTank READ getPlayerTank CONSTANT)

public:
    explicit CGameController(QObject *parent = nullptr);
    ~CGameController() override = default;

    void initialize(QQmlApplicationEngine *engine);

    QList<CEmemyTank *> getEmemyTanks();
    CPlayerTank *getPlayerTank();

    Q_INVOKABLE void startGame();
    Q_INVOKABLE void endGame();

private:
    std::unique_ptr<CGameManager> gameManager_;
};
