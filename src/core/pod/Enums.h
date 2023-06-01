#pragma once

#include <QObject>

class MyEnum : public QObject
{
    Q_OBJECT
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Q_ENUM(Direction)
};
typedef MyEnum::Direction EDirection;
