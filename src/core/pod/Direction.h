#pragma once

class Direction
{
public:
    enum class Type
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    Direction(Type type) : type(type) {}
    Type getType() const { return type; }

private:
    Type type;
};