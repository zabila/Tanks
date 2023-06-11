#pragma once

#include <QObject>

class MyEnum : public QObject
{
    Q_OBJECT
public:
    enum ObjectType { TANK, WALL, BULLET };
    Q_ENUM(ObjectType)

    enum Direction { UP, DOWN, LEFT, RIGHT };
    Q_ENUM(Direction)

    enum EnemyTankLevel { EASY, MEDIUM, HARD, BOSS, SUPER };
    Q_ENUM(EnemyTankLevel)
};
typedef MyEnum::Direction EDirection;
