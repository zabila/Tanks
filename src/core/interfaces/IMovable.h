#pragma once

#include "pod/Enums.h"

class IMovable
{
public:
    virtual ~IMovable() = default;
    virtual void move(MyEnum::Direction direction) = 0;
    virtual int speed() const = 0;
};

Q_DECLARE_INTERFACE(IMovable, "com.example.IMovable")

static std::string toString(MyEnum::Direction direction)
{
    switch (direction) {
    case MyEnum::Direction::UP:
        return "UP";
    case MyEnum::Direction::DOWN:
        return "DOWN";
    case MyEnum::Direction::LEFT:
        return "LEFT";
    case MyEnum::Direction::RIGHT:
        return "RIGHT";
    default:
        return "UNKNOWN";
    }
}
