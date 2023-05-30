#pragma once

#include <QObject>

#include "pod/Direction.h"
#include "pod/Point.h"

class IMovable
{
public:
    virtual ~IMovable() = default;
    virtual void move() = 0;

protected:
    Point position_{};
    int speed_{};
    Direction direction_{Direction::Type::DOWN};
};

Q_DECLARE_INTERFACE(IMovable, "com.example.IMovable")