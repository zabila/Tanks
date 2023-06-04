#pragma once

#include <QObject>

class MyEnum : public QObject
{
    Q_OBJECT
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Q_ENUM(Direction)

    enum TankSide { PLAYER, ENEMY };
    Q_ENUM(TankSide)

    enum EnemyTankLevel { EASY, MEDIUM, HARD, BOSS, SUPER };
    Q_ENUM(EnemyTankLevel)
};
typedef MyEnum::Direction EDirection;
